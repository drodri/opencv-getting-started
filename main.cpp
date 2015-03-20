#include "diego/opencv/opencv/cv.h"      // include it to used Main OpenCV functions.
#include "diego/opencv/opencv/highgui.h" //include it to use GUI functions.
 
int main(int argc, char** argv)
{
    //bii://bii.png
    IplImage* img = cvLoadImage( "diego/opencvex/bii.png" );
    cvNamedWindow( "Example1", CV_WINDOW_AUTOSIZE );

    cvShowImage("Example1", img);
    cvMoveWindow("Example1", 0, 0);
    cvWaitKey(0);
    cvReleaseImage( &img );
    cvDestroyWindow( "Example1" );
    return 0;
}
