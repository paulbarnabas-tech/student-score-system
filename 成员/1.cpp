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
void student::Getout()
{	cout<<"*******************************************************谢谢使用*********************************************************"<<endl;
	exit(0);
}
void student::Add ()
{	int no;

	cout<<"输入学生学号，姓名与成绩："<<endl;
	cout<<"学号"<<'\t'<<"姓名"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"物理"<<'\t'<<"生物"<<endl;
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
	cout<<"已输入"<<n<<"个学生的成绩"<<endl;
}
void student::Show ()
{	cout<<"学号"<<'\t'<<"姓名"<<'\t'<<"数学"<<'\t'<<"英语"<<'\t'<<"物理"<<'\t'<<"生物"<<'\t'<<"总分"<<endl;
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
	cout<<"输入要修改学生的学号：";
		cin>>no;
	while(i<=n&&stu[i].no !=no)
		i++;
	if(i>n)
		cout<<"查找不到该学生；"<<endl;
	else
	{	cout<<"请输入学生成绩：";
		stu[i].score [4]=0;
		for(int j=0;j<4;j++)
		{	cin>>stu[i].score [j];
			
		}
		for(int k=0;k<4;k++)
			stu[i].score [4]+=stu[i].score [k];
		cout<<"修改成功！"<<endl;	
	}
}
	
int main() 
{	char name[100],code[100];
	student s;
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
		cout<<"登陆失败"<<endl;
	return 0;
}
