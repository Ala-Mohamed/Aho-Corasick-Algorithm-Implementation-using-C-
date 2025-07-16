#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct nod {
    char charac;
    bool isLeaf;
    nod* fail;
    vector<nod*> childs;
    int len;

    nod(char ch) : charac(ch), isLeaf(false), fail(nullptr), childs(4, nullptr), len(0) {}
};

class trie {
private:
    nod* main_root;

    int indexing(char c) {
        switch (c) {
            case 'A':
                return 0;
            case 'G':
                return 1;
            case 'C':
                return 2;
            case 'T':
                return 3;
            default:
                return -1;
        }

    }

public:
    trie() {
        main_root = new nod('\0');
    };


    bool add(const string& seq) {
        nod* cur = main_root;
        for (char ch : seq) {
            int INDX = indexing(ch);
            if (INDX == -1) {
                cout << "Invalid sequence: " << endl;
                return false;
            }
            if (cur->childs[INDX] == nullptr) {
                cur->childs[INDX] = new nod(ch);
            }
            cur = cur->childs[INDX];
        }
        cur->isLeaf = true;
        cur->len = seq.size();
        return true;
    }

    bool seqExist(const string& seq) {
        nod* cur = main_root;
        for (char ch : seq) {
            int INDX = indexing(ch);
            if (INDX == -1 || cur->childs[INDX] == nullptr) {
                return false;
            }
            cur = cur->childs[INDX];
        }
        return cur->isLeaf;
    }

    bool prefixExist(const char* str) {
        nod* cur = main_root;
        while (*str) {
            int INDX = indexing(*str);
            if (INDX == -1 || cur->childs[INDX] == nullptr) {
                return false;
            }
            cur = cur->childs[INDX];
            str++;
        }
        return true;
    }

    void FAILFUNC() {
        queue<nod*> all_nodes;
        main_root->fail = main_root;
        for (int i = 0; i < 4; i++) {
            if (main_root->childs[i]) {
                main_root->childs[i]->fail = main_root;
                all_nodes.push(main_root->childs[i]);
            }
        }
        while (!all_nodes.empty()) {
            nod* cur = all_nodes.front();
            all_nodes.pop();
            for (int i = 0; i < 4; i++) {
                if (cur->childs[i]) {
                    nod* temp = cur->fail;
                    while (temp != main_root && !temp->childs[i]) {
                        temp = temp->fail;
                    }
                    if (temp->childs[i]) {
                        cur->childs[i]->fail = temp->childs[i];
                    }
                    else {
                        cur->childs[i]->fail = main_root;
                    }
                    all_nodes.push(cur->childs[i]);
                }
            }
        }
    }

    vector<int> search(const string& seq) {
        vector<int> results;
        nod* cur = main_root;

        for (int i = 0; i < seq.size(); i++) {
            int INDX = indexing(seq[i]);
            if (INDX == -1) {
                cout << "Invalid character in text: " << seq[i] << endl;
                continue;
            }

            while (cur != main_root && cur->childs[INDX] == nullptr) {
                cur = cur->fail;
            }

            if (cur->childs[INDX] != nullptr) {
                cur = cur->childs[INDX];
            }

            nod* temp = cur;
            while (temp != main_root) {
                if (temp->isLeaf) {
                    results.push_back(i - temp->len + 1);
                }
                temp = temp->fail;
            }
        }
        return results;
    }
};


int main() {
    trie trie;
    trie.add("ACC");
    trie.add("ATC");
    trie.add("CAT");
    trie.add("GCG");

    trie.FAILFUNC();
    vector<int> found = trie.search("GCATCG");
    if (trie.seqExist("ACn")) {
        cout << "Word 'ACn' found!" << endl;
    }
    else {
        cout << "Word 'ACn' not found." <<   endl;
    }

    if (trie.seqExist("ACC")) {
        cout << "Word 'ACC' found!" <<   endl;
    }
    else {
        cout << "Word 'ACC' not found." <<   endl;
    }
    string text = "ACCATCGCG";
    bool exi = trie.seqExist(text);
    cout << exi;
    vector<int> results = trie.search(text);

    for (int pos : results) {
        cout << "Pattern found ending at position: " << pos << endl;
    }
}