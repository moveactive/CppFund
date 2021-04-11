#include <iostream>
#include <cmath>
#include <array>

const int CAPACITY{100};

std::array<int, CAPACITY> readInput(int & arrLenght);
int findMinDistanceBetweenTwoNumbers(std::array<int, CAPACITY> & myArray, int & arrLenght);

int main(int argc, char const *argv[])
{
    int arrLenght{0};
    std::array<int, CAPACITY> myArray = readInput(arrLenght);
    std::cout << findMinDistanceBetweenTwoNumbers(myArray, arrLenght) << std::endl;

    return 0;
}

std::array<int, CAPACITY> readInput(int & arrLenght)
{
    std::cin >> arrLenght;
    std::array<int, CAPACITY> myArray;
    for(int i = 0; i < arrLenght; ++i)
    {
        std::cin >> myArray[i];
    }
    return myArray;    
}

int findMinDistanceBetweenTwoNumbers(std::array<int, CAPACITY> & myArray, int & arrLenght)
{
    int currentDistance{0};
    int minDistance{INT32_MAX};
    for(int i = 0; i < arrLenght; ++i)
    {
        for(int j = i; j < arrLenght; ++j)
        {
            if(i == j)
            {
                continue;
            }
            currentDistance = abs((myArray[i] - myArray[j]));
            if(currentDistance <= minDistance)
            {
                minDistance = currentDistance;
            }
        }
    }
    return minDistance;
}