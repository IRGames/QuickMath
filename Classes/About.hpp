//
//  About.hpp
//  QuickMath2-mobile
//
//  Created by Isaac Raymond on 11/29/17.
//

#ifndef About_hpp
#define About_hpp

#include <stdio.h>

USING_NS_CC;

class About : public cocos2d::Layer{
    public:
    
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    void update(float) override;
    
    void mainMenuLaunch10();
    void returnToMenu10();
  
    CREATE_FUNC(About);
};

#endif /* About_hpp */
