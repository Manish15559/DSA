void build(int ind,int low, int high, int arr[],vector<int> &seg,vector<int> &lazy){
    if(low==high){
        seg[ind]=arr[low];
        lazy[ind]=0;
        return;
    }
    int mid=(low+high)>>1;
    build(2*ind+1,low,mid,arr,seg,lazy);
    build(2*ind+2,mid+1,high,arr,seg,lazy);
    lazy[ind]=0;
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}

void update(int ind,int low ,int high,int l,int r,int val,vector<int> &seg,vector<int> &lazy){
    if(lazy[ind]!=0){
        seg[ind]+=(high-low+1)*lazy[ind];
        if(low!=high){
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }

    if(high<l||r<low){
        return;
    }
    if(low>=l&&high<=r){
        seg[ind]+=(high-low+1)*val;
        if(low!=high){
             lazy[2*ind+1]+=val;
            lazy[2*ind+2]+=val;

        }
        return;
    }
    int mid=(high+low)>>1;
    update(2*ind+1,low,mid,l,r,val,seg,lazy);
    update(2*ind+2,mid+1,high,l,r,val,seg,lazy);
    seg[ind]=seg[2*ind+1]+seg[2*ind+2];


}

int query(int ind,int low,int high,int l,int r,vector<int> &seg,vector<int> &lazy){
 if(lazy[ind]!=0){
        seg[ind]+=(high-low+1)*lazy[ind];
        if(low!=high){
            lazy[2*ind+1]+=lazy[ind];
            lazy[2*ind+2]+=lazy[ind];
        }
        lazy[ind]=0;
    }

 if(high<l||r<low){
        return 0;
    }
    if(low>=l&&high<=r){
      
        return seg[ind];
    }
    int mid=(high+low)>>1;
    int left=query(2*ind+1,low,mid,l,r,seg,lazy);
    int right=query(2*ind+2,mid+1,high,l,r,seg,lazy);
    return left+right;


}