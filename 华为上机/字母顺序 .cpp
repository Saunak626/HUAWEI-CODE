#include <iostream>  
using namespace std;  
      
void revese(char* start,char* end)  
{
	while(start<end)  
    {  
		*start=*start^*end;
		*end=*start^*end;  
        *start=*start^*end;  
        start++;  
        end--;  
    }  
}  
      

int main()  
{  
	char* p=new char[1024];  
    gets(p);  
    int len=strlen(p);  
    int i=0,j=0;  
      
    while(i<len)  
    { 
		//�ж��ַ�ch�Ƿ�ΪӢ����ĸ����ΪСд��ĸ������2����Ϊ��д��ĸ������1����������ĸ������0
        if(isalpha(p[i]))  
        {  
			char *start=p+i;  
            j=i+1;  
            while(j<len)  
            {  
				if(isalpha(p[j]))  
                    j++;  
                else  
					break;  
            }  
            char *end=p+j-1;  
            revese(start,end);  
        }  
        i=j+1;  
		j++;
    }  

    for(i=0;i<len;i++)
		cout<<p[i];  

	cout<<endl;
          
    return 0;  
}  