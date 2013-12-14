#include<cocos2d.h>
#include<cocos-ext.h>
#include<sstream>
#include<vector>
class CCRPGTalkBox : public cocos2d::CCLayer
{
	
private:
    std::vector<std::string> _speaker_icon;
    std::vector<std::string> _text;
	std::vector<std::string> _font;
    std::vector<float> _font_size;
    std::vector<std::string> _color;
    int width,height,origWidth;
    float box_scale;
    int boardpixel;
    int left;
    int tag;
    int cur_pos;
    int textpos;
	cocos2d::CCPoint* screenpos;
    bool startschdule;
    std::string _background_image;
     CC_SYNTHESIZE_RETAIN(cocos2d::CCLabelTTF*,_content,Content);
    //CC_SYNTHESIZE_RETAIN(cocos2d::CCLabelTTF*,_contentbuf,ContentBuf);
     CC_SYNTHESIZE_RETAIN(cocos2d::extension::CCScale9Sprite*,_box,Box);
    CC_SYNTHESIZE_RETAIN(cocos2d::CCSprite*,_icon,Icon);
    //CC_SYNTHESIZE_RETAIN(cocos2d::CCMenu*, _menu, Menu);
public:
    bool stop;
    void setScale(float scale);
    virtual void onEnter();
    virtual void onExit();
    
	CREATE_FUNC(CCRPGTalkBox);
	static CCRPGTalkBox*  create(int tag,std::string background_image,std::string script_filename,int boardpixel,cocos2d::CCSize boxsize,float scale,cocos2d::SEL_CallFunc nextfunc,CCObject* listen,cocos2d::CCPoint screenpos);
    CCRPGTalkBox();
    ~CCRPGTalkBox();
    bool hasNext();
	void NextText();
    std::string  getfilepath(std::string filename);
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void TextUpdate(float ctime);
protected:
    cocos2d::CCObject* m_pListen;
    
    // 回调函数指针
    cocos2d::SEL_CallFunc m_pfnSelectior;
};