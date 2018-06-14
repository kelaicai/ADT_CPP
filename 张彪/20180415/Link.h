#ifndef LINK_H
#define LINK_H
#include<iostream>
struct Node
{
	int value;
	Node *pnext;
};

//ʵ�ִ���ͷ���ĵ�����
class Link
{
public:
	//����ͷ���
	Link();
	//�ͷ�����
	~Link();
	//ͷ�巨
	void insertHead(int val);
	//β�巨
	void insertTail(int val);
	//ɾ��Ԫ��
	void deleteNode(int val);
	//��ӡ�����
	void showLink();
	//�޸������
	void motifyNode(int oldval,int newval);
	//�����ѯ
	void searchNode(int index);
   //��ֵ���캯��
	Link& operator=(const Link &src);
	//�������캯��
	Link(const Link &src);
private:
	Node *phead;
};


#endif