#include <iostream>  
using namespace std;  
  
void isHuiwen(int number)  
{   
    int n = 0;//����. 
	int m = number;
    while(m != 0)  
    {  
        n = n*10 + m %10;  //number�����λ��Ϊn�����λ
        m  = m /10;  
    }  

    if(n==number)  
        cout << "yes" << endl;  
    else  
        cout << "no" << endl;  
}  
  
int main()  
{  
    int number;  
    while(cin >> number)  
        isHuiwen(number);  
    return 0;  
} 