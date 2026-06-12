#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
vector<int> twosum(vector<int>& vec, int target ){
    unordered_map<int,int>mymap;
    for(int i = 0; i < vec.size();i++){
        int need = target-vec[i];
        if (mymap.find(need) != mymap.end()){
            return {mymap[need],i};
        }
        else{
            mymap[vec[i]] = i;
        }
    }
    return{};

    }
int main(){
    int n;
    cin >> n;
    vector <int> vec(n);
    for (int i = 0; i < vec.size();i++){
        cin >> vec[i];
    }
    int target;
    cin >> target;
    vector<int> ans = twosum(vec,target);
    cout << ans[0] <<" "<< ans[1];
}
