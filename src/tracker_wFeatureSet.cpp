#include "featureSet.h"


FeatureSet::FeatureSet()
{
}


void FeatureSet::clear( int totalCameras )
{
        fingerTips.detectionsBag.clear();          fingerTips.detectionsBag.resize( totalCameras );
        PCL_Curr.clear();                          PCL_Curr.resize(                 totalCameras );
}



// We back project input images -> pointclouds
// instead of straight reading the pcd files
// in order to avoid the extra dependency of PCL library
// http://pointclouds.org/
void FeatureSet::BackProject_Depth_2_PCL( const int             &camID,
                                          const QVector<double> &intrinsicsVec_fx_fy_cx_cy,
                                          const cv::Mat         &Img_COL_RAWW_Curr,
                                          const cv::Mat         &Img_DDD_RAWW_Curr )
{

        /////////////////////////////////////////
        double fx = intrinsicsVec_fx_fy_cx_cy[0];
        double fy = intrinsicsVec_fx_fy_cx_cy[1];
        double cx = intrinsicsVec_fx_fy_cx_cy[2];
        double cy = intrinsicsVec_fx_fy_cx_cy[3];
        /////////////////////////////////////////
        int www = Img_COL_RAWW_Curr.cols;
        int hhh = Img_COL_RAWW_Curr.rows;


                                            //////////////////////////////////////////
                                            PCL_Curr[camID].points.clear();
                                            PCL_Curr[camID].points.     resize( hhh );
        for (int iii=0; iii<hhh; iii++)     PCL_Curr[camID].points[iii].resize( www );
                                            //////////////////////////////////////////

        int count = 0;

        for     (int iii=0; iii<hhh; iii++)
        {   for (int jjj=0; jjj<www; jjj++)
            {
                double  currDepth = Img_DDD_RAWW_Curr.at<unsigned short>(iii,jjj); // / (float)1000;

                if (currDepth == 0)    {    PCL_Curr[camID].points[iii][jjj].x = std::numeric_limits<float>::quiet_NaN();
                                            PCL_Curr[camID].points[iii][jjj].y = std::numeric_limits<float>::quiet_NaN();
                                            PCL_Curr[camID].points[iii][jjj].z = std::numeric_limits<float>::quiet_NaN();
                                       }
                else                   {    PCL_Curr[camID].points[iii][jjj].x = (jjj - cx) * currDepth / fx;
                                            PCL_Curr[camID].points[iii][jjj].y = (iii - cy) * currDepth / fy;
                                            PCL_Curr[camID].points[iii][jjj].z =              currDepth;        count++;
                                       }
                                            PCL_Curr[camID].points[iii][jjj].rgb.R = Img_COL_RAWW_Curr.at<cv::Vec3b>(iii,jjj)[0];
                                            PCL_Curr[camID].points[iii][jjj].rgb.G = Img_COL_RAWW_Curr.at<cv::Vec3b>(iii,jjj)[1];
                                            PCL_Curr[camID].points[iii][jjj].rgb.B = Img_COL_RAWW_Curr.at<cv::Vec3b>(iii,jjj)[2];
                                            PCL_Curr[camID].points[iii][jjj].rgb.A = 0;
            }
        }

}
