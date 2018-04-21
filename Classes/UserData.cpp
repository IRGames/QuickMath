//
//  UserData.cpp
//  MyGame
//
//  Created by Isaac Raymond on 2/27/16.
//
//

#include "UserData.h"
#include "VideoData.h"
#include <fstream>
#include <iostream>
#include "cocos2d.h"
#include "time.h"

VideoData videoData();
static std::vector<std::vector<int>> types; //Each video's dataVector # is stored under its type
static std::vector<std::vector<int>> typesWords;
static std::vector<std::vector<int>> typesSimilar;
static std::vector<int> choices;
static std::vector<int> choicesWords;
static std::vector<int> choicesSimilar;
static std::vector<VideoData> dataVector;
static std::vector<VideoData> dataVectorWords;
static std::vector<VideoData> dataVectorSimilar;
static std::vector<std::vector <int>> dislike;
static std::vector<std::vector <int>> wordss;
static std::vector<std::vector <int>> similar;


//static std::vector<std::vector <int>> dislike;

std::vector<std::string> nameAndCode;
std::string line;
int numTagTypes;
int numTagTypesWords;


UserData::UserData(){
    numTagTypes = 54;
    numTagTypesWords = 18;
    
    dataVector.resize(200);
    dataVectorWords.resize(200);
    nameAndCode.resize(3);
//    dislike.resize(60);
    types.resize(numTagTypes+1);
    typesWords.resize(numTagTypesWords+1);
    
    for(int j=0; j<2; j++){
        for(int i=1; i<=numTagTypes; i++){
            choices.push_back(i);
        }
    }
    
    for(int j=0; j<2; j++){
        for(int i=1; i<=numTagTypesWords; i++){
            choicesWords.push_back(i);
        }
    }
    
    newVid = false;
    repeatCounter = 0;
}


