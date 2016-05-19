#include "animation.h"

Animation::Animation()
{
}



Animation::Animation(
                          //MODELSET
                           QString RadioSequenceID_String_In,
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
                    )
{

        //////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////

        modelSet = ModelSet(    RadioSequenceID_String_In,
                                INPUT_ModelNamesQVect_IN,
                                INPUT_EXTENSSS_Mesh_IN,
                                INPUT_EXTENSSS_Skeleton_IN,
                                INPUT_EXTENSSS_Skin_IN,
                                INPUT_EXTENSSS_Limits_IN,
                                INPUT_EXTENSSS_VOI_IN
                           );

        //////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////

        movingModels.resize( modelSet.totalModels );
        movingModels.squeeze();

        //////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////

        PathIngridient__RadioSequenceID_String = RadioSequenceID_String_IN;

        if (PathIngridient__RadioSequenceID_String.endsWith("/") == false )
            PathIngridient__RadioSequenceID_String    +=    "/";

        PathIngridient__INPUT_EXTENSSS_Motion =  INPUT_EXTENSSS_Motion_IN;

        refreshPATHs();

        //////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////

        readCheatIndexTXT( myFileString_IndexCheat_IN );

        //////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////

        poseMatrices_LoadFromFile( -888 );

        //////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////
        calculate_RotationAxes(0); // dummy, just to create DataStructure for LIMITS
        setLimitsForJoints_and_CreateDIRs();
        //////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////

}


void Animation::refreshPATHs()
{
        QDir basedir = QDir(QApplication::applicationDirPath());
        basedir.cdUp();
        QString basePath = basedir.path();
        for (int modelID=0; modelID<modelSet.totalModels; modelID++)
            movingModels[modelID].PATH_complete_Motion_INput  = basePath + "/Models/" + PathIngridient__RadioSequenceID_String + modelSet.models[modelID].name + PathIngridient__INPUT_EXTENSSS_Motion;
}



void Animation::readCheatIndexTXT( QString myFileString_IndexCheat_IN )
{

        QFile myFile ( myFileString_IndexCheat_IN );

        myFile.open(QIODevice::ReadOnly);

        if( !myFile.isOpen() )
        {
            ErrorManager::error(3, myFileString_IndexCheat_IN);
            return;
        }

        QTextStream myStream(&myFile);

        int         dummyValue;
        QString     dummyDescr;
        myStream >> dummyDescr;       myStream >> totalAllignedFrames;
        myStream >> dummyDescr;       myStream >> motionOffset;
        myStream >> dummyDescr;       myStream >> dummyValue;

        myFile.close();

}

