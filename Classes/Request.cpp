//
//  Request.cpp
//  QuickMath2
//
//  Created by Isaac Raymond on 5/17/17.
//
//

#include "Request.h"
#include "HelloWorldScene.h"
#include "MainMenu.h"
USING_NS_CC;

Scene* Request::createScene()

{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Request::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool Request::init(){
    visibleSize11 = Director::getInstance()->getVisibleSize();
    origin11 = Director::getInstance()->getVisibleOrigin();
    auto background = Sprite::create("Pictures/background3.jpg");
    
    background->setPosition(Vec2(visibleSize11.width/2, visibleSize11.height/2));
    background->setScale((visibleSize11.width/background->getContentSize().width), (visibleSize11.height/background->getContentSize().height));
    background->setAnchorPoint(Vec2(0.5,0.5));
    
    this->addChild(background);
    
    returnToMenu3();
    
    return true;
}


void Request::returnToMenu3(){
    
    auto browser2 = Sprite::create("Pictures/Main Menu.png");
    auto tSizeOrig2 = browser2->getContentSize();
    auto tTargetSize = Size(4*visibleSize11.height/18, visibleSize11.height/6);
    browser2->setScale( ( tTargetSize.width / tSizeOrig2.width ), ( tTargetSize.height / tSizeOrig2.height ));
    browser2->setAnchorPoint(Vec2(0,1));
    browser2->setPosition(Vec2(0,visibleSize11.height));
    this->addChild(browser2);
    
    auto touchListener3 = EventListenerTouchOneByOne::create();
    touchListener3->setSwallowTouches(true);
    
    touchListener3->onTouchBegan = [=](Touch* touch, Event* event){
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = browser2->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            Request::mainMenuLaunch();
        }
        
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority (touchListener3, browser2);
}

void Request::mainMenuLaunch(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    auto scene = MainMenu::createScene();
    Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene));
    
}