void UserData::initDataList(){
    std::string path = cocos2d::FileUtils::getInstance()->fullPathForFilename("List.txt");
    std::ifstream myfile (path.c_str());
    std::string s;
    std::string sub;
    int k=0;  //"k" represents the type of line we're on - line 0 through line 3
    int j=0;  //"j" represents the current video we're on
    int shit=0; //the video type we get from parsing the string
    
    struct timeval timeHolder;
    
    gettimeofday(&timeHolder, NULL);
    
    std::srand(timeHolder.tv_sec);
    
    dataVector.resize(480);
    types.resize(numTagTypes+1);
    for(int j=0; j<2; j++){
        for(int i=1; i<=numTagTypes; i++){
            choices.push_back(i);
        }
    }
    nameAndCode.resize(3);

    
    if(myfile){
        while (std::getline(myfile, line))
        {
            if(k==0)
            {
                s = line;
                std::istringstream iss(s);
                
                while(iss)
                {
                    iss >> sub;
                    shit = std::stoi(sub);
                    dataVector[j].videoType.push_back(shit);
                    types[shit].push_back(j);
                }
                types[shit].pop_back();
            }
            
            if(k==1){dataVector[j].pictureName = line;}
            if(k==2){dataVector[j].youtubeCode = line;}
            
            k++;
            if(k==4){k=0; j++;}
        }
    }

    

    
    /*
    std::string path2 = cocos2d::FileUtils::getInstance()->fullPathForFilename("DislikeList.txt");
    std::ifstream myfile2 (path2.c_str());
    std::string s2;
    std::string sub2;
    int shit2 = 0;
    int arrayNumber = 0;
    
    
    if(myfile2){
        while (std::getline(myfile2, line))
        {
            
            s2 = line;
            std::istringstream iss2(s2);
            
            while(iss2)
            {
                iss2 >> sub2;
                shit2 = std::stoi(sub2);
                dislike[arrayNumber].push_back(shit2);
            }
            
            arrayNumber++;
        }
    }
    
    for(int i = 0; i<dislike.size(); i++){
        for(int j=0; j<dislike[i].size(); j++){
            printf("%d ", dislike[i][j]);
        }
        
        printf("\n");
    }*/
    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
     for(int z = 0; z<dataVector.size()-1; z++){
     for(int q=0; q<dataVector[z].videoType.size()-1; q++){
     printf("%d ", dataVector[z].videoType[q]);
     }
     printf("\n \n");
     }
     */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
    for(int y=0; y<types.size()+1; y++){
        printf("The video type number is %d ", y);
        printf(", # of videos of this type %lu \n", types[y].size());
    }
    */

    std::string path2 = cocos2d::FileUtils::getInstance()->fullPathForFilename("DislikeList.txt");
    std::ifstream myfile2 (path2.c_str());
    std::string s2;
    std::string sub2;
    int shit2 = 0;
    int jj = 0;
    int jjj = 0;
    int arrayNumber = 0;
    std::string line;
    dislike.resize(numTagTypes);
    
    if(myfile2){
        while (std::getline(myfile2, line))
        {
            
            s2 = line;
            std::istringstream iss2(s2);
            
            while(iss2)
            {
                iss2 >> sub2;
                shit2 = std::stoi(sub2);
                dislike[arrayNumber].push_back(shit2);
            }
            
            arrayNumber++;
        }
    }
    
    
    dataVectorWords.resize(180);
    typesWords.resize(numTagTypesWords+1);
    for(int j=0; j<2; j++){
        for(int i=1; i<=numTagTypesWords; i++){
            choicesWords.push_back(i);
        }
    }
    
  
    
    std::string path3 = cocos2d::FileUtils::getInstance()->fullPathForFilename("Word Problems List.txt");
    std::ifstream myfile3 (path3.c_str());
    std::string s3;
    std::string sub3;
    int shit3 = 0;
    int kk = 0;
    int arrayNumber3 = 0;
    std::string line3;
    
    if(myfile3){
        while (std::getline(myfile3, line3))
        {
            if(kk==0)
            {
                s3 = line3;
                std::istringstream iss3(s3);
                
                while(iss3)
                {
                    iss3 >> sub3;
                    shit3 = std::stoi(sub3);
                    dataVectorWords[jj].videoType.push_back(shit3);
                    typesWords[shit3].push_back(jj);
                    printf("\n pushing back %d into typesWords \n", jj);
                }
                typesWords[shit3].pop_back();
            }
            
            if(kk==1){dataVectorWords[jj].pictureName = line3;}
            if(kk==2){dataVectorWords[jj].youtubeCode = line3;}
            
            kk++;
            if(kk==4){kk=0; jj++;}
        }
    }
    
    
    std::string path4 = cocos2d::FileUtils::getInstance()->fullPathForFilename("Similar.txt");
    std::ifstream myfile4 (path4.c_str());
    std::string s4;
    std::string sub4;
    int shit4 = 0;
    int arrayNumber4 = 0;
    std::string line4;
    similar.resize(numTagTypes);
    
    if(myfile4){
        while (std::getline(myfile4, line4))
        {
            
            s4 = line4;
            std::istringstream iss4(s4);
            
            while(iss4)
            {
                iss4 >> sub4;
                shit4 = std::stoi(sub4);
                similar[arrayNumber4].push_back(shit4);
            }
            similar[arrayNumber4].pop_back();
            arrayNumber4++;
        }
    }
    
    printf("\n current similar elements: ");
    for (int i=0; i<similar.size(); i++){
        for (int j=0; j<similar[i].size(); j++){
            printf("%d, ", similar[i][j]);
        }
        
        printf("\n");
    }
    
    /*
    
    printf("The choicesWords vector contains \n");
    for(int i=0; i<choicesWords.size(); i++){
        printf("%d ", choicesWords[i]);
    }
    
    printf("\n \n");
    
    printf("The dataVectorWords vector contains \n");
    for(int i=0; i<dataVectorWords.size(); i++){
        printf("%s, ", dataVectorWords[i].pictureName.c_str());
        printf("%s \n", dataVectorWords[i].youtubeCode.c_str());
    }
    
    printf("The typesWords vector contains \n");
    for(int i=0; i<typesWords.size(); i++){
        for(int j=0; j<typesWords[i].size(); j++){
        printf("%d, ", typesWords[i][j]);
        }
    }
    
    printf("\n \n");
    */
     
    /*
     if(myfile){
     while (std::getline(myfile, line))
     {
     if(k==0)
     {
     s = line;
     std::istringstream iss(s);
     
     while(iss)
     {
     iss >> sub;
     shit = std::stoi(sub);
     dataVector[j].videoType.push_back(shit);
     types[shit].push_back(j);
     }
     types[shit].pop_back();
     }
     
     if(k==1){dataVector[j].pictureName = line;}
     if(k==2){dataVector[j].youtubeCode = line;}
     
     k++;
     if(k==4){k=0; j++;}
     }
     }
     */
    
    
    
    
}


