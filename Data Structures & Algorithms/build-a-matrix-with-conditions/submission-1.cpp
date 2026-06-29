class Solution {
public:
    vector<int>Topo(vector<vector<int>>&rc,int k){
        vector<set<int>>adj(k); // k nodes
        vector<int>indeg(k,0); // indeg of k nodes 
       for(auto it:rc){
            int  u = it[0] , v = it[1];
            u-- , v-- ;
            if(!adj[u].count(v))indeg[v]++;
            adj[u].insert(v); // u -> v // u will come first then comes v ! 
       }
    //    for(auto it:indeg)cout<<it<<" ";
        queue<int>q;
        vector<int>topo;
        for(int i=0;i<k;i++){
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto ch:adj[node]){
                indeg[ch]--;
                if(indeg[ch]==0)q.push(ch);
            }
        }
        return topo;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
        vector<vector<int>>ans(k,vector<int>(k,0));
       vector<int>topor = Topo(rc,k);
       vector<int>topoc = Topo(cc,k);
       if(topor.size()!=k || topoc.size()!=k)return {};
       vector<int>row(k),col(k);
       for(int i=0;i<k;i++){
         row[topor[i]] = i;
         col[topoc[i]] = i;
        }
        // for(auto it:topor)cout<<it<<" "; 
        for(int i=0;i<k;i++){
            ans[row[i]][col[i]]=i+1;
        }
       return ans;
    }
};