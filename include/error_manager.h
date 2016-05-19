#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H

#include <QMessageBox>

class ErrorManager
{
public:
    static void error(int error_type, QString info="");
};

#endif // ERROR_MANAGER_H
