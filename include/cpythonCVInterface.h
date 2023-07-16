#ifndef cpythonCVInterface_h
#define cpythonCVInterface_h
#include "cpythonInterface.h"

class CPythonCVInterface : public CPythonInterface
{
private:
public:
  cv::Mat image1, image2;
  PyObject *assemblePArgs(cv::Mat im1, cv::Mat im2);
  std::vector<cv::Mat> convertPyObject2Mat(PyAPI_FUNC(PyObject *) pResult);
};

#endif