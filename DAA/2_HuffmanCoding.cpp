#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<string>
using namespace std;

class node{
    public:

    char chr;
    int freq;
    node *left, *right;

    node(char c, int f){
        chr = c;
        freq = f;
        left = right = nullptr;
    }
};

//Comparator for priority queue
struct compare{
    bool operator()(node* l, node* r){
        return l->freq > r->freq;
    }
};

//Take string input, build Huffman tree and return root
node* buildHuffmanTree(const string& text){
    //Map to store frequency of each character
    unordered_map<char, int> freqMap;
    for(char c : text){
        freqMap[c]++;
    }

    //Min-heap priority queue to build the tree(i.e. nodes with least frequency have highest priority)
    priority_queue<node*, vector<node*>, compare> minHeap;

    for(auto pair : freqMap){
        minHeap.push(new node(pair.first, pair.second));
    }

    //Build the tree
    while(minHeap.size() > 1){
        node* left = minHeap.top();
        minHeap.pop();
        node* right = minHeap.top();
        minHeap.pop();

        node* newNode = new node('*', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }

    return minHeap.top();
}

//Recursive function to generate the Huffman Codes
void generateCodes(node* root, string code, unordered_map<char, string>& huffmanCodes){
    if(!root) return;

    //If leaf node, store the code
    if(!root->left && !root->right){
        huffmanCodes[root->chr] = code;
    }

    generateCodes(root->left, code+"0", huffmanCodes);
    generateCodes(root->right, code+"1", huffmanCodes);
}

//Function to encode the input text using the generated Huffman Codes
string encode(const string& text, unordered_map<char, string>& huffmanCodes){
    string encodedString = "";
    for(char c : text){
        encodedString += huffmanCodes[c];
    }
    return encodedString;
}

int main(){
    string text;
    cout << "Enter the text: ";
    cin >> text;

    node* root = buildHuffmanTree(text);

    unordered_map<char, string> huffmanCodes;

    generateCodes(root, "", huffmanCodes);

    //Print the Huffman Codes
    cout << "Huffman Codes:\n";
    for(auto pair : huffmanCodes){
        cout << pair.first << ": " << pair.second << endl;
    }

    //Encode the text
    string encodedString = encode(text, huffmanCodes);
    cout << "Encoded String: " << encodedString << endl;

    return 0;
}