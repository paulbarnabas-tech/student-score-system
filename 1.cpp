#include<iostream>
#include<string>
#include<math.h>
using namespace std;

void primary()
{	cout<<"***********************************************ϵͳ���ڼ���ҳ�棬���Ժ�***********************************************"<<endl;
	cout<<"                                                      *********"<<endl;
	cout<<"                                                  *****************"<<endl;	
	cout<<"                                              ******0:�˳�����**********"<<endl;
	cout<<"                                             *******1:���ѧ���ɼ�*******"<<endl;
	cout<<"                                            ********2:��ʾѧ���ɼ�********"<<endl;
	cout<<"                                           *********3:�޸�ѧ���ɼ�*********"<<endl;
	cout<<"                                          **********4:ɾ��ѧ���ɼ�**********"<<endl;
	cout<<"                                         ***********5:���ѧ���ɼ�***********"<<endl;
	cout<<"                                          **********6:����ѧ���ɼ�**********"<<endl;
	cout<<"                                           *********7:ѧ�����ܷ�����*****"<<endl;
	cout<<"                                            ********8:���ѧ���ɼ�************"<<endl;
	cout<<"                                             *******9:����ѧ�������ļ�***"<<endl;
	cout<<"                                              **************************"<<endl;
	cout<<"                                                  *******************"<<endl;
	cout<<"                                                       *********"<<endl;
	cout<<"*******************************************************ѡ�����*********************************************************"<<endl;
}
void Getout()
{	cout<<"*******************************************************ллʹ��*********************************************************"<<endl;
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
	cout<<"����������������ѧ��ѧ����ɼ���"<<endl;
	cout<<"ѧ��"<<'\t'<<"����"<<'\t'<<"��ѧ"<<'\t'<<"Ӣ��"<<'\t'<<"����"<<'\t'<<"����"<<'\t'<<"�ܷ�"<<endl;
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
	cout<<"����ɹ���"<<endl;
	return head;
}
node *Fix(node *head)
{	node *p=head;
	int no;
	cout<<"����Ҫ�޸ĳɼ���ѧ��ѧ�ţ�";
	cin>>no;
	cout<<endl;
	while(p->No !=no)
		p=p->next ;
	cout<<"�����޸ĺ�ĳɼ���";
	cin>>p->Math>>p->Eng>>p->Phy>>p->Bio;
	cout<<"�޸ĳɹ�!";
	return head;
}
void Show(node *head)
{	node *pn;
	pn=head;
	cout<<"ѧ��"<<'\t'<<"����"<<'\t'<<"��ѧ"<<'\t'<<"Ӣ��"<<'\t'<<"����"<<'\t'<<"����"<<'\t'<<"�ܷ�"<<endl;
	while(pn!=0)
	{	cout<<pn->No <<'\t'<<pn->Name <<'\t'<<pn->Math <<'\t'<<pn->Eng<<'\t'<<pn->Phy<<'\t'<<pn->Bio <<'\t'<<pn->Sum<<endl ;
		pn=pn->next;
	}
}
node *Delete(node *head)
{	node *pc,*pa;
	int no;
	pa=head;
	cout<<"����Ҫɾ��ѧ����ѧ�ţ�";
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
	cout<<"�û�����"<<endl;
	cin>>name;
	cout<<"���룺"<<endl;
	cin>>code;
	if(strcmp(name,"sym")==0&&strcmp(code,"123456")==0)
	{	cout<<"��½�ɹ�,��ӭʹ��ѧ���ɼ�����ϵͳ"<<endl;
		for(;;)
		{	char flag[10];
			primary();
			cin>>flag;
			if(flag[1]!=0||flag[0]<'0'||flag[0]>'9')
				cout<<"����"<<endl;
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
		cout<<"��½ʧ��"<<endl;
	return 0;

}
