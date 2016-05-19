#include "animation.h"





void Animation::setLimitsForJoints_and_CreateDIRs()
{


        Eigen::Vector3d    tmpAxe;
        Custom_1DoF_Axis   curr_1D_Axe;


        //////////////////////////
        //////////////////////////
        modelSet.total_AxDOFs = 0;
        //////////////////////////
        //////////////////////////


        for (int modelID=0; modelID<modelSet.totalModels; modelID++)
        {

            //////////////////////////////////////////
            modelSet.models[modelID].total_AxDOFs = 0;
            //////////////////////////////////////////


                    for (int skkk=0; skkk<modelSet.models[modelID].articulationSkel.rotationAxes.size(); skkk++)
                    {

                                /////////////////////////////////////////////////////////////////////////////////////////////////////
                                Custom_3DoF_Axis *currRotationAxes = &(modelSet.models[modelID].articulationSkel.rotationAxes[skkk]);
                                /////////////////////////////////////////////////////////////////////////////////////////////////////

                                //////////////////////////////
                                currRotationAxes->axe.clear();
                                //////////////////////////////


                                        for (int ttt=0; ttt<modelSet.models[modelID].tmp_Limits.size(); ttt++)
                                        {

                                                        if ( currRotationAxes->name_joint_OR_bone == modelSet.models[modelID].tmp_Limits[ttt].NameBone )
                                                        {

                                                                            ///////////////////////////////////////////////////////////////////////////////////////
                                                                            ///////////////////////////////////////////////////////////////////////////////////////  RBM !!!
                                                                            if ( modelSet.models[modelID].tmp_Limits[ttt].Limits_FLAG_Translate == 1 &&
                                                                                 modelSet.models[modelID].tmp_Limits[ttt].Limits_FLAG_Rotate[0] == 1 &&
                                                                                 modelSet.models[modelID].tmp_Limits[ttt].Limits_FLAG_Rotate[1] == 1 &&
                                                                                 modelSet.models[modelID].tmp_Limits[ttt].Limits_FLAG_Rotate[2] == 1  )   continue;
                                                                            ///////////////////////////////////////////////////////////////////////////////////////
                                                                            ///////////////////////////////////////////////////////////////////////////////////////


                                                                            for (int axx=0; axx<3; axx++)
                                                                            {

                                                                                    if ( modelSet.models[modelID].tmp_Limits[ttt].Limits_FLAG_Rotate[axx] != 0 )   // OXI apeftheias ta oria !!!
                                                                                    {

                                                                                            if ( modelSet.models[modelID].tmp_Limits[ttt].LimitsDgr[axx].min != 0.0   ||   modelSet.models[modelID].tmp_Limits[ttt].LimitsDgr[axx].max != 0.0 )
                                                                                            {

                                                                                                            ///////////////////////////////////////////////////////////////////////////////////
                                                                                                            ///////////////////////////////////////////////////////////////////////////////////
                                                                                                                                            modelSet.total_AxDOFs++;
                                                                                                                                            modelSet.models[modelID].total_AxDOFs++;
                                                                                                            curr_1D_Axe.DOF_interModel_ID = modelSet.models[modelID].total_AxDOFs - 1; // logw ++number
                                                                                                            ///////////////////////////////////////////////////////////////////////////////////
                                                                                                            ///////////////////////////////////////////////////////////////////////////////////
                                                                                                            curr_1D_Axe.ID_se_SkinningBones = skkk;
                                                                                                            ///////////////////////////////////////////////////////////////////////////////////
                                                                                                            ///////////////////////////////////////////////////////////////////////////////////
                                                                                                            curr_1D_Axe.limitsDgr.min = modelSet.models[modelID].tmp_Limits[ttt].LimitsDgr[axx].min;
                                                                                                            curr_1D_Axe.limitsDgr.max = modelSet.models[modelID].tmp_Limits[ttt].LimitsDgr[axx].max;
                                                                                                            curr_1D_Axe.limitsRad.min = modelSet.models[modelID].tmp_Limits[ttt].LimitsDgr[axx].min * M_PI / 180;
                                                                                                            curr_1D_Axe.limitsRad.max = modelSet.models[modelID].tmp_Limits[ttt].LimitsDgr[axx].max * M_PI / 180;
                                                                                                            ///////////////////////////////////////////////////////////////////////////////////
                                                                                                            ///////////////////////////////////////////////////////////////////////////////////
                                                                                                            if      (axx == 0)      {      curr_1D_Axe.type = "X";      tmpAxe = modelSet.models[modelID].tmp_Limits[ttt].DofAxes.rotX;     }
                                                                                                            else if (axx == 1)      {      curr_1D_Axe.type = "Y";      tmpAxe = modelSet.models[modelID].tmp_Limits[ttt].DofAxes.rotY;     }
                                                                                                            else  /*(axx == 3)*/    {      curr_1D_Axe.type = "Z";      tmpAxe = modelSet.models[modelID].tmp_Limits[ttt].DofAxes.rotZ;     }

                                                                                                            curr_1D_Axe.dir      = tmpAxe;
                                                                                                            curr_1D_Axe.dir_iniV = tmpAxe;
                                                                                                            curr_1D_Axe.dir_draw = tmpAxe;
                                                                                                            ///////////////////////////////////////////////////////////////////////////////////
                                                                                                            ///////////////////////////////////////////////////////////////////////////////////
                                                                                                            currRotationAxes->axe.append( curr_1D_Axe );
                                                                                                            ///////////////////////////////////////////////////////////////////////////////////
                                                                                                            ///////////////////////////////////////////////////////////////////////////////////

                                                                                            }
                                                                                    }

                                                                            } // for (int axx=0; axx<3; axx++)

                                                        } // if name is the same

                                        } // for (int ttt=0; ttt<modelSet.models[modelID].tmp_Limits.size(); ttt++)

                    } // for (int skkk=0; skkk<modelSet.models[modelID].articulationSkel.rotationAxes.size(); skkk++)

        } // for (int modelID=0; modelID<modelSet.totalModels; modelID++)

}



