#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class student
{
public:
	char name[20];
	int no;
	int score[5];
	/*int total;
	int average;
	int last;*/

	student()
	{};
	void Getout();
	void Add();
	void Show();
	void Find();
	void Modify();
	void Deleted();
	void Plus();
	void Sort();
	void Save();
	void Emptify();
	void Load();
};
student stu[200];
int n=0;
void primary()
{	cout<<"***********************************************ϵͳ���ڼ���ҳ�棬���Ժ�***********************************************"<<endl;
	cout<<"                                                      *********"<<endl;
	cout<<"                                                  *****************"<<endl;	
	cout<<"                                              ******0:�˳�����**********"<<endl;
	cout<<"                                             *******1:����ѧ���ɼ�*******"<<endl;
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
void student::Getout()
{	cout<<"*******************************************************ллʹ��*********************************************************"<<endl;
	exit(0);
}
void student::Add ()
{	int no;

	cout<<"����ѧ��ѧ�ţ�������ɼ���"<<endl;
	cout<<"ѧ��"<<'\t'<<"����"<<'\t'<<"��ѧ"<<'\t'<<"Ӣ��"<<'\t'<<"����"<<'\t'<<"����"<<endl;
	cin>>no;
	while(no!=-1)
	{	stu[n].no =no;
		cin>>stu[n].name ;
		stu[n].score [4]=0;
		for(int i=0;i<4;i++)
		{	cin>>stu[n].score [i];
			
			
		}
		for(int j=0;j<4;j++)
				stu[n].score [4]+=stu[n].score [j];
		n++;
		cin>>no;
		
	}
	cout<<"������"<<n<<"��ѧ���ĳɼ�"<<endl;
}
void student::Show ()
{	cout<<"ѧ��"<<'\t'<<"����"<<'\t'<<"��ѧ"<<'\t'<<"Ӣ��"<<'\t'<<"����"<<'\t'<<"����"<<'\t'<<"�ܷ�"<<endl;
	for(int i=0;i<n;i++)
	{	cout<<stu[i].no <<'\t'<<stu[i].name<<'\t' ;
		for(int j=0;j<5;j++) 
		{	cout<<stu[i].score [j]<<'\t';
			
		}
		cout<<endl;
	}
}
void student::Modify ()
{	int no;
	int i=0;
	cout<<"����Ҫ�޸�ѧ����ѧ�ţ�";
		cin>>no;
	while(i<=n&&stu[i].no !=no)
		i++;
	if(i>n)
		cout<<"���Ҳ�����ѧ����"<<endl;
	else
	{	cout<<"������ѧ���ɼ���";
		stu[i].score [4]=0;
		for(int j=0;j<4;j++)
		{	cin>>stu[i].score [j];
			
		}
		for(int k=0;k<4;k++)
			stu[i].score [4]+=stu[i].score [k];
		cout<<"�޸ĳɹ���"<<endl;	
	}
}
	
int main() 
{	char name[100],code[100];
	student s;
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
				cout<<"��������ȷ�����֣�"<<endl;
			else
			{	switch(flag[0])
				{	case '0':s.Getout ();break;
			    	case '1':s.Add ();break;
					case '2':s.Show ();break;
					case '3':s.Modify ();break;
				/*	case '4':s.Deleted ();break;
					case '5':s.Plus ();break;
					case '6':s.Find ();break;
					case '7':s.Save ();break;
					case '8':s.Emptify ();break;
					case '9':s.Save ();break;*/
					
				}
			}
		}
	}
	else
		cout<<"��½ʧ��"<<endl;
	return 0;
}
