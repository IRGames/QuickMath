//
//  Problem.hpp
//  QuickMath2
//
//  Created by Isaac Raymond on 5/17/17.
//
//

#ifndef Problem_h
#define Problem_h

#include <stdio.h>

class Problem : public cocos2d::Layer{
public:
    CREATE_FUNC(Problem);

    static cocos2d::Scene* createScene();
    
    virtual bool init() override;
    
    void mainMenuLaunch2();
    void returnToMenu2();
    void addTextInputField();
    
private:
    cocos2d::Size visibleSize9;
    cocos2d::Vec2 origin9;
    

};

#endif /* Problem_hpp */
