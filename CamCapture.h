#ifndef CAMCAPTURE_H
#define CAMCAPTURE_H

#include <opencv2/opencv.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

#include "SkinExtraction.h"

class CamCapture
{
public:
    CamCapture();
    ~CamCapture();

    void startCapture();
    void stopCapture();

    cv::Mat getFrame();
    cv::Mat getHSVFrame();

    void startTracking();

private:
    SkinExtraction skin;
    cv::VideoCapture cap;
    cv::Mat frame;
    cv::Mat hsvFrame;

    bool stop;
    bool isTracking;
    cv::Rect trackWindow;
    cv::RotatedRect trackBox;
    cv::Mat hist;

    void setFrame();
    void setHSVFrame();

};

#endif // CAMCAPTURE_H
