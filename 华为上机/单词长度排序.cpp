#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_word(char input[],char output[])  
{  
    char *p;  
	char *temp;  
    char *word[10]; 
    int len_input=strlen(input);  
    int i,j;  
    char except[] = ",";  
    char *blank = " ";  

    for (i=0;i<len_input;i++)  
    {  
        if (input[i]<'A' || (input[i]>'Z'&&input[i]<'a') || input[i]>'z')  
        {  
            input[i]=',';  
        }  
    }  

    j=0;  
    /*����ȡ���ĵ���*/  
	p= strtok(input,except);  

    while(NULL!=p)  
    {  
        word[j++]=p;  
        p= strtok(NULL,except);  
    } 
	
    for(i=0;i<j;i++)
		printf("%s ",word[i]);
	printf("\n");

	int wordlen=j;
    /*�Ե��ʰ��ճ��Ƚ�������ð�ݷ�*/  
    for (i=0;i<wordlen;i++)  
    {  
        for (j=1;j<wordlen-i;j++)  
        {  
            if(strlen(word[j-1])<strlen(word[j]))  
            {  
                temp=word[j];  
                word[j]=word[j-1];  
                word[j-1]=temp;  
            }  
        }  

    } 
	
    /*ɾ����ͬ����*/  
    for (i=0;i<wordlen;i++)  
    {  
        for(j=i+1;j<wordlen;j++)  
        {  
            if(strcmp(word[i],word[j])==0)  
                word[j]="\0";  
        }  
    }  

    /*�����������������*/  
    for (j=0;j<wordlen;j++)  
    {  
		if (j==0)
			strncpy(output,word[j],strlen(word[j])+1);
        else  
        {  
            strcat(output,blank);  
            strcat(output,word[j]);  
        }  
    }
}  


int main()  
{  
	char input[] ="some local buses, some1234123drivers";  
	printf("ɸѡ֮ǰ���ַ���:%s\n",input);
    char output[30];  
    my_word(input,output);  
    printf("ɸѡ֮����ַ���:%s",output);  
    printf("\n");  
    return 0;  
}  
