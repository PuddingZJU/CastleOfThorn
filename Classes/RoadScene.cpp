//
//  RoadScene.cpp
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#include "RoadScene.h"
#include "CCRPGTalkBox.h"
#include "CCRPGJoystick.h"
#include "PreviewScene.h"
#include <sstream>
USING_NS_CC;

CCScene* RoadScene::scene(){
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease object
	RoadScene *layer = RoadScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
RoadScene* RoadScene::createWithPlayer(CCRPGPlayer *p)
{
    RoadScene *sm = new RoadScene();
    sm->player = p;
    if (sm && sm->init())
    {
        sm->autorelease();
        return sm;
    }
    else
    {
        delete sm;
        sm = NULL;
        return NULL;
    }
}
bool RoadScene::init(){
	if ( !CCLayer::init() )
	{
		return false;
	}
	event=false;
    LoadScene();
	return true;
}
void RoadScene::LoadScene(){
	removeChildByTag(12);
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	map = CCTMXTiledMap::create("road_castle.tmx");
	this->setPosition(-visibleSize.width/2,0);
	screenpos = ccp(-visibleSize.width/2,0);
	addChild(map,0,1);
	map->addChild(player,5,1024);
    player->setPosition(ccp(visibleSize.width+320, visibleSize.height/2));
    
	CCRPGJoystick* controller = CCRPGJoystick::create();
	controller->initJoyStick(this);
    
	addChild(controller,1);
    controller->setSceneScrollPosition(player->getPosition());
    CCRPGTalkBox* box1 = CCRPGTalkBox::create(12, "dialog-box.png", "2_1.txt", 13, CCSizeMake(800, 200), 1,NULL,this,screenpos);
	addChild(box1,9999,12);
	box1->NextText();
}



void RoadScene::Scan_cur_block(CCPoint pos){

	if (pos.y==5 &&(pos.x>=5 && pos.x<=10) && !event)
	{
        player->stopAllActions();
		event=true;
		CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "2_2.txt", 13, CCSizeMake(800, 200), 1,callfunc_selector(RoadScene::Event_1),this,screenpos);
		addChild(box1,9999,13);
		box1->NextText();
	}

}

void RoadScene::Event_1(){
    CCTMXLayer * layer = map->layerNamed("entrance_covered");
    layer->setVisible(false);
    CCRPGTalkBox* box1 = CCRPGTalkBox::create(13, "dialog-box.png", "2_3.txt", 13, CCSizeMake(800, 200), 1,callfunc_selector(RoadScene::GoToNextStage),this,screenpos);
    addChild(box1,9999,13);
    box1->NextText();
}

void RoadScene::GoToNextStage(){
    CCDirector::sharedDirector()->replaceScene(	CCTransitionFade::create(3.0f,PreviewScene::scene()));
}