//
//  VideoData.hpp
//  MyGame
//
//  Created by Isaac Raymond on 2/27/16.
//
//

#ifndef VideoData_h
#define VideoData_h

#include <stdio.h>

class VideoData{
public:
    VideoData();
    std::string pictureName;
    std::string youtubeCode;
    std::vector<int> videoType;
};

#endif /* VideoData_hpp */
