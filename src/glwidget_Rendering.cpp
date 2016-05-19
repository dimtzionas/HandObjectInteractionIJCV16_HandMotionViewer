#include <glwidget.h>




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void GLWidget::myPickColor( int modelID, QString &boneName, QString alphaChooser )
{

    double alphaValue = 1;

    if      (alphaChooser == "usual")       alphaValue = _myAlphaValues[1];

    if      (boneName.contains("R")     && boneName.contains("Lower Arm")){    glPointSize(20);   glColor4d(   (float)myColor_Right.toRgb().red()/255,   (float)myColor_Right.toRgb().green()/255,  (float)myColor_Right.toRgb().blue()/255,  alphaValue   );     }   // Lower Arm R
    else if (boneName.contains("L")     && boneName.contains("Lower Arm")){    glPointSize(20);   glColor4d(   (float)myColor_Left.toRgb(). red()/255,   (float)myColor_Left.toRgb(). green()/255,  (float)myColor_Left.toRgb(). blue()/255,  alphaValue   );     }   // Lower Arm L
    else if (boneName.contains("_Aux1") || boneName.contains("_Wrist"))   {    glPointSize(5);    glColor4d(   (float)myColor_Aux1.toRgb(). red()/255,   (float)myColor_Aux1.toRgb(). green()/255,  (float)myColor_Aux1.toRgb(). blue()/255,  alphaValue   );     }   // Aux1
    else if (boneName.contains("_Hand"))                                  {    glPointSize(5);    glColor4d(   (float)myColor__Hand.toRgb().red()/255,   (float)myColor__Hand.toRgb().green()/255,  (float)myColor__Hand.toRgb().blue()/255,  alphaValue   );     }   // _Hand
    else if (boneName.contains("_Aux" ))                                  {    glPointSize(5);    glColor4d(   (float)myColor_Aux.toRgb().  red()/255,   (float)myColor_Aux.toRgb().  green()/255,  (float)myColor_Aux.toRgb().  blue()/255,  alphaValue   );     }   // Aux
    else if (boneName.contains("_0"))                                     {    glPointSize(5);    glColor4d(   (float)myColor__0.toRgb().   red()/255,   (float)myColor__0.toRgb().   green()/255,  (float)myColor__0.toRgb().   blue()/255,  alphaValue   );     }   // _0
    else if (boneName.contains("_1"))                                     {    glPointSize(5);    glColor4d(   (float)myColor__1.toRgb().   red()/255,   (float)myColor__1.toRgb().   green()/255,  (float)myColor__1.toRgb().   blue()/255,  alphaValue   );     }   // _1
    else if (boneName.contains("_2"))                                     {    glPointSize(5);    glColor4d(   (float)myColor__2.toRgb().   red()/255,   (float)myColor__2.toRgb().   green()/255,  (float)myColor__2.toRgb().   blue()/255,  alphaValue   );     }   // _2
    else                                                                  {    glPointSize(5);    glColor4d(   (float)0.5,                               (float)0.5,                                (float)0.5,                               1            );     }

}




