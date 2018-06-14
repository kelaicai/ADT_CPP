#ifndef DTSystem_H
#define DTSystem_H
#include"Link.h"
#include"Queue.h"
#include"Stack.h"
class DTSystem
{
public:
	DTSystem();
	void run();
	void showMainMenu();
	void showChildMenu(int choise);
	void operationLink();
	void operationQueue();
	void operationStack();
private:
	bool isSysRunning;
	Link mLink;
	SqStack mStack;
	CircleQue mQueue;
};
#endif