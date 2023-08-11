/*

Prefiksno stablo drzi vrednost u samoj grani a ne u cvoru. Imamo dve operacije,
umetanje podataka i pretrazivanje. 
Listovi nisu cvorovi koji nemaju potomke, nego cvorovi u kojima se zavrsava rec.
Uvek krecemo od korena. Poenta je prefiks koji mozemo koristiti vise puta.
Prvi cvor u prefiksu je koren.
Prefiks je niz cvorova koji se koriste u pretrazi.
Prefiks je niz cvorova koji se koriste u umetanju podataka.


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
#define CHAR_SIZE 128

struct Node {
   bool isLeaf;
   Node *nodes[CHAR_SIZE];
};

Node *createNode() {
   Node *node = new Node;
   node->isLeaf = false;
   for (int i = 0; i < CHAR_SIZE; i++) {
      node->nodes[i] = nullptr;
   }
   return node;
}

void addWord(Node *root, string &word) {
   int n = word.length();
   for(int i = 0; i < n; i++) {
      if(root->nodes[word[i]] == nullptr) {
         root->nodes[word[i]] = createNode();
      }
      root = root->nodes[word[i]];
   }
   root->isLeaf = true;
}

bool findWord(Node *root, string &word) {
   if(root == nullptr) {
      return false;
   }
   int n = word.length();
   for(int i = 0; i < n; i++) {
      root = root->nodes[word[i]];
      if(root == nullptr) {
         return false;
      }
   }
   return root->isLeaf;
}

void freeTree(Node *root) {
   if(root == nullptr) {
      return;
   }
   for(auto &node : root->nodes) {
      freeTree(node);
   }
   free(root);
}


int main(int argc, char const *argv[]) {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
    
   vector<string> words = {"cod", "coder", "coding", "codecs"};
   Node *root = createNode();

   for(string &s : words) {
      addWord(root, s);
   }
   string s = "cod";

   cout << boolalpha << findWord(root, s) << endl;
   
   freeTree(root);
   return 0;
}
