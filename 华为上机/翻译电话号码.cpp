#include <iostream> 
#include <string>       
using namespace std;    
    
void process(string str)    
{    
    //���ַ������±꼴Ϊ���Ӧ�İ���������    
    char *ch[]={"zero","one","two","three","four","five","six","seven","eight","nine","double"};
	char *out[100];//�洢�����

	int f=0;
    int i,j,k;  
	
    string substr;    
    int len=str.length(); 
    int flag=0;//�ж�double����
	int flag2=0;//�ж���ѭ������break

    for(i=0;i<len;i++)    
    { 
		if(flag2)
			break;
		else if(str[i]<97 || str[i]>122)//����ĸ�ַ�
		{
			out[f++]="error";
			break;
		}
		else{
			//���Կ���ƴ�����Ϊ3���ַ����Ϊ6���ַ�    
			for(j=i+2;j<len&&(j-i)<6;j++)    
			{    
				substr=str.substr(i,j-i+1);    
				if(!substr.compare(ch[10]))//����double
				{
					if(i==len-6)//���һ��double
					{
						out[f++]="error";
						flag2=1;
						break;
					}else if(flag){//��������double
						out[f++]="error";
						flag2=1;
						break;
					}else
						flag=1;
				}
				else{
					for(k=0;k<10;k++) 
					{
						if(!substr.compare(ch[k]))    
						{    
							if(flag){
								out[f++]=ch[k];
								out[f++]=ch[k];
								flag=0;
								break;								
							}
							else{
								out[f++]=ch[k];   
								break;
							}
						} 
					}
				}
			} 
		}
    }  
	
	int flag3=0;//������error,Ĭ��û��error
	for(int r=0;r<f;r++){
		if(out[r]=="error")//��error
			flag3=1;
	}

	if(!flag3)
		for(r=0;r<f;r++)
			for(k=0;k<10;k++) 
			{
				if(out[r]==ch[k])    
					printf("%d",k);
			}
	else
		printf("error");

    printf("\n");  
}    
    
void main()  
{  
    string str;    
    while(getline(cin,str))  
        process(str); 
}  