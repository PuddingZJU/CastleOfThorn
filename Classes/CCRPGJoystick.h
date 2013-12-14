//
//  CCRPGJoystick.h
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#ifndef __Castle_of_Thorn__CCRPGJoystick__
#define __Castle_of_Thorn__CCRPGJoystick__

#include "cocos2d.h"
#include <sstream>
#include "CCRPGScene.h"
USING_NS_CC;
using std::string;
class CCRPGJoystick:public CCLayer{
public:
	CREATE_FUNC(CCRPGJoystick);
	void Enable(bool isStopOther );
	void Disable();
	void initJoyStick(CCRPGScene* scene);
	void A_button_Pressed(CCObject* Object);
	void B_button_Pressed(CCObject* Object);
	void setSceneScrollPosition(cocos2d::CCPoint position);
	void UpDate(float time);
private:
	bool isEnable;
	int height;
	void onEnter();
	void onExit();
	CCRPGScene* scene;
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual	void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
};

#endif /* defined(__Castle_of_Thorn__CCRPGJoystick__) */

