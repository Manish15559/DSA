struct Node{
    Node *links[26];


    bool containKey(int bit){
        return (links[bit]!=NULL);
    }
    void put(int bit,Node *node){
        links[bit]=node;
    }
    Node *get(int bit){
        return links[bit];
    }
};

class Trie{
    private: Node *root;
    public:
    Trie(){
        root=new Node();
    }

    void insert(int num){
    Node *node=root;
    for(int i=31;i>=0;i--){
        int bit=(num>>i)&1;
        if(!node->containKey(bit)){
            node->put(bit,new Node());
        }
        node=node->get(bit);
    }
    }

    int findMax(int num){
        Node *node=root;
        int mxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->containKey(!bit)){
                mxNum=(1<<i)|mxNum;
                node=node->get(!bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return mxNum;

    }
};



int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here.   

    Trie trie;
    for(int i=0;i<n;i++){
        trie.insert(arr1[i]);
    }
    int ans=0;
    for(int i=0;i<m;i++){
        ans=max(ans,trie.findMax(arr2[i]));
    }
    return ans;
}