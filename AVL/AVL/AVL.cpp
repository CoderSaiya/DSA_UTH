
//main.cpp
#include <iostream>
#include "AVL_tree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    AVL_tree* tree = new AVL_tree();
    Node* n;
    /* n=new Node(10);
     tree->InsertNodeRe(n);
      n=new Node(8);
     tree->InsertNodeRe(n);
      n=new Node(4);
     tree->InsertNodeRe(n);*/

    /*n = new Node("What","Cai gi");
    tree->InsertNode(n);
    n = new Node("Who","Ai");
    tree->InsertNode(n);
    n = new Node("How","Nhu the nao");
    tree->InsertNode(n);
    n = new Node("Where","O dau");
    tree->InsertNode(n);*/
    /*n = new Node(8);
    tree->InsertNode(n);
    n=new Node(4);
    tree->InsertNode(n);
    n=new Node(1);
    tree->InsertNode(n);
    n=new Node(15);
    tree->InsertNode(n);*/
    /*tree->TravelNLR();*/

    /*ifstream inputFile("test.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file.\n";
        return 1;
    }

    AVL_tree* tree_ = new AVL_tree();
    Node* n;
    int value;
    string line;

    while (getline(inputFile, line)) {
        istringstream iss(line);
        while (iss >> value) {
            n = new Node(value);
            tree_->InsertNode(n);
        }
    }

    inputFile.close();*/

    AVL_tree dictionary;

    ifstream file("dictionary.txt");
    if (!file.is_open()) {
        cout << "Khong the mo file." << endl;
        return 1;
    }

    string word, meaning;
    while (file >> word >> meaning) {
        Node* newNode = new Node(word, meaning);
        dictionary.InsertNode(newNode);
    }
    file.close();

    // Menu
    int choice;
    do {
        cout << "1. Tra cuu tu." << endl;
        cout << "2. Them tu moi." << endl;
        cout << "3. Sua chua tu." << endl;
        cout << "4. Thoat." << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Tra cuu tu
            string searchWord;
            cout << "Nhap tu can tra cuu: ";
            cin >> searchWord;

            Node* result = dictionary.search_x(searchWord);
            if (result != nullptr) {
                cout << "Nghia cua tu '" << searchWord << "': " << result->GetMeaning() << endl;
            }
            else {
                cout << "Khong tim thay tu '" << searchWord << "' trong tu dien." << endl;
            }
            break;
        }
        case 2: {
            // Them tu moi
            string newWord, newMeaning;
            cout << "Nhap tu moi: ";
            cin >> newWord;
            cout << "Nhap nghia cua tu: ";
            cin >> newMeaning;

            Node* newNode = new Node(newWord, newMeaning);
            dictionary.InsertNode(newNode);
            cout << "Tu da duoc them moi." << endl;
            break;
        }
        case 3: {
            // Sua chua tu
            string editWord, newMeaning;
            cout << "Nhap tu can sua chua: ";
            cin >> editWord;

            Node* editNode = dictionary.search_x(editWord);
            if (editNode != nullptr) {
                cout << "Nhap nghia moi cua tu: ";
                cin >> newMeaning;
                editNode->SetMeaning(newMeaning);
                cout << "Tu da duoc sua chua." << endl;
            }
            else {
                cout << "Khong tim thay tu '" << editWord << "' trong tu dien." << endl;
            }
            break;
        }
        case 4:
            // Thoat chuong trinh
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
            break;
        }
    } while (choice != 4);

    ofstream outFile("dictionary_update.txt");
    if (!outFile.is_open()) {
        cout << "Khong the mo file de ghi." << endl;
        return 1;
    }
    else {
        dictionary.outFile(dictionary.Getroot(), outFile);
        outFile.close();
    }

    return 0;
}