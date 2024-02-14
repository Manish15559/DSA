class DisJointSet{
    vector<int>rank,size,parent;
    public:
    DisJointSet(int n){
        rank.resize(n+1,0);   // one based indexing
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;

        }

    }
    int findParent(int node){   //T.c-o(4*alpha)=constant
        if(node==parent[node]){
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    void unionByRank(int u,int v){  //T.c-o(4*alpha)=constant
        int ultiParent_u=findParent(u);
        int ultiParent_v=findParent(v);
if (ultiParent_u ==ultiParent_v) return;

        if(rank[ultiParent_u]<rank[ultiParent_v]){
            parent[ultiParent_u]=ultiParent_v;
        }
        else if(rank[ultiParent_u]>rank[ultiParent_v]){
            parent[ultiParent_v]=ultiParent_u;
        }
        else{
             parent[ultiParent_v]=ultiParent_u;
             rank[ultiParent_u]++;

        }
    }
    void unionBySize(int u,int v){  //T.c-o(4*alpha)=constant
        int ultiParent_u=findParent(u);
        int ultiParent_v=findParent(v);
if (ultiParent_u ==ultiParent_v) return;
        if(size[ultiParent_u]<size[ultiParent_v]){
            parent[ultiParent_u]=ultiParent_v;
            size[ultiParent_v]+=size[ultiParent_u];
        }
     
        else{
             parent[ultiParent_v]=ultiParent_u;
             size[ultiParent_u]+=size[ultiParent_v];

        }
    }
  };




  void solve(){
    DisJointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionByRank(3, 7);

    if (ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    }
 