#include<stdio.h>

typedef struct MyType
{
	int number[3][3];int level;
}MyType;

MyType queue[10000];

MyType GetHead(int n)
{
	return queue[n];
}

//�Ƿ�Ϊ���ս��״̬
int IsFind(MyType cur)
{
	int flag=1;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(cur.number[i][j]!=3*i+j+1)
			{
				flag=0;
				break;
			}
		}
	return flag;
}

int main()
{
	
	int cnt=0;//����������
	int flag=0;//�Ƿ�Ѱ�ҵ����
	int ans=0;//��С����,Ҳ����չ�Ĳ���
	int head=0;//��Ϊ����������head����ʾ��һ��
	for(int m=0;m<3;m++)
	{
		for(int n=0;n<3;n++)
		{
			scanf("%d",&queue[cnt].number[m][n]);
		}
	}
	queue[cnt].level=0;
	cnt++;
	while(cnt!=0)
	{
		//��վ
		MyType cur=GetHead(head++);
		//�ж��Ƿ�Ϊ����״̬
		flag=IsFind(cur);
		if(flag==1)
		{
			printf("��С����Ϊ:%d\n",cur.level);
			break;
		}
		else      //��Ϊ����״̬��������չ
		{
			for(int row=0;row<3;row++)
				for(int col=0;col<3;col++)
				{
					if(cur.number[row][col]==1)    //�ҵ�1,������չ
					{
						//��1������
						if(row!=0)
						{
							MyType temp=cur;
							temp.number[row][col]=temp.number[row-1][col];
							temp.number[row-1][col]=1;
							temp.level=cur.level+1;
							queue[cnt++]=temp;
						}
						//��1�����ƶ�
						if(col!=2)
						{
							MyType temp=cur;
							temp.number[row][col]=temp.number[row][col+1];
							temp.number[row][col+1]=1;
							temp.level=cur.level+1;
							queue[cnt++]=temp;
						}
						//��1�����ƶ�
						if(row!=2)
						{
							MyType temp=cur;
							temp.number[row][col]=temp.number[row+1][col];
							temp.number[row+1][col]=1;
							temp.level=cur.level+1;
							queue[cnt++]=temp;
						}
						//��1�����ƶ�
						if(col!=0)
						{
							MyType temp=cur;
							temp.number[row][col]=temp.number[row][col-1];
							temp.number[row][col-1]=1;
							temp.level=cur.level+1;
							queue[cnt++]=temp;
						}
					}
				}
		}
	}
	return 0;
}