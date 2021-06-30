#include<iostream>
#include<string>
#include<math.h>
#include<fstream>
using namespace std;
void primary()
{	cout<<"***********************************************系统正在加载页面，请稍后！***********************************************"<<endl;
	cout<<"                                                      *********"<<endl;
	cout<<"                                                  *****************"<<endl;	
	cout<<"                                              ******0:退出程序**********"<<endl;
	cout<<"                                             *******1:导入学生成绩*******"<<endl;
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
	cout<<"输入学生学号，姓名与成绩："<<endl;
	cout<<"学号"<<'\t'<<"姓名"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"物理"<<'\t'<<"生物"<<endl;
	cin>>no;
	while(no!=-1)
	{	pn=new node;
		pn->No=no;
		cin>>pn->Name>>pn->Math>>pn->Eng>>pn->Phy>>pn->Bio;
		pn->Sum =pn->Math +pn->Eng +pn->Bio +pn->Phy;
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
	while(p!=0&&p->No !=no)
		p=p->next ;
	if(p==0)
	{	cout<<"查找不到该学生；"<<endl;
	}
	else
	{	cout<<"输入修改后的成绩：";
		cin>>p->Math>>p->Eng>>p->Phy>>p->Bio;
		p->Sum =p->Math +p->Eng +p->Phy +p->Bio ;
		cout<<"修改成功!"<<endl;
	}
	
	return head;
}
void Show(node *head)
{	node *pn;
	
	cout<<"学号"<<'\t'<<"姓名"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"物理"<<'\t'<<"生物"<<'\t'<<"总分"<<endl;
	if(head->No <-5000)
		cout<<"无学生成绩信息！"<<endl;
	else
	{	pn=head;	
		while(pn!=0)
		{	cout<<pn->No <<'\t'<<pn->Name <<'\t'<<pn->Math <<'\t'<<pn->Eng<<'\t'<<pn->Phy<<'\t'<<pn->Bio <<'\t'<<pn->Sum<<endl ;
			pn=pn->next;
		}
	}
}
node *Filein()
{		char ifstreamname[200];
		node *head=0,*pn,*pt;
		int no;
		cout<<"输入要打开的文件名："<<endl;
		cin>>ifstreamname;
		ifstream infile;
		infile.open (ifstreamname,ios::in );
		if(!infile)
		{	cout<<"不能打开文件"<<endl;
			exit(1);
		}
		else
		{	infile>>no;
			while(no!=-1)
			{	pn=new node;
				pn->No =no;
				infile>>pn->Name >>pn->Math >>pn->Eng >>pn->Phy >>pn->Bio ;
				pn->Sum =pn->Math +pn->Eng +pn->Phy +pn->Bio ;
				if(head==0)
				{	head=pn;
					pt=pn;
				}
				else
				{	pt->next =pn;
					pt=pn;
				}
				infile>>no;	
			}
										 
			pt->next =0;
			infile.close ();
			cout<<"打开成功！"<<endl;
			return head;
		}
			
}
node *Delete(node *head)
{	node *pc,*pa;
	int no;
	pa=head;
	cout<<"输入要删除学生的学号：";
	cin>>no;
	if(head->No ==no)
	{	head=pa->next ;
		delete pa;
	}
	else
	{	while(pa!=0&&pa->No !=no)
		{	pc=pa;
			pa=pa->next ;	
		}
		if(pa==0)
			cout<<"不存在该学生，删除失败"<<endl;
		else
		{	pc->next =pa->next ;
			delete pa;
			cout<<"删除成功~"<<endl;
		}
	}
		
	return head;
}
/*node *Delete1(node *head,node *pn)
{	node *pc,*pa;
	pa=head;
	if(head->No ==pn->No )
	{	head=pn->next ;
		delete pa;
	}
	else
	{	while(pa->No !=pn->No )
		{	pc=pa;
			pa=pa->next ;	
		}

		pc->next =pa->next ;
		delete pa;
	}
	return head;
}*/
node *Add(node *head)
{	node *pn=head;
	node *pt;
	int no;
	cout<<"添加学生成绩，以-1结尾："<<endl;
	cout<<"学号"<<'\t'<<"姓名"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"物理"<<'\t'<<"生物"<<'\t'<<endl;
	while(pn!=0)
	{	pt=pn;
		pn=pn->next ;
		
	}
	cin>>no;
	while(no!=-1)
	{	pn=new node;
		pn->No=no;
		cin>>pn->Name>>pn->Math>>pn->Eng>>pn->Phy>>pn->Bio;
		pn->Sum =pn->Math +pn->Eng +pn->Bio +pn->Phy ;
		pt->next =pn;
		pt=pn;
		cin>>no;
	}
	pn->next =0;
	cout<<"添加成功!"<<endl;
	return head;
}
void Find(node *head)
{	int no;
	node *pn=head;
	cout<<"要寻找学生的学号：";
	cin>>no;
	if(head->No ==no)
	{	cout<<"学号"<<'\t'<<"姓名"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"物理"<<'\t'<<"生物"<<'\t'<<"总分"<<endl;
		cout<<pn->No <<'\t'<<pn->Name <<'\t'<<pn->Math <<'\t'<<pn->Eng<<'\t'<<pn->Phy<<'\t'<<pn->Bio <<'\t'<<pn->Sum<<endl ;
	}
	else
	{	while(pn!=0&&pn->No !=no)
		{	pn=pn->next ;
		}
		if(pn==0)
			cout<<"无法找到该学生！"<<endl;
		else
		{	cout<<"学号"<<'\t'<<"姓名"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"物理"<<'\t'<<"生物"<<'\t'<<"总分"<<endl;
			cout<<pn->No <<'\t'<<pn->Name <<'\t'<<pn->Math <<'\t'<<pn->Eng<<'\t'<<pn->Phy<<'\t'<<pn->Bio <<'\t'<<pn->Sum<<endl ;
		}
	}
	
}
/*node *Insert(node *head,node *pn)
{	node *pa,*pc;
	pa=pc=head;
	if(pn->Sum >=head->Sum )
	{	pn->next =head;
		head=pn;
	}
	while(pc!=0&&pc->Sum >=pn->Sum )
	{	pa=pc;
		pc=pc->next ;
	}
	pa->next =pn;
	pn->next =pc;
	return head;
}*/
node *Inputfinal()
{	char flag[10];
    node *head;
	cout<<"请选择：1.输入学生成绩          2：从文件中导入"<<endl;
	cin>>flag;
	if(flag[1]!=0||flag[0]<'0'||flag[0]>'9')
		cout<<"请输入正确的数字！"<<endl;
	else
	{	switch(flag[0])
		{	case '1':head=Input();break;
			case '2':head=Filein();
		}
	}
	return head;
}
node *Sort(node *head)
{	int i,j,k=0;
	char name[100];
	int m,e,p,b,n;
	node *pa=head,*pc,*pn;
	while(pa!=0)
	{	k++;
		pa=pa->next ;
	}
	for(i=0;i<k-1;i++)
	{	pn=head;
		for(j=0;j<k-i-1;j++)
		{	pa=pn;
			pc=pn->next ;
			if(pa->Sum <=pc->Sum )
			{	int s=pa->Sum ;
				pa->Sum =pc->Sum ;
				pc->Sum =s;

				strcpy(name,pa->Name );
				strcpy(pa->Name ,pc->Name );
				strcpy(pc->Name ,name);

				m=pa->Math ;
				pa->Math =pc->Math ;
				pc->Math =m;

				e=pa->Eng ;
				pa->Eng =pc->Eng ;
				pc->Eng =e;

				p=pa->Phy ;
				pa->Phy =pc->Phy ;
				pc->Phy =p;

				b=pa->Bio ;
				pa->Bio =pc->Bio ;
				pc->Bio =b;

				n=pa->No ;
				pa->No =pc->No ;
				pc->No =n;
			}
			pn=pn->next ;
		}
		
	}
	cout<<"已成功排序"<<endl;
	return head;
}
void Emptify(node *head)
{	node *pn=head;
	while(head!=0)
	{	head=head->next ;
		delete pn;
		pn=head;
	}
	cout<<"已删除所有学生成绩"<<endl;
}

void Fileout(node *head)
{		char *path="D://student score.txt";
		node *pn=head;
		ofstream out(path);
		if(out)
		{	out<<"学号"<<'\t'<<"姓名"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"物理"<<'\t'<<"生物"<<'\t'<<"总分"<<endl;
			while(pn!=0)
			{	out<<pn->No <<'\t'<<pn->Name <<'\t'<<pn->Math <<'\t'<<pn->Eng<<'\t'<<pn->Phy<<'\t'<<pn->Bio <<'\t'<<pn->Sum<<endl ;
				pn=pn->next;
			}
		cout<<"已保存。"<<endl;	
		}			
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
				cout<<"请输入正确的数字！"<<endl;
			else
			{	switch(flag[0])
				{	case '0':Getout();break;
			    	case '1':head=Inputfinal();break;
					case '2':Show(head);break;
					case '3':head=Fix(head);break;
					case '4':head=Delete(head);break;
					case '5':head=Add(head);break;
					case '6':Find(head);break;
					case '7':head=Sort(head);break;
					case '8':Emptify(head);break;
					case '9':Fileout(head);break;
					
				}
			}
		}
	}
	else
		cout<<"登陆失败"<<endl;
	return 0;
}
