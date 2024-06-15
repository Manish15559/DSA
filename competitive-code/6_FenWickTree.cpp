class FenTree{
	vector<int>bit;
public:
	FenTree(int n){
		bit.resize(n+10,0);
	}
	void update(int idx,int val){
		while(idx<bit.size()){
			bit[idx]+=val;
			idx+=(idx&(-idx));
		}
	}
	int query(int idx){
		int ans=0;
		while(idx>0){
		ans+=bit[idx];
			idx-=(idx&(-idx));

		}

		return ans;
	}
};

void solve(){ 
	int n,q;
	cin>>n>>q;

	FenTree *obj=new FenTree(n+1);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		obj->update(i,x);
	}
	while(q--){
		int l,r;
		cin>>l>>r;

		cout<<(obj->query(r)-obj->query(l-1))<<endl;
	}





}
	
	
