//#include <iostream>
//#include <vector>
//
//class HashMap {
//private:
//    int M;
//    int* U;
//
//public:
//    HashMap(int size) {
//        M = size;
//        U = new int[M];
//        for (int i = 0; i < M; i++)
//            U[i] = 0;
//    }
//
//    ~HashMap() {
//    }
//
//    int Hash(int k) {
//        if (M == 0)
//            return 0;
//        return (k % M);
//    }
//
//    void InitHash(const std::vector<int>& keys) {
//        for (size_t i = 0; i < keys.size(); i++) {
//            int pos = Hash(keys[i]);
//            U[pos] = keys[i];
//        }
//    }
//
//    int Search(int key) {
//        int pos = Hash(key);
//        return U[pos];
//    }
//};
//
//int main() {
//    int M = 10;
//    std::vector<int> keys = { 1, 2, 4, 6, 9, 14 };
//
//    HashMap hashMap(M);
//    hashMap.InitHash(keys);
//
//    int x;
//    std::cout << "Nhap khoa tim kiem: ";
//    std::cin >> x;
//
//    int result = hashMap.Search(x);
//
//    if (result == 0) {
//        std::cout << "Khong tim thay khoa trong bang bam\n";
//    }
//    else {
//        std::cout << "Gia tri phan tu can tim kiem:\n" << result;
//    }
//
//    return 0;
//}
