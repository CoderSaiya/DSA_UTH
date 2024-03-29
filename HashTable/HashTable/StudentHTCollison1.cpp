#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
public:
    int MSSV;
    string name;
    string email;
    string phoneNumber;

    Student() : MSSV(0), name(""), email(""), phoneNumber("") {}

    Student(int mssv, const string& studentName, const string& email, const string& phone)
        : MSSV(mssv), name(studentName), email(email), phoneNumber(phone) {}
};

class Node {
public:
    Student data;
    Node* next;

    Node(const Student& student) : data(student), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void Insert(const Student& student) {
        Node* newNode = new Node(student);
        if (head == nullptr) head = newNode;
        else {
            Node* p = head;
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = newNode;
        }
    }

    Student Search(const string& key) {
        Node* current = head;

        while (current) {
            if (current->data.name == key) {
                return current->data;
            }
            current = current->next;
        }
        return Student();
    }
};

class HashMap {
private:
    int M;
    vector<LinkedList> U;

public:
    HashMap(int size) : M(size), U(size) {}

    int Hash(const string& key) {
        if (M == 0)
            return 0;

        int hashValue = 0;
        for (char c : key) {
            hashValue += static_cast<int>(c);
        }

        return (hashValue % M);
    }

    void InitHash(const vector<Student>& students) {
        for (const Student& student : students) {
            int pos = Hash(student.name);
            U[pos].Insert(student);
        }
    }

    Student Search(const string& key) {
        int pos = Hash(key);

        return U[pos].Search(key);
    }
};

int main() {
    int M;
    cout << "Nhap so phan tu cua bang bam (M): ";
    cin >> M;

    vector<Student> students;
    students.push_back(Student(1, "Messi", "m@gmail.com", "0900000001"));
    students.push_back(Student(3, "Ronaldo", "r@gmail.com", "0900000002"));
    students.push_back(Student(5, "Rooney", "r2@gmail.com", "0900000003"));
    students.push_back(Student(7, "Drogba", "d@gmail.com", "0900000004"));
    students.push_back(Student(9, "Xavi", "x@gmail.com", "0900000005"));

    HashMap hashMap(M);
    hashMap.InitHash(students);

    string name;
    cout << "Nhap ten sinh vien tim kiem: ";
    cin.ignore();
    getline(cin, name);

    Student result = hashMap.Search(name);

    if (result.MSSV == 0) {
        cout << "Khong tim thay SV nao trong bang bam\n";
    }
    else {
        cout << "MSSV\tName\t\tEmail\t\t\tPhone\n";
        cout << result.MSSV << "\t" << result.name << "\t\t" << result.email << "\t\t" << result.phoneNumber << "\n";
    }

    return 0;
}
