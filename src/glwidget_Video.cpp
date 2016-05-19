#include <glwidget.h>




void GLWidget::myRenderVideoBackground()
{

        ///////////////////////////////////////////////////
        if (tracker->typesBackground.Blank == true) return;
        ///////////////////////////////////////////////////


        QImage                                              qVideoFrame;
        if      (tracker->typesBackground.RGB  == true)     qVideoFrame = tracker->sequence.videoSequence.currFrame_RGB_QT;
        else if (tracker->typesBackground.RGBD == true)     qVideoFrame = tracker->sequence.videoSequence.currFrame_RGBD_QT;
        else if (tracker->typesBackground.DDD  == true)     qVideoFrame = tracker->sequence.videoSequence.currFrame_DDD_VIZ_QT;


        if (qVideoFrame.isNull() == false)
        {

                qVideoFrame = qVideoFrame.mirrored(false,true);

                try
                {
                    glDrawPixels(   this->width(),   this->height(),   GL_BGR, GL_UNSIGNED_BYTE,   qVideoFrame.bits()   );
                }
                catch(...)
                {

                }

        }

}
