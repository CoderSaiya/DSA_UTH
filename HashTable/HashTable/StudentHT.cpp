//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class Student {
//public:
//    int MSSV;
//    string name;
//    string email;
//    string phoneNumber;
//
//    Student() : MSSV(0), name(""), email(""), phoneNumber("") {}
//
//    Student(int mssv, const string& studentName, const string& email, const string& phone)
//        : MSSV(mssv), name(studentName), email(email), phoneNumber(phone) {}
//};
//
//class HashMap {
//private:
//    int M;
//    Student* U;
//
//public:
//    HashMap(int size) : M(size) {
//        U = new Student[M];
//        for (int i = 0; i < M; i++)
//            U[i] = Student();
//    }
//
//    ~HashMap() {
//
//    }
//
//    /*int Hash(int k) {
//        if (M == 0)
//            return 0;
//        return (k % M);
//    }*/
//
//    int Hash(const string& name) {
//        if (M == 0)
//            return 0;
//
//        int hashValue = 0;
//        for (char c : name) {
//            hashValue += static_cast<int>(c);
//        }
//
//        return (hashValue % M);
//    }
//
//    void InitHash(const vector<Student>& students) {
//        for (size_t i = 0; i < students.size(); i++) {
//            int pos = Hash(students[i].name);
//            U[pos] = students[i];
//        }
//    }
//
//    Student Search(const string& name) {
//        int pos = Hash(name);
//        return U[pos];
//    }
//    void InitHashChanning(const vector<Student>& students) {
//        for (const Student& student : students) {
//            int pos = Hash(student.name);
//            while (U[pos].MSSV != 0 && U[pos].name != student.name) {
//                pos = (pos + 1) % M;
//            }
//
//            U[pos] = student;
//        }
//    }
//
//    Student SearchChanning(const string& key) {
//        int pos = Hash(key);
//
//        while (U[pos].MSSV != 0 && U[pos].name != key) {
//            pos = (pos + 1) % M;
//        }
//        return U[pos];
//    }
//};
//
//int main() {
//    int M;
//    cout << "Nhap so phan tu cua bang bam (M): ";
//    cin >> M;
//
//    vector<Student> students;
//    students.push_back(Student(1, "Messi","m@gmail.com","0900000001"));
//    students.push_back(Student(3, "Ronaldo","r@gmail.com","0900000002"));
//    students.push_back(Student(5, "Rooney","r2@gmail.com","0900000003"));
//    students.push_back(Student(7, "Drogba", "d@gmail.com", "0900000004"));
//    students.push_back(Student(9, "Xavi","x@gmail.com","0900000005"));
//
//    HashMap hashMap(M);
//    hashMap.InitHash(students);
//
//    /*int x;
//    cout << "Nhap MSSV tim kiem: ";
//    cin >> x;*/
//
//    cout << "Nhap ten sinh vien tim kiem: ";
//    cin.ignore();
//    string x; getline(cin, x);
//
//    Student result = hashMap.Search(x);
//
//    if (result.MSSV == 0) {
//        cout << "Khong tim thay SV nao trong bang bam\n";
//    }
//    else {
//        cout << "MSSV\tName\t\tEmail\t\t\tPhone\n";
//        cout << result.MSSV << "\t" << result.name << "\t\t" << result.email << "\t\t" << result.phoneNumber << "\n";
//    }
//
//    return 0;
//}
