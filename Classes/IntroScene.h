//
//  IntroScene.h
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#ifndef __Castle_of_Thorn__IntroScene__
#define __Castle_of_Thorn__IntroScene__

#include "cocos2d.h"

class MainMenu : public cocos2d::CCLayer
{
private:
    float scaleX ;
    float scaleY;
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    void menu_startNewGame(CCObject* pSender);
    // implement the "static node()" method manually
    CREATE_FUNC(MainMenu);
    void talk2();
};
#endif /* defined(__Castle_of_Thorn__IntroScene__) */