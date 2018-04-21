//

//  Lesson.cpp

//  MyGame

//  videoTags needs to be personal to each Lesson, a la successful "nameAndCode"

//  Created by Isaac Raymond on 12/25/15.

//

//

#include "Lesson.h"
#include "ui/CocosGUI.h"
#include "HelloWorldScene.h"
#include "UserData.h"
#include <fstream>
#include <iostream>
#include "PluginChartboost/PluginChartboost.h"
#include "PluginSdkboxAds/PluginSdkboxAds.h"


USING_NS_CC;

static bool otherListeners;


bool found;
bool restartingLeftSwipes;
int check, firstCheck;
//int type;
int currentType;
std::string pics;
UserData userData;
Size tSizeOrig1;
int addCount;



std::vector<std::string> response;
std::vector<int> response2;

std::vector<int> similarMissings;
//static std::vector<std::vector <int>> dislike;




Lesson::Lesson(){
    name = "Pictures/Absolute Value Inequality 2.jpg";
    acceptChanges = false;

}

void Lesson::initiate(Layer* layer, int x, int y){
    check = 0;
    firstCheck = 0;
    sprite = Sprite::create(name);
    found = false;
    pics = "Pictures/";
    yTCode = "WsP_sH9jOnY";
    response.resize(2);
    videoTags.resize(1);
    words = false;
    otherListeners = false;
    restartingLeftSwipes = false;
    
    similarMissings.push_back(10);
    similarMissings.push_back(23);
    similarMissings.push_back(26);
    similarMissings.push_back(36);
    similarMissings.push_back(40);
    similarMissings.push_back(41);
    similarMissings.push_back(43);
    similarMissings.push_back(52);
    
    //Setting dimensions to conform to all ios devices
    tTargetSize = Size(4*y/9, y/3);
    tSizeOrig1 = sprite->getContentSize();
    
    //Drawing and adding the lesson's picture
    sprite->setScale( ( 1.8*tTargetSize.width / tSizeOrig1.width ), ( 1.8*tTargetSize.height / tSizeOrig1.height ));
    
    if(acceptChanges){
        sprite->setScale( ( 1.4*tTargetSize.width / tSizeOrig1.width ), ( 1.4*tTargetSize.height / tSizeOrig1.height ));
    }
    
    sprite->setAnchorPoint(Vec2(0,0));
    sprite->setPosition(pos);
    
    layer->addChild(sprite);
    spriteOrigin = sprite->getBoundingBox();

    tTargetSizeButton = Size(1.5*x/30, 1.5*x/30);
    
    setTouchEnabled(true);
    addCount = 0;

}


void Lesson::newVideoAfterWrong(){
    if(restartingLeftSwipes == false)
    {
    for(int j=0; j<videoTags.size(); j++){
        for(int i=0; i<userData.returnChoices().size(); i++)
        {
            if(userData.returnChoices()[i] == videoTags[j])
            {
                printf("DELETING %d \n", userData.returnChoices()[i]);
                
                //if(check > 0){
                    userData.returnChoicesAddress()->erase(userData.returnChoicesAddress()->begin() + i);
                //}
                
            }
            
            /////////////////////////////////////////////////////////////////////////////
            /*
            if(firstCheck > 1){
            for(int k=0; k<userData.returnSimilar()[j].size(); k++){
                if(userData.returnChoices()[i] == userData.returnSimilar()[videoTags[j]-1][k]){

                                //else{
                    
                    if(check < 1){
                    
                    printf("deleting %d \n", userData.returnChoices()[i]);
                    
                    userData.returnChoicesAddress()->erase(userData.returnChoicesAddress()->begin() + i);
                    check++;
                    }
                                // }
                }
                
            }
                
        }
            */
        check = 0;
            
            /////////////////////////////////////////////////////////////////////////////
            //check = 0;
        }
        
        //check++;
        
    }
        
                    /////////////////////////////////////////////////////////////////////////////
        /*
        for(int j=0; j<videoTags.size(); j++){
            for(int i=0; i<userData.returnChoices().size(); i++)
            {
                if(firstCheck > 1){
                    for(int k=0; k<userData.returnSimilar()[j].size(); k++){
                        
                        //printf("similar is %d |  ", userData.returnSimilar()[videoTags[j]-1][k]);
                        
                        if(userData.returnChoices()[i] == userData.returnSimilar()[videoTags[j]-1][k]){
            
                                printf("deleting %d \n", userData.returnChoices()[i]);
                                
                                userData.returnChoicesAddress()->erase(userData.returnChoicesAddress()->begin() + i);
                                
                            // }
                        }
                        
                    }
                    
                }
            }
            firstCheck++;
        }
        */
                    /////////////////////////////////////////////////////////////////////////////
        
        
    check = 0;
    videoTags.clear();
    userData.newVid=true;
    }
    
    
    
    
    else {userData.newVid=true;
        restartingLeftSwipes = false;
    }
}

