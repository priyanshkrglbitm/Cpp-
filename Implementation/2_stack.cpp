#include<bits/stdc++.h>
using namespace std;
#define size 100
class stackk{

    int top;
    int arr[size];
    public:

    stackk(){top=-1;}
    bool isFull(){
        return top==size-1;

    }
    bool isEmpty(){
        return top==-1;
    }

    void push(int data){
        if(isFull()){
            cout<<"Stack Overflow"<<endl;
        }else{
            arr[++top]=data;
            cout<<data<<" Pushed into Stack"<<endl;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            int x=arr[top--];
            cout<<x<<" Popped from Stack"<<endl;
        }
    }

    void peek(){
        if(isEmpty()){
            cout<<"Stack Empty"<<endl;
        }
        else{
            cout<<arr[top]<<" Top of Stack"<<endl;
        }
    }
    

};
int main(){
    stackk st; 
    st.push(1);  
    st.push(3);
    st.push(5);
    st.peek();   
    st.pop();
    st.pop();  
    st.peek();

}