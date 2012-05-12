#include "SkinExtraction.h"

SkinExtraction::SkinExtraction()
{
}

SkinExtraction::~SkinExtraction()
{
}

void SkinExtraction::calcHist(cv::Mat src, cv::Mat mask, cv::Mat &hist)
{
    try
    {
        cv::Mat hsv, hue;
        cv::cvtColor(src, hsv, CV_BGR2HSV);

        std::vector<cv::Mat> s;
        cv::split(hsv, s);
        hue = s.at(0).clone();

        int channels[] = { 0 };
        int histSize[] = { 256 };
        float hrange[] = { 0, 180 };
        const float *ranges[] = { hrange };

        cv::calcHist(&hue, 1, channels, mask, hist, 1, histSize, ranges);
    }
    catch(std::exception &e)
    {
        std::cerr << "SkinExtraction::calcHist" << std::endl
                  << e.what() << std::endl;
    }
}

void SkinExtraction::calcBackProj(cv::Mat src, cv::Mat hist, cv::Mat &backProject)
{
    try
    {
        cv::Mat hsv, hue;
        cv::cvtColor(src, hsv, CV_BGR2HSV);

        std::vector<cv::Mat> s;
        cv::split(hsv, s);
        hue = s.at(0).clone();

        float hrange[] = { 0, 180 };
        const float *ranges[] = { hrange };

        cv::calcBackProject(&hue, 1, 0, hist, backProject, ranges);
    }
    catch(std::exception &e)
    {
        std::cerr << "SkinExtraction::calcBackProj" << std::endl
                  << e.what() << std::endl;
    }
}
