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
#include <sstream>
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
	CCRPGTalkBox* box1 = CCRPGTalkBox::create(12, "dialog-box.png", "intro.txt", 13, CCSizeMake(visibleSize.width, 200), 1,callfunc_selector(IntroScene::LoadScene),this,screenpos);
	addChild(box1,9999,12);
	box1->NextText();
	return true;
}
void IntroScene::LoadScene(){
	removeChildByTag(12);
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	map = CCTMXTiledMap::create("maps/apartment.tmx");
	this->setPosition(-visibleSize.width/2,0);
	screenpos = ccp(-visibleSize.width/2,0);
	addChild(map,0,1);
	this->player = CCRPGPlayer::create("yi",100,100,100,100,1);
	player->setPosition(ccp(visibleSize.width/2-screenpos.x-48,visibleSize.height/2-screenpos.y));
	map->addChild(player,4,1024);
	CCRPGPlayer* lin = CCRPGPlayer::create("lin",100,100,100,100,1);
	lin->setPosition(ccp(visibleSize.width/2-screenpos.x-16,visibleSize.height/2-screenpos.y));
	addChild(lin,10,1025);
	CCRPGJoystick* controller = CCRPGJoystick::create();
	controller->initJoyStick(this);
	addChild(controller,1);
	CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "1_1.txt", 13, CCSizeMake(visibleSize.width, 200), 1,NULL,this,screenpos);
	addChild(box1,9999,13);
	box1->NextText();
}
void IntroScene::A_Button_Pressed(){
	int itemid = get_item("items");
	if (itemid!=0)
	{

	}
	
	CCMessageBox("ItemID:","About");

}
void IntroScene::B_Button_Pressed(){
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	player->setPosition(ccp(visibleSize.width/2-32,visibleSize.height/2));
}