//
//  IntroScene.cpp
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#include "IntroScene.h"
#include "CCRPGTalkBox.h"
#include "CCRPGJoystick.h"
USING_NS_CC;

CCScene* IntroScene::scene(){
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	IntroScene *layer = IntroScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool IntroScene::init(){
	if ( !CCLayer::init() )
	{
		return false;
	}
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	map = CCTMXTiledMap::create("maps/apartment.tmx");
	addChild(map,0,1);
	this->player = CCRPGPlayer::create("yi",100,100,100,100,1);
	player->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
	addChild(player,9999,2);
	CCRPGJoystick* controller = CCRPGJoystick::create();
	controller->initJoyStick(this);
	addChild(controller,1);
	return true;
}


void IntroScene::A_Button_Pressed(){
	player->MoveRight();
}
void IntroScene::B_Button_Pressed(){
	player->MoveLeft();
}