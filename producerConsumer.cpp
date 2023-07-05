#include<bits/stdc++.h>
using namespace std;
int main(){
    int bufferSize=5;
    int itemNo=0;
    while(1){
        int choice;
        cout<<"Enter a choice 1 to produce, 2 to consume & 3 to exit :- ";
        cin>>choice;
        if(choice==1){
            if(itemNo==bufferSize){
                cout<<"Buffer is Full!!!\n";
                continue;
            }
            cout<<"Producer Produces Item "<<++itemNo;
        }
        else if(choice==2){
            if(itemNo==0){
                cout<<"Buffer is Empty!!!\n";
                continue;
            }
            cout<<"Consumer Consumes the  Item "<<itemNo--;
        }
        else if(choice==3){
            break;
        }
        else{
            cout<<"Invalid Choice. Try Again";
        }
        cout<<endl;
    }
}
