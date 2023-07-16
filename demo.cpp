#include <Python.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <numpy/arrayobject.h>
#include "cpythonCVInterface.h"
#include<string>
using namespace std;

char *PYTHON_FILE_NAME = "run";
char *PYTHON_FUNC_NAME = "detect";

std::string WORK_SPACE = "./detector";

// Initialize the Python Interpreter
int main(int argc, char *argv[])
{
  CPythonCVInterface cp;
  PyObject *pFunc = cp.loadPyFunc(PYTHON_FILE_NAME, PYTHON_FUNC_NAME, WORK_SPACE);
  for (int i = 10; i < 90; ++i)
  {
    cout << i + 1 << endl;
    cv::Mat image1 = cv::imread("/home/finer/Datasets/TUM/fr3/walking_xyz/associated/rgb/00" + to_string(i) + ".png");
    cv::Mat image2 = cv::imread("/home/finer/Datasets/TUM/fr3/walking_xyz/associated/rgb/00" + to_string(i + 1) + ".png");
    PyObject *pArgs = cp.assemblePArgs(image1, image2);
    PyAPI_FUNC(PyObject *) pResult = cp.callPyFunc(pFunc, pArgs);
    auto res = cp.convertPyObject2Mat(pResult);
    // PyErr_Print();

    cv::imshow("Result Image 1", res[0] * 255);
    cv::imshow("Result Image 2", res[1] * 255);
    cv::imshow("Result Image 3", res[2] * 255);
    cv::waitKey(0);
  }
}
