#pragma once

#include "cocos2d.h"

class SpriteSheetScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
        
    // implement the "static create()" method manually
	CREATE_FUNC(SpriteSheetScene);
	
	cocos2d::Vector<cocos2d::SpriteFrame*> getAnimation(const char *format, int count);
};

