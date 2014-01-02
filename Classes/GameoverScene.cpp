//
//  GameoverScene.cpp
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#include "GameoverScene.h"
#include "MainMenuScene.h"
#include <sstream>
USING_NS_CC;

CCScene* GameoverScene::scene(){
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	GameoverScene *layer = GameoverScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool GameoverScene::init(){
	if ( !CCLayer::init() )
	{
		return false;
	}
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    //背景图片  start
    CCSprite* pSprite = CCSprite::create("game-over.png");
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
	backlabel->setColor(ccc3(255,255,255));
    backlabel->setPosition(ccp(0, 10));
	CCMenuItemLabel *back = CCMenuItemLabel::create(backlabel,this,menu_selector(GameoverScene::backCallback));
	CCMenu * menu = CCMenu::create(back,NULL);
	this->addChild(menu,2);
	
    
    return true;
}

void GameoverScene::backCallback(CCObject* pSender){
    CCDirector::sharedDirector()->replaceScene(	CCTransitionFade::create(3.0f,MainMenu::scene()));
}

