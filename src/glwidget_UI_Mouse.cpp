#include <glwidget.h>




void GLWidget::mousePressEvent(QMouseEvent *myEvent)     {      }




void GLWidget::wheelEvent(QWheelEvent *myEvent)     {     cameraTranslate( myEvent->delta() );     }




void GLWidget::mouseMoveEvent(QMouseEvent *myEvent)
{
        ///////////////////////////////////////////
        if (trackerInitialized == false)    return;
        ///////////////////////////////////////////

        int mousePos_X = myEvent->pos().x();
        int mousePos_Y = myEvent->pos().y();
        if (mousePos_X < 0)                                              mousePos_X=0;
        if (mousePos_Y < 0)                                              mousePos_Y=0;
        if (mousePos_X > tracker->sequence.videoSequence.frameWidth)     mousePos_X = tracker->sequence.videoSequence.frameWidth;
        if (mousePos_Y > tracker->sequence.videoSequence.frameHeight)    mousePos_Y = tracker->sequence.videoSequence.frameHeight;

        ///////////////////////////////////////////////////////
        double dx = (mousePos_X - lastMousePos.x()) / (float)4;
        double dy = (mousePos_Y - lastMousePos.y()) / (float)4;
        ///////////////////////////////////////////////////////

        if      (myEvent->buttons() & Qt::LeftButton )   {   cameraRotate(    mousePos_X, mousePos_Y );   }
        else if (myEvent->buttons() & Qt::RightButton)   {   cameraTranslate( dx, dy );                   }

        lastMousePos = myEvent->pos();
}

