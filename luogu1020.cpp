#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int a[100000],f[100000]={0};
    int n=0;
    while(cin>>a[n])n++;
    int len=1;
    f[0]=a[0];
    for(int i=1;i<n;i++){
        if(a[i]<=f[len-1]) len++,f[len-1]=a[i];
        else {
            int pos;
            pos=upper_bound(f,f+len,a[i],cmp)-f;
            f[pos]=a[i];
        }
    }
   // ans1=len;
    cout<<len<<'\n';
    memset(f,0,sizeof(f));
    len=1;
    f[1]=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>f[len]) f[++len]=a[i];
        else {
            int pos;
            pos=lower_bound(f,f+len,a[i])-f;
            f[pos]=a[i];
        }
    }
   // ans2=len;
    cout<<len;
}