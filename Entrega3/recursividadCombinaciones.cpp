#include<iostream>
using namespace std;

long factorial (long num){
    //cout<<"funcion"<<endl;
    long resultado=0;
    if(num>0){
       resultado=num*factorial(num-1); 
    }else{
        resultado=1;
    }
    
    return resultado;
}


int main(){
    int n=0;
    int r;

    //cout<<"Introduce los valores de n y r"<<endl;
    

    while(n>=0){
        cin>>n;
        cin>>r;

        if(n>0){
           if(n<r){
                cout<<"ERROR"<<endl;
            }else{
                long num1=factorial(n);
                //cout<<num1<<endl;
                long num2=factorial(r);
                //cout<<num2<<endl;
                long num3=factorial(n-r);
                //cout<<num3<<endl;
                long combinaciones=num1/(num2*num3);
                cout<<combinaciones<<endl;
            } 
        }
        
    }

    

    return 0;
}