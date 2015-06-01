#include<iostream>  
#include<string>  
#include<stack>  
using namespace std;  
 
#define inf 1000  //��������Զ����   
#define stanum 35 //������վ̨��  
  
string staName[stanum] = {"A1","A2","A3","A4","A5","A6","A7","A8","A9","A10",  
                    "A11","A12","A13","A14","A15","A16","A17","A18",  
                    "B1","B2","B3","B4","B5","B6","B7","B8","B9","B10",  
                    "B11","B12","B13","B14","B15","T1","T2"} ; //��¼��վ������  
  

//floyd�㷨�ҳ����·��  
void floyd(int dis[][stanum],int path[][stanum])  
{  
    //��ʼ��path����  
    for(int row=0;row<stanum;row++)  
        for(int col=0;col<stanum;col++)  
            path[row][col]=row;  
  
    //�����·��  
    for(int k=0;k<stanum;k++)  
        for(int i=0;i<stanum;i++)  
            for(int j=0;j<stanum;j++)  
                if(dis[i][j]>dis[i][k]+dis[k][j])  
                {  
                    dis[i][j]=dis[i][k]+dis[k][j];  
                    path[i][j]=path[k][j];  
                } 
				
}  
  
//ת����վ�����ֵ����������
int string2int(string s)  
{  
	for(int i=0;i<stanum;i++) { 
		if(s==staName[i])
		{  
			return i;  
            break;
		}  
	}
	return 0;
}  
  
void printres(int dis[][stanum],int path[][stanum],string start,string dest)  
{        
    int s;  
    int d; 
    s=string2int(start);  
    d=string2int(dest);  
    cout<<"���پ����ĳ�վ����: "<<dis[s][d]+1<<endl; //���վ����1��������ʼվ  
  
	cout<<"�����ĳ�վ·�����: ";
    for(int i=0;i<stanum;i++)  
        for(int j=0;j<stanum;j++)  
        {  
            if(i==s&&j==d) //���·��  
            {  
                stack<int> pathrout;  //ѹջ  
                int k=j;  
                do{  
                    k=path[i][k];  
                    pathrout.push(k);  
  
                }while(k!=i);  
  
                //��ջ  
                cout<<staName[pathrout.top()];  
                pathrout.pop();  
                  
                int length=pathrout.size();  
                for(int t=0;t<length;t++)  
                {  
                    cout<<"->"<<staName[pathrout.top()];  
                    pathrout.pop();  
                      
                }  
                cout<<"->"<<staName[d]<<endl;  
				break;  
            }                  
        }   
}  
  
int main()  
{  
    int distance[stanum][stanum];  
    int path[stanum][stanum];  
    string start;  
    string dest;  
      
    //��ʼ�����Ӿ���  
    for(int i=0;i<stanum;i++)  
    {  
        for(int j=0;j<stanum;j++)  
        {  
            if(i==j)  
                distance[i][j]=0;  
            else  
                distance[i][j]=inf;  
        }  
    } 
	
    //��ʼ������  
    int sa[21]={0,1,2,3,4,5,6,7,8,33,9,10,11,12,34,13,14,15,16,17,0};  
    for(i=0;i<20;i++)  
    {  
        distance[sa[i]][sa[i+1]]=1;  
        distance[sa[i+1]][sa[i]]=1;  
    }  

    int sb[17]={18,19,20,21,22,33,23,24,25,26,27,34,28,29,30,31,32};  
    for(i=0;i<16;i++)  
    {  
        distance[sb[i]][sb[i+1]]=1;  
        distance[sb[i+1]][sb[i]]=1;  
    }  
  
  
    floyd(distance,path);
	
    cout<<"���������յ�: "<<endl;  
    
	while(cin>>start>>dest){
		printres(distance,path,start,dest); 
		printf("\n");
	}

    return 0;  
}  