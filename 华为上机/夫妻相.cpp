#include <iostream>  
#include <string>  
using namespace std;  
  
//10�����֣�26���ַ�
char nameArray[10][26]={"wang fei","zhang man yu","zhang zhi yi","li li",  
"li xiao man","li yu cun","yang ni","xiao tong","li lei","zhang san"};  
  
//�ҳ�a��b����ĸ�ظ��Ĵ���
int findCount(bool a[],bool b[])  
{  
    int count=0;  
    for(int i=0;i<26;i++) {
		if(a[i]&&b[i])  
		count++; 
	}
    return count;  
}  
  
int main()  
{  
    char name[100];  
    gets(name); 
  
    bool flag_0[10][26]; //ÿ��Ůʿ�����м�¼���ֵ���ĸ������Ϊ1��������Ϊ0
    memset(flag_0,0,sizeof(flag_0)); 
	
    int i,j;   
    for(i=0;i<10;i++)  
    {  
        for(j=0;nameArray[i][j]!='\0';j++)  
        {  
            if(nameArray[i][j]<='z' && nameArray[i][j]>='a')  
            {  
                flag_0[i][nameArray[i][j]-'a']=1;  
            }  
        }  
    }  

    bool flag_1[26];  //ÿ����ʿ�����м�¼���ֵ���ĸ������Ϊ1��������Ϊ0
    memset(flag_1,0,sizeof(flag_1));  

    for(i=0;name[i]!='\0';i++)  
    {  
        if(name[i]<='z' && name[i]>='a')  
        {  
            flag_1[name[i]-'a']=1;  
        }  
    }  
  
  
    int count[10]; //��¼ÿ��Ůʿ�����к��������ʿ�����е��ظ���ĸ��
	int max =0;
    for(i=0;i<10;i++)  
    {  
        count[i]=findCount(flag_1,flag_0[i]); 
		if(count[i]>max)  
            max=count[i];  //���ƥ�����ߵĴ���
    }       
  
    for(i=0;i<10;i++)  
    {  
        if(count[i]==max)  
        {  
            cout<<nameArray[i]<<endl; //�������ƥ���Ůʿ���� 
            break;  
        }  
    }  
  
    return 0;  
}