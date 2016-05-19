#ifndef Sequence_H
#define Sequence_H


#include <cameraSet.h>
#include <animation.h>
#include <videoSequence.h>
#include "error_manager.h"


class Sequence
{
public:
    Sequence();

    Sequence(
                            //CAMERASET
                              QString INPUT_FINAL_PATH_Cameras_IN,

                            //MODEL
                              QString INPUT_dynamicStringPart_IN,
                              QVector<QString> INPUT_ModelNamesQVect_IN,
                              QString INPUT_EXTENSSS_Mesh_IN,
                              QString INPUT_EXTENSSS_Skeleton_IN,
                              QString INPUT_EXTENSSS_Skin_IN,
                              QString INPUT_EXTENSSS_Limits_IN,
                              QString INPUT_EXTENSSS_VOI_IN,

                            //ANIMATION
                              QString RadioSequenceID_String_IN,
                              QString INPUT_EXTENSSS_Motion_IN,
                              QString INPUT_FINAL_PATH_IndexCheat_IN,

                            //VIDEO_SEQUENCE
                              QString INPUT_FINAL_PATH_Video_IN,
                              QString INPUT_FINAL_PATH_IndexCheat_INN,
                            //SEQUENCE
                              QString INPUT_FINAL_PATH_IndexCheat_INNN,
                              QString RadioSequenceID_String_INN
            );


    CameraSet               cameraSet;
    QVector< Animation >    posedAnimations;
    VideoSequence           videoSequence;

    int  motionOffset;
    int  videoOffset;
    int  totalAllignedFrames;

    int     sequenceID;
    QString sequenceID_String;

    void updateFrameNumber();

    void appendNewPosedAnimation( Animation posedAnimation_IN );
    void removeAdditionalPosedAnimations();

    void transform_All_Model_MESHES();
    void transform_All_Model_SKELETONS();
    void calculate_All_Model_ROTATION_AXES();

    void loadCurrentVIDEOFrame();
    void loadCurrentVIDEOFrame_FOR_TRACKER();
    void loadCurrentVIDEOFrame_CUSTOM_FRAMENUMBER( int customFrameNumber );

    void sequenceID_Changed( int newID );

    int  currentFrameNumber;

};

#endif // Sequence_H
