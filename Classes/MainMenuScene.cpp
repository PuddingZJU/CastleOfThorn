#include "MainMenuScene.h"
#include "CCRPGTalkBox.h"
#include "IntroScene.h"
#include "CCRPGPlayer.h"
USING_NS_CC;

CCScene* MainMenu::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MainMenu *layer = MainMenu::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    scaleX = 0.0;
    scaleY = 0.0;
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    //背景图片  start
    CCSprite* pSprite = CCSprite::create("main_menu_background.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    float winw = visibleSize.width; //获取屏幕宽度
    float winh = visibleSize.height;//获取屏幕高度
    float spx = pSprite->getTextureRect().getMaxX();
    float spy = pSprite->getTextureRect().getMaxY();
    // add the sprite as a child to this layer
    scaleX = winw/spx;
    scaleY = winh/spy;
    pSprite->setScaleX(scaleX);
    pSprite->setScaleY(scaleY);
    this->addChild(pSprite, 0);
    //背景图片 end

    //菜单 start
    int btn_interval =50;
    CCMenuItemImage* newgameButton = CCMenuItemImage::create("btn-newgame.png", "btn-newgame-pressed.png",this,menu_selector(MainMenu::menu_startNewGame));
    CCMenuItemImage* continueButton = CCMenuItemImage::create("btn-continue.png", "btn-continue-pressed.png");
    CCMenuItemImage* exitButton = CCMenuItemImage::create("btn-about.png", "btn-about-pressed.png",this,menu_selector(MainMenu::menuCloseCallback));
    newgameButton->setScaleX(scaleX);
    newgameButton->setScaleY(scaleY);
    continueButton->setScaleX(scaleX);
    continueButton->setScaleY(scaleY);
    exitButton->setScaleX(scaleX);
    exitButton->setScaleY(scaleY);
    continueButton->setPosition(ccp(0 , -50));
    newgameButton->setPosition(0 , continueButton->getPositionY()+(continueButton->getContentSize().height/2+btn_interval)*scaleY);
    exitButton->setPosition(0, continueButton->getPositionY()-(continueButton->getContentSize().height/2+btn_interval)*scaleY);
    CCMenu * MainMenu = CCMenu::create(newgameButton,continueButton,exitButton,NULL);
    this->addChild(MainMenu);
	
    //菜单 end

    return true;
}

void MainMenu::menu_startNewGame(CCObject* pSender){
	CCDirector::sharedDirector()->replaceScene(	CCTransitionFade::create(3.0f,IntroScene::scene()));
}

void MainMenu::menuCloseCallback(CCObject* pSender)
{
	CCMessageBox("Hello, Write About Here","About");

}

