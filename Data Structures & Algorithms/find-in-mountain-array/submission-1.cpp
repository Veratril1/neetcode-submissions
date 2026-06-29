/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
int bs_asc(int l,int r,MountainArray &ma,int k){
    int ans = -1;
    while(l<=r){
        int mid = (l+r)/2;
        // cout<<l<<" "<<mid<<" "<<r<<endl;
        // cout<<ma.get(mid)<<endl;
        int val = ma.get(mid);
        if(val<k){
            l = mid+1;
        }else{
            if(val==k)ans = mid;
            r = mid-1;
        }
    }
        return ans;
}
int bs_desc(int l,int r,MountainArray &ma,int k){
    int ans = -1;
    while(l<=r){
        int mid = (l+r)/2;
        int val = ma.get(mid);
        // cout<<l<<" "<<mid<<" "<<r<<endl;
        if(val > k){
            l = mid+1; // here it dec 
        }else{
            if(val==k)ans = mid;
            r = mid-1;
        }
    }
        return ans;
}
class Solution {
public:
    int findInMountainArray(int k, MountainArray &ma) {
        int st = 0;
        int e = ma.length()-1;
        int pk;
        while(st<=e){
            int mid = (st+e)/2;
            int val0=ma.get(mid-1),val1=ma.get(mid),val2=ma.get(mid+1);
            if(val1>val2 && val1>val0){
                pk = mid;
                break;
            }
            if(val1 <val2){
                st = mid+1;
            }else{
                e = mid;
            }
        }
        int ind1 = bs_asc(0,pk,ma,k);
        if(ind1!=-1)return ind1;
        if(ma.get(pk) < k)return -1;
        else ind1 = 1e9;
        int ind2 = bs_desc(pk,ma.length()-1,ma,k);
        if(ind2==-1)ind2=1e9;
        int ind = min(ind1,ind2);
        return ind==1e9?-1:ind;
    }
};