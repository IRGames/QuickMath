#ifndef __HELLOWORLD_SCENE_H__

#define __HELLOWORLD_SCENE_H__



#include "cocos2d.h"
#include "PluginYoutube/PluginYoutube.h"
#include "PluginSdkboxAds/PluginSdkboxAds.h"
#include "Lesson.h"



class HelloWorld : public cocos2d::Layer, public sdkbox::PluginSdkboxAdsListener, sdkbox::YoutubeListener

{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init() override;
    
    // a selector callback
    
    void update(cocos2d::Layer);
    void mainMenuLaunch();

    
    
    
    
    Sprite *browser2;
    Sprite *browser3;
    Sprite *browser4;
    Sprite *browser5;
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    // youtube listener
    void onPlayEnds( bool ok );
    void update(float) override;
    void toMenu();
    void displayText();
    void returnToMenu();
    void reset();
    void reportAProblem();
    void requestAVideo();
    
    void stopYoutube();
    
private:
    void initiateLessons();
    void onAdAction(const std::string& ad_unit_id,
                    const std::string& zone_location_place_you_name_it,
                    sdkbox::AdActionType action_type);
    
    void onRewardAction(const std::string& ad_unit_id,
                        const std::string& zone_id,
                        float reward_amount,
                        bool reward_succeed);
};

#endif // __HELLOWORLD_SCENE_H__
