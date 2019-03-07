#include <iostream>
using namespace std;
int traverse(int mat[1000][1000],int n, int a,int count,int *fore){
    fore[a]=1;
    count++;
    for(int i=1;i<=n;i++){
        if(mat[a][i]==1 && fore[i]==0){
            count=traverse(mat,n,i,count,fore);
        }
    }
    return count;
}
int main() {
    int n,e,min=__INT_MAX__,max=0,count=0;
    cin>>n;
    cin>>e;
    int fore[n+1]={0};
    int mat[1000][1000]={{0}};
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a;
        cin>>b;
        mat[a][b]=1;
        mat[b][a]=1;
    }
    for(int i=1;i<=n;i++){
        if(fore[i]==0){
            count++;
            int s=traverse(mat,n,i,0,fore);
            if(s>max){
                max=s;
            }
            if(s<min){
                min=s;
            }
        }
    }
    cout<<max<<" "<<min<<" "<<count;
    
    return 0;
}
