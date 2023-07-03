#ifndef cpythonCVInterface_h
#define cpythonCVInterface_h
#include "cpythonInterface.h"

class CPythonCVInterface : public CPythonInterface
{
private:
public:
  cv::Mat image1, image2;
  CPythonCVInterface(cv::Mat im1, cv::Mat im2) : image1(im1), image2(im2){};
  PyObject *assemblePArgs();
  std::vector<cv::Mat> convertPyObject2Mat(PyAPI_FUNC(PyObject *) pResult);
};

#endif