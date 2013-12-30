#include "CCRPGAboutScene.h"

USING_NS_CC;

CCScene* AboutScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    AboutScene *layer = AboutScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool AboutScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    //背景图片  start
    CCSprite* pSprite = CCSprite::create("about.png");
	float winw = visibleSize.width; //获取屏幕宽度
    float winh = visibleSize.height;//获取屏幕高度
    float spx = pSprite->getTextureRect().getMaxX();
    float spy = pSprite->getTextureRect().getMaxY();
    // add the sprite as a child to this layer
    float scaleX = winw/spx;
    float scaleY = winh/spy;
    pSprite->setScaleX(scaleX);
    pSprite->setScaleY(scaleY);
    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
	addChild(pSprite,0);
	CCLabelTTF* backlabel =  CCLabelTTF::create("返回", "AR PLMingU20 Light", 24);
	backlabel->setColor(ccc3(0,0,0));
	CCMenuItemLabel *back = CCMenuItemLabel::create(backlabel,this,menu_selector(AboutScene::backCallback));
	back->setPosition(300,-200);
	CCMenu * menu = CCMenu::create(back,NULL);
	this->addChild(menu,2);
	

    return true;
}

 void AboutScene::backCallback(CCObject* pSender){
	 CCDirector::sharedDirector()->popScene();
 }