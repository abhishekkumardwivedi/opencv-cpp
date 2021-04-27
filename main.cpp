#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "display_image.h"
#include "display_video.h"

using namespace cv;

int main(int argc, char** argv )
{
    if ( argc != 3 )
    {
        printf("usage: simple <Image_Path>\n");
        return -1;
    }

//    new display_image(argv[1]);
    new display_video(argv[2]);
}