﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>

const int ARRAY_SIZE = 20;
const int MAX_VALUE = 50;

void printArray(const std::vector<int>& array, int highlight1 = -1, int highlight2 = -1) {
    for (int i = 0; i < array.size(); ++i) {
        if (i == highlight1 || i == highlight2) {
            std::cout << "[" << array[i] << "] ";
        }
        else {
            std::cout << array[i] << " ";
        }
    }
    std::cout << std::endl;
}

void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void bubbleSortVisualization(std::vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                printArray(array, j, j + 1);
                delay(100);
            }
        }
    }
}

void selectionSortVisualization(std::vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(array[i], array[minIndex]);
            printArray(array, i, minIndex);
            delay(100);
        }
    }
}
void mergeSortVisualization(std::vector<int>& array) {
    int n = array.size();
}
void insertionSoryVisualization(std::vector<int>& array) {
    int n = array.size();
}

void displayTimeComplexity() {
    std::cout << "\nTime Complexity of Sorting Algorithms:" << std::endl;
    std::cout << "Bubble Sort - Best Case: O(n), Average Case: O(n^2), Worst Case: O(n^2)" << std::endl;
    std::cout << "Selection Sort - Best, Average, and Worst Case: O(n^2)" << std::endl;
}

int main() {
    std::vector<int> array(ARRAY_SIZE);
    std::srand(std::time(0));
    std::generate(array.begin(), array.end(), []() { return std::rand() % MAX_VALUE; });

    std::cout << "Initial array:" << std::endl;
    printArray(array);

    std::cout << "\nBubble Sort process:" << std::endl;
    bubbleSortVisualization(array);

    std::cout << "\nSorted array with Bubble Sort:" << std::endl;
    printArray(array);

    // Generate a new random array for the next sort
    std::generate(array.begin(), array.end(), []() { return std::rand() % MAX_VALUE; });

    std::cout << "\nInitial array for Selection Sort:" << std::endl;
    printArray(array);

    std::cout << "\nSelection Sort process:" << std::endl;
    selectionSortVisualization(array);

    std::cout << "\nSorted array with Selection Sort:" << std::endl;
    printArray(array);

    displayTimeComplexity();

    return 0;
}
