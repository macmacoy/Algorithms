// input: 1. N number of ints to sort
//        2. N numbers
// output: sorted list

#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(int array[], int arraySize){
    cout<<endl;
    int length = arraySize;
    int i, j, temp;
    
    for(i = 1; i < length; i++){ // iterate through every space
        j = i;
        while (j > 0 && (array[j-1] > array[j])) {
            // swap the two spaces
            temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp;
            j--;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int length;
    cin>>length;
    
    int array[length];

    for(int i = 0; i<length; i++){
        int number;
        cin>>number;
        array[i] = number;
    }
    
    InsertionSort(array, length);
    
    for(int i = 0; i<length; i++){
        cout<<array[i]<<endl;
    }
    
    return 0;
}