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
#include "CCRPGStatusMenu.h"
#include "RoadScene.h"
#include <sstream>
USING_NS_CC;

CCScene* IntroScene::scene(){
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	IntroScene *layer = IntroScene::create();
	layer->LoadScene();
	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
CCScene* IntroScene::scene_load(){
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	IntroScene *layer = IntroScene::create();
	layer->LoadData();
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
	return true;
}

void IntroScene::LoadData(){
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	float sceneX = CCUserDefault::sharedUserDefault()->getFloatForKey("sceneposX",-visibleSize.width/2);
	float sceneY = CCUserDefault::sharedUserDefault()->getFloatForKey("sceneposY",0);
	float playerX = CCUserDefault::sharedUserDefault()->getFloatForKey("playposX",visibleSize.width/2-screenpos.x-48);
	float playerY = CCUserDefault::sharedUserDefault()->getFloatForKey("playposY",visibleSize.height/2-screenpos.y);
	event[0] =  CCUserDefault::sharedUserDefault()->getFloatForKey("event0",0);
	event[1] =  CCUserDefault::sharedUserDefault()->getFloatForKey("event1",0);
	map = CCTMXTiledMap::create("apartment.tmx");
    
	this->setPosition(-visibleSize.width/2,0);
	screenpos = ccp(sceneX,sceneY);
	addChild(map,0,1);
	this->player = CCRPGPlayer::create("yi",100,100,100,100,1);
	player->setPosition(ccp(playerX,playerY));
	map->addChild(player,3,1024);
	CCRPGJoystick* controller = CCRPGJoystick::create();
	controller->initJoyStick(this);
	addChild(controller,1);
	controller->setSceneScrollPosition(player->getPosition());
    string t = "item0";
    string tc = "itemcount0";
    if(CCUserDefault::sharedUserDefault()->getIntegerForKey(t.c_str(),-1)!=-1 && event[0] && event[1]){
        for (int i = 0;  CCUserDefault::sharedUserDefault()->getIntegerForKey(t.c_str(),-1)!=-1; i++)
        {
           
            player->items.push_back(CCUserDefault::sharedUserDefault()->getIntegerForKey(t.c_str(),-1));
            player->itemsccount[CCUserDefault::sharedUserDefault()->getIntegerForKey(tc.c_str(),-1)] = CCUserDefault::sharedUserDefault()->getIntegerForKey(tc.c_str(),0);
            t[4]+=1;
            tc[9]+=1;
        }
    }
}
void IntroScene::LoadScene(){
	removeChildByTag(12);
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	map = CCTMXTiledMap::create("apartment.tmx");
	this->setPosition(-visibleSize.width/2,0);
	screenpos = ccp(-visibleSize.width/2,0);
	addChild(map,0,1);
	this->player = CCRPGPlayer::create("yi",100,100,100,100,1);
	player->setPosition(ccp(visibleSize.width/2-screenpos.x-48,visibleSize.height/2-screenpos.y));
	map->addChild(player,3,1024);
	CCRPGPlayer* lin = CCRPGPlayer::create("lin",100,100,100,100,1);
	lin->setPosition(ccp(visibleSize.width/2-screenpos.x-16,visibleSize.height/2-screenpos.y));
    //player->teamer->addObject(lin);
	addChild(lin,10,1025);
	CCRPGJoystick* controller = CCRPGJoystick::create();
	controller->initJoyStick(this);
	addChild(controller,1);
	controller->setSceneScrollPosition(player->getPosition());
	CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "1_1.txt", 13, CCSizeMake(visibleSize.width, 200), 1,callfunc_selector(IntroScene::Event0),this,screenpos);
	addChild(box1,9999,13);
	box1->NextText();
}
void IntroScene::A_Button_Pressed(){
	int itemid = get_itemID("items","itemID");
	if (itemid!=0 && player->itemsccount[itemid]==0)
	{
		switch (itemid)
		{
		case 2:{
			CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "save.txt", 13, CCSizeMake(800, 200), 1,NULL,this,screenpos);
			addChild(box1,9999,13);
			box1->NextText();
            CCUserDefault::sharedUserDefault()->purgeSharedUserDefault();
            CCUserDefault::sharedUserDefault()->flush();
			CCUserDefault::sharedUserDefault()->setStringForKey("scene","apartment");
			CCUserDefault::sharedUserDefault()->setBoolForKey("event0",event[0]);
			CCUserDefault::sharedUserDefault()->setBoolForKey("event1",event[1]);
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
                string tc = "itemcount0";
				t[4]+=i;
                tc[9]+=i;
				CCUserDefault::sharedUserDefault()->setIntegerForKey(t.c_str(),player->items[i]);
                CCUserDefault::sharedUserDefault()->setIntegerForKey(tc.c_str(),player->itemsccount[player->items[i]]);
			}
			CCUserDefault::sharedUserDefault()->flush();
			break;
			   }
            case 4:{
                if (event[0] && event[1]) {
                    CCMessageBox("得到了一个手电筒", "获得物品");
                    player->items.push_back(itemid);
                    player->itemsccount[itemid]+=1;
                }
                else{
                    CCMessageBox(get_info("items","info").c_str(),"");
                }
                break;
            }
            case 6:{
                if (event[0] && event[1]) {
                    CCMessageBox("得到了一把水果刀", "获得物品");
                    player->items.push_back(itemid);
                    player->itemsccount[itemid]+=1;
                }
                else{
                    CCMessageBox(get_info("items","info").c_str(),"");
                }
                break;
            }
            case 12:{
                if (event[0] && event[1]) {
                     CCMessageBox("得到了一把钥匙", "获得物品");
                    player->items.push_back(itemid);
                    player->itemsccount[itemid]+=1;
                }
                else{
                    CCMessageBox(get_info("items","info").c_str(),"");
                }
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
				CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "1_go.txt", 13, CCSizeMake(800, 200), 1,callfunc_selector(IntroScene::GoToNextStage),this,screenpos);
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
void IntroScene::GoToNextStage(){
    CCScene *next = CCScene::create();
    
    player->retain();
    removeAllChildrenWithCleanup(true);
    RoadScene *rd = RoadScene::createWithPlayer(player);
    next->addChild(rd);
    CCDirector::sharedDirector()->replaceScene(	CCTransitionFade::create(3.0f,next));
}
void IntroScene::B_Button_Pressed(){
    CCDirector::sharedDirector()->pushScene(StatusMenu::scene(player));
}
void IntroScene::Event0(){
    CCRPGPlayer *lin = (CCRPGPlayer*)getChildByTag(1025);
    CCAction *actionLeft = CCSpawn::createWithTwoActions(CCAnimate::create(lin->animitionRight), CCMoveTo::create(0.5f, player->getPosition()));
    lin->runAction(actionLeft);
    lin->setVisible(false);
}
void IntroScene::changeZorder(cocos2d::CCPoint tilePos) {
    if ((tilePos.y<=20 && tilePos.y>= 18) || (tilePos.y==4 && tilePos.x ==14))
    {
        map->getChildByTag(1024)->setZOrder(3);
    }
    else{
        map->getChildByTag(1024)->setZOrder(4);
    }
}

void IntroScene::Scan_cur_block(CCPoint pos){

	if (pos.y==4 &&(pos.x>=30 && pos.x<=32) && !event[0])
	{
		player->stopAllActions();
		event[0]=true; 
		CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "1_2.txt", 13, CCSizeMake(800, 200), 1,NULL,this,screenpos);
		addChild(box1,9999,13);
		box1->NextText();
	}
	if (pos.x==24 && pos.y==4 && event[0] && !event[1])
	{
		player->stopAllActions();
		event[1]=true;
		CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "1_3.txt", 13, CCSizeMake(800, 200), 1,callfunc_selector(IntroScene::Event1),this,screenpos);
		addChild(box1,9999,13);
		box1->NextText();
	}
}
void IntroScene::Event1(){
    player->runAction(player->actionDown);
    CCRPGPlayer *lin = (CCRPGPlayer*)getChildByTag(1025);
    lin->setVisible(true);
    lin->setPosition(ccp(player->getPositionX(),player->getPositionY()-450));
    CCAction *actionUP = CCSpawn::createWithTwoActions(CCAnimate::create(lin->animitionUp), CCMoveTo::create(1.0f, ccp(player->getPositionX(),player->getPositionY()-100)));
    lin->runAction(actionUP);
    
    CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "1_4.txt", 13, CCSizeMake(800, 200), 1,callfunc_selector(IntroScene::Event2),this,screenpos);
    addChild(box1,9999,13);
    box1->NextText();
}

void IntroScene::Event2(){
    CCRPGPlayer *lin = (CCRPGPlayer*)getChildByTag(1025);
    lin->setVisible(false);
}
void IntroScene::Scan_Face_To_block(CCPoint pos){

}