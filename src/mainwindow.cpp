#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QGenericMatrix>
#include <QKeyEvent>
#include <QColor>
#include <QPainter>

#include <string>

#include <eigen3/Eigen/Geometry>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        ui->setupUi(this);
        // load the play and stop icons
        QDir basedir = QDir(QApplication::applicationDirPath());
        basedir.cdUp();
        QString basePath = basedir.path();
        QIcon play(basePath+"/img/play.png");
        QIcon stop(basePath+"/img/stop.png");
        ui->myButton_OpenGL_AutoPlay_START->setIcon(play);
        ui->myButton_OpenGL_AutoPlay_STOPP->setIcon(stop);

        RadioSequenceID_String = "-888";

        connect( this,               SIGNAL(extractOneFrame_SIGNAL()),          ui->myOpenGLWidget, SLOT(extractOneFrame_SLOT())       );
        connect( this,               SIGNAL(openGL_AutoPlay_SIGNAL(bool)),      ui->myOpenGLWidget, SLOT(openGL_AutoPlay_SLOT(bool))   );
        connect( ui->myOpenGLWidget, SIGNAL(openGL_AutoPlay_UpdUi_SIGNAL()),    this,               SLOT(openGL_AutoPlay_UpdUi_SLOT()) );
        connect(&seq_Sel,SIGNAL(setSequence(QString)),this, SLOT(loadSequence(QString)));
        connect(&seq_Sel,SIGNAL(closeWindow(bool)),this, SLOT(closeSelector(bool)));
        connect(&seq_Down,SIGNAL(closeWindow(bool)),this, SLOT(closeSelector(bool)));

        this->ui->mainWidget->setEnabled(false);
}




MainWindow::~MainWindow()
{
        delete ui;
}



void MainWindow::define_SEQ_numberStr( QString deqID )
{
        RadioSequenceID_String = deqID;
}

void MainWindow::initialize()
{

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        //ex - read_INPUT_TXT("INPUT_PATHS.txt");

        INPUT_Filename_Cameras         = "Cameras.txt";
        INPUT_EXTENSSS_Mesh            = ".OFF";
        INPUT_EXTENSSS_Skeleton        = ".SKEL";
        INPUT_EXTENSSS_Limits          = ".LIMITS";
        INPUT_EXTENSSS_Skin            = ".SKIN";
        INPUT_EXTENSSS_Motion          = ".MOTION";
        INPUT_EXTENSSS_VOI             = ".VOI";

        INPUT_Filename_IndexBounds     = "INDEX_BOUNDS.txt";
        INPUT_Filename_MODELS_INFO_TXT = "MODELS_INFO.txt";

        INPUT_BasePath_VideoFrames     = "/lala/";

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        QDir basedir = QDir(QApplication::applicationDirPath());
        basedir.cdUp();
        QString basePath = basedir.path();
        if (QDir(        QString(basePath+"/Capture/")).exists() == false)
            QDir().mkdir(QString(basePath+"/Capture/"));
        if (QDir(        QString(basePath+"/Capture/SingleFrames/")).exists() == false)
            QDir().mkdir(QString(basePath+"/Capture/SingleFrames/"));

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        trackerCreatedOnce = false;

        checkersForRendering.resize( 70 );

        colorID = 0;

        isOpenglSliderMovingXeriFLAG = false;
        isNextPrevPressedFLAG        = false;

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ui->myLabel_transMesh->setText(          QString::number(   qPow( (double)ui->mySlider_transpMesh->value()          /100, 3 ),   10,3   ) );
        ui->myLabel_transSkeleton->setText(      QString::number(   qPow( (double)ui->mySlider_transpSkeleton->value()      /100, 3 ),   10,3   ) );
        ui->myLabel_transLocalCoord->setText(    QString::number(   qPow( (double)ui->mySlider_transpLocalCoord->value()    /100, 3 ),   10,3   ) );

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//        readInputs_AND_passToOpenGL();

//        changedRenderCheckData();
//        hackButtonColors();
//        changeCamera( myTracker->sequence.cameraSet.currentCameraID ); // = 0

//        myTracker->sequence.cameraSet.setModelViewFrom_RT_cameraDefault();

//        ///////////////////////////////////////
//        ui->myOpenGLWidget->cameraTranslate(0); // to update centerOfRotation vector !!!
//        ///////////////////////////////////////

//        //////////////////////////////////
//        on_myCheckBox_MESH_FILL_clicked(); // regulate mesh alpha
//        //////////////////////////////////

//        ui->myLabel_transMesh->               setVisible( false );
//        ui->myLabel_transSkeleton->  setVisible( false );
//        ui->myLabel_transLocalCoord->setVisible( false );

//        BackGroundButtons_EnableDisable( false );

//        ui->myCheck_FingertipVertices_Centroid->setEnabled( ui->myCheck_FingertipVertices->isChecked() );

}



