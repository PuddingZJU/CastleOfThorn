//
//  CCRPGJoystick.cpp
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#include "CCRPGJoystick.h"


void CCRPGJoystick::initJoyStick(CCRPGScene* scene){
	this->scene = scene;
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	height = visibleSize.height/3;
	CCSprite* dpad = CCSprite::create("dpad.png"); 
	float scale = height/(dpad->getContentSize().height);
	dpad->setScale(scale);
	dpad->setVisible(true);
	dpad->setPosition(ccp(height/2+20-scene->screenpos.x,height/2+10-scene->screenpos.y));
	addChild(dpad,1,10);
	CCSprite* dpad_up = CCSprite::create("dpad_up.png"); 
	dpad_up->setScale(scale);
	dpad_up->setVisible(false);
	dpad_up->setPosition(ccp(height/2+20-scene->screenpos.x,height/2+10-scene->screenpos.y));
	addChild(dpad_up,2,11);
	CCSprite* dpad_down = CCSprite::create("dpad_down.png"); 
	dpad_down->setScale(scale);
	dpad_down->setVisible(false);
	dpad_down->setPosition(ccp(height/2+20-scene->screenpos.x,height/2+10-scene->screenpos.y));
	addChild(dpad_down,2,12);
	CCSprite* dpad_left = CCSprite::create("dpad_left.png"); 
	dpad_left->setScale(scale);
	dpad_left->setVisible(false);
	dpad_left->setPosition(ccp(height/2+20-scene->screenpos.x,height/2+10-scene->screenpos.y));
	addChild(dpad_left,2,13);
	CCSprite* dpad_right = CCSprite::create("dpad_right.png"); 
	dpad_right->setScale(scale);
	dpad_right->setVisible(false);
	dpad_right->setPosition(ccp(height/2+20-scene->screenpos.x,height/2+10-scene->screenpos.y));
	addChild(dpad_right,2,14);
	CCMenuItemImage* A_button = CCMenuItemImage::create("btnA.png","btnA_down.png",this,SEL_MenuHandler(&CCRPGJoystick::A_button_Pressed));
	A_button->setPosition(ccp(visibleSize.width/2-A_button->getContentSize().width*2-10-scene->screenpos.x,height/2-visibleSize.height/2-scene->screenpos.y));
	CCMenuItemImage* B_button = CCMenuItemImage::create("btnB.png","btnB_down.png",this,SEL_MenuHandler(&CCRPGJoystick::B_button_Pressed));
	B_button->setPosition(ccp(visibleSize.width/2-B_button->getContentSize().width-scene->screenpos.x,height/2-visibleSize.height/2-scene->screenpos.y));
	A_button->setTag(16);
    B_button->setTag(17);
	CCMenu* buttons = CCMenu::create(A_button,B_button,NULL);
	this->addChild(buttons,2,15);
	ismoving =false;
	schedule(schedule_selector(CCRPGJoystick::UpDate));
}

void CCRPGJoystick::onEnter(){
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -1, true);
	CCLayer::onEnter();
}


void CCRPGJoystick::onExit(){
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}

void CCRPGJoystick::A_button_Pressed(CCObject* Object){
	scene->A_Button_Pressed();
}

void CCRPGJoystick::B_button_Pressed(CCObject* Object){
	scene->B_Button_Pressed();
}
bool CCRPGJoystick::ccTouchBegan(CCTouch* pTouch, CCEvent* pEvent)  
{  
	ismoving = true;
	CCPoint location = this->convertTouchToNodeSpace(pTouch);  
	CCPoint controlpoint = getChildByTag(11)->getPosition();
	int x = location.x - controlpoint.x;  
	int y = location.y - controlpoint.y;  
 

	if (abs(x)<=height/2 && abs(y)<=height/2)
	{
		scene->player->isMoving = true;
		if(y > x && y > -x)  
		{  
			getChildByTag(11)->setVisible(true);
			scene->player->MoveUP();  
		}  
		else if(-y > x && -y > -x)  
		{  
			getChildByTag(12)->setVisible(true);
			scene->player->MoveDown();  
		}  
		else if(-x > y && -x > -y)  
		{  
			getChildByTag(13)->setVisible(true);
			scene->player->MoveLeft();  
		}  
		else if(x > y && x > -y)  
		{  
			getChildByTag(14)->setVisible(true);
			scene->player->MoveRight();    
		}  
	}
	return true;  
} 

