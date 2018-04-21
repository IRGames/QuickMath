#include "HelloWorldScene.h"
#include "MainMenu.h"
#include "Lesson.h"
#include "Problem.h"
#include "Request.h"
#include "PluginSdkboxAds/PluginSdkboxAds.h"
#include "PluginChartboost/PluginChartboost.h"

USING_NS_CC;

Lesson lesson1, lesson2, lesson3, lesson4;
Size visibleSize;
Size tTargetSize;
ui::Text *text1;
ui::Text *text2;
Size tSizeOrig2;

Scene* HelloWorld::createScene()

{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    visibleSize = Director::getInstance()->getVisibleSize();
    
    
    auto background = Sprite::create("Pictures/background2.jpg");
    background->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    background->setScale((visibleSize.width/background->getContentSize().width), (visibleSize.height/background->getContentSize().height));
    background->setAnchorPoint(Vec2(0.5,0.5));
    this->addChild(background);
    
    initiateLessons();
    returnToMenu();
    //reportAProblem();
    //requestAVideo();
    displayText();
    reset();
    stopYoutube();
    
    
    //sdkbox::PluginSdkboxAds::playAd();
    //sdkbox::PluginSdkboxAds::setListener(this);
    //sdkbox::PluginSdkboxAds::playAd("Chartboost", "Default");
    
    this->scheduleUpdate();
        
    return true;
}



void HelloWorld::update(float delta){
    
    lesson1.update(this);
    lesson2.update(this);
    
    text1->setString(lesson1.name2);
    text2->setString(lesson2.name2);
}

void HelloWorld::onPlayEnds( bool ok )
{
    CCLOG("Youtube play video: %s ", ok ? "ok" : "error");
    printf("\n \n /n /n bla BLA BLA bla BLA BLA BLA BLA");
}

void HelloWorld::mainMenuLaunch(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    auto scene = MainMenu::createScene();
    Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene));
}

void HelloWorld::displayText(){
    text1 = ui::Text::create(lesson1.name2,"fonts/arial.ttf",tTargetSize.height/3);
    text1->setAnchorPoint(Vec2(0,0));
    text1->setPosition(Vec2(visibleSize.width/45,visibleSize.height/8+2*lesson1.tTargetSize.height ));
    this->addChild(text1);
    
    text2 = ui::Text::create(lesson2.name2,"fonts/arial.ttf",tTargetSize.height/3);
    text2->setAnchorPoint(Vec2(0,0));
    text2->setPosition(Vec2(5*visibleSize.width/6 - 5*visibleSize.height/9,visibleSize.height/8 + 2*lesson1.tTargetSize.height - tTargetSize.height/3));
    this->addChild(text2);
    
}

void HelloWorld::initiateLessons(){
    lesson1 = *new Lesson();
    lesson2 = *new Lesson();
    
    lesson1.pos = Vec2(visibleSize.width/45, visibleSize.height/7);
    lesson2.pos = Vec2(5*visibleSize.width/6 - 5*visibleSize.height/9, visibleSize.height/7);
    
    lesson1.initiate(this, visibleSize.width, visibleSize.height);
    lesson2.initiate(this, visibleSize.width, visibleSize.height);
    
    lesson1.initData();
    
    lesson1.update(this);
    lesson2.update(this);
}




void HelloWorld::requestAVideo(){
    browser5 = Sprite::create("Pictures/RequestAVideo.png");
    browser5->setScale( ( tTargetSize.width / tSizeOrig2.width ), ( tTargetSize.height / tSizeOrig2.height ));
    browser5->setAnchorPoint(Vec2(0.5, 1));
    browser5->setPosition(Vec2(3*visibleSize.width/4, visibleSize.height));
    this->addChild(browser5);
    
    auto touchListener6 = EventListenerTouchOneByOne::create();
    touchListener6->setSwallowTouches(true);
    
    touchListener6->onTouchBegan = [=](Touch* touch, Event* event){
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = browser5->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
            auto scene = Request::createScene();
            Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene));
            
            return true;
        }
        
        else{return false;}
        
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener6, browser5);
}

void HelloWorld::reportAProblem(){
    browser4 = Sprite::create("Pictures/ReportAProblem.png");
    Size tSizeOrig5 = browser4->getContentSize();
    tTargetSize = Size(4*visibleSize.height/18, visibleSize.height/6);

    browser4->setScale( ( tTargetSize.width / tSizeOrig5.width ), ( tTargetSize.height / tSizeOrig5.height ));
    browser4->setAnchorPoint(Vec2(0.5, 1));
    browser4->setPosition(Vec2(visibleSize.width/4, visibleSize.height));
    
    this->addChild(browser4);
    
    auto touchListener5 = EventListenerTouchOneByOne::create();
    touchListener5->setSwallowTouches(true);
    
    touchListener5->onTouchBegan = [=](Touch* touch, Event* event){
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = browser4->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            
            Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
            auto scene = Problem::createScene();
            Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene));

            return true;
        }
        
        else {return false;}
        
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener5, browser4);
}

void HelloWorld::reset(){
    browser3 = Sprite::create("Pictures/Reset.png");
    Size tSizeOrig3 = browser3->getContentSize();
    tTargetSize = Size(4*visibleSize.height/18, visibleSize.height/6);
    browser3->setScale( (tTargetSize.width/tSizeOrig3.width ), ( tTargetSize.height / tSizeOrig3.height ) );
    browser3->setAnchorPoint(Vec2(1,1));
    browser3->setPosition(Vec2(visibleSize.width,visibleSize.height));
    this->addChild(browser3);
    
    auto touchListener4 = EventListenerTouchOneByOne::create();
    touchListener4->setSwallowTouches(true);
    
    touchListener4->onTouchBegan = [=](Touch* touch, Event* event){
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = browser3->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            lesson1.resetChoices();
            lesson2.resetChoices();
            
            text1->setString("");
            text2->setString("");
            
            return true;
        }
        
        else {return false;}
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener4, browser3);
}

void HelloWorld::returnToMenu(){
    
    browser2 = Sprite::create("Pictures/Main Menu.png");
    tSizeOrig2 = browser2->getContentSize();
    tTargetSize = Size(4*visibleSize.height/18, visibleSize.height/6);
    browser2->setScale( ( tTargetSize.width / tSizeOrig2.width ), ( tTargetSize.height / tSizeOrig2.height ));
    browser2->setAnchorPoint(Vec2(0,1));
    browser2->setPosition(Vec2(0,visibleSize.height));
    this->addChild(browser2);
    
    auto touchListener3 = EventListenerTouchOneByOne::create();
    touchListener3->setSwallowTouches(true);
    
    touchListener3->onTouchBegan = [=](Touch* touch, Event* event){
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = browser2->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            HelloWorld::mainMenuLaunch();
            
            return true;
        }
        
        else {return false;}
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(touchListener3, 30);
}


void HelloWorld::stopYoutube(){
    
    auto browser10 = Sprite::create("Pictures/aaa Stop Youtube.png");
    auto tSizeOrig10 = browser10->getContentSize();
    auto tTargetSize10 = Size(4*visibleSize.height/18, visibleSize.height/6);
    browser10->setScale( ( tTargetSize.width / tSizeOrig10.width ), ( tTargetSize.height / tSizeOrig10.height ));
    browser10->setAnchorPoint(Vec2(0.5,1));
    browser10->setPosition(Vec2(visibleSize.width/2,visibleSize.height));
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


void HelloWorld::onAdAction(const std::string& ad_unit_id,
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

void HelloWorld::onRewardAction(const std::string& ad_unit_id,
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

