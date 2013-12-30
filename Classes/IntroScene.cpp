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
	event[0]=false;
	event[1]=false;
	event[2]=false;
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
	int itemid = get_itemID("items","itemID");
	if (itemid!=0)
	{
		switch (itemid)
		{
		case 2:{
				CCMessageBox("存档完成！","存档");
			break;
			   }
		default:{
			CCMessageBox(get_info("items","info").c_str(),"");
			break;
				}
		}
	}
	if (player->curTile.y==24 &&(player->curTile.x>=23 && player->curTile.x<=24))
	{
		CCMessageBox("Exit","事件触发");
	}
}
void IntroScene::B_Button_Pressed(){
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	player->setPosition(ccp(visibleSize.width/2-32,visibleSize.height/2));
}

void IntroScene::Scan_cur_block(CCPoint pos){
	
	if (pos.y==4 &&(pos.x>=30 && pos.x<=32) && !event[0])
	{
		event[0]=true;
		CCMessageBox("事件1","事件触发");
	}
	if (pos.x==24 && pos.y==4 && event[0] && !event[1])
	{
		event[1]=true;
		CCMessageBox("事件2","事件触发");
	}
}

void IntroScene::Scan_Face_To_block(CCPoint pos){
	
}