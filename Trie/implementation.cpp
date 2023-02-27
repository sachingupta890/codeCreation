#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;

        //constructor
        TrieNode(char ch){
            data = ch;
            for (int i = 0; i < 25; i++){
                children[i] = NULL;
            }

            isTerminal = false;
        }
};

class Trie{
    public:
        TrieNode *root;
        
        Trie(){
            root = new TrieNode('\0');
        }
        void insertUtil(TrieNode* root,string word){
            //base case 
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }


            //assuming the string is in upperCase
            int index = word[0] - 'A';

            TrieNode *child;

            if(root->children[index] != NULL){
                //if present move ahead
                child = root->children[index];
            }
            else{
                //not present then create entry
                child = new TrieNode(word[0]);
                //connnect the node
                root->children[index] = child;
            }

            //Recursively call for next part
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word){

            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root,string word){

            //base case
            if(word.length() == 0 ){
                return root->isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode *child;

            if(root->children[index] != NULL){
                //present
                child = root->children[index];
            }
            else{
                //absent
                return false;
            }

            return searchUtil(child, word.substr(1));
        }
         
        bool search(string word){
            return searchUtil(root, word);
        }

        void deleteUtil(TrieNode *root, string word) {
  // Base case
  if (word.length() == 0) {
    root->isTerminal = false;
    if (!hasChildren(root)) {
      delete root;
      root = NULL;
    }
    return;
  }

  int index = word[0] - 'A';
  TrieNode *child;

  if (root->children[index] != NULL) {
    child = root->children[index];
  } else {
    return;
  }

  deleteUtil(child, word.substr(1));

  // If the deleted word is the last word in the Trie
  if (!hasChildren(root) && !root->isTerminal) {
    delete root;
    root = NULL;
  }
}

bool hasChildren(TrieNode *root) {
  for (int i = 0; i < 26; i++) {
    if (root->children[i] != NULL) {
      return true;
    }
  }
  return false;
}


        void deleteWord(string word){
            deleteUtil(root, word);
        }
};
int main(){

        Trie *t = new Trie();

        t->insertWord("ABCD");

        cout << "Present or not " << t->search("ABCD") << endl;

        t->insertWord("SACHIN");

        cout << "Present or not " << t->search("SACHIN") << endl;

        t->deleteWord("SACHIN");
        cout << "Present or not " << t->search("SACHIN") << endl;
}