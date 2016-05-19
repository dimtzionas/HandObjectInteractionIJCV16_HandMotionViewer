#ifndef TYPESBACKGROUND_H
#define TYPESBACKGROUND_H


#include <QString>
#include <QDebug>


class TypesBackground
{
public:
    TypesBackground();

    void reset();

    void setType_NonGUI( QString typeIN );

    void operator=(TypesBackground left);

    void print();

    bool RGB;
    bool RGBD;
    bool DDD;
    bool Blank;

};

#endif // TYPESBACKGROUND_H
