#include "DTSystem.h"
#include<iostream>

using namespace std;
/*
class DTSystem
{
public:
	DTSystem();
	void run();
	void showMainMenu();
	void showChildMenu();
private:
	bool isSysRunning;
	Link mLink;
	SqStack mStack;
	CircleQue mQueue;
};
*/

DTSystem::DTSystem() : mLink() , mStack(10) , mQueue(10)
{
     isSysRunning=true;
}

void DTSystem::run()
{
	showMainMenu();
}

void DTSystem::showMainMenu()
{
	int choise = 0;
	while (isSysRunning)
	{

		cout << "===========================================" << endl;
		cout << "1.单链表  2.循环队列  3.顺序栈  4.退出系统 " << endl;
		cout << "===========================================" << endl;
		cout << "请选择：                                   " << endl;
		cin >> choise;
		if (choise != 4)
		{
			showChildMenu(choise);
		}
		else
		{
			cout << "byebye，系统退出！" << endl;
			isSysRunning = false;
		}
	}
	cout << endl;
		
}

void DTSystem::showChildMenu(int choise)
{
	cout << "=======================" << endl;
	cout << "当前数据结构为： ";

	switch (choise)
	{
	case  1:
		cout << "单链表" << endl;
		operationLink();
		break;
	case  2:
		cout << "循环队列" << endl;
		DTSystem::operationQueue();
		break;
	case  3:
		cout << "顺序栈 " << endl;
		DTSystem::operationStack();
		break;

	default:  
		cout << "您的输入有误" << endl;
	}

} 
//
void displayLink()
{
	cout << " 1.增加" << endl;
	cout << " 2.删除" << endl;
	cout << " 3.修改" << endl;
	cout << " 4.查询" << endl;
	cout << " 5.返回" << endl;
}
void displayStack()
{
	cout << " 1.增加" << endl;
	cout << " 2.删除" << endl;
	cout << " 3.获取栈顶元素" << endl;
	cout << " 4.查询" << endl;
	cout << " 5.返回上一级菜单" << endl;
}
void DTSystem::operationLink()
{
	

	 int choise = 0;
	 int val = 0;
	 bool flag = true;
	 bool cont_flag = true;
	 int  arr[2] = { 0 };
	 while( cont_flag )
	 {
		 displayLink();  //显示操作界面
		 cout << "请输入操作选项" << endl;
		 cin >> choise;
		 switch (choise)
		 {
		 case 1:
			 while (flag)
			 {
				 cout << "请输入要加入的数据 继续添加 true，结束输入false" << endl;
				 cin >> val;
				 mLink.insertTail(val);
				 cout << "是否要继续输入" << endl;
				 cin >> flag;
			 }
			 cout << "添加成功" << endl;
			 flag = true;
			 break;

		 case 2:
			 cout << "请输入要删除的数据" << endl;
			 cin >> val;
			 mLink.deleteNode(val);
			 cout << "删除成功" << endl;
			 break;
		 case 3:

			 cout << "请输入要修改的数" << endl;
			 cin >> arr[0];
			 cout << "输入要修改成的数字" << endl;
			 cin >> arr[1];
			 mLink.motifyNode(arr[0], arr[1]);
			 cout << "修改成功" << endl;

			 break;
#if 0
		 case 4:
			 cout << "你要查询第几个数？" << endl;
			 cin >> val;
			 mLink.searchNode(val);
			 cout << "查询结束" << endl;
			 break;
#endif  
		 case 4:
			 mLink.showLink();
			 cout << "查询结束" << endl;

			 break;
		 case 5:
			 cout << "现在退出链表操作" << endl;
			 cont_flag = false;
			 break;
		 default:  cout << "输入选项不合法" << endl;
			 // mLink.
		 }//swicth
		 
		 cout << endl;
	 }//while
}

void displayQueue()
{

	cout << "1.添加数据" << endl;
	cout << "2.获取队首元素" << endl;
	cout << "3.获取队尾元素" << endl;
	cout << "4.删除队列" << endl;
	cout << "5.查询" << endl;
	cout << "6.返回上一级菜单" << endl;
}
void DTSystem::operationQueue()
{
	bool cont_flag = true; //k控制是否继续要操作本数据结构
	int val = 0;           //定义的接收键盘数据要输入的数据
	
	int choise = 0;       //定义的菜单选项接收项
	bool flag = true;
	while (cont_flag)
	{

		displayQueue();
			cout << "请输入选项" << endl;
		cin >> choise;

		switch (choise)
		{

		case 1:
			// 定义的控制选项内部的循环控制标志
			while (flag)
			{
				cout << "请输入数据" << endl;
				cin >> val;
				mQueue.addQue(val);
				cout << "是否要继续输入数据" << endl;
				cin >> flag;
			}
			cout << "添加数据成功" << endl;
			flag = true;
			
			break;

		case 2:
			cout << "当前队首元素是" << mQueue.front()<< endl;
		//	mQueue.showQueue();
			break;

		case 3:
			cout << "当前队尾部元素是" << mQueue.rear() << endl;
		//	mQueue.showQueue();
			break;

		case 4:
			cout << "删除队列开始" << endl;
			mQueue.delQue();
			
			cont_flag = false;
			break;
		case 5:
			//查询相当于遍历
			cout << "show queue" << endl;
			mQueue.showQueue();
			break;
		case 6:
			cout << "现在退出队列操作" << endl;
			cont_flag = false;
			break;
		default:cout << "输入有误" << endl;

		}
		cout << endl;
	}


}
void DTSystem::operationStack()
{
	bool cont_flag = true;
	int val = 0;
	while (cont_flag)
	{
		displayStack();
		bool flag = true;
		int choise = 0;
		cin >> choise;
		switch(choise)
		{
			
			case 1:
				while (flag)
				{
					cout << "请输入要加入的数据 继续添加 true，结束输入false" << endl;
					cin >> val;
					mStack.push(val);
					cout << "是否要继续输入" << endl;
					cin >> flag;
				}
				cout << "输入成功" << endl;
			//	mStack.showStack();
				flag = true;
				break;

			case 2:
				flag = true;
				while (flag)
				{
					cout << "删除数据" << mStack.top() << " " << endl;
					mStack.pop();
					cout << "是否要继续" << endl;
					cin >> flag;
				}
				cout << "删除数据成功" << endl;
				flag = true;
			//	mStack.showStack();
				break;

			case 3:
				cout << "当前栈顶元素为" << mStack.top()<<endl;
				break;
			case 4:
				cout << "查询遍历栈" << endl;
				displayStack();
				break;

			case 5:
				cout << "返回" << endl;
				cont_flag = false;
				break;
			default:cout << "您的输入不合法" << endl;
		}//swicth
		cout << endl;
	}//while
}