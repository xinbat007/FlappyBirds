#pragma once

#include "cocos2d.h"

class GameOverScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene(unsigned int tempScore);

    virtual bool init();
    
    // implement the "static create()" method manually
	CREATE_FUNC(GameOverScene);
private:
	void gotoMainMenuScene(cocos2d::Ref* sender);
	void gotoGameScene(cocos2d::Ref* sender);
};
