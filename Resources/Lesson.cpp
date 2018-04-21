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
//#include <CCEventDispatcher.h>

USING_NS_CC;

bool found;
int check;
//int type;
int currentType;
std::string pics;
UserData userData;

std::vector<std::string> response;
std::vector<int> response2;



Lesson::Lesson(){
    name = "Pictures/Rational Zeros Theorem 1.jpg";
}

void Lesson::initiate(Layer* layer, int x, int y){
    sprite = Sprite::create(name);
    found = false;
    pics = "Pictures/";
    yTCode = "jzltsSO0ejw";
    response.resize(2);
    videoTags.resize(1);
    
    //Setting dimensions to conform to all ios devices
    tTargetSize = Size(4*y/9, y/3);
    Size tSizeOrig1 = sprite->getContentSize();
    
    //Drawing and adding the lesson's picture
    sprite->setScale( ( tTargetSize.width / tSizeOrig1.width ), ( tTargetSize.height / tSizeOrig1.height ));
    sprite->setAnchorPoint(Vec2(0,0));
    sprite->setPosition(pos);
    layer->addChild(sprite);
    
    //Creating buttons/scrollviews
    buttonWrong = cocos2d::ui::Button::create("Pictures/CloseKey.png", "Pictures/CloseKey2.png");
    buttonRight = cocos2d::ui::Button::create("Pictures/CheckKey1.png", "Pictures/CheckKey2.png");
    
    buttonWrong->setAnchorPoint(Vec2(0, 1));
    buttonRight->setAnchorPoint(Vec2(0, 1));
    
    tSizeOrigButton = buttonWrong->getContentSize();
    tTargetSizeButton = Size(1.5*x/30, 1.5*x/30);
    
    buttonWrong->setScale( (tTargetSizeButton.width / tSizeOrigButton.width), (tTargetSizeButton.height / tSizeOrigButton.height));
    buttonRight->setScale( (tTargetSizeButton.width / tSizeOrigButton.width), (tTargetSizeButton.height / tSizeOrigButton.height));
    
    buttonWrong->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
        
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                newVideoAfterWrong();
                break;
            default:
                break;
        }
    });
    
    buttonRight->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType bype){
        switch(bype)
        {
            case ui::Widget::TouchEventType::BEGAN:
                break;
            case ui::Widget::TouchEventType::ENDED:
                newVideoAfterRight();
                break;
            default:
                break;
        }
    });
    
    setTouchEnabled(true);
    
    layer->addChild(buttonWrong);
    layer->addChild(buttonRight);
    
}

void Lesson::newVideoAfterWrong(){
    check = 0;
 
    for(int j=0; j<videoTags.size(); j++){
     for(int i=0; i<userData.returnChoices().size(); i++)
        {
            if(userData.returnChoices()[i] == videoTags[j])
            {
                check ++;
            }
     
            if(check == 2){
                userData.returnChoicesAddress()->erase(userData.returnChoicesAddress()->begin() + i);
                check = 0 ;
            }
            if(check == 3){
                userData.returnChoicesAddress()->erase(userData.returnChoicesAddress()->begin() + i);
                check = 0 ;
            }
            if(check == 4){
                userData.returnChoicesAddress()->erase(userData.returnChoicesAddress()->begin() + i);
                check = 0 ;
            }
            if(check == 5){
                userData.returnChoicesAddress()->erase(userData.returnChoicesAddress()->begin() + i);
                check = 0 ;
            }
            if(check == 6){
                userData.returnChoicesAddress()->erase(userData.returnChoicesAddress()->begin() + i);
                check = 0 ;
            }
            if(check == 7){
                userData.returnChoicesAddress()->erase(userData.returnChoicesAddress()->begin() + i);
                check = 0 ;
            }
            if(check == 8){
                userData.returnChoicesAddress()->erase(userData.returnChoicesAddress()->begin() + i);
                check = 0 ;
            }
            if(check == 9){
                userData.returnChoicesAddress()->erase(userData.returnChoicesAddress()->begin() + i);
                check = 0 ;
            }
            if(check == 10){
                userData.returnChoicesAddress()->erase(userData.returnChoicesAddress()->begin() + i);
                check = 0 ;
            }
        }
        check = 0;
    }
    
    videoTags.clear();
    
    userData.newVid=true;
}

void Lesson::newVideoAfterRight(){
    if(userData.returnChoicesAddress()->size() < 500){
    
        for(int i=0; i<videoTags.size()-1; i++)
        {
            for(int j=0; j<40; j++){
            userData.returnChoicesAddress()->push_back(videoTags[i]);
            }
        }
    }
    
    videoTags.clear();
    
    userData.newVid=true;
}

void Lesson::newVideoAfterNeither(){
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
        //touchListener->setSwallowTouches(true);
        
        touchListener->onTouchBegan = [=](Touch* touch, Event* event){
            cocos2d::Vec2 p = touch->getLocation();
            cocos2d::Rect rect = sprite->getBoundingBox();
            
            if(rect.containsPoint(p))
            {
                sdkbox::PluginYoutube::playVideo(yTCode, 0, true, true);
            }
            
            sdkbox::PluginYoutube::setListener(this);
            sdkbox::PluginYoutube::init();
            
            return true; // if you are consuming it
        };
        
        Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(touchListener, 30);
    }
    
    else if(!enabled){
        Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
        //Director::getInstance()->getEventDispatcher()->removeEventListener(touchListener);
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
        
        /*
        printf("videoTags (from update)is: \n");
        for(int i=0; i<videoTags.size(); i++){
            printf("%d ", videoTags[i]);
        }
        printf("\n \n");
         */
        
        userData.repeatCounter++;
    }
    
    if(userData.repeatCounter==4)
    {userData.newVid=false;
        userData.repeatCounter = 0;}
}

void Lesson::update2(int xxx){
    printf("xxx is %d \n \n \n \n", xxx);
    auto blaBla = userData.getDataOfType(xxx);
    name = pics+blaBla.nameAndCode2[0].c_str() +".jpg";
    name2 = blaBla.nameAndCode2[0].c_str();
    yTCode = blaBla.nameAndCode2[1].c_str();
    videoTags = blaBla.videoTypes;
    sprite->setTexture(name);
}