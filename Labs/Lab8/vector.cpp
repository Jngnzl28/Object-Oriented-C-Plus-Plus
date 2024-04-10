#include <iostream>
#include <vector>
using namespace std;

void printMemVec(vector<int> v)
{
    printf("Vector - Each int is worth %lu bytes\n", sizeof(v[0]));
    for(int i = 0; i < v.size(); i++)
    {
        printf("Value : %i at Memory Location: %p\n", v[i], &v + i);
    }
}

void incVecBy10(vector<int> & v) 
{
    for(int i = 0; i < v.size(); i++)
    {
        v[i] += 10;
    }
}

int main() 
{
    const int SIZE = 5;
    vector<int> vec;
    for(int i = 0; i < SIZE; i++)
    {        
        vec.push_back(100+i);
    }
    printf("Before--------------------------------------------\n");
    printMemVec(vec);
    incVecBy10(vec);
    
    printf("After---------------------------------------------\n");
    printMemVec(vec);
    
    vec.pop_back();
    printf("After Pop-----------------------------------------\n");
    printMemVec(vec);

    vec.push_back(101);
    vec.push_back(102);
    printf("After Push----------------------------------------\n");
    printMemVec(vec);

    return 0;
}