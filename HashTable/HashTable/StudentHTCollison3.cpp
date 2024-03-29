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

class HashMap {
private:
    int M;
    Student* U;

public:
    HashMap(int size) : M(size) {
        U = new Student[M];
        for (int i = 0; i < M; i++)
            U[i] = Student();
    }

    ~HashMap() {
    }

    int Hash(const string& name, int attempt) {
        if (M == 0)
            return 0;

        int hashValue = 0;
        for (char c : name) {
            hashValue += static_cast<int>(c);
        }
        return (hashValue + attempt * attempt) % M;
    }

    void InitHash(const vector<Student>& students) {
        for (const Student& student : students) {
            int attempt = 0;
            int pos = Hash(student.name, attempt);

            while (U[pos].MSSV != 0 && U[pos].name != student.name) {
                attempt++;
                pos = Hash(student.name, attempt);
            }

            U[pos] = student;
        }
    }

    Student Search(const string& key) {
        int attempt = 0;
        int pos = Hash(key, attempt);

        while (U[pos].MSSV != 0 && U[pos].name != key) {
            attempt++;
            pos = Hash(key, attempt);
        }

        return U[pos];
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
