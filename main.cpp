#include <iostream>
#include <cstring>

/*
 * Algorithms taken from Clifford A. Shaffer, Data Structures and Algorithm Analysis Edition 3.2
 */

void swapper(int& x, int& y){   //Generic swapping function for two variables
    int temp  = x;
    x = y;
    y = temp;
}
template <typename E>
void swap(E x[], int a, int b){ //Generic swapping functino for two elements in an array
    E temp = x[a];
    x[a] = x[b];
    x[b] = temp;
}
template <class T> void swap2 (T& a, T& b){ //Another swapping function apart from the generic methods, using some new features of C++11
    T c(std::move(a));
    a=std::move(b);
    b=std::move(c);
}

template <typename E>
void bubsort(E A[], int n) { // Bubble Sort
    for (int i=0; i<n-1; i++) // Bubble up i’th record
        for (int j=n-1; j>i; j--)
            if (A[j] < A[j-1])
                swapper(A[j], A[j-1]);
}
template <typename E>
void selsort(E A[], int n) { // Selection Sort
    for (int i=0; i<n-1; i++) { // Select i’th record
        int lowindex = i; // Remember its index
        for (int j=n-1; j>i; j--) // Find the least value
            if (A[j] < A[lowindex])
                lowindex = j; // Put it in place
        swap2(A[i], A[lowindex]);
    }
}

template <typename E>
void inssort(E A[], int n) { // Insertion Sort
    for (int i=1; i<n; i++) // Insert i’th record
        for (int j=i; (j>0) && (A[j] < A[j-1]); j--)
            swap2(A[j], A[j-1]);
}

void sortNames(char* array[], int size) {
    for(int startScan = 0; startScan < (size -1); startScan++){
        int minIndex = startScan;
        for (int j = startScan+1; j < size; j++){
            if (strcmp(array[j],array[minIndex]) < 0){
                minIndex = j;
            }
        }
        if (minIndex != startScan){
            char *temp = array[startScan];
            array[startScan] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

int main() {
    const int SIZE  = 6;


    int array[SIZE] = {12,45,23,46,7,2};
    int array2[SIZE] = {12,45,23,46,7,2};
    int array3[SIZE] = {12,45,23,46,7,2};

    char *test[] = {"James", "Jame", "Jaame", "Jab", "Jack"};


    //Basic sorting functions are used on three separate arrays that are initialized with the same data
    //The likeness of the cout outputs show that each function sorted each array properly
    bubsort(array,SIZE);
    for(int i = 0; i < SIZE - 1; i++){
        std::cout << array[i] << "  ";
    }
    std::cout << std::endl;

    selsort(array2,SIZE);
    for(int i = 0; i < SIZE - 1; i++){
        std::cout << array2[i] << "  ";
    }
    std::cout << std::endl;

    inssort(array3,SIZE);
    for(int i = 0; i < SIZE - 1; i++){
        std::cout << array3[i] << "  ";
    }
    std::cout << std::endl;


    //Demonstrates the sorting of names, with Selection Sort based function "sortNames" working on an a 2D array of characters.
    int size = sizeof(test)/sizeof(char*);
    sortNames(test,size);

    for(int i = 0; i <5; i++){
        std::cout << test[i] << " ";
    }

    return 0;
}
