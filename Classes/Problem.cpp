//
//  Problem.cpp
//  QuickMath2
//
//  Created by Isaac Raymond on 5/17/17.
//
//

#include "Problem.h"
#include "HelloWorldScene.h"
#include "MainMenu.h"
#include "ui/CocosGUI.h"

USING_NS_CC;



Scene* Problem::createScene()

{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Problem::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


bool Problem::init(){
    visibleSize9 = Director::getInstance()->getVisibleSize();
    origin9 = Director::getInstance()->getVisibleOrigin();
    auto background = Sprite::create("Pictures/background3.jpg");

    background->setPosition(Vec2(visibleSize9.width/2, visibleSize9.height/2));
    background->setScale((visibleSize9.width/background->getContentSize().width), (visibleSize9.height/background->getContentSize().height));
    background->setAnchorPoint(Vec2(0.5,0.5));
    
    this->addChild(background);
    
    returnToMenu2();
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    addTextInputField();
    
    
    
    return true;
}

void Problem::returnToMenu2(){
    
    auto browser10 = Sprite::create("Pictures/Main Menu.png");
    auto tSizeOrig10 = browser10->getContentSize();
    auto tTargetSize10 = Size(4*visibleSize9.height/18, visibleSize9.height/6);
    browser10->setScale( ( tTargetSize10.width / tSizeOrig10.width ), ( tTargetSize10.height / tSizeOrig10.height ));
    browser10->setAnchorPoint(Vec2(0,1));
    browser10->setPosition(Vec2(0,visibleSize9.height));
    this->addChild(browser10);
    
    auto touchListener10 = EventListenerTouchOneByOne::create();
    touchListener10->setSwallowTouches(true);
    
    touchListener10->onTouchBegan = [=](Touch* touch, Event* event){
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = browser10->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            Problem::mainMenuLaunch2();
        }
        
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener10, browser10);
}

void Problem::mainMenuLaunch2(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    auto scene = MainMenu::createScene();
    Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene));
    
}

void Problem::addTextInputField(){
    auto textField = cocos2d::ui::TextField::create("Fill in details about your error here","Arial",20);
    
    textField->ignoreContentAdaptWithSize(false);
    textField->setContentSize(Size(240, 160));
    textField->setMaxLength(200);
    textField->setPosition(Vec2(visibleSize9.width / 2, visibleSize9.height / 2));
    
    textField->addTouchEventListener([&](Ref* sender, cocos2d::ui::Widget::TouchEventType type){
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                Director::getInstance()->getOpenGLView()->setIMEKeyboardState(true);

                break;
            case ui::Widget::TouchEventType::ENDED:
               // Director().getOpenGLView()->setIMEKeyboardState(true);
                break;
            default:
                break;
        }
        
        printf("editing a TextField");
    });
    
    this->addChild(textField);
}