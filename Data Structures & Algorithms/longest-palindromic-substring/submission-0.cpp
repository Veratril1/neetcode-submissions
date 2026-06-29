class Solution {
public:
    pair<int,int>middle(int l,int r,string s){
        pair<int,int>p;
        while(l>=0 && r< s.size()){
            if(s[l]==s[r]){
                p.first = l;
                p.second = r;
                l--;
                r++;
            }else break;
        }
        
        return p;
    }
    string longestPalindrome(string s) {
        int len = 0;
        string ans;
        for(int i=0;i<s.size();i++){
            pair<int,int>lr = middle(i,i,s);
            pair<int,int>lr2 = middle(i,i+1,s);
            if(len < lr.second - lr.first+1){
                len = lr.second - lr.first+1;
                ans = s.substr(lr.first,len);
            }
             if(len < lr2.second - lr2.first+1){
                len = lr2.second - lr2.first+1;
                ans = s.substr(lr2.first,len);
            }
        }
        return ans;
    }
};
