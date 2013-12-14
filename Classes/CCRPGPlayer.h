//
//  CCRPGPlayer.h
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#ifndef __Castle_of_Thorn__CCRPGPlayer__
#define __Castle_of_Thorn__CCRPGPlayer__

#include "cocos2d.h"
#include <sstream>
using namespace std;

using namespace cocos2d;

template<typename T>
string Convert2String(const T &value){
	stringstream ss;
	ss <<value;
	return ss.str();
}

class CCRPGPlayer : public cocos2d::CCSprite{
public:
	bool isDead;
	int hp;
	int hpmax;
	int mp;
	int faceto;
	int mpmax;
	int level;
	string name;
	CCArray* items;
	CCArray* teamer;
	CCAnimation *animitionUp;
	CCAnimation *animitionDown ;
	CCAnimation *animitionLeft ;
	CCAnimation *animitionRight;
	cocos2d::CCAction* actionUp;  
	cocos2d::CCAction* actionDown;  
	cocos2d::CCAction* actionLeft;  
	cocos2d::CCAction* actionRight;
	CREATE_FUNC(CCRPGPlayer);
	static CCRPGPlayer* create(string name,int hp,int hpmax, int mp,int mpmax,int level);
	void MoveUP();
	void MoveDown();
	void MoveLeft();
	void MoveRight();
	int UseItem(string itemname);
private:
	void initAnimation();
	void initAction();
};
#endif /* defined(__Castle_of_Thorn__CCRPGPlayer__) */
