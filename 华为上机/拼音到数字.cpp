#include <string>  
#include <iostream>  
using namespace std;  
  
void filter(string str)  
{  
    //���ַ������±꼴Ϊ���Ӧ�İ���������  
    char *ch[]={"Ling","Yi","Er","San","Si","Wu","Liu","Qi","Ba","Jiu"};  
    int i,j,k,len;  
    string substr;  
    len=str.length();   
    for(i=0;i<len;i++)  
    {    
        //���Կ���ƴ�����Ϊ2���ַ����Ϊ4���ַ�  
        for(j=i+1;j<len&&(j-i)<4;j++)  
        {  
            substr=str.substr(i,j-i+1);  

            for(k=0;k<10;k++)  
              
                if(!substr.compare(ch[k]))  
                {  
                    printf("%d",k);//������ӡ������  
                    break;  
                }               
        }          
    } 
	printf("\n");
}  
  
int main()  
{  
    string str;  
    while(cin>>str){ 
    //cin>>str;
		filter(str);  }
    return 0;  
}  