//
//  PreviewScene.h
//  Castle of Thorn
//
//  Created by Leon on 14-1-2.
//
//

#ifndef __Castle_of_Thorn__PreviewScene__
#define __Castle_of_Thorn__PreviewScene__

#include "cocos2d.h"
#include "CCRPGScene.h"
class PreviewScene : public CCRPGScene
{
private:
    float scaleX ;
    float scaleY;
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	bool loadmode;
    virtual bool init();
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    // a selector callback
	void LoadScene();
	bool event[3];
    // implement the "static node()" method manually
    CREATE_FUNC(PreviewScene);
};
#endif /* defined(__Castle_of_Thorn__PreviewScene__) */
