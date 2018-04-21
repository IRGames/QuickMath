//
//  WordProblems.hpp
//  QuickMath2-mobile
//
//  Created by Isaac Raymond on 11/20/17.
//

#ifndef WordProblems_hpp
#define WordProblems_hpp

#include <stdio.h>

class WordProblems : public cocos2d::Layer{
public:
    static cocos2d::Scene* createScene();
    virtual bool init() override;
    void update(float) override;
    
    void mainMenuLaunch9();
    void returnToMenu9();
    void initiateLessons9();
    void displayText();
    void stopYoutube();
    void reset();
    
    
    CREATE_FUNC(WordProblems);
    
};
#endif /* WordProblems_hpp */
