#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter Number of Blocks :- ";
    int nb;
    cin>>nb;
    vector<int>v1(nb);
    for(int i=0;i<nb;++i){
        cout<<"Enter Size of the "<<i+1<<" th block :- ";
        cin>>v1[i];
    }

    cout<<"Enter Number of Files :- ";
    int nf;
    cin>>nf;
    vector<int>v2(nf);
    for(int i=0;i<nf;++i){
        cout<<"Enter Size of the "<<i+1<<" th file :- ";
        cin>>v2[i];
    }
    vector<bool> isBlockAllocated(nb,false);
    cout<<"File No\tFile Size\tBlock No\tBlock Size\tFragment\n";
    for(int i=0;i<nf;++i){
        int minFragment=INT_MAX;
        int selectedBlock=-1;
        for(int j=0;j<nb;++j){
            if(!isBlockAllocated[j]&&v2[i]<=v1[j]){
                if(v1[j]-v2[i]<minFragment){
                    selectedBlock=j;
                    minFragment=v1[j]-v2[i];
                }
            }
        }
        int j=selectedBlock;
        isBlockAllocated[j]=true;
                cout<<i+1<<"\t\t"<<v2[i]<<"\t\t"<<j+1<<"\t\t"<<v1[j]<<"\t\t"<<v1[j]-v2[i]<<endl;

    }
}
// 3
// 5
// 2
// 7
// 2
// 1
// 4
