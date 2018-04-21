//
//  MainMenu.cpp
//  MyGame
//
//  Created by Isaac Raymond on 5/23/16.
//
//
#include "PluginSdkboxAds/PluginSdkboxAds.h"
#include "MainMenu.h"
#include "HelloWorldScene.h"
#include "TagSearch.h"
#include "WordProblems.hpp"
USING_NS_CC;

Size visibleSize3;
Vec2 origin;

Scene* MainMenu::createScene()

{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenu::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}



bool MainMenu::init()
{
    //glClearColor(4.0,7.0,2.0,3.0);
    browser = Sprite::create("Pictures/browserLink.png");
    browser4 = Sprite::create("Pictures/Keyword Search.png");
    auto background = Sprite::create("Pictures/background.jpg");
    browser6 = Sprite::create("Pictures/Word Problems.png");
    
    visibleSize3 = Director::getInstance()->getVisibleSize();
    
    origin = Director::getInstance()->getVisibleOrigin();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Size tSizeOrig1 = browser->getContentSize();
    auto tTargetSize = Size(4*visibleSize.height/9, visibleSize.height/3);
    browser->setScale( ( tTargetSize.width / tSizeOrig1.width ), ( tTargetSize.height / tSizeOrig1.height ));
    browser->setPosition(Vec2(visibleSize.width/5,visibleSize.height/4));
    browser4->setScale( ( tTargetSize.width / tSizeOrig1.width ), ( tTargetSize.height / tSizeOrig1.height ));
    browser4->setPosition(Vec2(2.5*visibleSize.width/5,visibleSize.height/4));
    browser6->setScale( ( tTargetSize.width / tSizeOrig1.width ), ( tTargetSize.height / tSizeOrig1.height ));
    browser6->setPosition(Vec2(4*visibleSize.width/5,visibleSize.height/4));
    
    background->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    background->setScale((visibleSize3.width/background->getContentSize().width), (visibleSize3.height/background->getContentSize().height));
    background->setAnchorPoint(Vec2(0.5,0.5));
    
    this->addChild(background);
    this->addChild(browser);
    this->addChild(browser4);
    this->addChild(browser6);
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    auto touchListener2 = EventListenerTouchOneByOne::create();
    //touchListener2->setSwallowTouches(true);
    
    
    touchListener2->onTouchBegan = [&](Touch* touch, Event* event){
        
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = browser->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            MainMenu::launchBrowser();
        }
        
        return true;
    };
    
    
    auto touchListener5 = EventListenerTouchOneByOne::create();
    //touchListener5->setSwallowTouches(true);
    
    
    touchListener5->onTouchBegan = [&](Touch* touch, Event* event){
        
        cocos2d::Vec2 p2 = touch->getLocation();
        cocos2d::Rect rect2 = browser4->getBoundingBox();
        
        if(rect2.containsPoint(p2))
        {
            MainMenu::tagSearchLaunch();
        }
        
        return true;
    };
    
    auto touchListener6 = EventListenerTouchOneByOne::create();
    touchListener6->setSwallowTouches(true);
    
    touchListener6->onTouchBegan = [&](Touch* touch, Event* event){
        
        cocos2d::Vec2 p3 = touch->getLocation();
        cocos2d::Rect rect3 = browser6->getBoundingBox();
        
        if(rect3.containsPoint(p3))
        {
            MainMenu::wordProblemsLaunch();
        }
        
        return true;
    };
    
    exitMenu();
    
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(touchListener2, 31);
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(touchListener5, 31);
    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(touchListener6, 31);
    
    
    return true;
}

void MainMenu::launchBrowser(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    
    auto scene = HelloWorld::createScene();
    
    Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene));
}

void MainMenu::tagSearchLaunch(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    
    auto scene = TagSearch::createScene();
    
    Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene));
}

void MainMenu::wordProblemsLaunch(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    
    auto scene = WordProblems::createScene();
    
    Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene));
}

void MainMenu::aboutLaunch(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    
    auto scene = WordProblems::createScene();
    
    Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene));
}

void MainMenu::exitMenu(){
    Vector<MenuItem*> MenuItems;
    
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(MainMenu::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize3.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    MenuItems.pushBack(closeItem);
    
    closeItem->setPosition(Vec2(origin.x + visibleSize3.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    
    auto menu = Menu::createWithArray(MenuItems);
    menu->setPosition(Vec2(origin.x, origin.y));
    this->addChild(menu, 1);
}

void MainMenu::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
