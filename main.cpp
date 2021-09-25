#include <iostream>
using namespace std;

// main() is where program execution begins.
int main()
{
    int screenWidth = 1920;
    int screenHeight = 1080;
    int maxNumberBlockHeight = screenWidth / 32;
    int maxNumberBlockWidth = screenHeight / 32;

    int a[maxNumberBlockHeight][maxNumberBlockWidth];
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        //[i][0]=rand()%2;
        for (int j = 0; j < sizeof(a[i]) / sizeof(a[i][0]); j++)
        {
            int oneProbability = rand()%100;
            //cout<<"2D array have: "<< a[i][j]<<endl;
            //out = out + std::to_string(a[i][j]);
            //a[i][j] = rand()%2;
            // << "rand Numb: " << oneProbability;
            if (oneProbability >= 30 && oneProbability <= 90) {
                a[i][j] = 1;
            }
            else {
                a[i][j] = 0;
            }
            cout << a[i][j] << " \n"[j == sizeof(a[i]) / sizeof(a[i][0])-1];
        }
        //cout<<"Map: "<< out<<endl;
    }
    cout << "Hello World"; // prints Hello World
    return 0;
}

