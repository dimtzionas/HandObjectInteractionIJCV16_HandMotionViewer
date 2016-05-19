#include "typesBackground.h"

TypesBackground::TypesBackground()
{
}


void TypesBackground::reset()
{
    this->RGB   = false;
    this->RGBD  = false;
    this->DDD   = false;
    this->Blank = false;
}

void TypesBackground::operator=(TypesBackground left)
{
    this->RGB   = left.RGB;
    this->RGBD  = left.RGBD;
    this->DDD   = left.DDD;
    this->Blank = left.Blank;
}

void TypesBackground::setType_NonGUI( QString typeIN )
{

    reset();

    typeIN = typeIN.toLower();

    if      ( typeIN == "RGB"   || typeIN == QString("RGB").  toLower() )     this->RGB   = true;
    else if ( typeIN == "RGBD"  || typeIN == QString("RGBD"). toLower() )     this->RGBD  = true;
    else if ( typeIN == "DDD"   || typeIN == QString("DDD").  toLower() )     this->DDD   = true;
    else if ( typeIN == "Blank" || typeIN == QString("Blank").toLower() )     this->Blank = true;
}

void TypesBackground::print()
{
    qDebug() << this->RGB   << "\t"
             << this->RGBD  << "\t"
             << this->DDD   << "\t"
             << this->Blank << "\t";
}