UserData::videoInfo UserData::getNewVideo(){
    if(choices.size() == 0){printf("\n SPECIAL choices.size() is %lu \n", choices.size());  return vidInfo;}
    
    else{
    int choose = 0;
    choiceOfVideoID = 0;
    vidInfo.videoTypes.clear();
    

    //Random%lu choose one of the numbers in the choices list
    
    
    
    choose = choices[std::rand()%choices.size()];
        printf("\n choices.size() is %lu \n", choices.size());
    
    /*
    printf("The video type number is %d", choose);
    printf(", # of videos of this type %lu \n", types[choose].size());
    printf("the videos in this list are \n");
    for(int j = 0; j<types[choose].size(); j++){
        printf("%d ", types[choose][j]);
    }
    */
    
    //Randomly choose a video of that type
    
    choiceOfVideoID = types[choose][std::rand()%types[choose].size()];
    
    nameAndCode[0] = dataVector[choiceOfVideoID].pictureName;
    nameAndCode[1] = dataVector[choiceOfVideoID].youtubeCode;
    
    vidInfo.nameAndCode2 = nameAndCode;
    
    for(int i=0; i<dataVector[choiceOfVideoID].videoType.size(); i++){
        vidInfo.videoTypes.push_back(dataVector[choiceOfVideoID].videoType[i]);
    }
    
    return vidInfo;
    }
}


UserData::videoInfo UserData::getDataOfType(int xx){
    int choose = 0;
    choiceOfVideoID = 0;
    vidInfo.videoTypes.clear();
    nameAndCode.resize(3);
    types.resize(59);
    for(int i=0; i<59; i++){
        types[i].resize(10);
    }
    
    //select a video of a certain type
    choose = xx+1;
    
    //Randomly choose a video of that type
    choiceOfVideoID = types[choose][std::rand()%types[choose].size()];
    
    nameAndCode[0] = dataVector[choiceOfVideoID].pictureName;
    nameAndCode[1] = dataVector[choiceOfVideoID].youtubeCode;
    
    vidInfo.nameAndCode2 = nameAndCode;
    
    for(int i=0; i<dataVector[choiceOfVideoID].videoType.size(); i++){
        vidInfo.videoTypes.push_back(dataVector[choiceOfVideoID].videoType[i]);
    }
    
    return vidInfo;
}


std::vector<int> UserData::returnChoices(){
    return choices;
}

std::vector<int> UserData::returnChoicesWords(){
    return choicesWords;
}

std::vector<int> UserData::returnChoicesSimilar(){
    return choicesSimilar;
}

std::vector<int>* UserData::returnChoicesAddress(){
    return &choices;
}

std::vector<int>* UserData::returnChoicesWordsAddress(){
    return &choicesWords;
}

std::vector<int>* UserData::returnChoicesSimilarAddress(){
    return &choicesSimilar;
}

std::vector<VideoData> UserData::returnDataVector(){
    return dataVector;
}

std::vector<VideoData> UserData::returnDataVectorWords(){
    return dataVectorWords;
}

std::vector<VideoData> UserData::returnDataVectorSimilar(){
    return dataVectorSimilar;
}

std::vector<VideoData>* UserData::returnDataVectorAddress(){
    return &dataVector;
}

std::vector<VideoData>* UserData::returnDataVectorWordsAddress(){
    return &dataVectorWords;
}

std::vector<VideoData>* UserData::returnDataVectorSimilarAddress(){
    return &dataVectorSimilar;
}

std::vector<std::vector <int>> UserData::returnDislike(){
    return dislike;
}

std::vector<std::vector <int>>* UserData::returnDislikeAddress(){
    return &dislike;
}

std::vector<std::vector <int>> UserData::returnSimilar(){
    return similar;
}

std::vector<std::vector <int>>* UserData::returnSimilarAddress(){
    return &similar;
}



void UserData::resetingChoices(){
    choices.resize(0);
    
    
    
    for(int j=0; j<2; j++){
        for(int i=1; i<=numTagTypes; i++){
            choices.push_back(i);
        }
    }
}

void UserData::resetingChoicesWords(){
    choicesWords.resize(0);
    
    
    
    for(int j=0; j<2; j++){
        for(int i=1; i<=numTagTypesWords; i++){
            choicesWords.push_back(i);
        }
    }
}

