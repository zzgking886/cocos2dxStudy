#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Human.hpp"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    //using sprite
//    Sprite *oneSprite = Sprite::create("test_bg_1.jpg");
//    printf("x = %f",oneSprite->getAnchorPoint().x);
//    printf("y = %f",oneSprite->getAnchorPoint().y);
//    oneSprite->setAnchorPoint(Point(0,0));
//    addChild(oneSprite);
    
    log("hello world");
    
    MessageBox("内容", "标题");
    
    Size onesize = Director::getInstance()->getVisibleSize();
    
    Label *onelabel = Label::create();
    onelabel->setString("123123");
    onelabel->setTextColor(Color4B::WHITE);
    onelabel->setPosition(onesize.width/2, onesize.height/2);
    addChild(onelabel);
    
    TextFieldTTF *onetextField = TextFieldTTF::textFieldWithPlaceHolder("在这输入", "宋体", 13.0);
    onetextField->setPosition(onesize.width/2, onesize.height/2 + 60);
    addChild(onetextField);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [onetextField](Touch *touch, Event *event){
        if (onetextField->getBoundingBox().containsPoint(touch->getLocation()))
        {
            onetextField->attachWithIME();
        }
        else
        {
            onetextField->detachWithIME();
        }
        return false;
    };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, onetextField);
    
    auto oneHuman = Human::create();
    oneHuman->setAnchorPoint(Point(0,0));
    addChild(oneHuman);
    
    //Cocos2d-x之内存管理机制
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
