#include"Queue.h" 
#include<iostream>
using namespace std;
/*
int *mpQue;
int msize;
int mfront;
int mrear;
*/

CircleQue::CircleQue(int size=10)
{
	msize = size;
	mfront = 0;
	mrear = 0;
	mpQue = new int[msize];
}


//�������캯��
CircleQue::CircleQue(const CircleQue &src)
{
	mfront = src.mfront;
	mrear = src.mrear;
	msize = src.msize;
	mpQue = new int[msize];
	for (int i = 0; i < msize; i++)
	{
		mpQue[i] = src.mpQue[i];
	}
}

CircleQue::~CircleQue()
{
	delete[] mpQue;
	mpQue = NULL;  //��ֹ����Ұָ��
	mfront = 0;
	mrear = 0;
}

//���и�ֵ����
CircleQue& CircleQue::operator = (const CircleQue &src)
{
	if (this !=&src)
	{
		delete []mpQue;
		msize = src.msize;
		int *tmp = new int[msize];

		
		mfront = src.mfront;
		mrear = src.mrear;

		mpQue = tmp;
		for (int i = 0; i <msize; i++)
		{
			mpQue[i] = src.mpQue[i];
		}
		return *this;
	}
	return *this;
}
//����
/**/
void CircleQue::resizeQueue()
{
	int size = 2 * msize;
	int *tmp = new int[size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = mpQue[i];
	}
	delete[] mpQue;   //��ȥ��ԭ�������Ķ��еĿռ�
	mpQue = tmp;
	msize = size;
}

bool CircleQue::full()
{
	return mfront == (mrear + 1) % msize;
}

bool CircleQue::empty()
{
	return mrear == mfront;
}

void CircleQue::addQue(int val)
{
	if (full())
	{
		cout << "�ȶ�����������������" << endl;
		resizeQueue();
		return;
	}
	mpQue[mrear] = val;
	mrear = (mrear + 1) % msize;
}

void CircleQue::delQue()
{
	if (empty())
	{
		cout << "����Ϊ�ն����޷�ɾ��" << endl;
		return;
	}
	mrear = 0;
	mfront = mrear;
	cout << "����ɾ���ɹ�" << endl;
}

int CircleQue::front()
{
	if (empty())
	{
		return 0;
	}
	return  mpQue[mfront];
}



int CircleQue::rear()
{
	if (empty())
	{
		cout << "��ǰ����Ϊ��" << endl;
		return 0;
	}
	return mpQue[mrear-1];
}



void CircleQue::showQueue()
{
	cout << "���ڶ����ڵ���������" << endl;
	for (int i = mfront; i< mrear;i++)
	{
		cout << mpQue[i] << " ";
	}
	cout << endl;
}

