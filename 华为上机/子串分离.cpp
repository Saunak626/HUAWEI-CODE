#include <iostream>
#include <string>
using namespace std;

//�Ӵ�����
void DivideString(const char* pInputStr , long lInputLen , char* pOutputStr)  
{  
	int i,j=0;  
    bool flag;  
    for(i = 0 ; pInputStr[i] == ' ' ; ++i)   //�����ַ���ǰ��Ŀո�  
            continue;  
    flag = true;  
    for(;i < lInputLen ; ++i)  
    {  
		if(pInputStr[i] != ' ')  
        {  
			if(!flag)
				flag = true; 
			pOutputStr[j++] = pInputStr[i];    //�������Ӵ����뱣������  
        }  
        else  
        {  
			if(flag)
				pOutputStr[j++] = ',';  
            flag = false;  
        }  
    }  
    pOutputStr[j++] = ',';  
    pOutputStr[j++] = '\0';  
} 

void main()
{
	char s[100];
	char result[100];
	while(gets(s))
	{
		DivideString(s,strlen(s),result);
		cout<<result<<endl<<endl;
	}
	cout<<endl;
}
