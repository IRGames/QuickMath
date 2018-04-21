//
//  MainMenu.hpp
//  MyGame
//
//  Created by Isaac Raymond on 5/23/16.
//
//

#ifndef MainMenu_h
#define MainMenu_h

USING_NS_CC;

class MainMenu : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    void launchBrowser();
    void tagSearchLaunch();
    void wordProblemsLaunch();
    void aboutLaunch();
    
    CREATE_FUNC(MainMenu);
    
    Sprite *browser;
    Sprite *browser4;
    Sprite *browser6;
    
    void exitMenu();
};

#endif /* MainMenu_hpp */
