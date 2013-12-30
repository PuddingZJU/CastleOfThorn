//
//  GameoverScene.h
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#ifndef __Castle_of_Thorn__GameoverScene__
#define __Castle_of_Thorn__GameoverScene__

#include "cocos2d.h"
#include "CCRPGScene.h"
class GameoverScene : public CCRPGScene
{
private:
    float scaleX ;
    float scaleY;
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	bool loadmode;
    virtual bool init();
	virtual void A_Button_Pressed();
	virtual void B_Button_Pressed();
	virtual void Scan_cur_block(CCPoint pos);
	void Scan_Face_To_block(CCPoint pos);
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    // a selector callback
	void LoadScene();
	bool event[3];
    // implement the "static node()" method manually
    CREATE_FUNC(GameoverScene);
};
#endif /* defined(__Castle_of_Thorn__GameoverScene__) */
