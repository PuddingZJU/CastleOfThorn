//
//  PreviewScene.cpp
//  Castle of Thorn
//
//  Created by Leon on 14-1-2.
//
//

#include "PreviewScene.h"

#include "CCRPGTalkBox.h"
#include "CCRPGJoystick.h"
#include "GameoverScene.h"
#include <sstream>
USING_NS_CC;

CCScene* PreviewScene::scene(){
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();
    
	// 'layer' is an autorelease object
	PreviewScene *layer = PreviewScene::create();
    
	// add layer as a child to scene
	scene->addChild(layer);
    
	// return the scene
	return scene;
}

bool PreviewScene::init(){
	if ( !CCLayer::init() )
	{
		return false;
	}
	CCRPGTalkBox* box1 = CCRPGTalkBox::create(12, "dialog-box.png", "preview.txt", 13, CCSizeMake(800, 200), 1,callfunc_selector(PreviewScene::LoadScene),this,screenpos);
	addChild(box1,9999,12);
	box1->NextText();
	return true;
}
void PreviewScene::LoadScene(){
	CCDirector::sharedDirector()->replaceScene(	CCTransitionFade::create(3.0f,GameoverScene::scene()));
    
}

