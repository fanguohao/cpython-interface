#ifndef cpythonInterface_h
#define cpythonInterface_h

#include <Python.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <numpy/arrayobject.h>

class CPythonInterface
{
private:
  PyObject *pName, *pModule, *pDict, *pFunc, *pArgs, *pResult;

public:
  CPythonInterface(){};
  ~CPythonInterface();

  PyObject *loadPyFunc(char *pythonFileName, char *pythonFuncName, std::string work_space);
  PyAPI_FUNC(PyObject *) callPyFunc(PyObject *pFunc, PyAPI_FUNC(PyObject *) pArgs);
};

#endif
