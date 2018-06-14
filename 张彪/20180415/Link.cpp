#include "Link.h"
#include<iostream>
using namespace std;
/*
int value;
Node *pnext;
*/
//构造头结点
Link::Link()
{
	phead = new Node;
	phead->value = 0;
	phead->pnext = NULL;
}
//释放链表
Link::~Link()
{
	
	Node* ptr = phead->pnext;
	Node* tmp = phead->pnext;
	while (ptr!=NULL)
	{
		tmp = ptr;
		ptr->pnext = ptr->pnext;  //保存下一个节点的地址
		free(tmp);
	}
	phead->pnext = NULL;
}

//拷贝构造函数
Link::Link(const Link &src)
{
	Node* ptr = src.phead;
	if (ptr ->pnext== NULL)
	{
		cout << "复制了一个空表" << endl;
		return;
	}
	while (ptr->pnext != NULL)
	{
		this->insertTail(ptr->value);
	}
	cout << "拷贝构造成功" << endl;
}
//赋值运算符重载

Link& Link::operator=(const Link &src)
{
	if (this != &src)
	{
		
		delete phead;  //删除原来phead指向的堆内存
		this->phead = new Node;
		Node *ptr= new Node;
		ptr->pnext = NULL;
		ptr->value = src.phead->value;
		phead = ptr;
		
		if (src.phead->pnext == NULL)
		{  
			return *this;  //此时是只有头结点的情况
		}

		ptr = src.phead->pnext;
		while (ptr != NULL)
		{
			insertTail(ptr->value);
		}
	}
	return *this;  //自赋值
}

//删除元素
void Link::deleteNode(int val)
{
	if (phead->pnext == NULL)
	{
		cout << "现在为空表" << endl;
		return;
	}
	Node* curr = phead->pnext;
	Node* pre = curr->pnext;
	while (curr->pnext != NULL )
	{
		if (pre->value == val)
		{
			break;
		}
		pre = pre->pnext;
		curr = curr->pnext;
	}
	//有两个节点的情况，将第二个调整到第一节点，并释放原第一个节点
	if (curr->pnext == NULL)
	{
		Node* tmp = phead->pnext;
		phead->pnext = phead->pnext->pnext;
		delete tmp;
		tmp = NULL;
		return;
	}
	Node *tmp =curr->pnext;  //保存当前被删除节点的地址
    
	curr->pnext=pre->pnext;  //保存被删除元素的next
	delete tmp;
	tmp = NULL;
}

//头插法
void Link::insertHead(int val)
{
	Node* ptr = phead->pnext;
	Node* snode= new Node;
	snode->value = val;
	snode->pnext = phead->pnext;
	phead->pnext = snode;
}
//尾插法
void Link::insertTail(int val)
{
	Node* ptr = phead;
	
	while (ptr->pnext!=NULL)
	{
		ptr = ptr->pnext;
	}
	Node* snode = new Node;
	snode->value = val;
	snode->pnext = ptr->pnext;
	ptr->pnext = snode;
}


//打印链表的
void Link::showLink()
{
	cout << "当前链表存储情况" << endl;
	if (phead->pnext==NULL)
	{
		return;
	}
	Node* p = phead->pnext;
	while (p!=NULL)
	{
		cout << p->value << " " ;
		p = p->pnext;
	}
	cout << endl;

}
//修改节点
void Link::motifyNode(int oldval,int newval)
{
	if (phead->pnext == NULL)
	{
		return;
	}

	Node* ptr = phead->pnext;
	while (ptr != NULL )
	{
		if (ptr->value == oldval)
		{
			ptr->value = newval;
			cout << "修改成功" << endl;
		}
		ptr = ptr->pnext;
	}	
}

void Link::searchNode(int index)
{
	if (phead->pnext == NULL)
	{
		cout << "当前链表为空" << endl;
		return;
	}

	Node* ptr = phead->pnext;
	int count = 1;

	while (ptr != NULL)
	{
		
		if (count==index)
		{
			cout << "value is" << ptr->value << endl;
		}
			count++;
			ptr = ptr->pnext;
	}
	ptr = NULL;
}

