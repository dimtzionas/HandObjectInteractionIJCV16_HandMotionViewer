#include "sequencedownloader.h"
#include "ui_sequencedownloader.h"

SequenceDownloader::SequenceDownloader(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SequenceDownloader)
{
    ui->setupUi(this);
}

SequenceDownloader::~SequenceDownloader()
{
    delete ui;
}

void SequenceDownloader::on_loadSequenceButton_clicked()
{
    QUrl sequence;

    if      (ui->sequenceRadio_01->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/01.zip");
    else if (ui->sequenceRadio_02->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/02.zip");
    else if (ui->sequenceRadio_03->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/03.zip");
    else if (ui->sequenceRadio_04->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/04.zip");
    else if (ui->sequenceRadio_05->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/05.zip");
    else if (ui->sequenceRadio_06->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/06.zip");
    else if (ui->sequenceRadio_07->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/07.zip");
    else if (ui->sequenceRadio_08->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/08.zip");
    else if (ui->sequenceRadio_09->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/09.zip");
    else if (ui->sequenceRadio_10->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/10.zip");
    else if (ui->sequenceRadio_11->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/11.zip");
    else if (ui->sequenceRadio_12->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/12.zip");
    else if (ui->sequenceRadio_13->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/13.zip");
    else if (ui->sequenceRadio_14->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Hand___All_Files_No_PCL_ONI/14.zip");
    else if (ui->sequenceRadio_15->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Object___All_Files_No_PCL_ONI/15.zip");
    else if (ui->sequenceRadio_16->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Object___All_Files_No_PCL_ONI/16.zip");
    else if (ui->sequenceRadio_17->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Object___All_Files_No_PCL_ONI/17.zip");
    else if (ui->sequenceRadio_18->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Object___All_Files_No_PCL_ONI/18.zip");
    else if (ui->sequenceRadio_19->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Object___All_Files_No_PCL_ONI/19.zip");
    else if (ui->sequenceRadio_20->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Object___All_Files_No_PCL_ONI/20.zip");
    else if (ui->sequenceRadio_21->isChecked())     sequence = QUrl("http://files.is.tue.mpg.de/dtzionas/Hand-Object-Capture/Dataset/Hand_Object___All_Files_No_PCL_ONI/21.zip");
    QDesktopServices::openUrl (sequence );
    emit closeWindow( true );
}

void SequenceDownloader::closeEvent(QCloseEvent *){
    emit closeWindow(false);
}