void CCRPGJoystick::ccTouchMoved(CCTouch* pTouch, CCEvent* pEvent)  
{  
	CCPoint location = this->convertTouchToNodeSpace(pTouch);  
	getChildByTag(11)->setVisible(false);
	getChildByTag(12)->setVisible(false);
	getChildByTag(13)->setVisible(false);
	getChildByTag(14)->setVisible(false);
	CCPoint controlpoint = getChildByTag(11)->getPosition();
	int x = location.x - controlpoint.x;  
	int y = location.y - controlpoint.y;  
	if (abs(x)<=height/2 && abs(y)<=height/2)
	{

		if(y > x && y > -x && scene->player->faceto!=2)  
		{  
			getChildByTag(11)->setVisible(true);
			scene->player->stopAllActions();
			scene->player->MoveUP();  
		}  
		else if(-y > x && -y > -x  && scene->player->faceto!=1)  
		{  
			getChildByTag(12)->setVisible(true);
			scene->player->stopAllActions();
			scene->player->MoveDown();  
		}  
		else if(-x > y && -x > -y  && scene->player->faceto!=3)  
		{  
			getChildByTag(13)->setVisible(true);
			scene->player->stopAllActions();
			scene->player->MoveLeft();  
		}  
		else if(x > y && x > -y  && scene->player->faceto!=4)  
		{  
			getChildByTag(14)->setVisible(true);
			scene->player->stopAllActions();
			scene->player->MoveRight();    
		}  
	} 
} 

void CCRPGJoystick::ccTouchEnded(CCTouch* pTouch, CCEvent* pEvent)  
{    
	ismoving = false;
	getChildByTag(11)->setVisible(false);
	getChildByTag(12)->setVisible(false);
	getChildByTag(13)->setVisible(false);
	getChildByTag(14)->setVisible(false);
	scene->player->isMoving= false;
	scene->player->stopAllActions();
} 
void CCRPGJoystick::setSceneScrollPosition(cocos2d::CCPoint position){
	//ªÒ»°∆¡ƒª≥ﬂ¥Á
	CCSize screenSize=CCDirector::sharedDirector()->getWinSize();
	//º∆À„timeMapµƒ∏ﬂ∂»£¨µ•ŒªœÒÀÿ
	CCSize mapSizeInPixel=CCSizeMake(scene->map->getMapSize().width*scene->map->getTileSize().width, scene->map->getMapSize().height*scene->map->getTileSize().height);
	//ªÒ»°”¬ øŒª÷√∫Õ∆¡ƒª÷–µ„x∫Õyµƒ◊Ó¥Û÷µ
	float x=MAX(position.x, screenSize.width/2.0f);
	float y=MAX(position.y, screenSize.height/2.0f);
	//µÿÕº◊‹øÌ∂»¥Û”⁄∆¡ƒªøÌ∂» ±≤≈ø…ƒ‹πˆ∂Ø
	if (mapSizeInPixel.width>screenSize.width) {
		//≥°æ∞“∆∂Øæ‡¿Î≤ªƒ‹≥¨π˝µÿÕº◊‹øÌ∂»ºı»•∆¡ƒªøÌµƒ“ª∞Î
		x=MIN(x, mapSizeInPixel.width-screenSize.width/2.0f);
	}
	//µÿÕº◊‹∏ﬂ∂»¥Û”⁄∆¡ƒª∏ﬂ∂» ±≤≈ø…ƒ‹πˆ∂Ø
	if (mapSizeInPixel.height>screenSize.height) {
		//≥°æ∞“∆∂Øæ‡¿Î≤ªƒ‹≥¨π˝µÿÕº◊‹∏ﬂ∂»ºı»•∆¡ƒª∏ﬂµƒ“ª∞Î
		y=MIN(y, mapSizeInPixel.height-screenSize.height/2.0f);
	}
	//”¬ ø µº Œª÷√
	CCPoint heroPosition=ccp(x,y);
	//∆¡ƒª÷–µ„Œª÷√
	CCPoint screenCenter=ccp(screenSize.width/2.0f,screenSize.height/2.0f);
	//º∆À„”¬ ø µº Œª÷√∫Õ÷ÿµ„Œª÷√µƒæ‡¿Î
	CCPoint scrollPosition=ccpSub(screenCenter, heroPosition);

	//Ω´≥°æ∞“∆∂ØµΩœ‡”¶Œª÷√
	scene->screenpos = scrollPosition;
	scene->setPosition(scrollPosition);
	getChildByTag(10)->setPosition(ccp(height/2+20-scrollPosition.x,height/2+10-scrollPosition.y));
	getChildByTag(11)->setPosition(ccp(height/2+20-scrollPosition.x,height/2+10-scrollPosition.y));
	getChildByTag(12)->setPosition(ccp(height/2+20-scrollPosition.x,height/2+10-scrollPosition.y));
	getChildByTag(13)->setPosition(ccp(height/2+20-scrollPosition.x,height/2+10-scrollPosition.y));
	getChildByTag(14)->setPosition(ccp(height/2+20-scrollPosition.x,height/2+10-scrollPosition.y));
	getChildByTag(15)->getChildByTag(16)->setPosition(ccp(screenSize.width/2-66*2-10-scrollPosition.x,height/2-screenSize.height/2-scrollPosition.y));
	getChildByTag(15)->getChildByTag(17)->setPosition(ccp(screenSize.width/2-66-scrollPosition.x,height/2-screenSize.height/2-scrollPosition.y));
	CCLog("%f,%f",scrollPosition.x,scrollPosition.y);

}

