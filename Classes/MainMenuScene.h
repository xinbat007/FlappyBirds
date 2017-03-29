#pragma once

#include "cocos2d.h"

class MainMenuScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
	CREATE_FUNC(MainMenuScene);

private:
	void gotoGameScene(cocos2d::Ref* sender) const;

};
