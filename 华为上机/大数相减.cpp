#include <stdio.h>    
#include <string.h>    
 
#define MAX 100      
//100λ�������    
int lenA;
int lenB;

int bigNumSub(char a[],char b[],char sub[])    
{  
    int i=0;    
    int c=0;//�ж��Ƿ񹻼���0������1������ 
	
	//��0
	char m[MAX]={0};  //���������ڼ���
    char n[MAX]={0};  //����
    memset(sub,0,100);    
        
    //�ַ�����ת���ַ���������    
    lenA=strlen(a);    
    lenB=strlen(b);  
             
    for (i=0;i<lenA;i++)    
    {    
       m[i]=a[lenA-i-1]-'0';    
    }    
    for (i=0;i<lenB;i++)    
    {    
       n[i]=b[lenB-i-1]-'0';    
    }    
        
    //λ���㣺��������λ����������λ�����Һ�һλ��һ   
    for (i=0;i<lenA;i++)    
    {  
		c=(m[i]-n[i])<0?1:0;
		sub[i]=m[i]+10*c-n[i];
		if(i+1==lenA)
			break;
		m[i+1]-=c;
    } 

    return 0;   
}     
  
  
void print(char sub[])    
{    
    int i;     
  
    for(i=lenA; i>=0; i--)    
    {    
        printf("%c",sub[i]);    
    }    
    puts("\n");    
}   
  
int main()    
{   
    char a[MAX];    
    char b[MAX];    
    char sub[MAX];    
    puts("input a:");    
    gets(a);    
    puts("input b:");    
    gets(b);  
	bigNumSub(a,b,sub);
    print(sub);    
    return 0;    
}    