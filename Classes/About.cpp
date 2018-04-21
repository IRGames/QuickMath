//
//  About.cpp
//  QuickMath2-mobile
//
//  Created by Isaac Raymond on 11/29/17.
//

#include "About.hpp"
#include "MainMenu.h"

USING_NS_CC;

Size visibleSize10;
Size tTargetSize10;
Sprite* browser10;

Scene* About::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = About::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool About::init(){
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize10 = Director::getInstance()->getVisibleSize();
    tTargetSize10 = Size(4*visibleSize10.height/18, visibleSize10.height/6);
    
    auto background = Sprite::create("Pictures/background3.jpg");
    background->setPosition(Vec2(visibleSize10.width/2, visibleSize10.height/2));
    background->setScale((visibleSize10.width/background->getContentSize().width), (visibleSize10.height/background->getContentSize().height));
    background->setAnchorPoint(Vec2(0.5,0.5));
    this->addChild(background);
    
    this->scheduleUpdate();
    
    return true;
}

void About::update(float delta){

}

void About::returnToMenu10(){
    auto browser10 = Sprite::create("Pictures/Main Menu.png");
    Size tSizeOrig10 = browser10->getContentSize();
    browser10->setScale( ( tTargetSize10.width / tSizeOrig10.width ), ( tTargetSize10.height / tSizeOrig10.height ));
    browser10->setAnchorPoint(Vec2(0, 1));
    browser10->setPosition(Vec2(0,visibleSize10.height));
    this->addChild(browser10);
    
    auto touchListener10 = EventListenerTouchOneByOne::create();
    touchListener10->setSwallowTouches(true);
    
    touchListener10->onTouchBegan = [=](Touch* touch, Event* event){
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = browser10->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            About::mainMenuLaunch10();
            
            return true;
        }
        
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(touchListener10, 30);
}

void About::mainMenuLaunch10(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    auto scene = MainMenu::createScene();
    Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene) );
}




