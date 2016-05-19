#include "mainwindow.h"
#include "ui_mainwindow.h"




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void MainWindow::refreshPathsALL_ForCurrentSequence()
{

        INPUT_dynamicStringPart = QString("myTracker/") + "RGBD" + "_"  + RadioSequenceID_String + "/";
        QDir basedir = QDir(QApplication::applicationDirPath());
        basedir.cdUp();
        QString basePath = basedir.path();
        INPUT_FINAL_PATH_Cameras         = basePath + "/Calibration/" + INPUT_Filename_Cameras;
        INPUT_FINAL_PATH_IndexCheat      = basePath + "/Configs/"     + RadioSequenceID_String + "/" + INPUT_Filename_IndexBounds;
        INPUT_FINAL_PATH_MODELS_INFO_TXT = basePath + "/Configs/"     + RadioSequenceID_String + "/" + INPUT_Filename_MODELS_INFO_TXT;
        INPUT_FINAL_PATH_Video           = "/lala/";

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void MainWindow::readInputs_AND_passToOpenGL()
{

        /////////////////////////////////////
        refreshPathsALL_ForCurrentSequence();
        ////////////////////////////////////////////////////////   Do not change order ;)
         read_MODELS_INFO_TXT(INPUT_FINAL_PATH_MODELS_INFO_TXT);
      //print_MODELS_INFO_TXT();
        ////////////////////////////////////////////////////////

        if (trackerCreatedOnce){
            trackerCreatedOnce = false;
            ui->myOpenGLWidget->trackerInitialized = false;
            delete myTracker;
        }

        myTracker = new Tracker(
                                    //CAMERASET
                                      INPUT_FINAL_PATH_Cameras,

                                    //MODEL
                                      RadioSequenceID_String,
                                      INPUT_ModelNamesQVect,
                                      INPUT_EXTENSSS_Mesh,
                                      INPUT_EXTENSSS_Skeleton,
                                      INPUT_EXTENSSS_Skin,
                                      INPUT_EXTENSSS_Limits,
                                      INPUT_EXTENSSS_VOI,

                                    //ANIMATION
                                      RadioSequenceID_String,
                                      INPUT_EXTENSSS_Motion,
                                      INPUT_FINAL_PATH_IndexCheat,

                                    //VIDEO_SEQUENCE
                                      INPUT_FINAL_PATH_Video ,
                                      INPUT_FINAL_PATH_IndexCheat,

                                    //SEQUENCE
                                      INPUT_FINAL_PATH_IndexCheat,
                                      RadioSequenceID_String,

                                    //FINGERTIPS
                                      INPUT_FINAL_PATH_Video,
                                      INPUT_FINAL_PATH_IndexCheat
                               );


        //////////////////////////
        readModelsRenderability();
        //////////////////////////
        trackerCreatedOnce = true;
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        update_ONLYLabels_OfSlider_SEQ_LIMITS_AND_CURR_FR( 0 );
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        _myColorizer();
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        changedTypesBackground();
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        _myColorizer();
        ui->myOpenGLWidget->passColors(_myColors);
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        changed_myTracker_Frames_INI_FIN( "readFiles" );
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        ui->myOpenGLWidget->passVitalDataToGLWidget( myTracker );
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////
        changedAlphaData();
        changedRenderCheckData();
        changedRadiosForSkeleton();
        ui->myOpenGLWidget->passColors(       _myColors     );
        ui->myOpenGLWidget->passColorIndexes( _myColorIndex );
        /////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void MainWindow::_myColorizer()
{
        _myColors.clear();
        _myColors.resize( 0);
        _myColors.append( QColor::fromRgb( 255, 0,   0   ) );  // 0 - red
        _myColors.append( QColor::fromRgb( 0,   255, 0   ) );  // 1 - green
      //_myColors.append( QColor::fromRgb( 0,   0,   255 ) );  //     blue

        _myColors.append( QColor::fromRgb( 0,   255, 255 ) );
        _myColors.append( QColor::fromRgb( 255, 0,   255 ) );  // 3 -
        _myColors.append( QColor::fromRgb( 255, 255, 0   ) );  // 4 -

        colorID = -1;
        _myColorIndex.clear();
        _myColorIndex.resize(15);
        _myColorIndex[0]  = 4;      ui->myButtonColor_Mesh1->setStyleSheet( _myColorPicker(true) );   //xrwmatakia!!!
      //_myColorIndex[1]  = 1;
      //_myColorIndex[2]  = 2;
        _myColorIndex[3]  = 3;      ui->myButtonColor_Left->setStyleSheet(  _myColorPicker(true) );
        _myColorIndex[4]  = 4;      ui->myButtonColor_Right->setStyleSheet( _myColorPicker(true) );
        _myColorIndex[5]  = 0;
        _myColorIndex[6]  = 1;      ui->myButtonColor__Hand->setStyleSheet( _myColorPicker(true) );
        _myColorIndex[7]  = 2;
        _myColorIndex[8]  = 3;      ui->myButtonColor__0->setStyleSheet(    _myColorPicker(true) );
        _myColorIndex[9]  = 4;      ui->myButtonColor__1->setStyleSheet(    _myColorPicker(true) );
        _myColorIndex[10] = 0;      ui->myButtonColor__2->setStyleSheet(    _myColorPicker(true) );
      //_myColorIndex[11] = 1;
      //_myColorIndex[12] = 2;
        _myColorIndex[13] = 3;      ui->myButtonColor_Mesh2->setStyleSheet( _myColorPicker(true) );
        _myColorIndex[14] = 3;      ui->myButtonColor_Mesh3->setStyleSheet( _myColorPicker(true) );

        myAlphaVaules.clear();
        myAlphaVaules.resize(6);
        myAlphaVaules[0] = ui->mySlider_transpMesh->value();
        myAlphaVaules[1] = ui->mySlider_transpSkeleton->value();
        myAlphaVaules[2] = ui->mySlider_transpLocalCoord->value();
        myAlphaVaules[3] = 1;
        myAlphaVaules[4] = 1.0;
        myAlphaVaules[5] = 1.0;
}


QString MainWindow::_myColorPicker(bool increaseColorIndex)
{
        if (increaseColorIndex==true)    colorID++;

        if (colorID == _myColors.size())
            colorID =  0;

        QString myStyleString = "background: rgba(%1, %2, %3);";

        myStyleString = myStyleString.arg(   _myColors[colorID].toRgb().red()).arg(_myColors[colorID].toRgb().green()).arg(_myColors[colorID].toRgb().blue()   );

        return myStyleString;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void MainWindow::changedRenderCheckData()
{

        checkersForRendering[0]  = (ui->myCheckBox_RenderMesh->isChecked()              == true) ? true : false;
        checkersForRendering[1]  = (ui->myCheckBox_RenderSkeleton->isChecked()          == true) ? true : false;
      //checkersForRendering[2]  =                                                                        false;
      //checkersForRendering[3]  =                                                                        false;
      //checkersForRendering[4]  =                                                                        false;
      //checkersForRendering[5]  =                                                                        false;
      //checkersForRendering[6]  =                                                                        false;
      //checkersForRendering[7]  =                                                                        false;
      //checkersForRendering[8]  =                                                                        false;
      //checkersForRendering[9]  =                                                                        false;
      //checkersForRendering[10] =                                                                        false;
      //checkersForRendering[11] =                                                                        false;
      //checkersForRendering[12] =                                                                        false;
      //checkersForRendering[13] =                                                                        false;
      //checkersForRendering[14] =                                                                        false;
        checkersForRendering[15] = (ui->myCheck_LocalCoord->isChecked()                 == true) ? true : false;
        checkersForRendering[16] = (ui->myCheck_FingertipVertices->isChecked()          == true) ? true : false;
      //checkersForRendering[17] =                                                                        false;
      //checkersForRendering[18] =                                                                        false;
        checkersForRendering[19] = (ui->myCheckBox_PCL->isChecked()                     == true) ? true : false;
      //checkersForRendering[20] =                                                                        false;
      //checkersForRendering[21] =                                                                        false;
        checkersForRendering[23] = (ui->myCheck_RenderLeftRight_BoneLCS->isChecked()    == true) ? true : false;
        checkersForRendering[24] = (ui->myCheck_FingertipDetections->isChecked()        == true) ? true : false;
      //checkersForRendering[25] =                                                                        false;
        checkersForRendering[26] = (ui->myCheckBox_MESH_FILL->isChecked()               == true) ? true : false;
        checkersForRendering[27] = (ui->myCheck_FingertipVertices_Centroid->isChecked() == true) ? true : false;
      //checkersForRendering[28] =                                                                        false;
      //checkersForRendering[29] =                                                                        false;
      //checkersForRendering[30] =                                                                        false;
      //checkersForRendering[31] =                                                                        false;
      //checkersForRendering[32] =                                                                        false;
      //checkersForRendering[33] =                                                                        false;
      //checkersForRendering[34] =                                                                        false;
      //checkersForRendering[35] =                                                                        false;
      //checkersForRendering[36] =                                                                        false;
      //checkersForRendering[37] =                                                                        false;
      //checkersForRendering[38] =                                                                        false;
      //checkersForRendering[39] =                                                                        false;
      //checkersForRendering[40] =                                                                        false;
      //checkersForRendering[41] =                                                                        false;
      //checkersForRendering[42] =                                                                        false;
      //checkersForRendering[43] =                                                                        false;
      //checkersForRendering[44] =                                                                        false;
      //checkersForRendering[45] =                                                                        false;
      //checkersForRendering[46] =                                                                        false;
      //checkersForRendering[47] =                                                                        false;
      //checkersForRendering[48] =                                                                        false;
      //checkersForRendering[49] =                                                                        false;
      //checkersForRendering[50] =                                                                        false;
      //checkersForRendering[51] =                                                                        false;
      //checkersForRendering[52] =                                                                        false;
      //checkersForRendering[53] =                                                                        false;
      //checkersForRendering[54] =                                                                        false;
      //checkersForRendering[55] =                                                                        false;
      //checkersForRendering[56] =                                                                        false;
      //checkersForRendering[57] =                                                                        false;
      //checkersForRendering[58] =                                                                        false;
      //checkersForRendering[59] =                                                                        false;
      //checkersForRendering[60] =                                                                        false;
      //checkersForRendering[61] =                                                                        false;
      //checkersForRendering[62] =                                                                        false;
      //checkersForRendering[63] =                                                                        false;
      //checkersForRendering[64] =                                                                        false;
      //checkersForRendering[65] =                                                                        false;
      //checkersForRendering[66] =                                                                        false;
      //checkersForRendering[67] =                                                                        false;
      //checkersForRendering[68] =                                                                        false;
      //checkersForRendering[69] =                                                                        false;

        ////////////////////////////////////////////////////////////////
        ui->myOpenGLWidget->passRenderCheckData( checkersForRendering );
        ////////////////////////////////////////////////////////////////

}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void MainWindow::changedAlphaData()
{
        myAlphaVaules[0] = qPow( (double)ui->mySlider_transpMesh->value()          /100, 3 );
        myAlphaVaules[1] = qPow( (double)ui->mySlider_transpSkeleton->value()      /100, 3 );
        myAlphaVaules[2] = qPow( (double)ui->mySlider_transpLocalCoord->value()    /100, 3 );
        myAlphaVaules[3] = 0.5;
        myAlphaVaules[4] = 1.0;
        myAlphaVaules[5] = 1.0;

        ui->myOpenGLWidget->passAlphaData( myAlphaVaules );
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////