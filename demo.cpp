#include <Python.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <numpy/arrayobject.h>
#include "cpythonCVInterface.h"
using namespace std;

// char *PYTHON_FILE_NAME = "run";
// char *PYTHON_FUNC_NAME = "detect";

char *PYTHON_FILE_NAME = "pscript";
char *PYTHON_FUNC_NAME = "color2gray";

// python script folder
string WORK_SPACE = "./PY";

// Initialize the Python Interpreter
int main(int argc, char *argv[])
{
  CPythonCVInterface cp;
  PyObject *pFunc = cp.loadPyFunc(PYTHON_FILE_NAME, PYTHON_FUNC_NAME, WORK_SPACE);
  for (int i = 10; i < 90; ++i)
  {
    cout << "index:" << i + 1 << endl;
    cv::Mat image1 = cv::imread("/home/finer/Datasets/TUM/fr3/walking_xyz/associated/rgb/00" + to_string(i) + ".png");
    cv::Mat image2 = cv::imread("/home/finer/Datasets/TUM/fr3/walking_xyz/associated/rgb/00" + to_string(i + 1) + ".png");
    PyObject *pArgs = cp.assemblePArgs(image1, image2);
    PyAPI_FUNC(PyObject *) pResult = cp.callPyFunc(pFunc, pArgs);
    auto res = cp.convertPyObject2Mat(pResult);
    // PyErr_Print();

    cv::imshow("Result Image 1", res[0]);
    cv::imshow("Result Image 2", res[1]);
    cv::imshow("Result Image 3", res[2]);
    cv::waitKey(0);
  }
}
