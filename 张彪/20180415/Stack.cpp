#include "Stack.h"
#include<iostream>
using namespace std;
/*    member vars
int *mpstack;
int mtop;
int msize;

*/
//Ĭ�ϴ������Ĺ��캯��
SqStack::SqStack(int size=10)
{
	msize =size;
	mtop = -1;
	mpstack = new int[msize];
}
//��������
SqStack::~SqStack()
{
	delete[] mpstack;
	mtop = -1;
	msize = 0;
}
//�������캯��
SqStack::SqStack(const SqStack &src)
{
	msize = src.msize;
	delete[] mpstack;
	int* tmp = new int[msize]; 
	mpstack = tmp;
	for (int i = 0; i < msize; i++)
	{
		mpstack[i] = src.mpstack[i];
	}
	
}

SqStack SqStack::operator=(const SqStack &src)
{
	if (this == &src) //�Ը�ֵ
	{
		return *this;
	}
	//src��msize���ܱ�this�����msize��Ҳ����С
	msize = src.msize;
	delete[] mpstack;
	int *ptr = new int[msize];
	mpstack = ptr;
	ptr = NULL;
	for (int i = 0; i < msize; i++)
	{
		mpstack[i] = src.mpstack[i];
	}
	return *this;
}
//��ջ����
void SqStack::push(int val)
{
	if (full())
	{
		cout << "stack is full" << endl;
		//resizeStack():
		return;
	}
	mpstack[++mtop] = val;
}
//��ջ����
void SqStack::pop()
{
	if (empty())
	{
		cout << "ջ�Ѿ���" << endl;
		return;
	}
	mtop--;
}
//��ȡջ��Ԫ��
int SqStack::top()
{
	if (empty())
	{
		throw "stack is empty";
	}
	return mpstack[mtop];
}

//�ж�ջ��
bool SqStack::empty()
{
	return mtop == -1;
}
//�ж�ջ��
bool SqStack::full()
{
	return mtop == msize - 1;
}

void SqStack::showStack()
{
	cout << "��ǰ˳��ջ�е�����  ջ��---��ջ��" << endl;
	if (empty())
	{
		cout << "��ǰջΪ��" << endl;
		return;
	}
	
	for (int i = 0; i <= mtop; i++)
	{
		cout << mpstack[i] << " ";
	}
	cout << endl;

}
/**/
void SqStack::resizeStack()
{
	int size =msize*2;
	int *tmp = new int[size];
	for (int i = 0; i < size/2; i++)
	{
		tmp[i] = mpstack[i];
	}
	delete[] mpstack;
	mpstack = tmp;
	msize = size;

}
