#include<iostream>
#include<string>
#include<math.h>
using namespace std;

void primary()
{	cout<<"***********************************************系统正在加载页面，请稍后！***********************************************"<<endl;
	cout<<"                                                      *********"<<endl;
	cout<<"                                                  *****************"<<endl;	
	cout<<"                                              ******0:退出程序**********"<<endl;
	cout<<"                                             *******1:添加学生成绩*******"<<endl;
	cout<<"                                            ********2:显示学生成绩********"<<endl;
	cout<<"                                           *********3:修改学生成绩*********"<<endl;
	cout<<"                                          **********4:删除学生成绩**********"<<endl;
	cout<<"                                         ***********5:添加学生成绩***********"<<endl;
	cout<<"                                          **********6:查找学生成绩**********"<<endl;
	cout<<"                                           *********7:学生按总分排序*****"<<endl;
	cout<<"                                            ********8:清空学生成绩************"<<endl;
	cout<<"                                             *******9:保存学生磁盘文件***"<<endl;
	cout<<"                                              **************************"<<endl;
	cout<<"                                                  *******************"<<endl;
	cout<<"                                                       *********"<<endl;
	cout<<"*******************************************************选择序号*********************************************************"<<endl;
}
void Getout()
{	cout<<"*******************************************************谢谢使用*********************************************************"<<endl;
	exit(0);
}
struct node
{	char Name[8];
	int Math,Eng,No,Phy,Bio,Sum;
	node *next;
};
node *Input()
{	int no;
	node *head,*pn,*pt;
	head=0;
	cout<<"产生无序链表，输入学生学号与成绩："<<endl;
	cout<<"学号"<<'\t'<<"姓名"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"物理"<<'\t'<<"生物"<<'\t'<<"总分"<<endl;
	cin>>no;
	while(no!=-1)
	{	pn=new node;
		pn->No=no;
		cin>>pn->Name>>pn->Math>>pn->Eng>>pn->Phy>>pn->Bio;
		pn->Sum =pn->Math +pn->Eng +pn->Bio ;
		if(head==0)
		{	head=pn;
			pt=pn;
		}
		else
		{	pt->next =pn;
			pt=pn;
		}
		cin>>no;	
		
	}
	pt->next=0;
	cout<<"输入成功！"<<endl;
	return head;
}
node *Fix(node *head)
{	node *p=head;
	int no;
	cout<<"输入要修改成绩的学生学号：";
	cin>>no;
	cout<<endl;
	while(p->No !=no)
		p=p->next ;
	cout<<"输入修改后的成绩：";
	cin>>p->Math>>p->Eng>>p->Phy>>p->Bio;
	cout<<"修改成功!";
	return head;
}
void Show(node *head)
{	node *pn;
	pn=head;
	cout<<"学号"<<'\t'<<"姓名"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"物理"<<'\t'<<"生物"<<'\t'<<"总分"<<endl;
	while(pn!=0)
	{	cout<<pn->No <<'\t'<<pn->Name <<'\t'<<pn->Math <<'\t'<<pn->Eng<<'\t'<<pn->Phy<<'\t'<<pn->Bio <<'\t'<<pn->Sum<<endl ;
		pn=pn->next;
	}
}
node *Delete(node *head)
{	node *pc,*pa;
	int no;
	pa=head;
	cout<<"输入要删除学生的学号：";
	cin>>no;
	while(pa->No !=no)
	{	pc=pa;
		pa=pa->next ;	
	}
	pc->next =pa->next ;
	delete pa;
	return head;
}
int main()
{	char name[100],code[100];
	node *head;
	cout<<"用户名："<<endl;
	cin>>name;
	cout<<"密码："<<endl;
	cin>>code;
	if(strcmp(name,"sym")==0&&strcmp(code,"123456")==0)
	{	cout<<"登陆成功,欢迎使用学生成绩管理系统"<<endl;
		for(;;)
		{	char flag[10];
			primary();
			cin>>flag;
			if(flag[1]!=0||flag[0]<'0'||flag[0]>'9')
				cout<<"错误"<<endl;
			else
			{	switch(flag[0])
				{	case '0':Getout();break;
					case '1':head=Input();break;
					case '2':Show(head);break;
					case '3':head=Fix(head);break;
					case '4':head=Delete(head);break;
					/*	case '5':Add();break;
					case '6':Find();break;
					case '7':Sort();break;
					case '8':Emptify();break;
					case '9':File();break;*/
				}
			}
		}
	}
	else
		cout<<"登陆失败"<<endl;
	return 0;

}
