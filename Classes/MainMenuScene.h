#ifndef __MAINMENU_SCENE_H__
#define __MENUMENU_SCENE_H__

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

#endif // __MAINMENU_SCENE_H__
