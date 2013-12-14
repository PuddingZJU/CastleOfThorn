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
USING_NS_CC;
using std::string;
class CCRPGJoystick:public CCLayer{
public:
	CREATE_FUNC(CCRPGJoystick);
	static CCRPGJoystick* create(float Scale);
	void Enable(bool isStopOther );
	void Disable();
private:
	bool isEnable;
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual	void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
};

#endif /* defined(__Castle_of_Thorn__CCRPGJoystick__) */

