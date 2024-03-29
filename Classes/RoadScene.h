//
//  RoadScene.h
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#ifndef __Castle_of_Thorn__RoadScene__
#define __Castle_of_Thorn__RoadScene__

#include "cocos2d.h"
#include "CCRPGScene.h"
class RoadScene : public CCRPGScene
{
private:
    float scaleX ;
    float scaleY;
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	virtual void Scan_cur_block(CCPoint pos);
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    // a selector callback
	void LoadScene();
	bool event;
    static RoadScene* createWithPlayer(CCRPGPlayer *p);
    void GoToNextStage();
    void Event_1();
    // implement the "static node()" method manually
    CREATE_FUNC(RoadScene);
};
#endif /* defined(__Castle_of_Thorn__RoadScene__) */
