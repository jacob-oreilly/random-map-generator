#include <iostream>
#include <cmath>
#include "perlinnoise.h"
using namespace std;

//int repeat = -1;
//static setRepeat(int rep)  {
//    repeat = rep;
//}
//double OctavePerlin(double x, double y, double z, int octaves, double persistence) {
//    double total = 0;
//    double frequency = 1;
//    double amplitude = 1;
//    double maxValue = 0;			// Used for normalizing result to 0.0 - 1.0
//    for(int i=0;i<octaves;i++) {
//        total += perlin(x * frequency, y * frequency, z * frequency) * amplitude;
//
//        maxValue += amplitude;
//
//        amplitude *= persistence;
//        frequency *= 2;
//    }
//
//    return total/maxValue;
//}
//
//float GenerateNoiseMap(int mapWidth, int mapHeight, float scale) {
//    float noiseMap[mapHeight, mapWidth];
//
//    if(scale <= 0) {
//        scale = 0.001;
//    }
//    for(int i = 0; i < mapHeight; i++) {
//        for(int j = 0; j < mapWidth; j++) {
//            float sampleX = i / scale;
//            float sampleY = j / scale;
//            //float perlinValue
//        }
//    }
//    return 0.0;
//}
// main() is where program execution begins.
int main()
{
    unsigned int seed = 237;
    PerlinNoise pn(seed);
    unsigned int kk = 0;
    int screenWidth = 10;
    int screenHeight = 10;
//    int maxNumberBlockHeight = screenWidth / 32;
//    int maxNumberBlockWidth = screenHeight / 32;

    int a[screenHeight][screenWidth];
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    {
        //[i][0]=rand()%2;
        for (int j = 0; j < sizeof(a[i]) / sizeof(a[i][0]); j++)
        {
            //Old random generator
            //int oneProbability = rand()%100;
            //cout<<"2D array have: "<< a[i][j]<<endl;
            //out = out + std::to_string(a[i][j]);
            //a[i][j] = rand()%2;
            // << "rand Numb: " << oneProbability;
            //if (oneProbability >= 30 && oneProbability <= 90) {
            //    a[i][j] = 1;
            //}
            //else {
             //   a[i][j] = 0;
            //}
            double x  = (double)j/((double)screenWidth);
            double y = (double)i/((double)screenHeight);
            double n = pn.noise(10 * x, 10 * y, 0.3);
            a[i][j] = floor(255 * n);
            cout << a[i][j] << " \n"[j == sizeof(a[i]) / sizeof(a[i][0])-1];
        }
        //cout<<"Map: "<< out<<endl;
    }
    cout << "Hello World"; // prints Hello World
    return 0;
}

//int inc(int num) {
//    num++;
//    if (repeat > 0) num %= repeat;
//
//    return num;
//}
