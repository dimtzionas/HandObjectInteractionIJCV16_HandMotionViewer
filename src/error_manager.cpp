#include "error_manager.h"

void ErrorManager::error(int error_type, QString info){
    QMessageBox messageBox;

    switch ( error_type ) {
    case 1:
        messageBox.critical( 0, "Error", "The folder: \""+info+ "\" doesn't exist or doesn't contain a valid dataset" );
        break;
    case 2:
        messageBox.critical( 0, "Error", "The folder: \"" +info+ "\" is not the correct one for the current sequence or you have not chosen a sequence." );
        break;
    case 3:
        messageBox.critical( 0, "Error", "The file: \""+info+ "\" can not be found, please make sure this file exist or download and compile the program again. If the problem persists, please open an issue in the github project <a href='http://github.com/cvlabbonn/hands_3d_motion_viewer/issues'>here</a>" );
        break;
    case 4:
        messageBox.critical( 0, "Error", "The file: \""+info+ "\" can not be opened or created. If the problem persists, please open an issue in the github project <a href='http://github.com/cvlabbonn/hands_3d_motion_viewer/issues'>here</a>" );
        break;
    case 5:
        messageBox.critical( 0, "Error", "The image file: \""+info+ "\" could not be written in the hard disk.If the problem persists, please open an issue in the github project <a href='http://github.com/cvlabbonn/hands_3d_motion_viewer/issues'>here</a> " );
        break;
    case 6:
        messageBox.information( 0, "Success", "The file: \""+info+ "\" was saved succesfully in the folder ./Capture/SingleFrames" );
        break;
    case 7:
        messageBox.critical( 0, "Error", "Error reading the detection file, please download and compile the program again. If the problem persists, please open an issue in the github project <a href='http://github.com/cvlabbonn/hands_3d_motion_viewer/issues'>here</a>" );
        break;
    default:
        break;
    }
}
