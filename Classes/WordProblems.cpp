//
//  WordProblems.cpp
//  QuickMath2-mobile
//
//  Created by Isaac Raymond on 11/20/17.
//

#include "WordProblems.hpp"
#include "Lesson.h"
#include "MainMenu.h"

USING_NS_CC;

Size visibleSize9;
Size tTargetSize9;

ui::Text *text9;
ui::Text *text99;

Lesson lesson9, lesson99;

Scene* WordProblems::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = WordProblems::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


bool WordProblems::init(){
    if ( !Layer::init() )
    {
        return false;
    }
    
    lesson9.initData();
    
    visibleSize9 = Director::getInstance()->getVisibleSize();
    tTargetSize9 = Size(4*visibleSize9.height/18, visibleSize9.height/6);
    
    auto background = Sprite::create("Pictures/background4.jpg");
    
    background->setPosition(Vec2(visibleSize9.width/2, visibleSize9.height/2));
    background->setScale((visibleSize9.width/background->getContentSize().width), (visibleSize9.height/background->getContentSize().height));
    background->setAnchorPoint(Vec2(0.5,0.5));
    this->addChild(background);
    
    returnToMenu9();
    initiateLessons9();
    displayText();
    stopYoutube();
    reset();
    
    this->scheduleUpdate();
    
    return true;
}






void WordProblems::update(float delta){
    lesson9.update3(this);
    lesson99.update3(this);
    
    text9->setString(lesson9.name2);
    text99->setString(lesson99.name2);
}

void WordProblems::initiateLessons9(){
    lesson9 = *new Lesson();
    lesson99 = *new Lesson();
    
    //lesson9.acceptChanges = true;
    //lesson99.acceptChanges = true;
    
    lesson9.pos = Vec2(visibleSize9.width/45, visibleSize9.height/7);
    lesson99.pos = Vec2(5*visibleSize9.width/6 - 5*visibleSize9.height/9, visibleSize9.height/7);
    
    lesson9.initiate(this, visibleSize9.width, visibleSize9.height);
    lesson99.initiate(this, visibleSize9.width, visibleSize9.height);
    
    lesson9.initData();
    
    lesson9.words = true;
    lesson99.words = true;
    
    lesson9.update(this);
    lesson99.update(this);
}





void WordProblems::displayText(){
    text9 = ui::Text::create(lesson9.name2,"fonts/arial.ttf",tTargetSize9.height/3);
    text9->setAnchorPoint(Vec2(0,0));
    text9->setPosition(Vec2(visibleSize9.width/45,visibleSize9.height/9+2*lesson9.tTargetSize.height ));
    text9->setColor(cocos2d::Color3B::BLACK);
    this->addChild(text9);
    
    text99 = ui::Text::create(lesson99.name2,"fonts/arial.ttf",tTargetSize9.height/3);
    text99->setAnchorPoint(Vec2(0,0));
    text99->setPosition(Vec2(5*visibleSize9.width/6 - 5*visibleSize9.height/9,visibleSize9.height/8 + 2*lesson99.tTargetSize.height - tTargetSize9.height/3));
    text99->setColor(cocos2d::Color3B::BLACK);
    this->addChild(text99);
    
}








void WordProblems::returnToMenu9(){
    auto browser2 = Sprite::create("Pictures/Main Menu.png");
    Size tSizeOrig2 = browser2->getContentSize();
    browser2->setScale( ( tTargetSize9.width / tSizeOrig2.width ), ( tTargetSize9.height / tSizeOrig2.height ));
    browser2->setAnchorPoint(Vec2(0, 1));
    browser2->setPosition(Vec2(0,visibleSize9.height));
    this->addChild(browser2);
    
    auto touchListener3 = EventListenerTouchOneByOne::create();
    touchListener3->setSwallowTouches(true);
    
    touchListener3->onTouchBegan = [=](Touch* touch, Event* event){
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = browser2->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            WordProblems::mainMenuLaunch9();
            
            return true;
        }
        
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(touchListener3, 30);
}




void WordProblems::mainMenuLaunch9(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    auto scene = MainMenu::createScene();
    Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene) );
}




void WordProblems::stopYoutube(){
    
    auto browser10 = Sprite::create("Pictures/aaa Stop Youtube.png");
    auto tSizeOrig10 = browser10->getContentSize();
    auto tTargetSize10 = Size(4*visibleSize9.height/18, visibleSize9.height/6);
    browser10->setScale( ( tTargetSize9.width / tSizeOrig10.width ), ( tTargetSize9.height / tSizeOrig10.height ));
    browser10->setAnchorPoint(Vec2(0.5,1));
    browser10->setPosition(Vec2(visibleSize9.width/2,visibleSize9.height));
    this->addChild(browser10);
    
    auto touchListener10 = EventListenerTouchOneByOne::create();
    touchListener10->setSwallowTouches(true);
    
    touchListener10->onTouchBegan = [=](Touch* touch, Event* event){
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = browser10->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            sdkbox::PluginYoutube::close();
        }
        
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(touchListener10, 30);
}


void WordProblems::reset(){
    auto browser99 = Sprite::create("Pictures/Reset.png");
    
    Size tSizeOrig3 = browser99->getContentSize();
    tTargetSize9 = Size(4*visibleSize9.height/18, visibleSize9.height/6);
    browser99->setScale( (tTargetSize9.width/tSizeOrig3.width ), ( tTargetSize9.height / tSizeOrig3.height ) );
    browser99->setAnchorPoint(Vec2(1,1));
    browser99->setPosition(Vec2(visibleSize9.width,visibleSize9.height));
    this->addChild(browser99);
    
    auto touchListener4 = EventListenerTouchOneByOne::create();
    touchListener4->setSwallowTouches(true);
    
    touchListener4->onTouchBegan = [=](Touch* touch, Event* event){
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = browser99->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            lesson9.resetChoicesWords();
            lesson99.resetChoicesWords();
            
            text9->setString("");
            text99->setString("");
            
            return true;
        }
        
        else {return false;}
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener4, browser99);
}
