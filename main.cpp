#include <iostream>
using namespace std;

// main() is where program execution begins.
int main()
{
    int screenWidth = 640;
    int screenHeight = 480;
    int maxNumberBlockHeight = screenWidth / 32;
    int maxNumberBlockWidth = screenHeight / 32;

    int a[maxNumberBlockHeight][maxNumberBlockWidth];
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        a[i][0]=rand()%2;
        for (int j = 0; j < sizeof(a[i]) / sizeof(a[i][0]); j++)
        {
            //cout<<"2D array have: "<< a[i][j]<<endl;
            //out = out + std::to_string(a[i][j]);
            a[i][j] = rand()%2;
            cout << a[i][j] << " \n"[j == sizeof(a[i]) / sizeof(a[i][0])-1];
        }
        //cout<<"Map: "<< out<<endl;
    }
    cout << "Hello World"; // prints Hello World
    return 0;
}

