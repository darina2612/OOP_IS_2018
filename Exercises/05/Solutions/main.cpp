#include "Vector.h"
#include <fstream>
#include <iostream>

void fillVectorWithContentsOfFile(Vector<int>& v, const char* fileName)
{
    std::ifstream input(fileName);

    if(!input)
    {
        std::cout << "Problem opening " << fileName << " for reading." << std::endl;

        return;
    }

    int numbersCount;
    int number;

    input >> numbersCount;

    for(int i = 0; i < numbersCount; ++i)
    {
        input >> number;

        v.push_back(number);
    }
}

float averageValue(const Vector<int>& v)
{
    float sum = 0.0;

    for(size_t i = 0; i < v.size(); ++i)
    {
        sum += v[i];
    }

    return sum / (float)v.size();
}

void removeSmallerThan(Vector<int>& v, float value)
{
    for(size_t i = 0; i < v.size(); ++i)
    {
        if(v[i] < value)
        {
            v.removeElementAtIndex(i);
            --i;
        }
    }
}

Vector<int> merge(const Vector<int>& leftSortedVector, const Vector<int>& rightSortedVector)
{
    Vector<int> result;

    size_t leftIndex = 0, rightIndex = 0;

    while((leftIndex < leftSortedVector.size()) && (rightIndex < rightSortedVector.size()))
    {
        if(leftSortedVector[leftIndex] < rightSortedVector[rightIndex])
        {
            result.push_back(leftSortedVector[leftIndex]);
            ++leftIndex;
        }
        else
        {
            result.push_back(rightSortedVector[rightIndex]);
            ++rightIndex;
        }
    }

    while(leftIndex < leftSortedVector.size())
    {
        result.push_back(leftSortedVector[leftIndex]);
        ++leftIndex;
    }

    while(rightIndex < rightSortedVector.size())
    {
        result.push_back(rightSortedVector[rightIndex]);
        ++rightIndex;
    }

    return result;
}

void printIntVector(const Vector<int>& v)
{
    for(size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    Vector<int> v;
    fillVectorWithContentsOfFile(v, "numbers.txt");
    printIntVector(v);

    float average = averageValue(v);
    std::cout << average << std::endl;

    removeSmallerThan(v, average);
    printIntVector(v);

    Vector<int> sortedV1;
    Vector<int> sortedV2;

    sortedV1.push_back(0);
    sortedV1.push_back(3);
    sortedV1.push_back(5);

    sortedV2.push_back(-1);
    sortedV2.push_back(2);
    sortedV2.push_back(3);
    sortedV2.push_back(6);

    Vector<int> merged = merge(sortedV1, sortedV2);
    printIntVector(merged);

    return 0;
}

