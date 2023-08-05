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
using namespace std;

struct Cvor {
   Cvor(int v) {
      vr = v;
   }

   int vr;
   Cvor* l = nullptr;
   Cvor* d = nullptr;
};

Cvor* dodaj(Cvor* t, int v) {
   if (t == nullptr) {
      return new Cvor(v);
   }
   if (v < t->vr) {
      t->l = dodaj(t->l, v);
   } else {
      t->d = dodaj(t->d, v);
   }
   return t;
}

void oslobodi(Cvor* t) {
   if (t == nullptr) {
      return;
   }
   oslobodi(t->l);
   oslobodi(t->d);
   delete t;
   t = nullptr;
   return;
}

void ispisi(Cvor* t) {
   if (t == nullptr) {
      return;
   }
   ispisi(t->l);
   cout << t->vr << " ";
   ispisi(t->d);
   return;
}


int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
   int n;
   cin >> n;

   Cvor* t = nullptr;
   while(n--) {
      int v;
      cin >> v;
      t = dodaj(t, v);
   }

   //ispis
   ispisi(t);
   cout << endl;
   //oslobodi
   oslobodi(t);
    
    return 0;
}
