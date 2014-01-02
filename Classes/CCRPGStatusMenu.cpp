//
//  CCRPGStatusMenu.cpp
//  Castle of Thorn
//
//  Created by Leon on 13-12-13.
//
//

#include "CCRPGStatusMenu.h"

USING_NS_CC;

CCScene* StatusMenu::scene(CCRPGPlayer *p)
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();

	// 'layer' is an autorelease objec
	StatusMenu *layer = StatusMenu::createWithPlayer(p);

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
StatusMenu* StatusMenu::createWithPlayer(CCRPGPlayer *p)
{
    StatusMenu *sm = new StatusMenu();
    sm->player = p;
    if (sm && sm->init())
    {
        sm->autorelease();
        return sm;
    }
    else
    {
        delete sm;
        sm = NULL;
        return NULL;
    }
}
bool StatusMenu::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}
    CCSize s = CCDirector::sharedDirector()->getWinSize();
    CCLayerColor* layer = CCLayerColor::create( ccc4(135, 135 , 135, 255));
    layer->ignoreAnchorPointForPosition(false);
    layer->setPosition( CCPointMake(s.width/2, s.height/2) );
    addChild(layer, 0);
    CCMenuItemImage *closebutton = CCMenuItemImage::create("close.png", "close_down.png", this, menu_selector(StatusMenu::CloseCallback));
    CCMenuItemImage *itembutton = CCMenuItemImage::create("package.png", "package_down.png", this, menu_selector(StatusMenu::ItemMenuCallback));
    CCMenuItemImage *charabutton = CCMenuItemImage::create("chara.png", "chara_down.png", this, menu_selector(StatusMenu::CharacterMenuCallback));
    closebutton->setPosition(ccp(-250, 50));
    itembutton->setPosition(ccp(-250, 105));
    charabutton->setPosition(ccp(-250, 160));
    CCMenu *menu = CCMenu::create(charabutton,itembutton,closebutton,NULL);
    addChild(menu,1);
    CCSprite *charabox = CCSprite::create("menu_bg_all.png");
    charabox->setPosition(ccp(450, s.height/2));
    addChild(charabox,1,12);
    CCSprite *itembox = CCSprite::create("item_bg_all.png");
    itembox->setPosition(ccp(450, s.height/2));
    addChild(itembox,1,13);

    CCMenu *itemmenu = CCMenu::create();
    for (int i=0; i<player->items.size(); i++) {
        switch (player->items[i]) {
            case 4:{
                CCMenuItemLabel *item = CCMenuItemLabel::create(CCLabelTTF::create("手电筒         X1", "AR PLMingU20 Light", 24));
                itemmenu->addChild(item, i+1, i+1);
                break;
            }
            case 6:{
                CCMenuItemLabel *item = CCMenuItemLabel::create(CCLabelTTF::create("水果刀         X1", "AR PLMingU20 Light", 24));
                itemmenu->addChild(item, i+1, i+1);
                break;
            }
            case 12:{
                CCMenuItemLabel *item = CCMenuItemLabel::create(CCLabelTTF::create("钥匙          X1", "AR PLMingU20 Light", 24));
                itemmenu->addChild(item, i+1, i+1);
                break;
            }
            default:
                break;
        }
    }
    itemmenu->setAnchorPoint(ccp(0, 1));
    itemmenu->alignItemsVertically();
    itemmenu->setPosition(itembox->getPositionX()-300,itembox->getPositionY()+130);
    itembox->addChild(itemmenu);
    CharacterMenuCallback(NULL);
	return true;
}

void StatusMenu::CloseCallback(cocos2d::CCObject *pSender){
    CCDirector::sharedDirector()->popScene();
}

void StatusMenu::ItemMenuCallback(cocos2d::CCObject *pSender){
    getChildByTag(12)->setVisible(false);
      getChildByTag(13)->setVisible(true);
    
}

void StatusMenu::CharacterMenuCallback(cocos2d::CCObject *pSender){
    getChildByTag(13)->setVisible(false);
    getChildByTag(12)->setVisible(true);

}
