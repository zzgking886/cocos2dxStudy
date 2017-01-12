#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include <cocos-ext.h>
#include <Box2D/Box2D.h>

USING_NS_CC_EXT;
USING_NS_CC;

class HelloWorld : public cocos2d::Layer,TableViewDataSource,TableViewDelegate
{
    
private:
    b2World *world;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    void delayCall(float f);
public:
    /**
     * cell height for a given table.
     *
     * @param table table to hold the instances of Class
     * @return cell size
     */
    virtual Size cellSizeForTable(TableView *table);
    /**
     * a cell instance at a given index
     *
     * @param idx index to search for a cell
     * @return cell found at idx
     */
    virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);
    /**
     * Returns number of cells in a given table view.
     *
     * @return number of cells
     */
    virtual ssize_t numberOfCellsInTableView(TableView *table);
    
    virtual void tableCellTouched(TableView* table, TableViewCell* cell);
    
    virtual void update(float dt);
    void addRect();
    void addGround();
};

#endif // __HELLOWORLD_SCENE_H__
