#ifndef SKINEXTRACTION_H
#define SKINEXTRACTION_H

#include <opencv2/opencv.hpp>

class SkinExtraction
{
public:
    SkinExtraction();
    ~SkinExtraction();

    void calcHist(cv::Mat src, cv::Mat mask, cv::Mat &hist);
    void calcBackProj(cv::Mat src, cv::Mat hist, cv::Mat &backProject);

private:
    cv::Mat skinMask;


};

#endif // SKINEXTRACTION_H
