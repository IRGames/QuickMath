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
#include "PluginChartboost/PluginChartboost.h"
#include "PluginSdkboxAds/PluginSdkboxAds.h"

USING_NS_CC;

class Lesson : public sdkbox::PluginSdkboxAdsListener, public sdkbox::YoutubeListener
{
public:
    struct videoInfo2{
        std::vector<std::string> nameAndCode3;
        std::vector<int> videoTypes2;
    } vidInfo2;
    
    void update(cocos2d::Layer* layer);
    void update2(int x);
    void update3(cocos2d::Layer* layer);
    Lesson();
    void initiate(cocos2d::Layer* layer, int x, int y);
    void newVideoAfterWrong();
    void newVideoAfterWrongWords();
    void newVideoAfterRight();
    void newVideoAfterRightWords();
    
    cocos2d::Vec2 pos;
    std::string name;
    std::string name2;
    std::string yTCode;
    
    cocos2d::ui::Button *buttonWrong;
    cocos2d::ui::Button *buttonRight;
    cocos2d::ui::ScrollView *scrollView;
    
    void testBla();
    void initData();
    void playVideo();
    void setTouchEnabled(bool enabled);
    void resetChoices();
    void resetChoicesWords();
    
    Size tTargetSize;
    Size tTargetSizeDialogue;
    Size tSizeOrigButton;
    Size tTargetSizeButton;
    
    std::vector<int> videoTags;
    
    bool words;
    
    // youtube listener
    void onPlayEnds( bool ok );
    void update(float) ;
    
        Sprite *sprite, *sprite2;
        cocos2d::Rect spriteOrigin;
        EventListenerTouchOneByOne* touchListener;
    
    bool acceptChanges;
    
private:
    void onAdAction(const std::string& ad_unit_id,
                    const std::string& zone_location_place_you_name_it,
                    sdkbox::AdActionType action_type);
    
    void onRewardAction(const std::string& ad_unit_id,
                        const std::string& zone_id,
                        float reward_amount,
                        bool reward_succeed);
};

#endif /* Lesson_hpp */
