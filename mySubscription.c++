#include<bits/stdc++.h>
using namespace std;


class newspaperSubscription{
public:
 vector<string> newspaperNames;
 unordered_map<string, double> prices;
    newspaperSubscription(){
        this->newspaperNames = {"TOI", "Hindu", "ET", "BM", "HT"};
        vector<vector<double>> price = {
                {3,3,3,3,3,5,6},
                {2.5,2.5,2.5,2.5,2.5,4,4},
                {4,4,4,4,4,4,10},
                {1.5,1.5,1.5,1.5,1.5,1.5,1.5},
                {2,2,2,2,2,4,4}
                };
                
            for(int i=0;i<5;i++){
                double sum = 0;
                for(auto &x:price[i])
                    sum += x;
                this->prices[newspaperNames[i]] = sum;
            }
        return ;
    }
};

void helper(int idx, int budget, newspaperSubscription &obj, vector<string> &combination, vector<vector<string>> &combinations){
 if(idx == 5){
  if(combination.size() != 1)
   combinations.push_back(combination);
  return ;
 }
 if(budget >= obj.prices[obj.newspaperNames[idx]]){
  combination.push_back(obj.newspaperNames[idx]);
  helper(idx+1, budget - obj.prices[obj.newspaperNames[idx]], obj, combination, combinations);
  combination.pop_back();
 }

 helper(idx + 1, budget, obj, combination, combinations);
 return ;

}

int main(){
    
    int budget;
    cin>>budget;
    newspaperSubscription obj;
    vector<string> combination;
    vector<vector<string>> combinations;

 helper(0, budget, obj, combination, combinations);

    for(auto &combination:combinations){
        for(auto &newspaper:combination){
            cout<<newspaper<<" ";
        }
        cout<<"\n";
    }
return 0;
}