void UserData::resetingChoicesSimilar(){
    choicesSimilar.resize(0);
    
    
    
    for(int j=0; j<2; j++){
        for(int i=1; i<=numTagTypesWords; i++){
            choicesSimilar.push_back(i);
        }
    }
}

//Code to check each type's contents (which videos are listed under which types)
/*printf("The video type number is %d", choose);
 printf(", # of videos of this type %lu \n", types[choose].size());
 printf("the videos in this list are \n");
 for(int j = 0; j<types[choose].size(); j++){
 printf("%d ", types[choose][j]);
 }*/




UserData::videoInfo UserData::getNewVideo2(){
        if(choicesWords.size() == 0){printf("\n SPECIAL choices.size() is %lu \n", choices.size());  return vidInfo;}
        else{
    int choose = 0;
    choiceOfVideoID = 0;
    vidInfo.videoTypes.clear();
    
    
    //Random%lu choose one of the numbers in the choices list
    choose = choicesWords[std::rand()%choicesWords.size()];
    
    /*
     printf("The video type number is %d", choose);
     printf(", # of videos of this type %lu \n", typesWords[choose].size());
     printf("the videos in this list are \n");
     for(int j = 0; j<typesWords[choose].size(); j++){
     printf("%d ", typesWords[choose][j]);
     }
    */
    
    //Randomly choose a video of that type
    /*
    printf("\n choose is %d \n", choose);
    
    printf("\n \n The typesWords vector contains \n");
    for(int i=0; i<typesWords.size(); i++){
        for(int j=0; j<typesWords[i].size(); j++){
            printf("%d, ", typesWords[i][j]);
        }
        printf("\n \n");
    }
    */
    
    choiceOfVideoID = typesWords[choose][std::rand()%typesWords[choose].size()];
    
    nameAndCode[0] = dataVectorWords[choiceOfVideoID].pictureName;
    nameAndCode[1] = dataVectorWords[choiceOfVideoID].youtubeCode;
    
    vidInfo.nameAndCode2 = nameAndCode;
    
    for(int i=0; i<dataVectorWords[choiceOfVideoID].videoType.size(); i++){
        vidInfo.videoTypes.push_back(dataVectorWords[choiceOfVideoID].videoType[i]);
    }
    
    return vidInfo;
    }
}


//Code to check each type's contents (which videos are listed under which types)
/*printf("The video type number is %d", choose);
 printf(", # of videos of this type %lu \n", types[choose].size());
 printf("the videos in this list are \n");
 for(int j = 0; j<types[choose].size(); j++){
 printf("%d ", types[choose][j]);
 }*/




UserData::videoInfo UserData::getNewVideo3(){
    if(choicesSimilar.size() == 0){printf("\n SPECIAL choices.size() is %lu \n", choices.size());  return vidInfo;}
    else{
        int choose = 0;
        choiceOfVideoID = 0;
        vidInfo.videoTypes.clear();
        
        
        //Random%lu choose one of the numbers in the choices list
        choose = choicesSimilar[std::rand()%choicesSimilar.size()];
        
        /*
         printf("The video type number is %d", choose);
         printf(", # of videos of this type %lu \n", typesWords[choose].size());
         printf("the videos in this list are \n");
         for(int j = 0; j<typesWords[choose].size(); j++){
         printf("%d ", typesWords[choose][j]);
         }
         */
        
        //Randomly choose a video of that type
        /*
         printf("\n choose is %d \n", choose);
         
         printf("\n \n The typesWords vector contains \n");
         for(int i=0; i<typesWords.size(); i++){
         for(int j=0; j<typesWords[i].size(); j++){
         printf("%d, ", typesWords[i][j]);
         }
         printf("\n \n");
         }
         */
        
        choiceOfVideoID = typesSimilar[choose][std::rand()%typesSimilar[choose].size()];
        
        nameAndCode[0] = dataVectorSimilar[choiceOfVideoID].pictureName;
        nameAndCode[1] = dataVectorSimilar[choiceOfVideoID].youtubeCode;
        
        vidInfo.nameAndCode2 = nameAndCode;
        
        for(int i=0; i<dataVectorSimilar[choiceOfVideoID].videoType.size(); i++){
            vidInfo.videoTypes.push_back(dataVectorSimilar[choiceOfVideoID].videoType[i]);
        }
        
        return vidInfo;
    }
}
