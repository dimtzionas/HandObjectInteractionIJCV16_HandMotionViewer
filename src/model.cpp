#include "model.h"

Model::Model()
{
}

Model::Model(   QString RadioSequenceID_String,
                QString INPUT_fileNameOhneExtension,
                QString INPUT_EXTENSSS_Mesh,
                QString INPUT_EXTENSSS_Skeleton,
                QString INPUT_EXTENSSS_Skin,
                QString INPUT_EXTENSSS_Limits,
                QString INPUT_EXTENSSS_VOI   )
{
        QDir basedir = QDir(QApplication::applicationDirPath());
        basedir.cdUp();
        QString basePath = basedir.path();
        QString fileString_Mesh     = basePath + "/Models/" + RadioSequenceID_String + "/" + INPUT_fileNameOhneExtension + INPUT_EXTENSSS_Mesh;
        QString fileString_Skeleton = basePath + "/Models/" + RadioSequenceID_String + "/" + INPUT_fileNameOhneExtension + INPUT_EXTENSSS_Skeleton;
        QString fileString_Skin     = basePath + "/Models/" + RadioSequenceID_String + "/" + INPUT_fileNameOhneExtension + INPUT_EXTENSSS_Skin;
        QString fileString_Limits   = basePath + "/Models/" + RadioSequenceID_String + "/" + INPUT_fileNameOhneExtension + INPUT_EXTENSSS_Limits;
                fileString_VOI      = basePath + "/Models/" + RadioSequenceID_String + "/" + INPUT_fileNameOhneExtension + INPUT_EXTENSSS_VOI;
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        name = INPUT_fileNameOhneExtension;
        ////////////////////////////////////////////////////
        if (name.contains("Hand"))     has_OnlySkin = true;
        else                           has_OnlySkin = false;
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        isRenderable = true;
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        totalBones          = 0;
        totalSkeletonFrames = 0;
        totalSkinningBones  = 0;
        totalTriangles      = 0;
        totalVertices       = 0;
        total_AxDOFs        = 0;
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        readSkeleton( fileString_Skeleton );                        //print_SkeletonBones();

        readMesh_OFF( fileString_Mesh     );                        //print_Mesh_Vertices();
                                                                    //print_Mesh_Triangles();

        readSkin_TXT( fileString_Skin     );                        //print_SkinningWeights();
                                                                    //print_SkinningBones();

        readLimits(   fileString_Limits   );                        //print_Limits();

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        create_Lookup_SkinningBone_to_Bones_ID();                   //print_SkinningBoneNames();
                                                                    //test_lookup_SkinningBone_to_Bones_ID();

        create_thresholded_SkinningWeights();                       //print_thresholded_SkinningWeights();
                                                                    //test_SkinningWeihgts_sum_to_1();

        create_Vertices_DominantSkinningBone();                     //print_Vertices_DominantSkinningBone();

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

}



void Model::compute_Centroid4D_curr()
{

    double sXXX = 0;
    double sYYY = 0;
    double sZZZ = 0;

    for (int vvv=0; vvv<totalVertices; vvv++)
    {
        sXXX += mesh.verticesWeighted[vvv](0);
        sYYY += mesh.verticesWeighted[vvv](1);
        sZZZ += mesh.verticesWeighted[vvv](2);
    }

    this->centroid4D_curr(0) = sXXX / (float)totalVertices;
    this->centroid4D_curr(1) = sYYY / (float)totalVertices;
    this->centroid4D_curr(2) = sZZZ / (float)totalVertices;
    this->centroid4D_curr(3) = 1;

}



