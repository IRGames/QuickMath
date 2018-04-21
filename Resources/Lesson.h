//

//  Lesson.hpp

//  MyGame

//

//  Created by Isaac Raymond on 12/25/15.

//

//



#ifndef Lesson_h
#define Lesson_h

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "PluginYoutube/PluginYoutube.h"

USING_NS_CC;

class Lesson : public sdkbox::YoutubeListener
{
public:
    struct videoInfo2{
        std::vector<std::string> nameAndCode3;
        std::vector<int> videoTypes2;
    } vidInfo2;
    
    void update(cocos2d::Layer* layer);
    void update2(int x);
    Lesson();
    void initiate(cocos2d::Layer* layer, int x, int y);
    void newVideoAfterWrong();
    void newVideoAfterRight();
    void newVideoAfterNeither();

    cocos2d::Vec2 pos;
    std::string name;
    std::string name2;
    std::string yTCode;
    Sprite *sprite;
    
    cocos2d::ui::Button *buttonWrong;
    cocos2d::ui::Button *buttonRight;
    cocos2d::ui::ScrollView *scrollView;
    
    void testBla();
    void initData();
    void playVideo();
    void setTouchEnabled(bool enabled);
    
    Size tTargetSize;
    Size tTargetSizeDialogue;
    Size tSizeOrigButton;
    Size tTargetSizeButton;

    std::vector<int> videoTags;
    
    EventListenerTouchOneByOne* touchListener;

    // youtube listener
    void onPlayEnds( bool ok );
    void update(float) ;
};

#endif /* Lesson_hpp */