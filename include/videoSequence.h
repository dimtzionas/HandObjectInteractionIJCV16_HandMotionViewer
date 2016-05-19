#ifndef VIDEOSEQUENCE_H
#define VIDEOSEQUENCE_H


#include <QString>
#include <QDebug>
#include <QImage>
#include <QFile>

#include <opencv2/opencv.hpp>
#include "error_manager.h"


class VideoSequence
{
public:
    VideoSequence();
    VideoSequence( QString basePathFramesForAllCameras_IN, QString myFileString_IndexCheat_IN );

    QString basePathFramesForAllCameras;

    QImage  currFrame_RGB_QT;
    cv::Mat currFrame_RGB_CV;

    QImage  currFrame_RGBD_QT;
    cv::Mat currFrame_RGBD_CV;

    QImage  currFrame_DDD_VIZ_QT;
    cv::Mat currFrame_DDD_VIZ_CV;

    cv::Mat currFrame_DDD_RAW_CV;

    void loadCurrentFrame( int cameraNumber, int frameNumber );

    int videoOffset;
    int totalAllignedFrames;

    int frameRate;
    int frameWidth;
    int frameHeight;

};

#endif // VIDEOSEQUENCE_H
