/*

Najcesca rec u prefiksnom stablu

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <stack>
#include <utility>
#include <numeric>
#include <cstring>
#include <functional>
#include <cstdlib>
using namespace std;

struct Node {
   string word;
   int count;
   unordered_map<char, Node*> nodes;
};

Node* createNode() {
   Node* node = new Node();
   node->count = 0;
   node->word = "";
   return node;
}

void insert(Node* root, string &word, int i) {
   if(i == word.size()) {
      root->count++;
      root->word = word;
      return;
   }
   auto iterator = root->nodes.find(word[i]);
   if(iterator == root->nodes.end()) {
      root->nodes[word[i]] = createNode();
   }
   insert(root->nodes[word[i]], word, i+1);
}

void maxOccuringWord(Node* root, string &word, int i) {
   if(root->word != "") {
      cout << root->word << " " << i << endl;
      if(root->count > i) {
         i = root->count;
         word = root->word;
      }
   }
   auto begin = root->nodes.begin();
   auto end = root->nodes.end();
   while(begin != end) {
      maxOccuringWord(begin->second, word, i);
      begin++;
   }
}

void freeTree(Node* root) {
   if(root == nullptr) { 
      return;
   }
   for(auto &node : root->nodes) {
      freeTree(node.second);
   }
   delete root;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
   vector<string> words = {"cod", "codecs", "coding", "coder", "coding", "coder", "coding"};
   Node* root = createNode();
   for(auto &word : words) {
      insert(root, word, 0);
   }
   string word = "";
   int i = 0;
   maxOccuringWord(root, word, i);
   cout << word << endl;
   freeTree(root);
    
    return 0;
}
