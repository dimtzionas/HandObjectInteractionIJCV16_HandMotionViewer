#ifndef SEQUENCE_H
#define SEQUENCE_H


#include <modelSET.h>


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

struct PosedBone
{
    QString name;

    Eigen::MatrixXd R;
    Eigen::MatrixXd T;
    Eigen::MatrixXd RT_3x4;
    Eigen::MatrixXd RT_4x4;
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

struct PosedSkeleton
{
    QVector<PosedBone> bones;
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

struct movingModel
{
    QVector<PosedSkeleton> motionFrames;

    QString PATH_complete_Motion_INput;
};

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////



class Animation
{

public:
    Animation();

    Animation(
                  //MODEL
                   QString INPUT_dynamicStringPart_IN,
                   QVector<QString> INPUT_ModelNamesQVect_IN,
                   QString INPUT_EXTENSSS_Mesh_IN,
                   QString INPUT_EXTENSSS_Skeleton_IN,
                   QString INPUT_EXTENSSS_Skin_IN,
                   QString INPUT_EXTENSSS_Limits_IN,
                   QString INPUT_EXTENSSS_VOI_IN,

                 //ANIM
                   QString RadioSequenceID_String_IN,
                   QString INPUT_EXTENSSS_Motion_IN,
                   QString myFileString_IndexCheat_IN
             );

    //////////////////////////////////////////////////////////////////////////////////////

    ModelSet modelSet;

    int motionOffset;
    int totalAllignedFrames;

    /////////////////////////////////////
    QVector< movingModel >  movingModels;
    /////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////////////////

    void transform_ModelSet_MESHES(    int frameNumber_XwrisOffset );
    void transform_ModelSet_SKELETONS( int frameNumber_XwrisOffset );

    void calculate_Bones_using_RT( int modelID, int frameNumber_MeOffset, int currrAdd );

    void calculate_RotationAxes(   int frameNumber_XwrisOffset );

    void readCheatIndexTXT( QString myFileString_IndexCheat_IN );

    //////////////////////////////////////////////////////////////////////////////////////
    void poseMatrices_Clear();
    void poseMatrices_LoadFromFile( int frameNumberForReadOutput );
    //////////////////////////////////////////////////////////////////////////////////////
    void setLimitsForJoints_and_CreateDIRs();
    //////////////////////////////////////////////////////////////////////////////////////
    void construct__RT_3x4__RT_4x4__basedOn__R_T__1bone( int modelID, int fr, int b );
    void construct__RT_3x4__RT_4x4__basedOn__R_T(        int modelID, int fr        );
    void construct__RT_3x4__R_T__basedOn__RT_4x4__1bone( int modelID, int fr, int b );
    void construct__RT_3x4__R_T__basedOn__RT_4x4(        int modelID, int fr        );
    //////////////////////////////////////////////////////////////////////////////////////

    void refreshPATHs();

    QString PathIngridient__RadioSequenceID_String;
private:
    QString PathIngridient__INPUT_EXTENSSS_Motion;

    void readFromTXT( QString shouldPrint );

};





#endif // SEQUENCE_H





