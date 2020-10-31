#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int b[n];
        for(int i=0;i<n;i++)
        cin>>b[i];
        unordered_map<int,int>m;
        int i=0,j=0;
        int sum=0;
        int maxi=0;
        for(i=0;i<n;i++){
            if(m[a[i]]==0){
                m[a[i]]++;
                sum+=b[i];
            }
            else{
                maxi=max(maxi,sum);
                m[a[i]]++;
                sum+=b[i];
                while(m[a[i]]!=1){
                    m[a[j]]--;
                    sum-=b[j];
                    j++;
                }
            }
        }
        maxi=max(maxi,sum);
        cout<<maxi<<endl;
    }
 //code
 return 0;
}
