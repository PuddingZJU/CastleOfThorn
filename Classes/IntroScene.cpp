//
//  IntroScene.cpp
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#include "IntroScene.h"

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
	CCTMXTiledMap* map = CCTMXTiledMap::create("maps/map-apartment.tmx");
	addChild(map,0,1);
	this->Player = CCRPGPlayer::create("xi",100,100,100,100,1);
	Player->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
	addChild(Player,9999,2);
	Player->MoveUP();
	//Player->MoveUP();
	//schedule(SEL_SCHEDULE(&IntroScene::PlayerMove),1);
	return true;
}

void IntroScene::PlayerMove(float t){

	Player->MoveUP();

}