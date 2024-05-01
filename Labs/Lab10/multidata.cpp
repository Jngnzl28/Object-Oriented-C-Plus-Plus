#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;

template<typename T>
int iterativeSearch(vector<T>v, T elem)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == elem)
            return i;
    }
    return -1;
}

template<typename T>
int binarySearch(vector<T>v, T start, T end, T elem)
{
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    if (v[mid] > elem){
        end = mid - 1;
    } else if (v[mid] < elem) {
        start = mid + 1;
    } else {
        return mid;
    }
    return binarySearch(v, start, end, elem);
}

template<class T, class U>
void vecGen(T filename, vector<U> & v)
{
    ifstream file(filename);
    int num;
    v.clear();
    while (file.is_open() && file >> num) {
        v.push_back(num);
    }
    file.close();
}

int main()
{
    vector<int> v;
    vecGen("10000_numbers.csv", v);

    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    for(int i = 0; i < elem_to_find.size(); i++)
    {
        int elem = elem_to_find[i];

        auto start = chrono::high_resolution_clock::now();
        int index_if_found = iterativeSearch(v, elem);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

        cout << index_if_found << ": " << duration.count() << endl;
    }

    cout << endl;

    int b_start = 0;
    int b_end = v.size() - 1;

    for(int i = 0; i < elem_to_find.size(); i++)
    {
        int elem = elem_to_find[i];

        auto start = chrono::high_resolution_clock::now();
        int index_if_found = binarySearch(v, b_start, b_end, elem);
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

        cout << index_if_found << ": " << duration.count() << endl;
    }
    
    return 0;
}

