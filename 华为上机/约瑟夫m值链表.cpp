#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef struct MyNode{
	int number;
	struct MyNode *next;
}MyNode;

int main()
{
	MyNode *head,*tail;
	srand( (unsigned)time( NULL ) ); //������������ĳ�ʼ������
	int n=rand()%9+1;//����1-9�������
	int m=rand()%5+1;//����1-5�������
	printf("%d %d\n",n,m);

	for(int i=0;i<n;i++)
	{
		if(i==0)   //��һ��
		{
			MyNode *cur=(MyNode *)malloc(sizeof(MyNode));
			cur->number=rand()%9+1;
			head=cur;
			tail=cur;
			head->next=tail;
			tail->next=head;
		}
		else
		{
			MyNode *cur=(MyNode *)malloc(sizeof(MyNode));
			cur->number=rand()%9+1;
			tail->next=cur;
			cur->next=head;
			tail=cur;
		}
	}

	//�����ǰ������������ֵ
	MyNode *p=head;
	for(int j=0;j<n;j++)
	{
		printf("%d ",p->number);
		p=p->next;
	}
	printf("\n");

	//��ʼ����
	p=head;
	MyNode *q=tail;
	while(n--)    //����n--ʡȥ����
	{
		for(int k=1;k<m;k++)
		{
			p=p->next;
			q=q->next;
		}
		printf("%d ",p->number);
		m=p->number;
		//ɾ��p�ڵ�
		q->next=p->next;
		free(p);
		p=q->next;
	}
	printf("\n");
	return 0;
}