void Lesson::newVideoAfterWrongWords(){
    for(int j=0; j<videoTags.size(); j++){
        for(int i=0; i<userData.returnChoicesWords().size(); i++)
        {
            if(userData.returnChoicesWords()[i] == videoTags[j])
            {
                check++;
                
                if(check > 0){
                    userData.returnChoicesWordsAddress()->erase(userData.returnChoicesWordsAddress()->begin() + i);
                }
            }
            
            //check = 0;
        }
        check = 0;
    }
    
    
    
    videoTags.clear();
    
    userData.newVid=true;
}


void Lesson::newVideoAfterRight(){
    
    
    if(userData.returnChoicesAddress()->size() < 1000){
        
        
        
        for(int i=0; i<videoTags.size()-1; i++)
        {
            for(int j=0; j<40; j++){
                userData.returnChoicesAddress()->push_back(videoTags[i]);
            }
            
        }
        
        
        for(int k = 0; k<videoTags.size(); k++){
            
            for(int z = 0; z < userData.returnSimilar()[videoTags[k]-1].size(); z++){
                userData.returnChoicesAddress()->push_back(userData.returnSimilar()[videoTags[k]-1][z]);
                userData.returnChoicesAddress()->push_back(userData.returnSimilar()[videoTags[k]-1][z]);
                userData.returnChoicesAddress()->push_back(userData.returnSimilar()[videoTags[k]-1][z]);
                userData.returnChoicesAddress()->push_back(userData.returnSimilar()[videoTags[k]-1][z]);
                //userData.returnChoicesAddress()->push_back(userData.returnSimilar()[videoTags[k]-1][z]);
                printf("pushing back %d into the choices array \n", userData.returnSimilar()[videoTags[k]-1][z]);
            }
            printf("\n \n");
            
            //userData.returnChoicesAddress()->pop_back();
            //userData.returnChoicesAddress()->pop_back();
            //userData.returnChoicesAddress()->pop_back();
            //userData.returnChoicesAddress()->pop_back();
            //userData.returnChoicesAddress()->pop_back();
        }
        
        
    }
    
    
    //////////////
    
    printf("/n the videoTags vector's size is %lu /n", videoTags.size());
    
    /*
    for(int j=0; j<videoTags.size(); j++){
        for(int i=0; i<userData.returnChoices().size(); i++)
        {
            
            if(userData.returnChoices()[i] == videoTags[j]){
            
        for(int z=0; z<userData.returnSimilar()[videoTags[j]-1].size(); z++){
            userData.returnChoicesAddress()->push_back(userData.returnSimilar()[videoTags[j]-1][z]);
            printf("\n pushing back %d into the choices array \n", userData.returnSimilar()[videoTags[j]-1][z]);
        }
                
                
    }
        }
    }
    */
    
    
    
    /*
    for(int k=0; k<videoTags.size()-1; k++){
        for(int l=0; l<userData.returnDislike()[videoTags[k]].size(); l++){
            
     
            printf("Current dislikes array, %d, is \n", videoTags[k]);
            for(int q=0; q<dislike[videoTags[k] ].size(); q++){
                printf("%d ", dislike[videoTags[k]-1][q]);
            }
            
            
            
            for(int i=0; i<userData.returnChoicesAddress()->size(); i++)
            {
                if(userData.returnChoices()[i] == userData.returnDislike()[videoTags[k]-1][l])
                {
                    //printf("videoTags[k] - 1[l] is %d \n", dislike[videoTags[k]-1][l]);
                    check ++;
                    
                    if(check == 2){
                        //printf("deleting %d \n", userData.returnChoices()[i]);
                        
                        userData.returnChoicesAddress()->erase(userData.returnChoicesAddress()->begin() + i);
                        check = 0 ;

                    }
                }
            }
            
     
            
            
            
            
            check = 0;
        }
        
    }
    */
    
    
    videoTags.clear();
    
    userData.newVid=true;
}




