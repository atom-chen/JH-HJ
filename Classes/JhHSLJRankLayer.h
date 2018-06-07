﻿#ifndef _HSLJRANK_LAYER_H_
#define _HSLJRANK_LAYER_H_
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "JhServerDataSwap.h"
#include "JhGlobalData.h"
USING_NS_CC;
class JhHSLJRankLayer :public Layer, public ServerDataDelegateProtocol
{
public:
	JhHSLJRankLayer();
	~JhHSLJRankLayer();

	bool init();
	virtual void onEnterTransitionDidFinish();
	static JhHSLJRankLayer* create();

	void getRankData();

	HSLJRankData myrankdata;

private:
	void onBack(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);

	void delayShowData(float dt);
	void onSuccess();
	void onErr(int errcode);

private:
	cocos2d::ui::ScrollView* srollView;
	Node* m_csbnode;
};

class HSLJRankItem :public Sprite
{
public:
	HSLJRankItem();
	~HSLJRankItem();

	bool init(HSLJRankData *data);
	static HSLJRankItem* create(HSLJRankData *data);

private:
private:
	HSLJRankData *m_data;
};
#endif