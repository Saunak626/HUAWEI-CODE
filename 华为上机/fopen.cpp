#include <stdio.h>

int main()
{
	char ch;
	
	FILE* fp;
	FILE* fp2;
	fp = fopen("f:\\11.txt","r"); //ֻ����ȡ
	fp2 = fopen("f:\\12.txt","w"); //ֻ����ȡ
	if(fp == NULL) //���ʧ����
	{
		printf("ERROR");
		return 1;
	}

	//getc()�����ڴ��ļ��л�ȡһ���ַ�
	while((ch = getc(fp)) != EOF)  //ѭ����ȡֱ���ļ����� EOF��־(End Of File)
		putchar(ch);  //��ӡ��ȡ�����ַ�

	//fgets(s, 2, fp); 

	int i=9;
	char *s="dfsffs";
	char chh='b';
	fprintf(fp2, "%d\n", i);
	fprintf(fp2,"%s\n",s);
	fprintf(fp2,"%c\n",chh);

	fscanf(fp2, "%d", &i);         /*��ȡ������*/
    printf("%d\n", i); 

	fclose(fp); //�ر��ļ�
	return 0;
}