void Lesson::newVideoAfterRightWords(){
    
    if(userData.returnChoicesAddress()->size() < 1000){
        
        
        
        for(int i=0; i<videoTags.size()-1; i++)
        {
            for(int j=0; j<40; j++){
                userData.returnChoicesWordsAddress()->push_back(videoTags[i]);
            }
            
        }
    }
    
    videoTags.clear();
    
    userData.newVid=true;
}

void Lesson::initData(){
    userData.initDataList();
}

void Lesson::playVideo(){
    
}

void Lesson::onPlayEnds(bool ok){
    
}



void Lesson::setTouchEnabled(bool enabled){
    if (enabled){
        touchListener = EventListenerTouchOneByOne::create();
        touchListener->setSwallowTouches(true);
        
        
        
        
 
        //touchListener->onTouchBegan = [=](Touch* touch, Event* event){
        //    cocos2d::Vec2 p = touch->getLocation();
        //    cocos2d::Rect rect = sprite->getBoundingBox();
        //
        //    if(rect.containsPoint(p))
        //    {
        //        sdkbox::PluginYoutube::playVideo(yTCode, 0, true, true);
        //    }
        //
        //    sdkbox::PluginYoutube::setListener(this);
        //    //sdkbox::PluginYoutube::init();
        //
        //    return true; // if you are consuming it
        //};
        
 
        
        
        touchListener->onTouchMoved = [=](Touch* touch, Event* event){
            cocos2d::Vec2 p = touch->getLocation();
            cocos2d::Rect rect = sprite->getBoundingBox();
            
            if(rect.containsPoint(p))
            {
                sprite->setPosition(p);
            }
            
            
            return false;
        };
        
    touchListener->onTouchBegan = [=](Touch* touch, Event* event)
        {
            cocos2d::Vec2 p = touch->getLocation();
            cocos2d::Rect rect = sprite->getBoundingBox();
            
            
            
            if(rect.containsPoint(p))
            {
                sprite->setAnchorPoint(Vec2((p.x - rect.origin.x)/(rect.size.width), (p.y - rect.origin.y)/(rect.size.height)));
                sprite->setPosition(p);
                
                return true;
                
            }
            else{return false;}
            
        };
        
        touchListener->onTouchEnded = [=](Touch* touch, Event* event)
        {
            cocos2d::Vec2 p = touch->getLocation();
            cocos2d::Rect rect = sprite->getBoundingBox();
            
            if(rect.containsPoint(p)){
                
                if(rect.origin.x < (spriteOrigin.origin.x - rect.size.width/16)){
                    if(words == true){
                        newVideoAfterWrongWords();
                    }
                    
                    else{
                    newVideoAfterWrong();
                    }
                }
            
                else if(rect.origin.x > (spriteOrigin.origin.x + rect.size.width/16)){
                    if(words == true){
                        newVideoAfterRightWords();
                    }
                    
                    else {
                    newVideoAfterRight();
                    }
                }
            
                else{
                    addCount++;
                    
                    if(addCount > 4){
                    sdkbox::PluginChartboost::show(sdkbox::CB_Location_Default);
                        sdkbox::PluginSdkboxAds::playAd("Chartboost", "Default");
                        addCount = 0;
                    }
                    
                    else{
                    sdkbox::PluginYoutube::playVideo(yTCode, 0, true, true);
                    }
                }
            
            sdkbox::PluginYoutube::setListener(this);
            
            sprite->setAnchorPoint(Vec2(0,0));
            this->sprite->setPosition(pos);
                
                
            }
                
            return true;
            
        };

        Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, sprite);
        
    }
    
    
    
    else if(!enabled){
        printf("Not enabled");
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        touchListener->release();
        touchListener = nullptr;
    }
}






void Lesson::update(Layer* layer){
    sprite->setTexture(name);
    if(userData.newVid == true){
        auto blaBla = userData.getNewVideo();
        
        name = pics+blaBla.nameAndCode2[0].c_str() +".jpg";
        name2 = blaBla.nameAndCode2[0].c_str();
        yTCode = blaBla.nameAndCode2[1].c_str();
        videoTags = blaBla.videoTypes;
        
        userData.repeatCounter++;
    }
    
    if(userData.repeatCounter==2)
    {
        userData.newVid=false;
        userData.repeatCounter = 0;
        
        
        printf("The choices vector contains \n");
        for(int i=0; i<userData.returnChoicesAddress()->size(); i++){
            printf("%d ", userData.returnChoices()[i]);
        }
        
        printf("\n \n");
    }
}

