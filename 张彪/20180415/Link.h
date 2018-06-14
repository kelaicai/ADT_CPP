#ifndef LINK_H
#define LINK_H
#include<iostream>
struct Node
{
	int value;
	Node *pnext;
};

//实现带有头结点的单链表
class Link
{
public:
	//构造头结点
	Link();
	//释放链表
	~Link();
	//头插法
	void insertHead(int val);
	//尾插法
	void insertTail(int val);
	//删除元素
	void deleteNode(int val);
	//打印链表的
	void showLink();
	//修改链表的
	void motifyNode(int oldval,int newval);
	//链表查询
	void searchNode(int index);
   //赋值构造函数
	Link& operator=(const Link &src);
	//拷贝构造函数
	Link(const Link &src);
private:
	Node *phead;
};


#endif