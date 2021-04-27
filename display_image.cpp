//
// Created by abhishek on 23/04/21.
//

#include "display_image.h"

display_image::display_image(const std::string& path)
{
    Mat image;
    image = imread( path, 1 );

    if ( !image.data )
    {
        printf("No image data \n");
        return;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Press ESC to close window", image);

    while (1) {
        char c = (char) waitKey(25);
        if (c == 27) break;
    }

    destroyAllWindows();
}