void CCRPGJoystick::UpDate(float time){
	if (ismoving)
	{
		setSceneScrollPosition(scene->player->getPosition());
		
		CCPoint pos = scene->player->getPosition();
		
		CCPoint offset;
		if(scene->player->faceto == 2){
			pos.y-=24;
			offset.x =0;
			offset.y = -1;
		}else if(scene->player->faceto == 1){
			offset.x = 0;
			offset.y = 1;
		}else if(scene->player->faceto == 3){
			pos.x+=16;
			offset.x = -1;
			offset.y = 0;
		}else if(scene->player->faceto == 4){
			pos.x-=16;
			offset.x = 1;
			offset.y = 0;
		}
		CCPoint tilePos = this->tilePosFromLocation(pos, scene->map);  
		scene->player->curTile = tilePos;
		scene->Scan_cur_block(tilePos);
		scene->changeZorder(tilePos);
		//ªÒ»°µ±«∞“™“∆∂Ø“ª∏ˆŒª÷√µƒœ‡∂‘◊¯±Í  
		//º∆À„ªÒµ√“™“∆∂ØµΩƒ«∏ˆŒª÷√µƒæ¯∂‘◊¯±Í  
		tilePos = CCPointMake(tilePos.x + offset.x, tilePos.y + offset.y); 
		scene->player->facetoTile = tilePos;
		scene->Scan_Face_To_block(tilePos);
		//»∑±£÷˜Ω«≤ªª·≥¨≥ˆ∆¡ƒªµƒ±ﬂΩÁ,»Áπ˚≥¨≥ˆ‘Ú∞¥’’±ﬂΩÁµ„¿¥À„  
		//tilePos = this->ensureTilePosIsWithinBounds(tilePos);  
		//≈–∂œƒø±ÍŒª÷√ «∑Òƒ‹“∆∂Ø  
		if (this->isTilePosBlocked(tilePos, scene->map) == true && ismoving) {  
			//Ω´“™“∆∂Øµƒƒ«∏ˆ◊¯±Íµƒ¥…◊©øÈ“∆∂ØµΩµ±«∞∆¡ƒªµƒ÷–—Î  
			scene->player->stopAllActions();
		}  
		
	}
	
}
CCPoint CCRPGJoystick::tilePosFromLocation(cocos2d::CCPoint location, cocos2d::CCTMXTiledMap *tilemap)  
{  
	//ºı»•µÿÕºµƒ∆´“∆¡ø  
	CCPoint pos = ccpSub(location, tilemap->getPosition());  

	float mapHeight = tilemap->getMapSize().height;  
	float tileWidth = tilemap->getTileSize().width;  
	float tileHeight = tilemap->getTileSize().height;  

	CCPoint tilePasDiv = ccp(pos.x / tileWidth, pos.y / tileHeight);  
	float inverseTileY = mapHeight - tilePasDiv.y;  

	float posX = (int)tilePasDiv.x ;  
	float posY = (int)inverseTileY ;  

	//    posX = MAX(0, posX);  
	//    posX = MIN(tilemap->getMapSize().width - 1, posX);  
	//    posY = MAX(0, posY);  
	//    posY = MIN(tilemap->getMapSize().height - 1, posY);  

	//posX = MAX(playableAreaMin.x,posX);  
	//posX = MIN(playableAreaMax.x, posX);  
	//posY = MAX(playableAreaMin.y, posY);  
	//posY = MIN(playableAreaMax.y, posY);  

	pos = CCPointMake(posX, posY);  

	CCLog("X:%f,Y:%f",pos.x,pos.y);  

	return pos;  
}  
bool CCRPGJoystick::isTilePosBlocked(cocos2d::CCPoint tilepos, cocos2d::CCTMXTiledMap *tileMap)  
{
    if (tilepos.x<=0 || tilepos.y<=0 || tilepos.x>=tileMap->getMapSize().width || tilepos.y>=tileMap->getMapSize().height) {
        return true;
    }
	CCTMXLayer * layer = tileMap->layerNamed("walk");  
	bool isBokcked = true;  
	unsigned int tileGID = layer->tileGIDAt(tilepos);  
	if (tileGID > 0) {  
		CCDictionary * tileProperties = tileMap->propertiesForGID(tileGID);  
		void * blocks_movement = tileProperties->objectForKey("allow_movement");  
		isBokcked = (blocks_movement == NULL);  
	}  
	return isBokcked;  
}  