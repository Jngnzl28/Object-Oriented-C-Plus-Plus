//Lab2_calc.cpp
/***
 * { This program creates numbers and displays them}
***/

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int x = 0;
    int y = 5;

    while(x < y) 
    {
        printf("%i\n", x);
        x=x + 3;
    }
    
    if (x%2 == 0)
        printf("Even");
    else
        printf("Odd");
    return 0;
}