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


//拷贝构造函数
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
	mpQue = NULL;  //防止出现野指针
	mfront = 0;
	mrear = 0;
}

//队列赋值重载
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
//扩容
/**/
void CircleQue::resizeQueue()
{
	int size = 2 * msize;
	int *tmp = new int[size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = mpQue[i];
	}
	delete[] mpQue;   //除去和原来不够的队列的空间
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
		cout << "先队列已满，现在扩容" << endl;
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
		cout << "现在为空队列无法删除" << endl;
		return;
	}
	mrear = 0;
	mfront = mrear;
	cout << "队列删除成功" << endl;
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
		cout << "当前队列为空" << endl;
		return 0;
	}
	return mpQue[mrear-1];
}



void CircleQue::showQueue()
{
	cout << "现在队列内的数据如下" << endl;
	for (int i = mfront; i< mrear;i++)
	{
		cout << mpQue[i] << " ";
	}
	cout << endl;
}