void GLWidget::myPartColor( int modelID, QString &boneName, QString alphaChooser )
{

    double                                  alphaValue = 1;
    if      (alphaChooser == "usual")       alphaValue = _myAlphaValues[1];

    if      (boneName.contains("R")     && boneName.contains("Lower Arm")){    glPointSize(20);   glColor4d(   (float)myColor_Right.toRgb().red()/255,   (float)myColor_Right.toRgb().green()/255,  (float)myColor_Right.toRgb().blue()/255,  alphaValue   );     }   // Lower Arm R
    else if (boneName.contains("L")     && boneName.contains("Lower Arm")){    glPointSize(20);   glColor4d(   (float)myColor_Left. toRgb().red()/255,   (float)myColor_Left.toRgb(). green()/255,  (float)myColor_Left.toRgb(). blue()/255,  alphaValue   );     }   // Lower Arm L

    else if (boneName.contains("0_Hand")                                 ){    glPointSize(5);    glColor4d(   (float)myColor__Hand.toRgb().red()/255,   (float)myColor__Hand.toRgb().green()/255,  (float)myColor__Hand.toRgb().blue()/255,  alphaValue   );     }   // _Hand
    else if (boneName.contains("1_Hand")                                 ){    glPointSize(5);    glColor4d(   (float)myColor__0   .toRgb().red()/255,   (float)myColor__0   .toRgb().green()/255,  (float)myColor__0   .toRgb().blue()/255,  alphaValue   );     }   // _Hand
    else if (boneName.contains("2_Hand")                                 ){    glPointSize(5);    glColor4d(   (float)myColor__Hand.toRgb().red()/255,   (float)myColor__Hand.toRgb().green()/255,  (float)myColor__Hand.toRgb().blue()/255,  alphaValue   );     }   // _Hand
    else if (boneName.contains("3_Hand")                                 ){    glPointSize(5);    glColor4d(   (float)myColor__0   .toRgb().red()/255,   (float)myColor__0   .toRgb().green()/255,  (float)myColor__0   .toRgb().blue()/255,  alphaValue   );     }   // _Hand
    else if (boneName.contains("4_Hand")                                 ){    glPointSize(5);    glColor4d(   (float)myColor__Hand.toRgb().red()/255,   (float)myColor__Hand.toRgb().green()/255,  (float)myColor__Hand.toRgb().blue()/255,  alphaValue   );     }   // _Hand

    else if (boneName.contains("0_0")                                    ){    glPointSize(5);    glColor4d(   (float)myColor__1.toRgb().   red()/255,   (float)myColor__1.toRgb().   green()/255,  (float)myColor__1.toRgb().   blue()/255,  alphaValue   );     }   // _0
    else if (boneName.contains("1_0")                                    ){    glPointSize(5);    glColor4d(   (float)myColor__2.toRgb().   red()/255,   (float)myColor__2.toRgb().   green()/255,  (float)myColor__2.toRgb().   blue()/255,  alphaValue   );     }   // _0
    else if (boneName.contains("2_0")                                    ){    glPointSize(5);    glColor4d(   (float)myColor__1.toRgb().   red()/255,   (float)myColor__1.toRgb().   green()/255,  (float)myColor__1.toRgb().   blue()/255,  alphaValue   );     }   // _0
    else if (boneName.contains("3_0")                                    ){    glPointSize(5);    glColor4d(   (float)myColor__2.toRgb().   red()/255,   (float)myColor__2.toRgb().   green()/255,  (float)myColor__2.toRgb().   blue()/255,  alphaValue   );     }   // _0
    else if (boneName.contains("4_0")                                    ){    glPointSize(5);    glColor4d(   (float)myColor__1.toRgb().   red()/255,   (float)myColor__1.toRgb().   green()/255,  (float)myColor__1.toRgb().   blue()/255,  alphaValue   );     }   // _0

    else if (boneName.contains("0_1")                                    ){    glPointSize(5);    glColor4d(   (float)myColor__Hand.toRgb().red()/255,   (float)myColor__Hand.toRgb().green()/255,  (float)myColor__Hand.toRgb().blue()/255,  alphaValue   );     }   // _1
    else if (boneName.contains("1_1")                                    ){    glPointSize(5);    glColor4d(   (float)myColor__0   .toRgb().red()/255,   (float)myColor__0   .toRgb().green()/255,  (float)myColor__0   .toRgb().blue()/255,  alphaValue   );     }   // _1
    else if (boneName.contains("2_1")                                    ){    glPointSize(5);    glColor4d(   (float)myColor__Hand.toRgb().red()/255,   (float)myColor__Hand.toRgb().green()/255,  (float)myColor__Hand.toRgb().blue()/255,  alphaValue   );     }   // _1
    else if (boneName.contains("3_1")                                    ){    glPointSize(5);    glColor4d(   (float)myColor__0   .toRgb().red()/255,   (float)myColor__0   .toRgb().green()/255,  (float)myColor__0   .toRgb().blue()/255,  alphaValue   );     }   // _1
    else if (boneName.contains("4_1")                                    ){    glPointSize(5);    glColor4d(   (float)myColor__Hand.toRgb().red()/255,   (float)myColor__Hand.toRgb().green()/255,  (float)myColor__Hand.toRgb().blue()/255,  alphaValue   );     }   // _1

    else if (boneName.contains("0_2")                                    ){    glPointSize(5);    glColor4d(   (float)myColor_Right.toRgb().red()/255,   (float)myColor_Right.toRgb().green()/255,  (float)myColor_Right.toRgb().blue()/255,  alphaValue   );     }   // _2
    else if (boneName.contains("1_2")                                    ){    glPointSize(5);    glColor4d(   (float)myColor_Left .toRgb().red()/255,   (float)myColor_Left .toRgb().green()/255,  (float)myColor_Left .toRgb().blue()/255,  alphaValue   );     }   // _2
    else if (boneName.contains("2_2")                                    ){    glPointSize(5);    glColor4d(   (float)myColor_Right.toRgb().red()/255,   (float)myColor_Right.toRgb().green()/255,  (float)myColor_Right.toRgb().blue()/255,  alphaValue   );     }   // _2
    else if (boneName.contains("3_2")                                    ){    glPointSize(5);    glColor4d(   (float)myColor_Left .toRgb().red()/255,   (float)myColor_Left .toRgb().green()/255,  (float)myColor_Left .toRgb().blue()/255,  alphaValue   );     }   // _2

    else if (boneName.startsWith("Bone") && boneName.endsWith("0")       ){    glPointSize(5);    glColor4d(   (float)myColor_Right.toRgb().red()/255,   (float)myColor_Right.toRgb().green()/255,  (float)myColor_Right.toRgb().blue()/255,  alphaValue   );     }   // _2
    else if (boneName.startsWith("Bone") && boneName.endsWith("1")       ){    glPointSize(5);    glColor4d(   (float)myColor_Left .toRgb().red()/255,   (float)myColor_Left .toRgb().green()/255,  (float)myColor_Left .toRgb().blue()/255,  alphaValue   );     }   // _2
    else if (boneName.startsWith("Bone") && boneName.endsWith("2")       ){    glPointSize(5);    glColor4d(   (float)myColor__Hand.toRgb().red()/255,   (float)myColor__Hand.toRgb().green()/255,  (float)myColor__Hand.toRgb().blue()/255,  alphaValue   );     }   // _2
    else if (boneName.startsWith("Bone") && boneName.endsWith("3")       ){    glPointSize(5);    glColor4d(   (float)myColor__0   .toRgb().red()/255,   (float)myColor__0   .toRgb().green()/255,  (float)myColor__0   .toRgb().blue()/255,  alphaValue   );     }   // _2
    else if (boneName.startsWith("Bone") && boneName.endsWith("4")       ){    glPointSize(5);    glColor4d(   (float)myColor__1   .toRgb().red()/255,   (float)myColor__1   .toRgb().green()/255,  (float)myColor__1   .toRgb().blue()/255,  alphaValue   );     }   // _2
    else if (boneName.startsWith("Bone") && boneName.endsWith("5")       ){    glPointSize(5);    glColor4d(   (float)myColor__2   .toRgb().red()/255,   (float)myColor__2   .toRgb().green()/255,  (float)myColor__2   .toRgb().blue()/255,  alphaValue   );     }   // _2
    else if (boneName.startsWith("Bone") && boneName.endsWith("6")       ){    glPointSize(5);    glColor4d(   (float)myColor__Hand.toRgb().red()/255,   (float)myColor__Hand.toRgb().green()/255,  (float)myColor__Hand.toRgb().blue()/255,  alphaValue   );     }   // _2
    else if (boneName.startsWith("Bone") && boneName.endsWith("7")       ){    glPointSize(5);    glColor4d(   (float)myColor__0   .toRgb().red()/255,   (float)myColor__0   .toRgb().green()/255,  (float)myColor__0   .toRgb().blue()/255,  alphaValue   );     }   // _2
    else if (boneName.startsWith("Bone") && boneName.endsWith("8")       ){    glPointSize(5);    glColor4d(   (float)myColor__1   .toRgb().red()/255,   (float)myColor__1   .toRgb().green()/255,  (float)myColor__1   .toRgb().blue()/255,  alphaValue   );     }   // _2
    else if (boneName.startsWith("Bone") && boneName.endsWith("9")       ){    glPointSize(5);    glColor4d(   (float)myColor__2   .toRgb().red()/255,   (float)myColor__2   .toRgb().green()/255,  (float)myColor__2   .toRgb().blue()/255,  alphaValue   );     }   // _2

    else                                                                  {    glPointSize(5);    glColor4d(   (float)0.5,                               (float)0.5,                                (float)0.5,                               1            );     }

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void GLWidget::myRenderMesh()
{

        for (int animNumb=0; animNumb<tracker->sequence.posedAnimations.size(); animNumb++)
        {

                    for (int modelID=0; modelID<tracker->sequence.posedAnimations[animNumb].modelSet.totalModels; modelID++)
                    {

                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                if (tracker->sequence.posedAnimations[animNumb].modelSet.models[modelID].isRenderable == false)    continue;
                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                if      (animNumb==0  &&  _myRender_Mesh    ==false)       continue;

                                //////////////////////////////////////////////////////////////////////////////////////////////////
                                Model      *pModel = &(tracker->sequence.posedAnimations[animNumb].modelSet.models[modelID]);
                                MeshStruct *pMesh  = &(tracker->sequence.posedAnimations[animNumb].modelSet.models[modelID].mesh);
                                //////////////////////////////////////////////////////////////////////////////////////////////////

                                /////////////////////////////////////////////
                                /////////////////////////////////////////////
                                myRender_HANDLE_LIGHTS_and_FilledNonFilled();
                                /////////////////////////////////////////////
                                /////////////////////////////////////////////

                                glBegin(GL_TRIANGLES);

                                                                    for (int tr=0; tr<tracker->sequence.posedAnimations[animNumb].modelSet.models[modelID].totalTriangles; tr++)
                                                                    {

                                                                            if      (animNumb==0)   {   if (modelID == 0)   glColor4d(   (float)myColor_Mesh1.   toRgb().red()/255,   (float)myColor_Mesh1.   toRgb().green()/255,   (float)myColor_Mesh1.   toRgb().blue()/255,   _myAlphaValues[0]   );
                                                                                                        if (modelID == 1)   glColor4d(   (float)myColor_Mesh2.   toRgb().red()/255,   (float)myColor_Mesh2.   toRgb().green()/255,   (float)myColor_Mesh2.   toRgb().blue()/255,   _myAlphaValues[0]   );
                                                                                                        if (modelID == 2)   glColor4d(   (float)myColor_Mesh3.   toRgb().red()/255,   (float)myColor_Mesh3.   toRgb().green()/255,   (float)myColor_Mesh3.   toRgb().blue()/255,   _myAlphaValues[0]   );   }
                                                                            else if (animNumb==1)                           glColor4d(   (float)myColor_MeshComp.toRgb().red()/255,   (float)myColor_MeshComp.toRgb().green()/255,   (float)myColor_MeshComp.toRgb().blue()/255,   _myAlphaValues[4]   );

                                                                            int index1 = pMesh->triangles[tr].vertexID_1;
                                                                            int index2 = pMesh->triangles[tr].vertexID_2;
                                                                            int index3 = pMesh->triangles[tr].vertexID_3;

                                                                            glNormal3d( pMesh->normals_Vertices[index1](0),pMesh->normals_Vertices[index1](1),pMesh->normals_Vertices[index1](2));
                                                                            glVertex3d( pMesh->verticesWeighted[index1](0),pMesh->verticesWeighted[index1](1),pMesh->verticesWeighted[index1](2));

                                                                            glNormal3d( pMesh->normals_Vertices[index2](0),pMesh->normals_Vertices[index2](1),pMesh->normals_Vertices[index2](2));
                                                                            glVertex3d( pMesh->verticesWeighted[index2](0),pMesh->verticesWeighted[index2](1),pMesh->verticesWeighted[index2](2));

                                                                            glNormal3d( pMesh->normals_Vertices[index3](0),pMesh->normals_Vertices[index3](1),pMesh->normals_Vertices[index3](2));
                                                                            glVertex3d( pMesh->verticesWeighted[index3](0),pMesh->verticesWeighted[index3](1),pMesh->verticesWeighted[index3](2));

                                                                    }

                                glEnd();


                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                                if (_myRender_FingerTipVertices)
                                {
                                        for     (int fingID=0; fingID<pModel->VerticesOfInterest_Viz_Indices.size();            fingID++)     //int IDD = 7400;
                                        {   for (int  vrtID=pModel->VerticesOfInterest_Viz_Indices[fingID].size()-1;  vrtID>=0;  vrtID--)  // draw order stuff ;)
                                            {
                                                glPointSize(2);
                                                glColor4d(0,1,0,1);

                                                glBegin(GL_POINTS);
                                                glVertex3d( pModel->mesh.verticesWeighted[ pModel->VerticesOfInterest_Viz_Indices[fingID][vrtID] ](0),
                                                            pModel->mesh.verticesWeighted[ pModel->VerticesOfInterest_Viz_Indices[fingID][vrtID] ](1),
                                                            pModel->mesh.verticesWeighted[ pModel->VerticesOfInterest_Viz_Indices[fingID][vrtID] ](2) );
                                                glEnd();
                                            }
                                        }


                                    if (_myRender_FingerTipVert_CENTROID)
                                    {
                                        for     (int fingID=0; fingID<pModel->VerticesOfInterest_Centroid.size();         fingID++)    //int IDD = 7400;
                                        {   for (int  vrtID=0;  vrtID<pModel->VerticesOfInterest_Centroid[fingID].size();  vrtID++)
                                            {
                                                                      glPointSize(3);   glColor4d(1,1,0,1);

                                                glBegin(GL_POINTS);
                                                glVertex3d( pModel->VerticesOfInterest_Centroid[fingID](0),
                                                            pModel->VerticesOfInterest_Centroid[fingID](1),
                                                            pModel->VerticesOfInterest_Centroid[fingID](2) );
                                                glEnd();
                                            }
                                        }
                                    }

                                }

                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                    } // for (int modelID=0; modelID<tracker->sequence.posedAnimations[animNumb].modelSet.totalModels; modelID++)

        } // for (int animNumb=0; animNumb<tracker->sequence.posedAnimations.size(); animNumb++)

}



void GLWidget::myRender_PCL_Points()
{

    int camID = tracker->sequence.cameraSet.currentCameraID;

    glPointSize(1);
    glBegin(GL_POINTS);

    for     (int iii=0; iii<tracker->FEAT_Skinnnnn.PCL_Curr[camID].points.size();      iii++)
    {   for (int jjj=0; jjj<tracker->FEAT_Skinnnnn.PCL_Curr[camID].points[iii].size(); jjj++)
        {
            glColor4f( tracker->FEAT_Skinnnnn.PCL_Curr[camID].points[iii][jjj].rgb.B / 255.0,
                       tracker->FEAT_Skinnnnn.PCL_Curr[camID].points[iii][jjj].rgb.G / 255.0,
                       tracker->FEAT_Skinnnnn.PCL_Curr[camID].points[iii][jjj].rgb.R / 255.0, _myAlphaValues[1] );

            glVertex3d(  (float)tracker->FEAT_Skinnnnn.PCL_Curr[camID].points[iii][jjj].x,
                         (float)tracker->FEAT_Skinnnnn.PCL_Curr[camID].points[iii][jjj].y,
                         (float)tracker->FEAT_Skinnnnn.PCL_Curr[camID].points[iii][jjj].z  );
        }
    }
    glEnd();
    glPointSize(1);

}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





void GLWidget::myRenderSkeleton()
{


            /////////////////////////////////////////////
            /////////////////////////////////////////////
            myRender_HANDLE_LIGHTS_and_FilledNonFilled();
            /////////////////////////////////////////////
            /////////////////////////////////////////////


            for (int animNumb=0; animNumb<tracker->sequence.posedAnimations.size(); animNumb++)
            {



                    for (int modelID=0; modelID<tracker->sequence.posedAnimations[animNumb].modelSet.totalModels; modelID++)
                    {

                            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                            if (tracker->sequence.posedAnimations[animNumb].modelSet.models[modelID].isRenderable == false)    continue;
                            ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                            ////////////////////////////////////////////////////////////////////////////////////////////////////////////

                            if      (animNumb==0  &&  _myRender_Skeleton    ==false)       continue;

                            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                            Model                       *pModel            = &(tracker->sequence.posedAnimations[animNumb].modelSet.models[modelID]);
                            SkinningBonesSkeletonStruct *pSkinningSkeleton = &(tracker->sequence.posedAnimations[animNumb].modelSet.models[modelID].skinningSkeleton);
                            RotationAxesStruct          *pArticulationSkel = &(tracker->sequence.posedAnimations[animNumb].modelSet.models[modelID].articulationSkel);
                            //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                            for (int skkk=0; skkk<pModel->totalSkinningBones; skkk++)
                            {

                                        /////////////////////////////////////////////////////////////////////////////////////////////////
                                        /////////////////////////////////////////////////////////////////////////////////////////////////
                                        if (pModel->skinningSkeleton.skinningBones.size() == 1)                                 continue;
                                        /////////////////////////////////////////////////////////////////////////////////////////////////
                                        if (skkk == 0  &&  _myRender_LeftRight_BoneLCS == false  &&  pModel->has_OnlySkin)      continue;
                                        /////////////////////////////////////////////////////////////////////////////////////////////////
                                        /////////////////////////////////////////////////////////////////////////////////////////////////

                                        Eigen::Vector3d _startBoneVec3;
                                        Eigen::Vector3d _endddBoneVec3;
                                        Eigen::Vector3d _startLOC;
                                        Eigen::Vector3d _endddLOC;

                                        //////////////////////////////////////////////////////////////////////////////////////////////
                                        //////////////////////////////////////////////////////////////////////////////////////////////
                                        //////////////////////////////////////////////////////////////////////////////////////////////
                                        QString colorChooserCaller;

                                        if      (animNumb == 0)     colorChooserCaller = "usual";

                                        myPickColor( modelID, pSkinningSkeleton->skinningBones[skkk].name, colorChooserCaller);
                                        //////////////////////////////////////////////////////////////////////////////////////////////
                                        //////////////////////////////////////////////////////////////////////////////////////////////
                                        //////////////////////////////////////////////////////////////////////////////////////////////


                                        _startBoneVec3 << pSkinningSkeleton->skinningBones[skkk].bone_Start_4x1(0),
                                                          pSkinningSkeleton->skinningBones[skkk].bone_Start_4x1(1),
                                                          pSkinningSkeleton->skinningBones[skkk].bone_Start_4x1(2);
                                        _endddBoneVec3 << pSkinningSkeleton->skinningBones[skkk].bone_Leaff_4x1(0),
                                                          pSkinningSkeleton->skinningBones[skkk].bone_Leaff_4x1(1),
                                                          pSkinningSkeleton->skinningBones[skkk].bone_Leaff_4x1(2);



                                        if (   (_mySkeletonType == "Points")   ||   (_mySkeletonType == "Both_Points_Lines")   )             {          glPointSize(5);                             glBegin(GL_POINTS);         glVertex3d( _startBoneVec3(0),_startBoneVec3(1),_startBoneVec3(2) );
                                                                                                                                                                                                    glEnd();
                                                                                                                                             }
                                        if (   (_mySkeletonType == "Lines")    ||   (_mySkeletonType == "Both_Points_Lines")   )             {          glLineWidth(1);                             glBegin(GL_LINES);                      glVertex3d( _startBoneVec3(0),_startBoneVec3(1),_startBoneVec3(2) );
                                                                                                                                                                                                                                            glVertex3d( _endddBoneVec3(0),_endddBoneVec3(1),_endddBoneVec3(2) );

                                                                                                                                                                                                    glEnd();
                                                                                                                                             }
                                                                                                                                                        glPointSize(1);
                                                                                                                                                        glLineWidth(1);

                                        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                        if (_myRender_LocalCoord == true)
                                        {

                                                    glLineWidth(1);

                                                    glBegin(GL_LINES);

                                                                            for (int axx=0; axx<pArticulationSkel->rotationAxes[skkk].axe.size(); axx++)
                                                                            {
                                                                                    _startLOC = pArticulationSkel->rotationAxes[skkk].location;
                                                                                    _endddLOC = pArticulationSkel->rotationAxes[skkk].axe[axx].dir_draw;

                                                                                    QString axeType = pArticulationSkel->rotationAxes[skkk].axe[axx].type;

                                                                                    if      (axeType == "X")      glColor4d(1,0,0,_myAlphaValues[2]);
                                                                                    else if (axeType == "Y")      glColor4d(0,1,0,_myAlphaValues[2]);
                                                                                    else if (axeType == "Z")      glColor4d(1,1,0,_myAlphaValues[2]);

                                                                                    glVertex3d(   _startLOC(0),   _startLOC(1),   _startLOC(2)   );
                                                                                    glVertex3d(   _endddLOC(0),   _endddLOC(1),   _endddLOC(2)   );
                                                                            }

                                                    glEnd();


                                                    glLineWidth(1);
                                        }

                                        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                            } // for (int skkk=0; skkk<pModel->totalSkinningBones; skkk++)

                    } // for (int modelID=0; modelID<modelSet.totalModels; modelID++)

            } // for (int animNumb=0; animNumb<tracker->sequence.posedAnimations.size(); animNumb++)

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void GLWidget::myRender_fingerTip_Detections()   // MI VALEIS KATHOLOU OPENGL !!!!!!  ->  MONO QPAINTER !!!!!!!!!!!!!!    gamietai o dias
{

        ////////////////////////////////////////////////////////
        int camID = tracker->sequence.cameraSet.currentCameraID;
        ////////////////////////////////////////////////////////
        int www = tracker->sequence.videoSequence.frameWidth;
        int hhh = tracker->sequence.videoSequence.frameHeight;
        ////////////////////////////////////////////////////////

        painter.begin(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(Qt::NoBrush);
        painter.setPen(QPen(Qt::yellow, 0, Qt::SolidLine, Qt::RoundCap, Qt::BevelJoin));


                for (int ddd=0; ddd<tracker->FEAT_Skinnnnn.fingerTips.detectionsBag[camID].size(); ddd++)     painter.drawRect(   QRect( MyMath::myRounding( tracker->FEAT_Skinnnnn.fingerTips.detectionsBag[camID][ddd].topLeft_X,www),
                                                                                                                                         MyMath::myRounding( tracker->FEAT_Skinnnnn.fingerTips.detectionsBag[camID][ddd].topLeft_Y,hhh),
                                                                                                                                                             tracker->FEAT_Skinnnnn.fingerTips.detectionsBag[camID][ddd].width,
                                                                                                                                                             tracker->FEAT_Skinnnnn.fingerTips.detectionsBag[camID][ddd].height )   );

        painter.end();

        /////////////////
        myOpenGL_Flags();
        /////////////////

}


