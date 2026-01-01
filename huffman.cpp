#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

// A Tree Node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f, Node* l = nullptr, Node* r = nullptr) {
        ch = c;
        freq = f;
        left = l;
        right = r;
    }
};

// Comparison object to order the heap (Min-Heap)
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Recursive function to generate Huffman Codes
void generateCodes(Node* root, string str, map<char, string> &huffmanCode) {
    if (!root) return;

    // Found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    generateCodes(root->left, str + "0", huffmanCode);
    generateCodes(root->right, str + "1", huffmanCode);
}

// "Low-level memory management": Function to delete the tree and free memory
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// Main Huffman coding function
void buildHuffmanTree(string text) {
    // 1. Count frequency of appearance of each character
    map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // 2. Create a priority queue to store live nodes of Huffman tree
    priority_queue<Node*, vector<Node*>, compare> pq;

    // 3. Create a leaf node for each character and add it to the priority queue
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // 4. Iterate while size of heap contains more than one node
    while (pq.size() != 1) {
        // Remove the two nodes of highest priority (lowest frequency)
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        // Create a new internal node with these two nodes as children
        // and with frequency equal to the sum of the two nodes' frequencies.
        int sum = left->freq + right->freq;
        pq.push(new Node('\0', sum, left, right));
    }

    // Root stores pointer to root of Huffman Tree
    Node* root = pq.top();

    // 5. Traverse the Huffman Tree and store Huffman Codes in a map
    map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // --- DISPLAY RESULTS ---
    cout << "--- Huffman Codes Generated ---" << endl;
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }

    cout << "\nOriginal String: " << text << endl;

    // Create Encoded String
    string encodedString = "";
    for (char ch : text) {
        encodedString += huffmanCode[ch];
    }

    // --- FILE I/O OPERATIONS ---
    // Save to compressed file
    ofstream outFile("compressed.txt");
    outFile << encodedString;
    outFile.close();

    cout << "Encoded String (Saved to compressed.txt): " << encodedString << endl;

    // Calculate Efficiency
    int originalBits = text.length() * 8; // ASCII is 8 bits
    int compressedBits = encodedString.length(); // Huffman is 1 bit per char in string
    double ratio = (1.0 - (double)compressedBits / originalBits) * 100;
    
    cout << "\n--- Efficiency Stats ---" << endl;
    cout << "Original Size: " << originalBits << " bits" << endl;
    cout << "Compressed Size: " << compressedBits << " bits" << endl;
    cout << "Compression Ratio: " << ratio << "%" << endl;

    // --- MEMORY CLEANUP ---
    deleteTree(root);
}

int main() {
    string text = "Hello this is Shreesh Pathak who build file compression using Huffman Coding.";

    // Or uncomment below to read from file:
    /*
    ifstream inFile("input.txt");
    string line, text;
    while (getline(inFile, line)) { text += line + "\n"; }
    */

    buildHuffmanTree(text);

    return 0;
}