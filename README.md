# High-Performance File Compressor (Huffman Coding)
![Language](https://img.shields.io/badge/C%2B%2B-17-blue.svg)
![Focus](https://img.shields.io/badge/Focus-Systems%20Programming-green.svg)
![Status](https://img.shields.io/badge/Status-Completed-orange.svg)

## 📌 Project Overview
This project is a high-efficiency file compression tool engineered in **C++**. It utilizes **Huffman Coding** (a greedy algorithm) to minimize file size without losing data. 

I built this project to demonstrate **low-level system skills**, specifically manual memory management and algorithm optimization, which are critical for resource-constrained environments like embedded systems.

## 🚀 Key Features
* **Huffman Algorithm:** Implements a Min-Heap (`std::priority_queue`) to generate optimal prefix codes based on character frequency.
* **Memory Management:** Features a custom recursive destructor to manually free all nodes in the Huffman Tree, ensuring **zero memory leaks**.
* **File I/O:** Reads raw text files and outputs a compressed binary string sequence.
* **Efficiency Metrics:** Automatically calculates and displays the compression ratio (typically 30-40% reduction for text).

## 🛠️ Technical Implementation
### The Logic
1.  **Frequency Analysis:** Maps character occurrences ($O(N)$).
2.  **Tree Construction:** Builds a binary tree where frequent characters are near the root (short codes) and rare characters are deep leaves ($O(N \log N)$).
3.  **Encoding:** Generates unique bit-sequences for every character.

### Why C++?
I chose C++ for this project to leverage:
* **STL Containers:** Used `std::map` and `std::priority_queue` for efficient data handling.
* **Pointers:** Used raw pointers for the Tree Nodes to simulate low-level data structure control.

## 💻 How to Run
**1. Compile the code:**
```bash
g++ -std=c++17 huffman.cpp -o huffman
Run the executable:
./huffman

📊 Sample Output:
--- Efficiency Stats ---
Original Size: 616 bits
Compressed Size: 335 bits
Compression Ratio: 45.6169%

🔮 Future Improvements
Implement bitwise operations to write actual binary data to disk (currently writes string representation for demonstration).
Add a decompression module to restore original files.

Author: Shreesh Pathak

