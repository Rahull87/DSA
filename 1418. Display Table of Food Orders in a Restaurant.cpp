class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string> > result;
        
        int n=orders.size();
        if(!n){
            return result;
        }
        
        int m=orders[0].size();
        
        if(!m){
            return result;
        }
        
        map<int,map<string,int> > mymap;
        
        set<string> dishes;
        
        for(auto v:orders){
            dishes.insert(v[2]);
            mymap[stoi(v[1])][v[2]]++;            
        }
        
        vector<string> heading(dishes.begin(),dishes.end());
        heading.insert(heading.begin(),"Table");
        
        result.push_back(heading);
        
        for(auto it:mymap){
            vector<string> row;
            row.push_back(to_string(it.first));
            map<string,int> mp=it.second;
            
            for(string s:dishes){
                row.push_back(to_string(mp[s]));
            }
            result.push_back(row);
        }
        return result;
    }
};
