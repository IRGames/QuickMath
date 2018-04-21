//
//  UserData.hpp
//  MyGame
//
//  Created by Isaac Raymond on 2/27/16.
//
//

#ifndef UserData_h
#define UserData_h

#include <stdio.h>
#include "VideoData.h"

class UserData{
public:
    struct videoInfo{
        std::vector<std::string> nameAndCode2;
        std::vector<int> videoTypes;
    } vidInfo;
    
    struct videoInfo2{
        std::vector<std::string> nameAndCode2;
        std::vector<int> videoTypes;
    } vidInfo2;
    
    UserData();
    std::vector<int> returnChoices();
    std::vector<int> returnChoicesWords();
    std::vector<int> returnChoicesSimilar();
    std::vector<VideoData> returnDataVector();
    std::vector<VideoData> returnDataVectorWords();
    std::vector<VideoData> returnDataVectorSimilar();
    std::vector<VideoData>* returnDataVectorAddress();
    std::vector<VideoData>* returnDataVectorWordsAddress();
    std::vector<VideoData>* returnDataVectorSimilarAddress();
    std::vector<int>* returnChoicesAddress();
    std::vector<int>* returnChoicesWordsAddress();
    std::vector<int>* returnChoicesSimilarAddress();
    std::vector<std::vector <int>>* returnDislikeAddress();
    std::vector<std::vector <int>> returnDislike();
    std::vector<std::vector <int>> returnSimilar();
    std::vector<std::vector <int>>* returnSimilarAddress();
    void initDataList();
    videoInfo getDataOfType(int choice);
    //std::vector<std::string> getNewVideo();
    videoInfo getNewVideo();
    videoInfo getNewVideo2();
    videoInfo getNewVideo3();
    void resetingChoices();
    void resetingChoicesWords();
    void resetingChoicesSimilar();
    
    static bool alreadyDone;
    bool newVid;
    int repeatCounter;
    int choiceOfVideoID;
};

#endif /* UserData_hpp */
