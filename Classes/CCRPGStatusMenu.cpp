//
//  CCRPGStatusMenu.cpp
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#include "CCRPGStatusMenu.h"

USING_NS_CC;

CCScene* StatusMenu::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	StatusMenu *layer = StatusMenu::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool StatusMenu::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}


	return true;
}