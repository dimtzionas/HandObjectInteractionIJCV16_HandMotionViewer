#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::keyPressEvent(QKeyEvent *myKey)
{

        if      (myKey->key() == Qt::Key_1  &&  QApplication::keyboardModifiers() == Qt::ControlModifier)   {   ui->myRadioButton_Tracker_Background_RGB->  setChecked(true);     changedTypesBackground();   }
        else if (myKey->key() == Qt::Key_2  &&  QApplication::keyboardModifiers() == Qt::ControlModifier)   {   ui->myRadioButton_Tracker_Background_RGBD-> setChecked(true);     changedTypesBackground();   }
        else if (myKey->key() == Qt::Key_3  &&  QApplication::keyboardModifiers() == Qt::ControlModifier)   {   ui->myRadioButton_Tracker_Background_DDD->  setChecked(true);     changedTypesBackground();   }
        else if (myKey->key() == Qt::Key_4  &&  QApplication::keyboardModifiers() == Qt::ControlModifier)   {   ui->myRadioButton_Tracker_Background_Blank->setChecked(true);     changedTypesBackground();   }

        else if (myKey->key() == Qt::Key_1)         {  changeCamera(0);  }

        else if (myKey->key() == Qt::Key_R)         {   if   (myTracker->sequence.cameraSet.currentCameraID == 0)   return;
                                                        else                                                        changeCamera(0);
                                                    }
        else if (myKey->key() == Qt::Key_M)         {   ui->myCheckBox_RenderMesh->toggle();
                                                        on_myCheckBox_RenderMesh_clicked();
                                                    }
        else if (myKey->key() == Qt::Key_S)         {   ui->myCheckBox_RenderSkeleton->toggle();
                                                        on_myCheckBox_RenderSkeleton_clicked();
                                                    }
        else if (myKey->key() == Qt::Key_U)         {   ui->myCheckBox_PCL->toggle();
                                                        on_myCheckBox_PCL_clicked();
                                                    }
        else if (myKey->key() == Qt::Key_J)         {   ui->myCheck_FingertipVertices->toggle();
                                                        on_myCheck_FingertipVertices_clicked();
                                                    }
        else if (myKey->key() == Qt::Key_G)         {   ui->myCheck_FingertipVertices_Centroid->toggle();
                                                        on_myCheck_FingertipVertices_Centroid_clicked();
                                                    }
        else if (myKey->key() == Qt::Key_F)         {   ui->myCheckBox_MESH_FILL->toggle();
                                                        on_myCheckBox_MESH_FILL_clicked();
                                                    }
        else if (myKey->key() == Qt::Key_B)         {   ui->myCheckBox_PCL->toggle();
                                                        on_myCheckBox_PCL_clicked();
                                                    }
        else if (myKey->key() == Qt::Key_X)         {   ui->myCheck_FingertipDetections->toggle();
                                                        on_myCheck_FingertipDetections_clicked();
                                                    }
        else if (myKey->key() == Qt::Key_Escape)    {   this->close();
                                                        exit(-1);
                                                    }

}
