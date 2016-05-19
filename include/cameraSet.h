#ifndef CAMERASET_H
#define CAMERASET_H


#include <QtOpenGL> // for projectionStuff

#include <iostream>

#include <mymath.h>
#include "error_manager.h"

struct OpenGL_Stuff
{
    int nearPlane;
    int farPlane;
};


struct cameraMatricesStruct
{
        Eigen::MatrixXd K;
        Eigen::MatrixXd R;
        Eigen::MatrixXd T;
        Eigen::MatrixXd RT_3x4;
        Eigen::MatrixXd RT_4x4;
        Eigen::MatrixXd P_3x4;

        QVector<double> intrinsicsVec_fx_fy_cx_cy;
};



class CameraSet
{



public:

    Eigen::MatrixXd RT_4x4_custom;

    CameraSet();
    CameraSet( QString INPUT_FINAL_PATH__Cameras );

    void setupCameras( QString INPUT_FINAL_PATH__Cameras );
    void print();

    int totalCameras;
    int currentCameraID;

    QVector<OpenGL_Stuff> openGL_Stuff;

    QVector< cameraMatricesStruct >  cameras;

    bool switchCamera( int newCurrCamID );
    void setProjectionFrom_K();
    void setModelViewFrom_RT_cameraDefault();
    void setModelViewFrom_RT_customMat_4_4();

};

#endif // CAMERASET_H
