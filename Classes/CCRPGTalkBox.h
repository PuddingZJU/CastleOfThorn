#include<cocos2d.h>
#include<sstream>

class CCRPGTalkBox : public cocos2d::CCLayer
{
	
private:
	std::string _speaker;
	std::string _content;
	std::string _icon;
	std::string _font;
	cocos2d::CCMenu* choise_menu;

public:

	CREATE_FUNC(CCRPGTalkBox);
	CCRPGTalkBox(std::string speaker,std::string content,std::string font,std::string speaker_icon,bool Choise); 
	CCRPGTalkBox(std::string content,std::string font,bool Choise);
	CCRPGTalkBox(std::string speaker,std::string content,std::string font,std::string speaker_icon); 
	CCRPGTalkBox(std::string content,std::string font);
    ~CCRPGTalkBox(); 
	int Show();

	


	
};