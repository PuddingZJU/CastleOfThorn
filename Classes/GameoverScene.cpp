//
//  GameoverScene.cpp
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#include "GameoverScene.h"
#include "CCRPGTalkBox.h"
#include "CCRPGJoystick.h"
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
	loadmode = false;
	event[0]=false;
	event[1]=false;
	event[2]=false;
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCRPGTalkBox* box1 = CCRPGTalkBox::create(12, "dialog-box.png", "Gameover.txt", 13, CCSizeMake(visibleSize.width, 200), 1,callfunc_selector(GameoverScene::LoadScene),this,screenpos);
	addChild(box1,9999,12);
	box1->NextText();
	return true;
}
void GameoverScene::LoadScene(){
	removeChildByTag(12);
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	map = CCTMXTiledMap::create("maps/apartment.tmx");
	this->setPosition(-visibleSize.width/2,0);
	screenpos = ccp(-visibleSize.width/2,0);
	addChild(map,0,1);
	this->player = CCRPGPlayer::create("yi",100,100,100,100,1);
	player->setPosition(ccp(visibleSize.width/2-screenpos.x-48,visibleSize.height/2-screenpos.y));
	map->addChild(player,3,1024);
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
void GameoverScene::A_Button_Pressed(){
	int itemid = get_itemID("items","itemID");
	if (itemid!=0)
	{
		switch (itemid)
		{
		case 2:{
			CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "save.txt", 13, CCSizeMake(800, 200), 1,NULL,this,screenpos);
			addChild(box1,9999,13);
			box1->NextText();
			CCUserDefault::sharedUserDefault()->setStringForKey("scene","apartment");
			CCUserDefault::sharedUserDefault()->setBoolForKey("Event0",false);
			CCUserDefault::sharedUserDefault()->setBoolForKey("Event1",false);
			CCUserDefault::sharedUserDefault()->setIntegerForKey("item0",-1);
			CCUserDefault::sharedUserDefault()->setIntegerForKey("item1",-1);
			CCUserDefault::sharedUserDefault()->setIntegerForKey("item2",-1);
			CCUserDefault::sharedUserDefault()->setFloatForKey("playposX",player->getPositionX());
			CCUserDefault::sharedUserDefault()->setFloatForKey("playposY",player->getPositionY());
			CCUserDefault::sharedUserDefault()->setFloatForKey("sceneposX",this->getPositionX());
			CCUserDefault::sharedUserDefault()->setFloatForKey("sceneposY",this->getPositionY());
			if (event[0])
			{
				CCUserDefault::sharedUserDefault()->setBoolForKey("Event0",true);
			}
			for (int i = 0; i < player->items.size(); i++)
			{
				string t = "item0";
				t[4]+=i;
				CCUserDefault::sharedUserDefault()->setIntegerForKey(t.c_str(),player->items[i]);
			}
			CCUserDefault::sharedUserDefault()->flush();
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
		if (event[0] && event[1])
		{
			if (player->items.size() ==3)
			{
				CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "1_go.txt", 13, CCSizeMake(800, 200), 1,NULL,this,screenpos);
				addChild(box1,9999,13);
				box1->NextText();
			}
			else{
				CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "1_notgo.txt", 13, CCSizeMake(800, 200), 1,NULL,this,screenpos);
				addChild(box1,9999,13);
				box1->NextText();
			}
		}
	}
}
void GameoverScene::B_Button_Pressed(){
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	player->setPosition(ccp(visibleSize.width/2-32,visibleSize.height/2));
}

void GameoverScene::Scan_cur_block(CCPoint pos){

	if (pos.y==4 &&(pos.x>=30 && pos.x<=32) && !event[0])
	{
		event[0]=true;
		CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "1_2.txt", 13, CCSizeMake(800, 200), 1,NULL,this,screenpos);
		addChild(box1,9999,13);
		box1->NextText();
	}
	if (pos.x==24 && pos.y==4 && event[0] && !event[1])
	{
		event[1]=true;
		CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "1_3.txt", 13, CCSizeMake(800, 200), 1,NULL,this,screenpos);
		addChild(box1,9999,13);
		box1->NextText();
	}
}

void GameoverScene::Scan_Face_To_block(CCPoint pos){

}