#include<iostream>
using namespace std;

int main()
{
	//���㵽f[48]�Ѿ��ӽ�����int�����ݷ�Χ��
	int f[48];
	f[0] = 0, f[1] = 1;
	int i, n;
	for (i = 2; i < 48; i++)
		f[i] = f[i-1] + f[i-2];

	while(cin>>n && n!=0)
	{
		bool flags = 0;

		//������Ŀ��˼��n>=2�ģ����Դ�f[3] = 2��ʼ
		for (i = 3; i < 48; i++)
		{
			if (n == f[i]) 
			{
				flags = 1;
				break;
			}
		}

		if(flags) 
			cout<<"Second win"<<endl;
		else 
			cout<<"First win"<<endl;
	}

	return 0;
}