#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;


void writeToFile(string filename, int * arr, int sample_size)
{
    ofstream file(filename);

    
    for(int i = 0; i < sample_size; i++){
        file << arr[i];
        file << "\n";
    }
    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

void writeToFile(string filename, string * arr, int sample_size)
{
    ofstream file(filename);

    
    for(int i = 0; i < sample_size; i++){
        file << arr[i];
        file << "\n";
    }
    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

void writeToFile(string filename, char * arr, int sample_size)
{
    ofstream file(filename);

    
    for(int i = 0; i < sample_size; i++){
        file << arr[i];
        file << "\n";
    }
    file.close();
    printf("Wrote to %s\n", filename.c_str());
}

void readFile(string filename)
{
    ifstream ifile;
    ifile.open(filename.c_str());
    string line;
    
    if (!ifile.fail())
    {
        while(getline(ifile, line))
        {
            cout << line << " ";
        }
        ifile.close();
    } 
    else
        cout << "file not found.\n\n";

}

int main()
{
    const int SAMPLE_SIZE = 10; 
    int array_int[SAMPLE_SIZE] = {1,2,3,4,5,6,7,8,9,10};
    string array_str[SAMPLE_SIZE] = {"This","is","a","sentence. ",
                                     "This","is","another","sentence. ",
                                     "The", "end."};
    
    char array_char[SAMPLE_SIZE] = {'a','b','c','d','e','0','1','2','3','4'};

    string int_file = "array_int.csv";
    writeToFile(int_file, array_int, SAMPLE_SIZE);

    string str_file = "array_str.csv";
    writeToFile(str_file, array_str, SAMPLE_SIZE);

    string char_file = "array_char.csv";
    writeToFile(char_file, array_char, SAMPLE_SIZE);

    readFile(int_file);
    cout << "\n\n";
    readFile(str_file);
    cout << "\n\n";
    readFile(char_file);
    cout << "\n\n";

    return 0;
}