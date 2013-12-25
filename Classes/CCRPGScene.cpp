#include "CCRPGScene.h"

void CCRPGScene::A_Button_Pressed(){

}

void CCRPGScene::B_Button_Pressed(){

}

void CCRPGScene::Scan_cur_block(CCPoint pos){

}

void CCRPGScene::Scan_Face_To_block(CCPoint pos){

}

int CCRPGScene::get_item(string item_layer_name){
	CCTMXLayer * layer = map->layerNamed(item_layer_name.c_str());   
	unsigned int tileGID = layer->tileGIDAt(player->facetoTile);
	CCString * value = new CCString();
	if (tileGID > 0) {  
		CCDictionary * tileProperties = map->propertiesForGID(tileGID);  
		value = (CCString*)tileProperties->objectForKey("ItemID");  
	}  
	int res =0;
	if (value!= NULL)
	{
		 res = value->intValue();
	}
	return res; 
}