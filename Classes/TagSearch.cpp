//
//  TagSearch.cpp
//  MyGame
//
//  Created by Isaac Raymond on 5/31/16.
//
//

#include "TagSearch.h"
#include "Lesson.h"
#include "MainMenu.h"

USING_NS_CC;

Lesson lesson11, lesson22;
Size visibleSize1;
Size tTargetSize22;
std::vector<std::string> tags;
Sprite* browser2;

Scene* TagSearch::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TagSearch::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool TagSearch::init(){
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize1 = Director::getInstance()->getVisibleSize();
    tTargetSize22 = Size(4*visibleSize1.height/18, visibleSize1.height/6);
    
    auto background = Sprite::create("Pictures/background3.jpg");
    background->setPosition(Vec2(visibleSize1.width/2, visibleSize1.height/2));
    background->setScale((visibleSize1.width/background->getContentSize().width), (visibleSize1.height/background->getContentSize().height));
    background->setAnchorPoint(Vec2(0.5,0.5));
    this->addChild(background);
    
    
    
    lesson11.initData();
    tagsList();
    initiateLessons2();
    returnToMenu2();
    scrollViewMaker();
    stopYoutube();
    
    
    
    this->scheduleUpdate();
    
    return true;
}

void TagSearch::update(float delta){
    lesson11.update(this);
    lesson22.update(this);
}

void TagSearch::launchBrowser(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    auto scene = TagSearch::createScene();
    Director::getInstance()->replaceScene(scene);
}

void TagSearch::initiateLessons2(){
    lesson11 = *new Lesson();
    lesson22 = *new Lesson();
    
    lesson11.acceptChanges = true;
    lesson22.acceptChanges = true;
    
    lesson11.pos = Vec2(0, visibleSize1.height/9);
    lesson22.pos = Vec2(5*visibleSize1.width/6 - visibleSize1.height/3, visibleSize1.height/9);
    
    lesson11.initiate(this, visibleSize1.width, visibleSize1.height);
    lesson22.initiate(this, visibleSize1.width, visibleSize1.height);
    
    lesson11.initData();
    
    lesson11.update(this);
    lesson22.update(this);
}

