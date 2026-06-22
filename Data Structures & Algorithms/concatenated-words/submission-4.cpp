class Tnode{
    public:
        map<char,Tnode*>links;
        int fl;
        Tnode(){
            fl = 0;
        }
};
class Solution {
public:
    map<tuple<int,Tnode*>,int>dp;
    int dfs(int ind,Tnode* curr,string s,Tnode* head){
        if(ind == s.size())return curr->fl ? 1 : -1e9;
        if(dp.count({ind,curr}))return dp[{ind,curr}];
        int op1 = (curr->fl)? (1+dfs(ind,head,s,head)) : -1e9;
        int op2 = (curr->links.count(s[ind]))?dfs(ind+1,curr->links[s[ind]],s,head):-1e9;
        return dp[{ind,curr}]=max(op1,op2);
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& wd) {
        Tnode * head = new Tnode();
        for(int i=0;i<wd.size();i++){
            auto curr = head;
            for(int j=0;j<wd[i].size();j++){
                if(!curr->links.count(wd[i][j])){
                    curr->links[wd[i][j]]=new Tnode();
                }
                curr = curr->links[wd[i][j]];
            }
            curr->fl = 1;
        }
        vector<string>ans;
        for(int i=0;i<wd.size();i++){
            int val = dfs(0,head,wd[i],head);
            if(val>=2)ans.push_back(wd[i]);
            // cout<<val<<endl;
            dp.clear();
        }
        return ans;
    }
};