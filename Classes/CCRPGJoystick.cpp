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
	dpad->setPosition(ccp(height/2+20,height/2+10));
	addChild(dpad,1,10);
	CCSprite* dpad_up = CCSprite::create("dpad_up.png"); 
	dpad_up->setScale(scale);
	dpad_up->setVisible(false);
	dpad_up->setPosition(ccp(height/2+20,height/2+10));
	addChild(dpad_up,2,11);
	CCSprite* dpad_down = CCSprite::create("dpad_down.png"); 
	dpad_down->setScale(scale);
	dpad_down->setVisible(false);
	dpad_down->setPosition(ccp(height/2+20,height/2+10));
	addChild(dpad_down,2,12);
	CCSprite* dpad_left = CCSprite::create("dpad_left.png"); 
	dpad_left->setScale(scale);
	dpad_left->setVisible(false);
	dpad_left->setPosition(ccp(height/2+20,height/2+10));
	addChild(dpad_left,2,13);
	CCSprite* dpad_right = CCSprite::create("dpad_right.png"); 
	dpad_right->setScale(scale);
	dpad_right->setVisible(false);
	dpad_right->setPosition(ccp(height/2+20,height/2+10));
	addChild(dpad_right,2,14);
	CCMenuItemImage* A_button = CCMenuItemImage::create("btnA.png","btnA_down.png",this,SEL_MenuHandler(&CCRPGJoystick::A_button_Pressed));
	A_button->setPosition(ccp(visibleSize.width/2-A_button->getContentSize().width*2-10,height/2-visibleSize.height/2));
	CCMenuItemImage* B_button = CCMenuItemImage::create("btnB.png","btnB_down.png",this,SEL_MenuHandler(&CCRPGJoystick::B_button_Pressed));
	B_button->setPosition(ccp(visibleSize.width/2-B_button->getContentSize().width,height/2-visibleSize.height/2));
	CCMenu* buttons = CCMenu::create(A_button,B_button,NULL);
	this->addChild(buttons);
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
	CCPoint location = this->convertTouchToNodeSpace(pTouch);  

	int x = location.x - height/2-20;  
	int y = location.y - height/2-10;  

	if (abs(x)<=height/2 && abs(y)<=height/2)
	{

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
	int x = location.x - height/2-20;  
	int y = location.y - height/2-10;  
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
	getChildByTag(11)->setVisible(false);
	getChildByTag(12)->setVisible(false);
	getChildByTag(13)->setVisible(false);
	getChildByTag(14)->setVisible(false);

	scene->player->stopAllActions();
} 