void TagSearch::returnToMenu2(){
    browser2 = Sprite::create("Pictures/Main Menu.png");
    Size tSizeOrig2 = browser2->getContentSize();
    browser2->setScale( ( tTargetSize22.width / tSizeOrig2.width ), ( tTargetSize22.height / tSizeOrig2.height ));
    browser2->setAnchorPoint(Vec2(0, 1));
    browser2->setPosition(Vec2(0,visibleSize1.height));
    this->addChild(browser2);
    
    auto touchListener3 = EventListenerTouchOneByOne::create();
    touchListener3->setSwallowTouches(true);
    
    touchListener3->onTouchBegan = [=](Touch* touch, Event* event){
        cocos2d::Vec2 p = touch->getLocation();
        cocos2d::Rect rect = browser2->getBoundingBox();
        
        if(rect.containsPoint(p))
        {
            TagSearch::mainMenuLaunch2();
            
            return true;
        }
        
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(touchListener3, 30);
}

void TagSearch::mainMenuLaunch2(){
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    auto scene = MainMenu::createScene();
    Director::getInstance()->replaceScene(TransitionSlideInT::create(1, scene) );
}

void TagSearch::scrollViewMaker(){
    int _fontSize = tTargetSize22.height/3;
    
    MenuItemFont::setFontSize(_fontSize);
    
    
    // set the text color for the menu
    //menuCenter->setColor(Color3B(4.0f, 2.0f, 2.0f));
    
    Size scrollFrameSize = Size(1.2f*lesson11.tTargetSize.width, lesson11.tTargetSize.height*2);
    
    Vector<MenuItem*> menuItems;
    
    for(int i=0; i<45; i++){
        auto currentItem = MenuItemFont::create(tags.at(i),[=](Ref* sender){changeVidsByTag(i);});
        currentItem->setColor(cocos2d::Color3B::BLACK);
        currentItem->setPosition(0, scrollFrameSize.height*3.5 - 1.2*i*_fontSize - _fontSize/2);
        menuItems.pushBack(currentItem);
    }
    
    auto menuCenter = Menu::createWithArray(menuItems);
    
    auto scrollView = cocos2d::ui::ScrollView::create();
    scrollView->setBackGroundColorType(cocos2d::ui::ScrollView::BackGroundColorType::SOLID);
    scrollView->setBackGroundColor(cocos2d::Color3B::WHITE);
    scrollView->setBackGroundColorOpacity(250);
    scrollView->setSize(scrollFrameSize);
    scrollView->setAnchorPoint(Vec2(0.5, 0.5));
    scrollView->setPosition(Vec2(visibleSize1.width/2, visibleSize1.height/2));
    scrollView->setDirection(cocos2d::ui::SCROLLVIEW_DIR_VERTICAL);
    
    auto containerSize = Size(scrollFrameSize.width, scrollFrameSize.height*4);
    scrollView->setInnerContainerSize(containerSize);
    
    scrollView->setLayoutType(cocos2d::ui::LAYOUT_LINEAR_VERTICAL);
    menuCenter->setPosition(Vec2(scrollFrameSize.width/2, scrollFrameSize.height/2));
    
    scrollView->addChild(menuCenter);
    addChild(scrollView);
}

void TagSearch::tagsList(){
    tags.push_back("Word Problems");
    tags.push_back("Graphing");
    tags.push_back("Linear");
    tags.push_back("Quadratic");
    tags.push_back("Factoring Trinomials");
    tags.push_back("Factoring Expressions");
    tags.push_back("Rational Equations");
    tags.push_back("Matrices");
    tags.push_back("Exponential Equations");
    tags.push_back("Piecewise");
    tags.push_back("Solving Inequalities");
    tags.push_back("Slope Intercept Form");
    tags.push_back("Slope");
    tags.push_back("Creating Equations");
    tags.push_back("Radicals");
    tags.push_back("System of Equations");
    tags.push_back("Fractions");
    tags.push_back("Vertex");
    tags.push_back("Asymptote");
    tags.push_back("Rationalize Denominator");
    tags.push_back("Simplify");
    tags.push_back("Parallel Perpendicular");
    tags.push_back("Absolute Value");
    tags.push_back("Compound Inequality");
    tags.push_back("Exponents");
    tags.push_back("Parenthesis");
    tags.push_back("Inverse");
    tags.push_back("Rearrange");
    tags.push_back("Geometry");
    tags.push_back("Intercepts");
    tags.push_back("Points");
    tags.push_back("Data");
    tags.push_back("Graphing Inequalities");
    tags.push_back("Graphing Systems of Equations");
    tags.push_back("Three Variable System");
    tags.push_back("Negatives");
    tags.push_back("Circle");
    tags.push_back("Triangle");
    tags.push_back("Binomial");
    tags.push_back("Divide");
    tags.push_back("Cubic");
    tags.push_back("Polynomials");
    tags.push_back("Complicated Fractions");
    tags.push_back("Imaginary");
    tags.push_back("Domain/Range");
    tags.push_back("Function");
    tags.push_back("Logarithm");
    tags.push_back("Trigonometry");
    tags.push_back("Interest");
    tags.push_back("Summation Operator");
    tags.push_back("Sequences");
    tags.push_back("Permutation/Combination");
}

void TagSearch::changeVidsByTag(int x){
    lesson11.update2(x);
    lesson22.update2(x);
}


void TagSearch::stopYoutube(){
    
    auto browser10 = Sprite::create("Pictures/aaa Stop Youtube.png");
    auto tSizeOrig10 = browser10->getContentSize();
    auto tTargetSize10 = Size(4*visibleSize1.height/18, visibleSize1.height/6);
    browser10->setScale( ( tTargetSize10.width / tSizeOrig10.width ), ( tTargetSize10.height / tSizeOrig10.height ));
    browser10->setAnchorPoint(Vec2(0.5,1));
    browser10->setPosition(Vec2(visibleSize1.width/2,visibleSize1.height));
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
