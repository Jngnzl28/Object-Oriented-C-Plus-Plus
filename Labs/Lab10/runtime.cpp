#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>
#include <numeric>
#include <string>

using namespace std;



void writeTimes(string filename, const vector<double> times, const vector<int> n)
{
    ofstream myFile(filename);

    myFile << "Number of Elements (n)\t Time (sec) " << endl;
    for(int i = 0; i < times.size(); i++)
    {
        myFile<< n[i] << "\t" << times[i] <<"\n";
    }
    myFile.close();
    cout << "Wrote to " << filename << endl;
}

double average(const vector<double> a)
{
    if (a.empty())
    {
        return 0;
    }
    return accumulate(a.begin(), a.end(), 0.0) / a.size();
    /*     
    int n = 0;
    double mean = 0.0;
    for (auto x : a) {
        double delta = x - mean;
        mean += delta/++n;
    }
    return mean;
    */

}

int iterativeSearch(vector<int>v, int elem)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == elem)
            return i;
    }
    return -1;
}

int binarySearch(vector<int>v, int start, int end, int elem)
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

void vecGen(string filename, vector<int> & v)
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
    vector<int> elem_to_find;
    vecGen("test_elem.csv", elem_to_find);

    vector<int> file_sizes;
    vecGen("sizes.csv", file_sizes);

    vector<int> v;

    vector<double> times;

    vector<double> avg;

    string filename;

    for(int i = 0; i < file_sizes.size(); i++)
    {
        filename = to_string(file_sizes[i]) + "_numbers.csv";

        vecGen(filename, v);

        cout << filename << endl;

        times.clear();

        for(int i = 0; i < elem_to_find.size(); i++)
        {
            int elem = elem_to_find[i];

            auto start = chrono::high_resolution_clock::now();
            int index_if_found = iterativeSearch(v, elem);
            auto end = chrono::high_resolution_clock::now();

            auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

            double duration_double = std::chrono::duration<double>(duration).count();

            times.push_back(duration_double);

            cout << index_if_found << ": " << duration.count() << endl;

        }

        double average_times = average(times);

        avg.push_back(average_times);

    }

    writeTimes("iterativeSearch_times.csv", times, v);


    for(int i = 0; i < file_sizes.size(); i++)
    {
        filename = to_string(file_sizes[i]) + "_numbers.csv";

        vecGen(filename, v);

        cout << filename << endl;

        times.clear();
        int b_start = 0;
        int b_end = v.size() - 1;
        for(int i = 0; i < elem_to_find.size(); i++)
        {
            int elem = elem_to_find[i];

            auto start = chrono::high_resolution_clock::now();
            int index_if_found = binarySearch(v, b_start, b_end, elem);
            auto end = chrono::high_resolution_clock::now();

            auto duration = chrono::duration_cast<std::chrono::microseconds>(end - start);

            double duration_double = std::chrono::duration<double>(duration).count();

            times.push_back(duration_double);

            cout << index_if_found << ": " << duration.count() << endl;

        }

        double average_times = average(times);

        avg.push_back(average_times);

    }

    writeTimes("binarySearch_times.csv", times, v);

    avg.clear();

    return 0;
}

