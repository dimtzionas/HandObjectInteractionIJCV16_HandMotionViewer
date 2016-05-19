#ifndef MYMATH_H
#define MYMATH_H


#include <QDebug>
#include <qmath.h>

#include <eigen3/Eigen/Core>


class MyMath
{
public:
    MyMath();


        static Eigen::MatrixXd  my_Rv_2_RM( Eigen::MatrixXd   rvvv    );              // rv(3,1)  // Exponential Map - so(3)=>SO(3) // (zero pitch screw)
        static int              myRounding( double double_IN, int MAX );

};

#endif // MYMATH_H
