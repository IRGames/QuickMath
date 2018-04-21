//
//  Request.hpp
//  QuickMath2
//
//  Created by Isaac Raymond on 5/17/17.
//
//

#ifndef Request_h
#define Request_h

#include <stdio.h>

class Request : public cocos2d::Layer{
public:
    CREATE_FUNC(Request);
    
    void returnToMenu3();
    
    virtual bool init() override;
    
    static cocos2d::Scene* createScene();
    
private:
    cocos2d::Size visibleSize11;
    cocos2d::Vec2 origin11;
    
    void mainMenuLaunch();
};

#endif /* Request_hpp */
