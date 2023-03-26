#include<bits/stdc++.h>
using namespace std;

class Newspaper{
    vector<vector<int,string>>v;
    public:
    Newspaper()
    {
        v={
            {26,"TOI"}, {20.5,"Hindu"}, {34,"ET"}, {10.5,"BM"}, {18,"HT"}
        };
    }

    vector<vector<string,int>> subscription(double target)
    {
        sort(v.begin(),v.end());
        double sum=0;
        int n=v.size();
        int i=0;
        int j=0;
        vector<vector<string,int>>ans;
        vector<string,int>out;
        while(j<n){
            
            sum+=v[i][0];

            if(sum>target & i<j){
                out.erase(out.begin());
                i++;
            }

            if(sum<=target & i<j){
                
                for(int k=i;k<=j;k++){
                    out.push_back({v[k][1],v[k][0]});
                }
                if(out.size()>1){
                    ans.push_back(out);
                    out.clear();

                }
                
            }
            
            j++;
        }
        return ans;
    }
    
    
};
 

int main()
{
    Newspaper n;
    double price;
    cout<<"Enter the budget";
    cin>>price;
    vector<vector<string,int>> comb=n.subscription(price);
    cout<<"{";
    for (int i=0;i<comb.size();i++) {
        cout<<"{"
        for(int j=0;j<comb[i].size();j++){
            cout<<comb[i][j]<<",";
        }
        cout<<"}";
    }
    cout<<"}";
    return 0;
}