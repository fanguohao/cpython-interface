#include "cpythonInterface.h"

CPythonInterface::~CPythonInterface()
{
  // Clean up
  Py_DECREF(pName);
  Py_DECREF(pModule);

  // Finish the Python Interpreter
  Py_FinalizeEx();
}

PyObject *CPythonInterface::loadPyFunc(char *pythonFileName, char *pythonFuncName)
{
  setenv("PYTHONPATH", ".", 1);

  // Initialize the Python Interpreter
  Py_Initialize();

  // import_array(); // Initialize the NumPy C API
  // Build the name object
  pName = PyUnicode_FromString((char *)pythonFileName);

  // Load the module object
  pModule = PyImport_Import(pName);

  // pDict is a borrowed reference
  pDict = PyModule_GetDict(pModule);

  // pFunc is also a borrowed reference
  pFunc = PyDict_GetItemString(pDict, (char *)pythonFuncName);
  return pFunc;
}

PyAPI_FUNC(PyObject *) CPythonInterface::callPyFunc(PyObject *pFunc, PyAPI_FUNC(PyObject *) pArgs)
{
  if (PyCallable_Check(pFunc))
  {
    // Call the function with the image arguments
    pResult = PyObject_CallObject(pFunc, pArgs);
    PyErr_Print();
    return pResult;
  }
  return NULL;
}
