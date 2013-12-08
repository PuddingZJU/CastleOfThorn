#include<cocos2d.h>
#include<cocos-ext.h>
#include<sstream>

class CCRPGTalkBox : public cocos2d::CCLayer
{
	
private:
	std::string _speaker_icon;
	std::string _font;
    int boardpixel;
    int left;
     CC_SYNTHESIZE_RETAIN(cocos2d::CCLabelTTF*,_content,Content);
     CC_SYNTHESIZE_RETAIN(cocos2d::extension::CCScale9Sprite*,_box,Box);
    CC_SYNTHESIZE_RETAIN(cocos2d::CCMenu*, _menu, Menu);
public:

	CREATE_FUNC(CCRPGTalkBox);
    
	static CCRPGTalkBox*  create(cocos2d::CCSize screensize,std::string font,cocos2d::ccColor3B textcolor,float textsize,std::string speaker_icon,std::string background_image,int boardpixel,cocos2d::CCSize boxsize);
	static CCRPGTalkBox* create(cocos2d::CCSize screensize,std::string font,cocos2d::ccColor3B textcolor,float textsize,std::string background_image,int boardpixel,cocos2d::CCSize boxsize);
    
    CCRPGTalkBox();
    ~CCRPGTalkBox(); 
	void SetContent(std::string content);
    bool SetYesNoQuestion(std::string question,std::string yes_string,std::string no_string);

	


	
};