void Lesson::update2(int xxx){
    auto blaBla = userData.getDataOfType(xxx);
    name = pics+blaBla.nameAndCode2[0].c_str() +".jpg";
    name2 = blaBla.nameAndCode2[0].c_str();
    yTCode = blaBla.nameAndCode2[1].c_str();
    videoTags = blaBla.videoTypes;
    sprite->setTexture(name);
}

void Lesson::resetChoices(){
    firstCheck = 0;
    restartingLeftSwipes = true;
    userData.resetingChoices();
    name = "Pictures/Absolute Value Inequality 2.jpg";
    yTCode = "WsP_sH9jOnY";
    sprite->setTexture(name);
    
    /*
    printf("The choices vector contains \n");
    for(int i=52; i<userData.returnChoicesAddress()->size(); i++){
        printf("%d ", userData.returnChoices()[i]);
    }
    
    printf("\n \n");*/
}

void Lesson::resetChoicesWords(){
    userData.resetingChoicesWords();
    name = "Pictures/Absolute Value Inequality 2.jpg";
    yTCode = "WsP_sH9jOnY";
    sprite->setTexture(name);
    
    /*
     printf("The choices vector contains \n");
     for(int i=52; i<userData.returnChoicesAddress()->size(); i++){
     printf("%d ", userData.returnChoices()[i]);
     }
     
     printf("\n \n");*/
}

void Lesson::onAdAction(const std::string& ad_unit_id,
                            const std::string& zone_location_place_you_name_it,
                            sdkbox::AdActionType action_type)
{
    std::string action;
    
    switch (action_type)
    {
        case sdkbox::AdActionType::LOADED:
            action = "LOADED";
            break;
            
        case sdkbox::AdActionType::LOAD_FAILED:
            action = "LOAD_FAILED";
            break;
            
        case sdkbox::AdActionType::CLICKED:
            action = "CLICKED";
            break;
            
        case sdkbox::AdActionType::REWARD_STARTED:
            action = "REWARD_STARTED";
            break;
            
        case sdkbox::AdActionType::REWARD_ENDED:
            action = "REWARD_ENDED";
            break;
            
        case sdkbox::AdActionType::REWARD_CANCELED:
            action = "REWARD_CANCELED";
            break;
            
        case sdkbox::AdActionType::AD_STARTED:
            action = "AD_STARTED";
            break;
            
        case sdkbox::AdActionType::AD_CANCELED:
            action = "AD_CANCELED";
            break;
            
        case sdkbox::AdActionType::AD_ENDED:
            action = "AD_ENDED";
            break;
            
        case sdkbox::AdActionType::ADACTIONTYPE_UNKNOWN:
            action = "ADACTIONTYPE_UNKNOWN";
            break;
            
        default:
            action = "null";
    }
    
    CCLOG("onAdAction, ad_unit_id: %s, zone_location_place_you_name_it: %s, action_type: %s",
          ad_unit_id.c_str(),
          zone_location_place_you_name_it.c_str(),
          action.c_str());
}

void Lesson::onRewardAction(const std::string& ad_unit_id,
                                const std::string& zone_id,
                                float reward_amount,
                                bool reward_succeed)
{
    CCLOG("onRewardAction, ad_unit_id: %s, zone_id: %s, reward_amount: %0.2f, reward_succeed: %s",
          ad_unit_id.c_str(),
          zone_id.c_str(),
          reward_amount,
          reward_succeed ? "YES" : "NO");
}






void Lesson::update3(Layer* layer){
    sprite->setTexture(name);
    if(userData.newVid == true){
        auto blaBla = userData.getNewVideo2();
        
        name = pics+blaBla.nameAndCode2[0].c_str() +".jpg";
        name2 = blaBla.nameAndCode2[0].c_str();
        yTCode = blaBla.nameAndCode2[1].c_str();
        videoTags = blaBla.videoTypes;
        
        userData.repeatCounter++;
    }
    
    if(userData.repeatCounter==2)
    {
        userData.newVid=false;
        userData.repeatCounter = 0;
        
        
        printf("The choices vector contains \n");
        for(int i=0; i<userData.returnChoicesWordsAddress()->size(); i++){
            printf("%d ", userData.returnChoicesWords()[i]);
        }
        
        printf("\n \n");
    }
}
