#include <stdio.h>
 
//ѹ���ո����ַ�������
int deleteKong(char s[],int n)
{
    int i=0,j=0;
 
    for(i=0;i<n;++i)
    {
        if(s[i]==' ')
        {
            while(s[++i]==' ')
                continue;
            s[j++]=s[--i];
        }
        else
        {
            s[j++]=s[i];
        }
    }
    s[j]='\0';
    return j;
}
 
//�Ӵ���ת
void change(char s[],int start,int end)
{
    char t;
    while(start<end)
    {
        t=s[start];
        s[start]=s[end];
        s[end]=t;
        start++;
        end--;
    }
}
 
 
int main()
{
    int n,i,start,end;
    char a[100001];
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        while (getchar()!='\n') 
            continue; 
        gets (a); 
        n=deleteKong(a,n);
 
        for(i=0;i<n;++i)
        {
            if(a[i]!=' ')
            {
                start = i;
                while(++i<n&&a[i]!=' ')
                    continue;
                end = i-1;
                change(a,start,end);
            }
        }
        puts(a);
    }
    return 0;
}