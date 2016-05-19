#include <glwidget.h>



void GLWidget::extractOneFrame_SLOT()
{

        QImage myCapturedFrame = this->grabFrameBuffer();

        QImageWriter imagefile;

        QDir basedir = QDir(QApplication::applicationDirPath());
        basedir.cdUp();

        QString         filename = basedir.path() + "/Capture/SingleFrames/number.txt";
        QFile myFileIN( filename );

        if (myFileIN.exists() == true)
        {
                myFileIN.open(QIODevice::ReadOnly);

                if(!myFileIN.isOpen())
                {
                        ErrorManager::error(3, filename);
                        extractOne_Count = -1;
                }
                else
                {
                        QTextStream myStreamIN(&myFileIN);

                        extractOne_Count = myStreamIN.readAll().toInt();

                        myFileIN.close();
                }
        }
        else            extractOne_Count = -1;

        ///////////////////
        extractOne_Count++;
        ///////////////////
        QFile myFileOUT(  filename );
        myFileOUT.open(QIODevice::WriteOnly);

        if(!myFileOUT.isOpen())
        {
            ErrorManager::error(4, filename);
            return;
        }

        QTextStream myStreamOUT(&myFileOUT);

        myStreamOUT << QString::number(extractOne_Count);

        myFileOUT.close();

        QString PATH = basedir.path() + "/Capture/SingleFrames/" + QString::number( extractOne_Count ).rightJustified(5,'0',false) + ".jpg";

        imagefile.setFileName( PATH );
        imagefile.setFormat("jpg");
        imagefile.setQuality( 100 );
        bool result = imagefile.write(myCapturedFrame);

        if(!result)
        {
            ErrorManager::error(5, filename);
            return;
        } else {

        QFileInfo file_path = QFileInfo(PATH);
        ErrorManager::error(6, file_path.fileName());
        }

}
