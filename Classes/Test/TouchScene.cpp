#include "TouchScene.h"

using namespace cocos2d;

cocos2d::Scene* TouchScene::createScene()
{
	Scene* scene = Scene::create();
	Layer* layer = TouchScene::create();
	scene->addChild(layer);
	return scene;
}
bool TouchScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	/*labelTouchInfo = Label::createWithSystemFont("Touch or click somewhere to begin", "Courier New", 30);
	labelTouchInfo->setPosition(Vec2(
		Director::getInstance()->getVisibleSize().width / 2,
		Director::getInstance()->getVisibleSize().height / 2));
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(TouchScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(TouchScene::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(TouchScene::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(TouchScene::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
	this->addChild(labelTouchInfo);*/
	Sprite* sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
		Director::getInstance()->getVisibleSize().height / 2));
	EventListenerTouchOneByOne* touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [](Touch* touch, Event* event) -> bool {
		auto bounds = event->getCurrentTarget()->getBoundingBox();
		if (bounds.containsPoint(touch->getLocation())) {
			std::stringstream touchDetails;
			touchDetails << "Touch at Open GL coordinate: " <<
				touch->getLocation().x << ", " << touch->getLocation().y << std::endl <<
				"Touch at UI coordinate: " <<
				touch->getLocationInView().x << ", " << touch->getLocationInView().y << std::endl <<
				"Touch at local coordinate: " <<
				event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).x << ", " <<
				event->getCurrentTarget()->convertToNodeSpace(touch->getLocation()).y << std::endl <<
				"Touch moved by: " << touch->getDelta().x << ", " << touch->getDelta().y;
			MessageBox(touchDetails.str().c_str(), "Touched");
		}
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, sprite);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, sprite);
	this->addChild(sprite, 0);
	return true;
}
bool TouchScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	labelTouchInfo->setPosition(touch->getLocation());
	labelTouchInfo->setString("You touched here");
	return true;
}
void TouchScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	cocos2d::log("touch ended");
}
void TouchScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	cocos2d::log("touch moved");
}
void TouchScene::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event)
{
	cocos2d::log("touch cancelled");
}