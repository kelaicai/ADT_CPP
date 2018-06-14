#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
//—≠ª∑∂”¡–
const int DEFAULT_QUEUE_SIZE = 10;
class CircleQue
{
public:
	CircleQue(int);
	~CircleQue();
	 CircleQue(const CircleQue &src);
	CircleQue& operator=(const CircleQue &src);

	void addQue(int val);
	void delQue();
	int front();
	int rear();

	bool empty();
	bool full();
	void showQueue();
private:
	int *mpQue;
	int msize;
	int mfront;
	int mrear;
	void resizeQueue();
};


#endif