#include "CCRPGScene.h"
#include "CCRPGStatusMenu.h"
void CCRPGScene::A_Button_Pressed(){

}

void CCRPGScene::B_Button_Pressed(){
        CCDirector::sharedDirector()->pushScene(StatusMenu::scene(player));
}

void CCRPGScene::Scan_cur_block(CCPoint pos){

}

void CCRPGScene::Scan_Face_To_block(CCPoint pos){

}
void CCRPGScene::changeZorder(CCPoint tilePos){
    
}

int CCRPGScene::get_itemID(string item_layer_name,string ItemIDKey){
	CCTMXLayer * layer = map->layerNamed(item_layer_name.c_str());   
	unsigned int tileGID = layer->tileGIDAt(player->facetoTile);
	CCString * value = new CCString();
	if (tileGID > 0) {  
		CCDictionary * tileProperties = map->propertiesForGID(tileGID);  
		if(tileProperties==NULL){
			return 0;
		}
		value = (CCString*)tileProperties->objectForKey(ItemIDKey);  
	}  
	int res =0;
	if (value!= NULL)
	{
		 res = value->intValue();
	}
	return res; 
}

string CCRPGScene::get_info(string layer,string key){
	CCTMXLayer * mlayer = map->layerNamed(layer.c_str());   
	unsigned int tileGID = mlayer->tileGIDAt(player->facetoTile);
	CCString * value = new CCString();
	if (tileGID > 0) {  
		CCDictionary * tileProperties = map->propertiesForGID(tileGID);  
		if(tileProperties==NULL){
			return "";
		}
		value = (CCString*)tileProperties->objectForKey(key.c_str());  
	}  
	return value->getCString();
}