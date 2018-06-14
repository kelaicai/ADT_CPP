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
		cout << "1.������  2.ѭ������  3.˳��ջ  4.�˳�ϵͳ " << endl;
		cout << "===========================================" << endl;
		cout << "��ѡ��                                   " << endl;
		cin >> choise;
		if (choise != 4)
		{
			showChildMenu(choise);
		}
		else
		{
			cout << "byebye��ϵͳ�˳���" << endl;
			isSysRunning = false;
		}
	}
	cout << endl;
		
}

void DTSystem::showChildMenu(int choise)
{
	cout << "=======================" << endl;
	cout << "��ǰ���ݽṹΪ�� ";

	switch (choise)
	{
	case  1:
		cout << "������" << endl;
		operationLink();
		break;
	case  2:
		cout << "ѭ������" << endl;
		DTSystem::operationQueue();
		break;
	case  3:
		cout << "˳��ջ " << endl;
		DTSystem::operationStack();
		break;

	default:  
		cout << "������������" << endl;
	}

} 
//
void displayLink()
{
	cout << " 1.����" << endl;
	cout << " 2.ɾ��" << endl;
	cout << " 3.�޸�" << endl;
	cout << " 4.��ѯ" << endl;
	cout << " 5.����" << endl;
}
void displayStack()
{
	cout << " 1.����" << endl;
	cout << " 2.ɾ��" << endl;
	cout << " 3.��ȡջ��Ԫ��" << endl;
	cout << " 4.��ѯ" << endl;
	cout << " 5.������һ���˵�" << endl;
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
		 displayLink();  //��ʾ��������
		 cout << "���������ѡ��" << endl;
		 cin >> choise;
		 switch (choise)
		 {
		 case 1:
			 while (flag)
			 {
				 cout << "������Ҫ��������� ������� true����������false" << endl;
				 cin >> val;
				 mLink.insertTail(val);
				 cout << "�Ƿ�Ҫ��������" << endl;
				 cin >> flag;
			 }
			 cout << "��ӳɹ�" << endl;
			 flag = true;
			 break;

		 case 2:
			 cout << "������Ҫɾ��������" << endl;
			 cin >> val;
			 mLink.deleteNode(val);
			 cout << "ɾ���ɹ�" << endl;
			 break;
		 case 3:

			 cout << "������Ҫ�޸ĵ���" << endl;
			 cin >> arr[0];
			 cout << "����Ҫ�޸ĳɵ�����" << endl;
			 cin >> arr[1];
			 mLink.motifyNode(arr[0], arr[1]);
			 cout << "�޸ĳɹ�" << endl;

			 break;
#if 0
		 case 4:
			 cout << "��Ҫ��ѯ�ڼ�������" << endl;
			 cin >> val;
			 mLink.searchNode(val);
			 cout << "��ѯ����" << endl;
			 break;
#endif  
		 case 4:
			 mLink.showLink();
			 cout << "��ѯ����" << endl;

			 break;
		 case 5:
			 cout << "�����˳��������" << endl;
			 cont_flag = false;
			 break;
		 default:  cout << "����ѡ��Ϸ�" << endl;
			 // mLink.
		 }//swicth
		 
		 cout << endl;
	 }//while
}

void displayQueue()
{

	cout << "1.�������" << endl;
	cout << "2.��ȡ����Ԫ��" << endl;
	cout << "3.��ȡ��βԪ��" << endl;
	cout << "4.ɾ������" << endl;
	cout << "5.��ѯ" << endl;
	cout << "6.������һ���˵�" << endl;
}
void DTSystem::operationQueue()
{
	bool cont_flag = true; //k�����Ƿ����Ҫ���������ݽṹ
	int val = 0;           //����Ľ��ռ�������Ҫ���������
	
	int choise = 0;       //����Ĳ˵�ѡ�������
	bool flag = true;
	while (cont_flag)
	{

		displayQueue();
			cout << "������ѡ��" << endl;
		cin >> choise;

		switch (choise)
		{

		case 1:
			// ����Ŀ���ѡ���ڲ���ѭ�����Ʊ�־
			while (flag)
			{
				cout << "����������" << endl;
				cin >> val;
				mQueue.addQue(val);
				cout << "�Ƿ�Ҫ������������" << endl;
				cin >> flag;
			}
			cout << "������ݳɹ�" << endl;
			flag = true;
			
			break;

		case 2:
			cout << "��ǰ����Ԫ����" << mQueue.front()<< endl;
		//	mQueue.showQueue();
			break;

		case 3:
			cout << "��ǰ��β��Ԫ����" << mQueue.rear() << endl;
		//	mQueue.showQueue();
			break;

		case 4:
			cout << "ɾ�����п�ʼ" << endl;
			mQueue.delQue();
			
			cont_flag = false;
			break;
		case 5:
			//��ѯ�൱�ڱ���
			cout << "show queue" << endl;
			mQueue.showQueue();
			break;
		case 6:
			cout << "�����˳����в���" << endl;
			cont_flag = false;
			break;
		default:cout << "��������" << endl;

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
					cout << "������Ҫ��������� ������� true����������false" << endl;
					cin >> val;
					mStack.push(val);
					cout << "�Ƿ�Ҫ��������" << endl;
					cin >> flag;
				}
				cout << "����ɹ�" << endl;
			//	mStack.showStack();
				flag = true;
				break;

			case 2:
				flag = true;
				while (flag)
				{
					cout << "ɾ������" << mStack.top() << " " << endl;
					mStack.pop();
					cout << "�Ƿ�Ҫ����" << endl;
					cin >> flag;
				}
				cout << "ɾ�����ݳɹ�" << endl;
				flag = true;
			//	mStack.showStack();
				break;

			case 3:
				cout << "��ǰջ��Ԫ��Ϊ" << mStack.top()<<endl;
				break;
			case 4:
				cout << "��ѯ����ջ" << endl;
				displayStack();
				break;

			case 5:
				cout << "����" << endl;
				cont_flag = false;
				break;
			default:cout << "�������벻�Ϸ�" << endl;
		}//swicth
		cout << endl;
	}//while
}