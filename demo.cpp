#include <Python.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <numpy/arrayobject.h>
#include "cpythonCVInterface.h"

char *PYTHON_FILE_NAME = "pscript";
char *PYTHON_FUNC_NAME = "color2gray";

int main()
{
  cv::Mat image1 = cv::imread("/home/finer/Datasets/TUM/fr3/walking_xyz/rgb/1341846342.316068.png");
  cv::Mat image2 = cv::imread("/home/finer/Datasets/TUM/fr3/walking_xyz/rgb/1341846342.316068.png");
  CPythonCVInterface cp(image1, image2);
  PyObject *pFunc = cp.loadPyFunc(PYTHON_FILE_NAME, PYTHON_FUNC_NAME);
  PyObject *pArgs = cp.assemblePArgs();
  PyAPI_FUNC(PyObject *) pResult = cp.callPyFunc(pFunc, pArgs);
  auto res = cp.convertPyObject2Mat(pResult);
  cv::imshow("Result Image 1", res[0]);
  cv::imshow("Result Image 2", res[1]);
  cv::waitKey(0);
}
