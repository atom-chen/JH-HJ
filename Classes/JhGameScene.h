﻿
/********************************************************************
*	 游戏主场景
*********************************************************************/
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "JhUIScroll.h"
#include "JhTopBar.h"
#include "JhNature.h"
#include "JhHero.h"
#include "JhHomeLayer.h"
#include "JhServerDataSwap.h"

class JhGameScene : public cocos2d::Layer, public ServerDataDelegateProtocol
{
public:
	JhGameScene();
	~JhGameScene();
    static cocos2d::Scene* createScene();
    virtual bool init();

	virtual void onExit();

	CREATE_FUNC(JhGameScene);
	/****************************
	角色复活更新UI
	*****************************/
	void heroRevive();

	/****************************
	保存数据到本地文件
	*****************************/
	void saveAllData();

	/****************************
	新手引导
	*****************************/
	void showNewerGuide(int step, std::vector<Node*> nodes);

	/****************************
	延迟新手引导
	*****************************/
	void delayShowNewerGuide(float dt);

	/****************************
	延迟显示出门场景
	*****************************/
	void delayShowOutScence(float dt);

	/****************************
	出门
	*****************************/
	void showGOOut(float dt);

	/****************************
	检查成就完成
	*****************************/
	void checkAchiveIsDone(float dt);

	/****************************
	安卓返回键保存数据
	*****************************/
	static void saveMyData();

	/****************************
	安卓返回键时改变游戏状态
	*****************************/
	static void changeGameStates(int status);


	/****************************
	重置支线任务（每天重置）
	*****************************/
	void checkRestBranchMisson();

private:
	JhTopBar* topBar;//角色属性和天气NODE
	JhHomeLayer *homeLayer;//角色家
	std::vector<Node*> m_newerNode;
	int m_newerStep;
	bool issavedata;
	bool isAnewGetData;
	
private:
	/****************************
	读取保存到本地的JhNature(时间天气)数据
	*****************************/
	void loadSaveNatureData();

	/****************************
	读取保存到本地的角色数据
	*****************************/
	void loadSaveHeroData();

	/****************************
	读取保存到本地的角色属性数据
	*****************************/
	void loadSavedHeroPropData();

	/****************************
	定时更新资源列表数据
	*****************************/
	void updata(float dt);

	/****************************
	定时查看角色是否死亡，生命为0死掉
	*****************************/
	void checkiflive(float dt);

	/****************************
	定时保存数据
	*****************************/
	void timerSaveData(float dt);

	/****************************
	韦小宝和独孤求败地图位置
	*****************************/
	void getNpcRandMap();

	/****************************
	VIP奖励回调
	*****************************/
	void onSuccess();
	void onErr(int errcode);

	void delayChangeStartScene(float dt);

};
extern JhNature* g_nature;//天气数据
extern JhHero* g_hero;//角色数据
extern JhGameScene* g_gameLayer;//游戏层
extern JhUIScroll* g_uiScroll;//topbar文件事件滚动控件
extern Sprite* scrollbg;//topbar文字滚动背景
#endif // __GAME_SCENE_H__
