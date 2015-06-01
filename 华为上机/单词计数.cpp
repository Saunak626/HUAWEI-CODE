#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

#define  N 2048
int compare(const void *p,const void *q){
	return *(int *)p-*(int *)q;
}

//��дתСд
string tolow(string s){
	for(int i=0;i<s.length();i++)
		if(s[i]>='A'&&s[i]<='Z')
			s[i]=s[i]+32;

		return s;
}

void process(string tmp)
{
	 string word[N]={""};//�浥��
	 int  num[N]={0};//�浥�ʸ���
	 int  num2[N]={0};//�浥�ʸ���,��Ϊ�м������num����䶯����num2�洢����֮ǰ�ĵ��ʸ���

	 int m=0,i,j;
	 string str="";

	 for (i=0;i<tmp.length();i++)
	 {
		 if (tmp[i]==' ' || tmp[i]==',' || tmp[i]=='.')
		 {
				word[m++]=str;
				str="";
		 }
		 else 
		 {
			//���±�Ϊstr.length()���ַ�֮ǰ����1���ַ�tmp[i]
		    str.insert(str.length(),1,tmp[i]);
		 }
	 }

	 for (i=0;i<m;i++)
		 for(j=0;j<m;j++)
			 if (word[i]==word[j]){
				  num[i]++;
				  num2[i]++;//������ʵһ��
			 }

	 qsort(num,m,sizeof(int),compare);

     int max_num = num[m-1];//���Ƶ������
	 int second_num = num[m-2];//�ڶ�������

	 for(i=3;i<m;i++)
		if(second_num==max_num)
			second_num=num[m-i];

	 for (i=0;i<m;i++)
	 {
		 if (num2[i]==max_num)
		 {
			 cout<<tolow(word[i]);
			 break;
		 }
	 }
	 cout<<",";
	 for (i=0;i<m;i++)
	 {
		 if (num2[i]==second_num)
		 {
			 cout<<tolow(word[i])<<endl;
			 break;
		 }
	 }
}

void main()
{
	string in;
	getline(cin,in);
    process(in);
}