#ifndef STACK_H
#define STACK_H

//˳��ջ
const int DEFAULT_STACK_SIZE = 10;
class SqStack
{
public:
	SqStack(int);
	~SqStack();
	SqStack(const SqStack &src);
	SqStack operator=(const SqStack &src);
	//��ջ����
	void push(int val);
	//��ջ����
	void pop();
	//��ȡջ��Ԫ��
	int top();
	//�ж�ջ��
	bool empty();
	//�ж�ջ��
	bool full();
	//��ʾջ�ϵ�����
	void showStack();
private:
	int *mpstack;
	int mtop;
	int msize;
	void resizeStack();
};

#endif