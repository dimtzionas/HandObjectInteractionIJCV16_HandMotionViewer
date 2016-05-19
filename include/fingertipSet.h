#ifndef FINGERTIPSET_H
#define FINGERTIPSET_H


#include <modelSET.h>


struct DetectionFigerTip
{
    double topLeft_X;
    double topLeft_Y;
    int    width;
    int    height;
    double center_X;
    double center_Y;
    double confidence;

    Eigen::Vector3d centroid_PCL_3D;

    bool isAssigned_And_Overlooked;
    bool isAttractedByCenterBB;
};


class FingertipSet
{
public:
    FingertipSet();
    FingertipSet( QString basePath_Detections_ForAllCameras_IN, QString myFileString_IndexCheat_IN );

    int totalAllignedFrames;

    QString basePath_Detections_ForAllCameras;

    int videoOffset;

    QVector< QVector<DetectionFigerTip> >    detectionsBag;

    void READ_and_FILTER_detections_ALL_cameras( int totalCameras, int frameNumber, double detectionConfidenceTHRESH );
    void read_Curr_Detections_fromFile(          int      camID,   int frameNumber                                   );
    void filter_DetectionBag(                    int      camID,                    double detectionConfidenceTHRESH );

};

#endif // FINGERTIPSET_H
