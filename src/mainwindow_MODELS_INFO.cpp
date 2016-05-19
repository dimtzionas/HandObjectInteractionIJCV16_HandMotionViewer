#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::read_MODELS_INFO_TXT( QString myFileString_MODELS_INFO_TXT )
{
        std::map<QString, QString> gui_names;
        gui_names["Model_Hand_R"] = "Right Hand";
        gui_names["Model_Hand_L"] = "Left Hand";
        gui_names["Model_Object_Ball"] = "Ball";
        gui_names["Model_Object_Cube"] = "Cube";
        gui_names["Model_Object_Pipe_Green_Long"] = "Rope";
        gui_names["Model_Object_Pipe_Gray"] = "Pipe";
        QFile myFile( myFileString_MODELS_INFO_TXT );

        myFile.open(QIODevice::ReadOnly);

        if (myFile.exists() == false || !myFile.isOpen()){
            ErrorManager::error(3, myFileString_MODELS_INFO_TXT);
            return;
        }

        QTextStream myTextStream(&myFile);

        int                           modelsNumber;
        myTextStream >>               modelsNumber;
        INPUT_ModelNamesQVect.resize( modelsNumber );

        for (int i=0; i<INPUT_ModelNamesQVect.size(); i++)     myTextStream >> INPUT_ModelNamesQVect[i];

        myFile.close();

                                            ui->myCheck_RenderObject_1->setEnabled(false);      ui->myCheck_RenderObject_1->setVisible(false);      ui->myCheck_RenderObject_1->setChecked(false);  ui->myButtonColor_Mesh1->setEnabled(false); ui->myButtonColor_Mesh1->setVisible(false);
                                            ui->myCheck_RenderObject_2->setEnabled(false);      ui->myCheck_RenderObject_2->setVisible(false);      ui->myCheck_RenderObject_2->setChecked(false);  ui->myButtonColor_Mesh2->setEnabled(false); ui->myButtonColor_Mesh2->setVisible(false);
                                            ui->myCheck_RenderObject_3->setEnabled(false);      ui->myCheck_RenderObject_3->setVisible(false);      ui->myCheck_RenderObject_3->setChecked(false);  ui->myButtonColor_Mesh3->setEnabled(false); ui->myButtonColor_Mesh3->setVisible(false);

        if (modelsNumber == 0)              return;
        if (modelsNumber >= 1)      {       ui->myCheck_RenderObject_1->setEnabled(true);       ui->myCheck_RenderObject_1->setVisible(true);       ui->myCheck_RenderObject_1->setChecked(true);   ui->myButtonColor_Mesh1->setEnabled(true);  ui->myButtonColor_Mesh1->setVisible(true);  ui->myCheck_RenderObject_1->setText( gui_names[INPUT_ModelNamesQVect[0]] );   }
        if (modelsNumber >= 2)      {       ui->myCheck_RenderObject_2->setEnabled(true);       ui->myCheck_RenderObject_2->setVisible(true);       ui->myCheck_RenderObject_2->setChecked(true);   ui->myButtonColor_Mesh2->setEnabled(true);  ui->myButtonColor_Mesh2->setVisible(true);  ui->myCheck_RenderObject_2->setText( gui_names[INPUT_ModelNamesQVect[1]] );   }
        if (modelsNumber >= 3)      {       ui->myCheck_RenderObject_3->setEnabled(true);       ui->myCheck_RenderObject_3->setVisible(true);       ui->myCheck_RenderObject_3->setChecked(true);   ui->myButtonColor_Mesh3->setEnabled(true);  ui->myButtonColor_Mesh3->setVisible(true);  ui->myCheck_RenderObject_3->setText( gui_names[INPUT_ModelNamesQVect[2]] );   }

}


void MainWindow::print_MODELS_INFO_TXT()
{

                                                                qDebug() << "\n";
                                                                qDebug() << INPUT_ModelNamesQVect.size();
    for (int mmm=0; mmm<INPUT_ModelNamesQVect.size(); mmm++)    qDebug() << INPUT_ModelNamesQVect[mmm];
                                                                qDebug() << "\n";

}

