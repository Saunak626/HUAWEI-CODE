#include <iostream>
#include <string>  
using namespace std;  
  
void filter(string str)  
{  
    //���ַ������±꼴Ϊ���Ӧ�İ���������  
    char *ch[]={"Ling","Yi","Er","San","Si","Wu","Liu","Qi","Ba","Jiu"};  
	int a=0;//�洢����
    int i,j=1,k,len,sum=0,flag;  
    string substr;  
    len=str.length(); 
    for(i=0;i<len;)  
    {    
        //������һ����д��ĸ��ͣ����
		if(str[j]<'a'||j==len)
		{
			flag=0;//�����������ֻ���wan,qian,bai,shi

			substr=str.substr(i,j-i);

			if(!substr.compare("Wan")){
				sum+=a*10000;
			}else if(!substr.compare("Qian")){
				sum+=a*1000;
			}else if(!substr.compare("Bai")){
				sum+=a*100;
			}else if(!substr.compare("Shi")){
				sum+=a*10;
			}else{
				for(k=0;k<10;k++) {              
					if(!substr.compare(ch[k]))  
					{
						flag=1;
						a=k;
						//printf("%d",k);//������ӡ������  
						break;  
					} 
				}
			}
            i+=(j-i);//i������һ����д��ĸ��ʼ
			j=i+1;
		}else{
			j++;
		}
    } 
	if(flag)
		printf("%d\n",sum+a);
	else
		printf("%d\n",sum);
}  
  
int main()  
{  
    string str;  
    while(cin>>str){ 
    //cin>>str;
		filter(str);  }
    return 0;  
}  