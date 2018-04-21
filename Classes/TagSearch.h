//
//  TagSearch.hpp
//  MyGame
//
//  Created by Isaac Raymond on 5/31/16.
//
//

#ifndef TagSearch_h
#define TagSearch_h

#include <stdio.h>

USING_NS_CC;


class TagSearch : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    void update(float) override;
    
    void launchBrowser();
    void returnToMenu2();
    void mainMenuLaunch2();
    void scrollViewMaker();
    void lessonSet(int);
    void tagsList();
    void changeVidsByTag(int x);
    void stopYoutube();
    
    CREATE_FUNC(TagSearch);
    
private:
    void initiateLessons2();
    
    
};

#endif /* TagSearch_h */
