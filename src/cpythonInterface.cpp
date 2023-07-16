#include "cpythonInterface.h"

CPythonInterface::~CPythonInterface()
{
  // Clean up
  Py_DECREF(pName);
  Py_DECREF(pModule);

  // Finish the Python Interpreter
  Py_FinalizeEx();
}

PyObject *CPythonInterface::loadPyFunc(char *pythonFileName, char *pythonFuncName, std::string work_space = ".")
{

  setenv("PYTHONPATH", ".", 1);

  // Initialize the Python Interpreter
  if (!Py_IsInitialized())
    Py_Initialize();

  std::string command = "import sys; sys.path.append('" + work_space + "')";
  PyRun_SimpleString(command.c_str());

  // Build the name object
  pName = PyUnicode_FromString((char *)pythonFileName);

  // Load the module object
  pModule = PyImport_Import(pName);
  PyErr_Print();

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
