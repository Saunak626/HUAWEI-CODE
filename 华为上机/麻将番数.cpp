#include <iostream>
#include <string>
using namespace std;

int main()  
{  
    int fan;  
    int i;  
    int gang;  
    int ka,lian3,ka2tiao; 

    char s[42];  
       
	while(cin>>s){

		fan=gang=ka=lian3=ka2tiao=0;
		int len = strlen(s);
  
		for(i=0;i<len;i++)  
		{ 
			if(s[i]<='9'&&s[i]>='1')
			{
				if(s[i]==s[i+2]&&s[i+2]==s[i+4]&&s[i+4]==s[i+6]&&(s[i+8]==','||s[i+8]=='.'))//�ж��Ƿ��иܲ����������Ĺ�һ��1D1D1D1D
					gang++;  
				else if((s[i]==s[0]||s[i-1]==',')&&s[i]==s[i+2]&&s[i+2]==s[i+4]&&(s[i+6]==','||s[i+6]=='.'))//�ж��Ƿ�����3������2D2D2D  
					lian3=1;  
				else if((s[i]+2)==(s[i+2]+1)&&(s[i+2]+1)==(s[i+4])&&(s[i+6]==','||s[i+6]=='.'))//�ж��Ƿ��п�����nT(n+1)T(n+2)T  
				{
					ka=1;  
					if(s[i]=='1'&&s[i+1]=='T')  
						ka2tiao++;//�жϿ�2��-----1T2T3T ����
				}  
		   }  
		}
              
		if(ka||lian3||gang==4)//����nT(n+1)T(n+2)T��2D2D2D�Ļ���4�����Ĺ�һ��������ض��ǵ�2�ֺ��Ʒ�ʽ  
			fan=ka2tiao*1+gang*2;  
		else  
			fan=2+gang*2;//���߶Եĺ��Ʒ�ʽ  
  
		cout<<fan<<endl; 
	}

    return 0;  
} 