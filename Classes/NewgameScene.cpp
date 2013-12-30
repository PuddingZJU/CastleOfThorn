//
//  NewgameScene.cpp
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#include "NewgameScene.h"
#include "CCRPGTalkBox.h"
#include "CCRPGJoystick.h"
#include "IntroScene.h"
#include <sstream>
USING_NS_CC;

CCScene* NewgameScene::scene(){
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	NewgameScene *layer = NewgameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool NewgameScene::init(){
	if ( !CCLayer::init() )
	{
		return false;
	}
	CCRPGTalkBox* box1 = CCRPGTalkBox::create(12, "dialog-box.png", "intro.txt", 13, CCSizeMake(800, 200), 1,callfunc_selector(NewgameScene::LoadScene),this,screenpos);
	addChild(box1,9999,12);
	box1->NextText();
	return true;
}
void NewgameScene::LoadScene(){
	CCDirector::sharedDirector()->replaceScene(	CCTransitionFade::create(3.0f,IntroScene::scene()));

}
void NewgameScene::A_Button_Pressed(){

}
void NewgameScene::B_Button_Pressed(){

}

void NewgameScene::Scan_cur_block(CCPoint pos){


}

void NewgameScene::Scan_Face_To_block(CCPoint pos){

}