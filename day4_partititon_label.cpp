#include <bits/stdc++.h>

using namespace std;

vector<int> partititonLabels(string s){
    unordered_map<char,int> last;
    int n=s.size();
    if(!n)
        return {};
    for(int i=0; i<n;i++){
        last[s[i]]=max(i,last[s[i]]);
    }
    // for(auto i:last){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    vector<int> ans;
    int i=0;
    while(i<n){
        int curr=i;
        // cout<<curr<<endl;
        int upto=last[s[i]];
        for(i=curr;i<=upto;i++){
            upto=max(upto,last[s[i]]);
        }
        ans.push_back(upto-curr+1);
    }

    return ans;
}

int main(){
    string s;
    cin>>s;
    auto ans = partititonLabels(s);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}