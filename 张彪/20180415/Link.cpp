#include "Link.h"
#include<iostream>
using namespace std;
/*
int value;
Node *pnext;
*/
//����ͷ���
Link::Link()
{
	phead = new Node;
	phead->value = 0;
	phead->pnext = NULL;
}
//�ͷ�����
Link::~Link()
{
	
	Node* ptr = phead->pnext;
	Node* tmp = phead->pnext;
	while (ptr!=NULL)
	{
		tmp = ptr;
		ptr->pnext = ptr->pnext;  //������һ���ڵ�ĵ�ַ
		free(tmp);
	}
	phead->pnext = NULL;
}

//�������캯��
Link::Link(const Link &src)
{
	Node* ptr = src.phead;
	if (ptr ->pnext== NULL)
	{
		cout << "������һ���ձ�" << endl;
		return;
	}
	while (ptr->pnext != NULL)
	{
		this->insertTail(ptr->value);
	}
	cout << "��������ɹ�" << endl;
}
//��ֵ���������

Link& Link::operator=(const Link &src)
{
	if (this != &src)
	{
		
		delete phead;  //ɾ��ԭ��pheadָ��Ķ��ڴ�
		this->phead = new Node;
		Node *ptr= new Node;
		ptr->pnext = NULL;
		ptr->value = src.phead->value;
		phead = ptr;
		
		if (src.phead->pnext == NULL)
		{  
			return *this;  //��ʱ��ֻ��ͷ�������
		}

		ptr = src.phead->pnext;
		while (ptr != NULL)
		{
			insertTail(ptr->value);
		}
	}
	return *this;  //�Ը�ֵ
}

//ɾ��Ԫ��
void Link::deleteNode(int val)
{
	if (phead->pnext == NULL)
	{
		cout << "����Ϊ�ձ�" << endl;
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
	//�������ڵ����������ڶ�����������һ�ڵ㣬���ͷ�ԭ��һ���ڵ�
	if (curr->pnext == NULL)
	{
		Node* tmp = phead->pnext;
		phead->pnext = phead->pnext->pnext;
		delete tmp;
		tmp = NULL;
		return;
	}
	Node *tmp =curr->pnext;  //���浱ǰ��ɾ���ڵ�ĵ�ַ
    
	curr->pnext=pre->pnext;  //���汻ɾ��Ԫ�ص�next
	delete tmp;
	tmp = NULL;
}

//ͷ�巨
void Link::insertHead(int val)
{
	Node* ptr = phead->pnext;
	Node* snode= new Node;
	snode->value = val;
	snode->pnext = phead->pnext;
	phead->pnext = snode;
}
//β�巨
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


//��ӡ�����
void Link::showLink()
{
	cout << "��ǰ����洢���" << endl;
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
//�޸Ľڵ�
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
			cout << "�޸ĳɹ�" << endl;
		}
		ptr = ptr->pnext;
	}	
}

void Link::searchNode(int index)
{
	if (phead->pnext == NULL)
	{
		cout << "��ǰ����Ϊ��" << endl;
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

