/********************************************************************
*��ʾ��
*********************************************************************/
#ifndef __HINTBOX__
#define __HINTBOX__

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
USING_NS_CC;

class JhHintBox : public Layer
{
public:
	/****************************
	��ʼ��
	@param ��ʾ������
	*****************************/
    bool init(std::string text);

	static JhHintBox* create(std::string content);
	/****************************
	�Ƴ���
	*****************************/
	void removSelf();
private:
	/****************************
	�����ȷ�ϡ���ť�ص�
	*****************************/
	void onOk(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
};

#endif