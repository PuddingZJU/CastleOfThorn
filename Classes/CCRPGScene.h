
#ifndef __Castle_of_Thorn__CCRPGScene__
#define __Castle_of_Thorn__CCRPGScene__

#include "cocos2d.h"
#include "CCRPGPlayer.h"
USING_NS_CC;

class CCRPGScene:public cocos2d::CCLayer{
public:
	virtual void A_Button_Pressed();
	virtual void B_Button_Pressed();
	virtual void Scan_cur_block(CCPoint pos);
	virtual void Scan_Face_To_block(CCPoint pos);
    virtual void changeZorder(CCPoint tilePos);

	virtual int get_itemID(string item_layer_name,string ItemIDKey);
	virtual string get_info(string layer,string key);
	CCRPGPlayer* player;
	CCTMXTiledMap* map;
	CCPoint screenpos;
};
#endif /* defined(__Castle_of_Thorn__CCRPGScene__) */
