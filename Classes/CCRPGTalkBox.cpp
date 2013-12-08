#include "CCRPGTalkBox.h"

USING_NS_CC;
USING_NS_CC_EXT;
CCRPGTalkBox::CCRPGTalkBox(){

}

CCRPGTalkBox* CCRPGTalkBox::create(cocos2d::CCSize screensize,std::string font,cocos2d::ccColor3B textcolor,float textsize,std::string speaker_icon,std::string background_image,int boardpixel,cocos2d::CCSize boxsize){
    
    CCRPGTalkBox *cur = new CCRPGTalkBox();
    cur->boardpixel = boardpixel;
    cur->setContentSize(screensize);
    cur->_content = CCLabelTTF::create("", font.c_str(), textsize);
    //_content->setFontFillColor(textcolor);
    CCSprite* tmp = CCSprite::create(background_image.c_str());
    CCSize size = tmp->getContentSize();
    CCRect fullRect = CCRectMake(0,0, size.width, size.height);
    CCRect insetRect = CCRectMake(boardpixel, boardpixel,size.width-boardpixel*2, size.height-boardpixel*2);
    cur->_box = CCScale9Sprite::create(background_image.c_str(),fullRect,insetRect);
    int width = boxsize.width;
    int height = boxsize.height;
    int left=0;
    if (!speaker_icon.empty()) {
        left = height;
        width-=height;
        CCSprite* sp_icon = CCSprite::create(speaker_icon.c_str());
        sp_icon->cocos2d::CCNode::setScale(height/sp_icon->getContentSize().width, height/sp_icon->getContentSize().height);
        sp_icon->setPosition(CCSizeMake(height/2, height/2));
        cur->addChild(sp_icon,0);
    }
    cur->_box->setContentSize(CCSizeMake(width,height));
   
    cur->_box->setPosition(ccp(left+cur->_box->getContentSize().width/2, height/2));
    cur->addChild(cur->_box, 0);
    cur->left= left;
    return cur;
}
CCRPGTalkBox* CCRPGTalkBox::create(cocos2d::CCSize screensize,std::string font,cocos2d::ccColor3B textcolor,float textsize,std::string background_image,int boardpixel,cocos2d::CCSize boxsize)
{
    CCRPGTalkBox *cur = new CCRPGTalkBox();

    return cur->create(screensize, font, textcolor,textsize,"", background_image,boardpixel,boxsize);
}
void CCRPGTalkBox::SetContent(std::string content ){
    _content->setString(content.c_str());
    ///_content->setContentSize(CCSizeMake(_box->getContentSize().width-boardpixel*2, _box->getContentSize().height-boardpixel*2));
    _content->setPosition(CCSize(_box->getPositionX()-_box->getContentSize().width/2+boardpixel*2+_content->getContentSize().width/2, _box->getPositionY()+_box->getContentSize().height/2-boardpixel*2-_content->getContentSize().height/2));
    this->addChild(_content,1);
}
CCRPGTalkBox::~CCRPGTalkBox(){
    CC_SAFE_RELEASE(_content);
    CC_SAFE_RELEASE(_menu);
    CC_SAFE_RELEASE(_box);
}