#include <iostream>  
using namespace std;  
  
int A[10][10] =   
{  
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  
    0, 0, 0, 0, 2, 0, 0, 0, 0, 0,  
    0, 0, 0, 2, 1, 2, 0, 0, 0, 0,  
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0  
};  

bool B[10][10];  
int eatCount = 0;  
  
//��ʼ������B��Ϊfalse 
void initFlagMatrix()  
{  
    for(int i = 0; i < 10; i++)  
    {  
        for(int j = 0; j < 10; j++)   
            B[i][j] = false;  
    }  
}  
  
bool hasAir(int i, int j, int type)  
{  
    if(A[i][j] == 0) 
		return true;  
    if(A[i][j] != type) 
		return false;  
    eatCount++; 
	
    B[i][j] = true;  
    if(i > 0 && !B[i-1][j] && hasAir(i-1, j, type)) return true;  
    else if(i < 9 && !B[i+1][j] && hasAir(i+1, j, type)) return true;  
    else if(j > 0 && !B[i][j-1] && hasAir(i, j-1, type)) return true;  
    else if(j < 9 && !B[i][j+1] && hasAir(i, j+1, type)) return true;  
    else return false;  
}  
  
//����A[i][j]��������ͬ���͵�����ȫ���Ե�  
void eatChess(int i, int j, int type)  
{  
    if(A[i][j] != type) return;  
    A[i][j] = 0;    //�Ե���
    if(i > 0) eatChess(i-1, j, type);  
    if(i < 9) eatChess(i+1, j, type);  
    if(j > 0) eatChess(i, j-1, type);  
    if(j < 9) eatChess(i, j+1, type);  
}  
  
//�����������̿������Ƿ�����  
bool hasAirOfType(int type, int &p, int &q)  
{  
    for(int i  = 0; i < 10; i++)  
    {  
        for(int j = 0; j < 10; j++)  
        {  
            if(A[i][j] != type || B[i][j]) 
				continue;   
            eatCount = 0;  
            if(!hasAir(i, j, type))   
            {  
                p = i, q = j;  
                return false;  
            }  
        }  
    }  
    return true;  
}  

//��λ��[i,j]�Ÿ��ڰ��ӵ�ʱ��Ե��ӵĸ���  
int eatenChesscount(int i, int j, int type)  
{  
    initFlagMatrix();  
    bool self_hasAir = hasAir(i, j, type);  
    eatCount = 0;  
    int p = 0, q = 0;  
    int other_type = (type==1?2:1);  
    initFlagMatrix();  
    bool other_hasAir = hasAirOfType(other_type, p, q);  
  
    if(!self_hasAir && other_hasAir)//��ɱ
    {  
        A[i][j] = 0;  
        return 2147483647; 
    }  
    if(!other_hasAir)  
    {  
        eatChess(p, q, other_type);  
        if(other_type == 1) //��������
			return eatCount;  
        else                //���Ӹ���
			return 0-eatCount;  
    }  
    return 0;  
}  

//��ӡ10*10����Ĳо�״̬
void printChessState()  
{  
    for(int i = 0; i < 10; i++)  
    {  
        for(int j = 0; j < 10; j++)  
        {  
            cout << A[i][j] << " ";  
        }  
        cout << endl;  
    }  
}  
  
int main()  
{  
    int i, j, type;  
    while(cin >> i >> j >> type)  
    {  
        if(A[i][j] != 0)  
        {  
            cout << "2147483647" << endl;  
            continue;  
        }  
        A[i][j] = type;
		
		cout<<"��ǰ�Ĳо�״̬��"<<endl;
        printChessState();  
        cout << "�˴γ��Ӹ�����"<< eatenChesscount(i, j, type) << endl;  
		cout<<"���Ӻ�о�״̬"<<endl;
        printChessState();  
    }  

	return 0;
} 