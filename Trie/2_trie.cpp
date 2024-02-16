struct Node{
    Node *links[26];
    int cntPrefix=0;
    int cntEndWith=0;

    bool containKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    
};
class Trie{
    private: Node *root;

    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                node->put(word[i], new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
         Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
            
        }
       return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
            Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
            
        }
       return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(node->containKey(word[i])){
                node=node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
            
        }
        node->deleteEnd();
    }
};
