#ifndef MODELSET_H
#define MODELSET_H


#include <model.h>
#include <error_manager.h>


class ModelSet
{
public:
    ModelSet();
    ModelSet(
                    QString INPUT_dynamicStringPart_IN,
                    QVector<QString> INPUT_ModelNamesQVect_IN,
                    QString INPUT_EXTENSSS_Mesh_IN,
                    QString INPUT_EXTENSSS_Skeleton_IN,
                    QString INPUT_EXTENSSS_Skin_IN,
                    QString INPUT_EXTENSSS_Limits_IN,
                    QString INPUT_EXTENSSS_VOI_IN
            );

    QVector< Model > models;

    int total_AxDOFs;
    int totalModels;

    bool has_OnlySkin;
    int  handNUMB;

    Eigen::Vector4d         centroid4D_curr;            // updated in ***Animation::transform_ModelSet_MESHES***
    void            compute_Centroid4D_curr();

    void  create_VerticesOfInterest( int voiTYPE );
    void compute_VerticesOfInterest_Centroids();

    /////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////
    int get_1st_Object_s_modelID();
    /////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////
};

#endif // MODELSET_H
