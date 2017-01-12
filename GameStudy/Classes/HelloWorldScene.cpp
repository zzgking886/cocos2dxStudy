#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Human.hpp"
#include "FirstScene.hpp"


USING_NS_CC;

#define RATIO ((Director::getInstance()->getVisibleSize().height) / 5)

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
    
//    log("hello world");
//    
////    MessageBox("内容", "标题");
//    
//    Size onesize = Director::getInstance()->getVisibleSize();
//    
//    Label *onelabel = Label::create();
//    onelabel->setString("123123");
//    onelabel->setTextColor(Color4B::WHITE);
//    onelabel->setPosition(onesize.width/2, onesize.height/2);
//    addChild(onelabel);
//    
//    TextFieldTTF *onetextField = TextFieldTTF::textFieldWithPlaceHolder("在这输入", "宋体", 13.0);
//    onetextField->setPosition(onesize.width/2, onesize.height/2 + 60);
//    addChild(onetextField);
//    
//    auto listener = EventListenerTouchOneByOne::create();
//    listener->onTouchBegan = [onetextField](Touch *touch, Event *event){
//        if (onetextField->getBoundingBox().containsPoint(touch->getLocation()))
//        {
//            onetextField->attachWithIME();
//        }
//        else
//        {
//            onetextField->detachWithIME();
//        }
//        return false;
//    };
//    
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, onetextField);
//    
//    auto oneHuman = Human::create();
//    oneHuman->setAnchorPoint(Point(0,0));
//    addChild(oneHuman);
    
    //http://api.cocos.com/d3/d5c/classcocos2d_1_1_sprite.html
    
//    auto onemenuImage = MenuItemImage::create("favImage.png", "favImageSelected.png", [](Ref *ref){
//        log("onemenuImage clicked");
//    });
    
//    auto onemenu = Menu::create(onemenuImage, NULL);
//    addChild(onemenu);
    
//    TableView *tableview = TableView::create(this, Size(300, 100));
//    tableview->setAnchorPoint(Point(0,0));
//    tableview->setPosition(100, 100);
//    tableview->setDelegate(this);
//    addChild(tableview);
    
//    Size size = Director::getInstance()->getVisibleSize();
//    log("width = %f",size.width);
//    log("height = %f",size.height);
//    Label *onelabel = Label::createWithSystemFont("show next scene", "Courier", 36);
//    onelabel->setDimensions(size.width, 30);
//    log("label height = %f", onelabel->getHeight());
//    onelabel->setPosition(0, onelabel->getHeight());
//    onelabel->setAnchorPoint(Point(0,0));
//    onelabel->setColor(Color3B::RED);
//    addChild(onelabel);
    
//    Size onesize = Director::getInstance()->getVisibleSize();
//    Sprite *onesprite = Sprite::create("test_bg_2.jpg");
//    onesprite->setPosition(onesize.width/2, onesize.height/2);
//    addChild(onesprite);
//    
//    this->scheduleOnce(CC_SCHEDULE_SELECTOR(HelloWorld::delayCall), 2.0f);
    
    
    
//    auto cache = SpriteFrameCache::getInstance();
//    cache->addSpriteFramesWithFile("anim.plist");
//    Vector<SpriteFrame *> oneVec;
//    
//    char strAnim[15];
//    
//    for (int i = 0; i < 20; i++)
//    {
//        sprintf(strAnim, "anim%04d",i);
//        oneVec.pushBack(cache->getSpriteFrameByName(strAnim));
//    }
//    
//    Animation *animation = Animation::createWithSpriteFrames(oneVec, 0.1);
//    Animate *animate = Animate::create(animation);
//    
//    auto oneSprite = Sprite::create();
//    oneSprite->setTextureRect(Rect(0, 0, 80, 80));
//    oneSprite->setPosition(0, 0);
//    oneSprite->setAnchorPoint(Point(0, 0));
//    addChild(oneSprite);
//    oneSprite->runAction(RepeatForever::create(animate));
    
    world = new b2World(b2Vec2(0,-10));
    
    addGround();
    addRect();
    scheduleUpdate();
    
    return true;
}

void HelloWorld::update(float dt)
{
    Size onesize = Director::getInstance()->getVisibleSize();
    world->Step(dt, 8, 3);
    Sprite *onesprite;
    for (b2Body *b = world->GetBodyList(); b; b=b->GetNext())
    {
        if (b->GetType() == b2_dynamicBody)
        {
            if (b->GetUserData())
            {
                onesprite = (Sprite *)b->GetUserData();
                onesprite->setPosition(Point(onesize.width / 2, b->GetPosition().y * RATIO));
            }
        }
    }
}

void HelloWorld::addRect()
{
    Size onesize = Director::getInstance()->getWinSize();
    b2BodyDef def;
    def.position = b2Vec2(0, 5);
    def.type = b2_dynamicBody;
    b2Body *body = world->CreateBody(&def);
    
    b2PolygonShape groundshape;
    groundshape.SetAsBox(0.5, 0.5);
    
    b2FixtureDef fixturedef;
    fixturedef.density = 1;
    fixturedef.friction = 0.3;
    fixturedef.shape = &groundshape;
    body->CreateFixture(&fixturedef);
    
    auto onesprite = Sprite::create();
    onesprite->setTextureRect(Rect(0, 0, 0.5*2*RATIO, 0.5*2*RATIO));
    onesprite->setAnchorPoint(Point(0, 0));
    addChild(onesprite);
//    onesprite->setPosition(Point(onesize.width / 2, onesize.height-80));
    body->SetUserData(onesprite);
}


void HelloWorld::addGround()
{
    b2BodyDef def;
    def.position = b2Vec2(Director::getInstance()->getWinSize().width / RATIO, 0);
    def.type = b2_staticBody;
    b2Body *body = world->CreateBody(&def);
    
    b2PolygonShape groundshape;
    groundshape.SetAsBox(Director::getInstance()->getWinSize().width / RATIO, 0.5);
    
    b2FixtureDef fixturedef;
    fixturedef.density = 1;
    fixturedef.friction = 0.3;
    fixturedef.shape = &groundshape;
    body->CreateFixture(&fixturedef);
}


void HelloWorld::delayCall(float f)
{
    Director::getInstance()->replaceScene(TransitionFadeBL::create(1.0, FirstScene::createScene()));
}


Size HelloWorld::cellSizeForTable(cocos2d::extension::TableView *table)
{
    return Size(300, 50);
}


TableViewCell* HelloWorld::tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx)
{
    TableViewCell *cell = table->dequeueCell();
    if (cell == NULL)
    {
        cell = TableViewCell::create();
        Label *onelabel = Label::create();
        onelabel->setTag(20);
        onelabel->setSystemFontSize(20.0);
        onelabel->setAnchorPoint(Point(0,0));
        onelabel->setTextColor(Color4B::WHITE);
        cell->addChild(onelabel);
    }
    Label *label = (Label *)cell->getChildByTag(20);
    label->setString(StringUtils::format("label %ld",idx));
    return cell;
}


ssize_t HelloWorld::numberOfCellsInTableView(cocos2d::extension::TableView *table)
{
    return 20;
}

void HelloWorld::tableCellTouched(cocos2d::extension::TableView *table, cocos2d::extension::TableViewCell *cell)
{
    Label *onelabel = (Label *)cell->getChildByTag(20);
    log("%s",onelabel->getString().c_str());
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
