//
// Created by abhishek on 23/04/21.
//

#include "display_video.h"

display_video::display_video(const std::string path) {

    VideoCapture cap(path);
    if(!cap.isOpened())
    {
        std::cout << "Error in opening video file!!!!" << std::endl;
        return;
    }

    int stage  = -1; // not set

    enum state {
        UNKNOWN = -1,
        PLAY,
        PAUSE = 112,
        STOP,
        START
    } _state;

    enum state current_state = PLAY;

    while (1)
    {
        if(current_state == PLAY)
        {
            Mat frame;
            cap >> frame;
            if(frame.empty()) break;
            imshow("Frame", frame);
        }

        char c = (char) waitKey(25);
        if(c == 27) break;
        if (c == 112)
        {
            std::cout << current_state << std::endl;
            current_state = (current_state == PLAY) ? PAUSE : PLAY; //toggle the state on "p" key
        }
    }

    cap.release();
    destroyAllWindows();
}
