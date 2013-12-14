//
//  CCRPGPlayer.cpp
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#include "CCRPGPlayer.h"

CCRPGPlayer* CCRPGPlayer::create(string name,int hp,int hpmax, int mp,int mpmax,int level){
	CCRPGPlayer* cur = new CCRPGPlayer();
	if (cur && cur->initWithFile(("animation/"+name+"-front.png").c_str()))
	{
		cur->autorelease();
		cur->name = name;
		cur->hp = hp;
		cur->hpmax = hpmax;
		cur->mp = mp;
		cur->mpmax = mpmax;
		cur->initAnimation();
		cur->initAction();
		return cur;
	}
	CC_SAFE_DELETE(cur);
	return NULL;
}

void CCRPGPlayer::initAnimation(){
	CCArray* framesUp = CCArray::create();  
	CCArray* framesDown = CCArray::create();  
	CCArray* framesLeft = CCArray::create();  
	CCArray* framesRight = CCArray::create();  

	CCSpriteFrame* frame = NULL;   
	string act[4]={".png","-left.png","-right.png","-left.png"};
	string to[4]={"-front","-right","-left","-back"};
	for(int i = 0; i < 4; i ++)  
	{  
		for(int j = 0; j < 4; j ++)  
		{  
			frame = CCSpriteFrame::createWithTexture(CCTextureCache::sharedTextureCache()->addImage(("animation/"+name+to[i]+act[j]).c_str()),CCRectMake(0,0,32.0,48.0));  
			if(i == 0)  
			{  
				framesDown->addObject(frame);  
			}else if(i == 1)  
			{  
				framesLeft->addObject(frame);  
			}else if(i == 2)  
			{  
				framesRight->addObject(frame);  
			}else if(i == 3)  
			{  
				framesUp->addObject(frame);  
			}  
		}  
	}  
	animitionUp = CCAnimation::createWithSpriteFrames(framesUp, 0.1f);  
	animitionDown = CCAnimation::createWithSpriteFrames(framesDown, 0.1f);  
	animitionLeft = CCAnimation::createWithSpriteFrames(framesLeft, 0.1f);  
	animitionRight = CCAnimation::createWithSpriteFrames(framesRight, 0.1f);  
}

void CCRPGPlayer::initAction(){
	actionUp = CCSpawn::createWithTwoActions(CCAnimate::create(animitionUp), CCMoveBy::create(0.4f, ccp(0, 32)));  
	actionDown = CCSpawn::createWithTwoActions(CCAnimate::create(animitionDown), CCMoveBy::create(0.4f, ccp(0, -32)));  
	actionLeft = CCSpawn::createWithTwoActions(CCAnimate::create(animitionLeft), CCMoveBy::create(0.4f, ccp(-32, 0)));  
	actionRight = CCSpawn::createWithTwoActions(CCAnimate::create(animitionRight), CCMoveBy::create(0.4f, ccp(32, 0)));  

	actionUp->retain();  
	actionDown->retain();  
	actionLeft->retain();  
	actionRight->retain();  
}
void CCRPGPlayer::MoveUP(){
	this->runAction(actionUp);  
}
void CCRPGPlayer::MoveDown(){
	this->runAction(actionDown); 
}
void CCRPGPlayer::MoveLeft(){
	this->runAction(actionLeft); 
}
void CCRPGPlayer::MoveRight(){
	this->runAction(actionRight); 
}