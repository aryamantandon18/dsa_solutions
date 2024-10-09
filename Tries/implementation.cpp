#include<iostream>

using namespace std;

class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};

class Trie{
 public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        //assuming word to be in capital letters
        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL){
            //letter Present
            child = root->children[index];
        }
        else{
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        //Recursion
       insertUtil(child,word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root,word);
    }


    bool searchUtil(TrieNode* root,string word){
        if(word.length() == 0){
            return root->isTerminal;
        }
        int i = word[0] - 'A';
        TrieNode* child;

        if(root->children[i] != NULL){
            child = root->children[i];
        }
        else{
            return false;
        }
    //Recursion
    return searchUtil(root,word.substr(1));     //passing the whole word except the first letter.    
    }

    bool search(string word){
        return searchUtil(root,word);
    }

    void DeleteUtil(TrieNode* root,string word){
        if(word.length() == 0){
            root->isTerminal = false;
            return;
        }

        int i = word[0]-'A';
        TrieNode* child;
        if(root->children[i] != NULL){
            child = root->children[i];
        }
        else{
            cout<<"Word not Present"<<endl;
            return;
        }
       return DeleteUtil(child,word.substr(1));
    }

    void Delete(string word){
        DeleteUtil(root,word);
    }
};

int main(){
    Trie* t = new Trie();
    t->insertWord("HELLO");
    cout<<t->search("HELLO")<<endl;

}