#ifndef STACK_H
#define STACK_H

//顺序栈
const int DEFAULT_STACK_SIZE = 10;
class SqStack
{
public:
	SqStack(int);
	~SqStack();
	SqStack(const SqStack &src);
	SqStack operator=(const SqStack &src);
	//入栈操作
	void push(int val);
	//出栈操作
	void pop();
	//获取栈顶元素
	int top();
	//判断栈空
	bool empty();
	//判断栈满
	bool full();
	//显示栈上的数据
	void showStack();
private:
	int *mpstack;
	int mtop;
	int msize;
	void resizeStack();
};

#endif