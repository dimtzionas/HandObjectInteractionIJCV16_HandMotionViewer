#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

#include <typesBackground.h>

#include <tracker.h>

#include <mymath.h>

#include "error_manager.h"

#include <fingertipSet.h>
#include "sequenceselector.h"
#include "sequencedownloader.h"

namespace Ui {
class MainWindow;
}




class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void  read_MODELS_INFO_TXT(        QString myFileString_MODELS_INFO_TXT );
    void print_MODELS_INFO_TXT();
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Tracker* myTracker;

    void changeCamera( int newCamID );

    void define_SEQ_numberStr( QString seqID_Str );
    void initialize();

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////    (sxedon) OLA kai sto NON-GUI    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    QString INPUT_dynamicStringPart;

    QString INPUT_EXTENSSS_Mesh;
    QString INPUT_EXTENSSS_Skeleton;
    QString INPUT_EXTENSSS_Skin;
    QString INPUT_EXTENSSS_Motion;
    QString INPUT_EXTENSSS_VOI;
    QString INPUT_EXTENSSS_Limits;

    QString INPUT_FINAL_PATH_Cameras;
    QString INPUT_FINAL_PATH_IndexCheat;
    QString INPUT_FINAL_PATH_MODELS_INFO_TXT;
    QString INPUT_FINAL_PATH_Video;

    QString INPUT_Filename_Cameras;
    QString INPUT_Filename_MODELS_INFO_TXT;
    QString INPUT_Filename_IndexBounds;

    QString INPUT_BasePath_VideoFrames;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    QVector< QString > INPUT_ModelNamesQVect;

    ///////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////

    void readMotion();

    ///////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////

    void readModelsRenderability();

    int colorID;

    QVector<QColor> _myColors;
    QVector<int> _myColorIndex;
    QString _myColorPicker(bool increaseColorIndex);
    void _myColorizer();

    void changedRenderCheckData();
    void changedRadiosForSkeleton();

    QString mySkeletonType;


    QVector<bool>   checkersForRendering;

    bool isOpenglSliderMovingXeriFLAG;
    bool isNextPrevPressedFLAG;

    int myIDforNextFrame;

    cv::Mat myFrameOpenCV;
    cv::Mat myFrameQT;

    bool trackerCreatedOnce;

    QVector<double> myAlphaVaules;

    void changedAlphaData();

    void refreshPathsALL_ForCurrentSequence();

    void update_ONLYLabels_OfSlider_SEQ_LIMITS_AND_CURR_FR( int currFrame );

    //////////////////////////////////////////////
    //////////////////////////////////////////////

    QString RadioSequenceID_String;   // MIN vgaleis, einai gia prin arxikopoiithei tracker

    QString _myPath_FramesForCurr_SeqqCam;

    TypesBackground myTypesBackground;

    void changedTypesBackground();

    void changed_myTracker_Frames_INI_FIN( QString caller );

    //////////////////////////////////////////
    //////////////////////////////////////////

    void hackButtonColors();

    void readInputs_AND_passToOpenGL();

    void BackGroundButtons_EnableDisable( bool state );

    //////////////////////////////////////////
    //////////////////////////////////////////

    int selectedBone_ListID;

    //////////////////////////////////////////
    //////////////////////////////////////////


private:
    SequenceSelector   seq_Sel;
    SequenceDownloader seq_Down;
    void on_myButton_TRACKER_Load_Pose_RESULT_clicked();
    void sequence_selector();
    void sequence_downloader();



private slots:

    void keyPressEvent(QKeyEvent *myKey);

    void on_myButtonColor_Left_clicked();

    void on_myButtonColor_Right_clicked();

    void on_myButtonColor__Hand_clicked();

    void on_myButtonColor__0_clicked();

    void on_myButtonColor__1_clicked();

    void on_myButtonColor__2_clicked();

    void on_myCheckBox_RenderMesh_clicked();

    void on_myCheckBox_RenderSkeleton_clicked();

    void on_myRadioButton_Points_clicked();

    void on_myRadioButton_Lines_clicked();

    void on_myRadioButton_Both_Points_Lines_clicked();

    void on_mySlider_transpMesh_valueChanged(int value);

    void on_mySlider_transpSkeleton_valueChanged(int value);

    void on_mySliderOpenGL_actionTriggered(int action);

    void on_myButton_extractFrame_clicked();

    void on_myCheck_LocalCoord_clicked();

    void on_myButton_OpenGL_Next_clicked();

    void on_myButton_OpenGL_Previous_clicked();

    void on_myButton_upd_clicked();

    void on_myButton_Reset_clicked();

    void on_myCheck_RenderLeftRight_BoneLCS_clicked();

    void on_myCheck_RenderObject_1_clicked();

    void on_myCheck_RenderObject_2_clicked();

    void on_myCheck_RenderObject_3_clicked();

    void on_mySlider_transpLocalCoord_valueChanged(int value);

    void on_myRadioButton_Tracker_Background_RGB_clicked();

    void on_myRadioButton_Tracker_Background_RGBD_clicked();

    void on_myRadioButton_Tracker_Background_DDD_clicked();

    void on_myRadioButton_Tracker_Background_Blank_clicked();

    void on_myCheckBox_PCL_clicked();

    void on_myCheck_FingertipVertices_clicked();

    void on_myCheck_FingertipDetections_clicked();

    void on_myCheckBox_MESH_FILL_clicked();

    void on_myCheck_FingertipVertices_Centroid_clicked();

    void on_myButton_TRACKER_Load_Motion_File_clicked();

    void on_myButtonColor_Mesh1_clicked();

    void on_myButtonColor_Mesh2_clicked();

    void on_myButtonColor_Mesh3_clicked();

    void on_myButton_defaultCameraView_clicked();

    void on_selectSequence_clicked();

    void loadSequence(QString num);

    void closeSelector( bool );

    void on_downloadSequenceBackgroundFrames_clicked();

    void on_myButton_OpenGL_AutoPlay_START_clicked();

    void on_myButton_OpenGL_AutoPlay_STOPP_clicked();

signals:

    void openGL_AutoPlay_SIGNAL(bool);

    void extractOneFrame_SIGNAL();

public slots:

    void openGL_AutoPlay_UpdUi_SLOT();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
