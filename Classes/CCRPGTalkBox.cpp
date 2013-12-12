#include "CCRPGTalkBox.h"
#include <fstream>
USING_NS_CC;
USING_NS_CC_EXT;
CCRPGTalkBox::CCRPGTalkBox(){
    stop = true;
    box_scale = 1;
}
std::string  CCRPGTalkBox::getfilepath(std::string filename){
    return CCFileUtils::sharedFileUtils()->fullPathForFilename(filename.c_str());
}
CCRPGTalkBox* CCRPGTalkBox::create(int tag,std::string background_image,std::string script_filename,int boardpixel,cocos2d::CCSize boxsize,float scale,SEL_CallFunc nextfunc,CCObject* listen){
    CCRPGTalkBox *cur = new CCRPGTalkBox();
    if (cur == NULL) {
        CCLOG("error");
    }
    cur->m_pListen = listen;
    cur->m_pfnSelectior = nextfunc;
    cur->tag = tag;
    cur->setScale(scale);
    cur->boardpixel = boardpixel;
    cur->_content = CCLabelTTF::create();
    cur->addChild(cur->_content, 3, 3);
    cur->_background_image = background_image;
    cur->origWidth = boxsize.width;cur->width = boxsize.width;
    cur->height = boxsize.height*scale;
    cur->_speaker_icon.clear();
    cur->_text.clear();
    cur->_font_size.clear();
    cur->_font.clear();
    cur->_color.clear();
    std::string path = cur->getfilepath(script_filename);
    std::ifstream fin(path.c_str());
    std::string t_spicn,t_text,t_f,t_c;
    float t_fs;
    while (fin>>t_spicn>>t_text>>t_f>>t_fs>>t_c) {
        cur->_speaker_icon.push_back(t_spicn);
        cur->_text.push_back(t_text);
        cur->_font_size.push_back(t_fs);
        cur->_font.push_back(t_f);
        cur->_color.push_back(t_c);
    }
    fin.close();
    return cur;
}

void CCRPGTalkBox::onEnter(){
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, true);
   
    CCLayer::onEnter();
}

void  CCRPGTalkBox::onExit(){
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    CCDirector::sharedDirector()->resume();
    CCLayer::onExit();
}

void CCRPGTalkBox::setScale(float scale) {
    box_scale = scale;
}

bool CCRPGTalkBox::hasNext(){
    return cur_pos<_text.size();
}

void CCRPGTalkBox::NextText(){
    if (cur_pos<_text.size()) {
        this->setTouchEnabled(true);
        left=0;
        if (_speaker_icon[cur_pos]!="unknowm") {
            left = height;
            width=origWidth-height;
            this->removeChildByTag(2);
            _icon = CCSprite::create(_speaker_icon[cur_pos].c_str());
            _icon->cocos2d::CCNode::setScale(height/_icon->getContentSize().width, height/_icon->getContentSize().height);
            _icon->setPosition(CCSizeMake(height/2, height/2));
            this->addChild(_icon,2,2);
        }
        this->removeChildByTag(1);
        CCSprite* tmp = CCSprite::create(_background_image.c_str());
        CCSize size = tmp->getContentSize();
        CCRect fullRect = CCRectMake(0,0, size.width, size.height);
        CCRect insetRect = CCRectMake(boardpixel, boardpixel,size.width-boardpixel*2, size.height-boardpixel*2);
        _box = CCScale9Sprite::create(_background_image.c_str(),fullRect,insetRect);
        _box->setContentSize(CCSizeMake(width,height));
        _box->setPosition(ccp(left+_box->getContentSize().width/2, height/2));
        _content->setString(_text[cur_pos].c_str());
        _content->setColor(ccc3(0, 0, 0));
        _content->setAnchorPoint(ccp(0.5, 0.5));
        _content->setFontName(_font[cur_pos].c_str());
        _content->setFontSize(_font_size[cur_pos]);
        _content->setPosition(CCSize(_box->getPositionX()-_box->getContentSize().width/2+boardpixel*2+_content->getContentSize().width/2, _box->getPositionY()+_box->getContentSize().height/2-boardpixel*2-_content->getContentSize().height/2));
        this->addChild(_box,1,1);
        width=origWidth;
    }
    cur_pos+=1;
}
bool CCRPGTalkBox::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    CCLOG("ccTouchBegan"); 
    return true;
}

void CCRPGTalkBox::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent){
    if (hasNext()) {
        NextText();
    }
    else{
        this->removeFromParentAndCleanup(true);
        if (m_pfnSelectior!=NULL) {
            (m_pListen->*m_pfnSelectior)();
        }
    }
}
CCRPGTalkBox::~CCRPGTalkBox(){
    CC_SAFE_RELEASE(_content);
    CC_SAFE_RELEASE(_menu);
    CC_SAFE_RELEASE(_box);
    CC_SAFE_RELEASE(_icon);
}