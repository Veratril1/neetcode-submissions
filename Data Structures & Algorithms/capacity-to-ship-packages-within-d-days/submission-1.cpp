class Solution {
public:
    int check(int cap,vector<int>&wei){
        int d = 1;
        int sum = 0;
        for(int i=0;i<wei.size();i++){
            if(sum+wei[i]>cap){
                sum = wei[i];
                d++;
            }else sum+=wei[i];
        }
        return d;
    }
    int shipWithinDays(vector<int>& wei, int k) {
        int st = *max_element(wei.begin(),wei.end());
        int e = 1e9;
        int ans;
        while(st<=e){
            int mid = (st+e)/2;
            if(check(mid,wei)<=k){
                ans = mid;
                e = mid-1;
            }else{
                st = mid+1;
            }
        }
        return ans;
    }
};