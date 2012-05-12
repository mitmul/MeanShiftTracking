#include "CamCapture.h"

CamCapture::CamCapture()
    : stop(false)
    , isTracking(true)
{
}

CamCapture::~CamCapture()
{
    stopCapture();
    cap.release();
}

void CamCapture::startCapture()
{
    cap.open(0);
    boost::thread cap_th(boost::bind(&CamCapture::setFrame, this));
}

void CamCapture::stopCapture()
{
    stop = true;
}

cv::Mat CamCapture::getFrame()
{
    return frame;
}

cv::Mat CamCapture::getHSVFrame()
{
    setHSVFrame();
    return hsvFrame;
}

void CamCapture::startTracking()
{
    isTracking = false;
}

void CamCapture::setFrame()
{
    while(!stop)
    {
        try
        {
            cv::Mat image;
            cap >> image;
            cv::flip(image, frame, 1);

            if(!isTracking)
            {
                // 初期ウインドウ
                int wSize = 100;
                cv::Rect initWindow(frame.cols / 2 - wSize / 2, frame.rows / 2 - wSize / 2, wSize, wSize);
                trackWindow = initWindow;

                // ヒストグラム計算
                cv::Mat roiFrame(frame, initWindow);
                skin.calcHist(roiFrame, cv::Mat(), hist);

                isTracking = true;
            }
            if(isTracking)
            {
                if(!hist.empty())
                {
                    // 追跡
                    cv::Mat backProject;
                    skin.calcBackProj(frame, hist, backProject);
                    trackBox = cv::CamShift(backProject, trackWindow, cv::TermCriteria( CV_TERMCRIT_EPS | CV_TERMCRIT_ITER, 10, 1 ));

                    if(trackWindow.area() <= 1)
                    {
                        int cols = backProject.cols;
                        int rows = backProject.rows;
                        int r = (MIN(cols, rows) + 5) / 6;
                        trackWindow = cv::Rect(trackWindow.x - r, trackWindow.y - r, trackWindow.x + r, trackWindow.y + r) & cv::Rect(0, 0, cols, rows);
                    }

                    cv::circle(frame, trackBox.center, 20, cv::Scalar( 0, 255, 255), 2);
                }
                else
                {
                    int wSize = 100;
                    cv::Rect initWindow(frame.cols / 2 - wSize / 2, frame.rows / 2 - wSize / 2, wSize, wSize);
                    cv::rectangle(frame, initWindow, cv::Scalar( 0, 0, 255 ), 2);
                }
            }
            cv::imshow("frame", frame);
        }
        catch(std::exception &e)
        {
            std::cerr << "CamCapture::setFrame" << std::endl
                      << e.what() << std::endl;
        }
    }
}

void CamCapture::setHSVFrame()
{
    cv::cvtColor(frame, hsvFrame, CV_BGR2HSV);
}