void MainWindow::hackButtonColors()
{
        on_myButtonColor_Mesh1_clicked();
        on_myButtonColor_Mesh1_clicked();
        on_myButtonColor_Mesh1_clicked();
        on_myButtonColor_Mesh1_clicked();
        on_myButtonColor_Left_clicked();
        on_myButtonColor_Right_clicked();
        on_myButtonColor__Hand_clicked();
        on_myButtonColor__0_clicked();
        on_myButtonColor__1_clicked();
        on_myButtonColor__2_clicked();
        on_myButtonColor_Mesh2_clicked();
        on_myButtonColor_Mesh2_clicked();
        on_myButtonColor_Mesh2_clicked();
        on_myButtonColor_Mesh2_clicked();
        on_myButtonColor_Mesh3_clicked();
        on_myButtonColor_Mesh3_clicked();
        on_myButtonColor_Mesh3_clicked();
        on_myButtonColor_Mesh3_clicked();
        on_myButtonColor_Mesh3_clicked();
}


void MainWindow::changeCamera( int newCamID )
{
        myTracker->sequence.cameraSet.switchCamera( newCamID );

        if (myTypesBackground.Blank == false)   myTracker->sequence.videoSequence.loadCurrentFrame( myTracker->sequence.cameraSet.currentCameraID, myTracker->currentFrameNumberGET() );

        ui->myOpenGLWidget->spinCenter4D_curr = myTracker->sequence.cameraSet.RT_4x4_custom * myTracker->sequence.posedAnimations[0].modelSet.centroid4D_curr;
}

void MainWindow::on_myButton_defaultCameraView_clicked()
{
        changeCamera(0);
}

void MainWindow::openGL_AutoPlay_UpdUi_SLOT()
{
        changed_myTracker_Frames_INI_FIN( "auto" );
}

void MainWindow::loadSequence(QString num)
{
    this->setEnabled(true);
    this->ui->mainWidget->setEnabled(true);
    this->ui->selectSequence->setEnabled(true);
    this->ui->downloadSequenceBackgroundFrames->setEnabled(true);
    this->setWindowTitle("Hands 3d Motion Viewer - Sequence ID " + num);
    define_SEQ_numberStr(num);
    readInputs_AND_passToOpenGL();

    changedRenderCheckData();
    hackButtonColors();
    changeCamera( myTracker->sequence.cameraSet.currentCameraID );

    myTracker->sequence.cameraSet.setModelViewFrom_RT_cameraDefault();

    ///////////////////////////////////////
    ui->myOpenGLWidget->cameraTranslate(0); // to update centerOfRotation vector !!!
    ///////////////////////////////////////

    //////////////////////////////////
    on_myCheckBox_MESH_FILL_clicked(); // regulate mesh alpha
    //////////////////////////////////

    ui->myLabel_transMesh->      setVisible( false );
    ui->myLabel_transSkeleton->  setVisible( false );
    ui->myLabel_transLocalCoord->setVisible( false );

    BackGroundButtons_EnableDisable( false );

    ui->myCheck_FingertipVertices_Centroid->setEnabled( ui->myCheck_FingertipVertices->isChecked() );

    //////////////////////////////////////////////
    ui->myOpenGLWidget->trackerInitialized = true;
    //////////////////////////////////////////////

}

void MainWindow::on_selectSequence_clicked()
{
    sequence_selector();
}

void MainWindow::on_downloadSequenceBackgroundFrames_clicked()
{
    sequence_downloader();
}

void MainWindow::closeSelector(bool enable)
{
    this->setEnabled(true);
    ui->mainWidget->setEnabled(false);
    if (enable)
        ui->mainWidget->setEnabled(true);
    else if (RadioSequenceID_String != "-888")
        ui->mainWidget->setEnabled(true);
    this->ui->selectSequence->setEnabled(true);
    this->ui->downloadSequenceBackgroundFrames->setEnabled(true);
    this->seq_Down.hide();
    this->seq_Sel.hide();
}




