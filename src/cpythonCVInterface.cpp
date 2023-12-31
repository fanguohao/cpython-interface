#include "cpythonCVInterface.h"

PyObject *CPythonCVInterface::assemblePArgs(cv::Mat image1, cv::Mat image2)
{
  // Py_Initialize();
  // Initialize the NumPy C API
  this->image1 = image1;
  this->image2 = image2;

  import_array();

  // Convert the images to numpy arrays
  npy_intp dims[] = {image1.rows, image1.cols, image1.channels()};
  PyObject *pImage1 = PyArray_SimpleNewFromData(3, dims, NPY_UINT8, image1.data);
  PyObject *pImage2 = PyArray_SimpleNewFromData(3, dims, NPY_UINT8, image2.data);

  // Create a tuple to hold the image arguments
  PyObject *pArgs = PyTuple_New(2);
  PyTuple_SetItem(pArgs, 0, pImage1);
  PyTuple_SetItem(pArgs, 1, pImage2);
  return pArgs;
}

std::vector<cv::Mat> CPythonCVInterface::convertPyObject2Mat(PyAPI_FUNC(PyObject *) pResult)
{
  std::vector<cv::Mat> res;
  if (pResult != NULL && PyTuple_Check(pResult) && PyTuple_Size(pResult) == 3)
  {
    // Extract the images from the result
    PyObject *pResultImg1 = PyTuple_GetItem(pResult, 0);
    PyObject *pResultImg2 = PyTuple_GetItem(pResult, 1);
    PyObject *pResultImg3 = PyTuple_GetItem(pResult, 2);

    // Convert the images to OpenCV Mats
    cv::Mat resultImage1(
        image1.rows, image1.cols, CV_8UC1,
        PyArray_DATA(reinterpret_cast<PyArrayObject *>(pResultImg1)));
    cv::Mat resultImage2(
        image2.rows, image1.cols, CV_8UC1,
        PyArray_DATA(reinterpret_cast<PyArrayObject *>(pResultImg2)));
    cv::Mat resultImage3(
        image2.rows, image1.cols, CV_8UC1,
        PyArray_DATA(reinterpret_cast<PyArrayObject *>(pResultImg3)));

    // Display or process the resulting images as desired
    res.push_back(resultImage1);
    res.push_back(resultImage2);
    res.push_back(resultImage3);
  }
  return res;
}
