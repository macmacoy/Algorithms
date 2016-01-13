//
//  main.cpp
//  InsertionSort
//
//  Created by Mac Macoy on 1/10/16.
//  Copyright © 2016 COP3530. All rights reserved.
//

#include <iostream>
#include <stdlib.h> // random number generator
#include <time.h> // time
using namespace std;

void InsertionSort(int array[]){
    int length = sizeof(array);
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
    cout<<"How long is the array?"<<endl;
    cin>>length;
    
    cout<<"Original Array:"<<endl;
    
    int array[length];
    
    srand(time(NULL)); // generate random seed
    for(int i = 0; i<length; i++){
        int number = rand()%100+1; // int between 1 and 100
        array[i] = number;
        cout<<number<<endl;
    }
    cout<<endl;
    
    InsertionSort(array);
    
    cout<<"Sorted Array:"<<endl;
    
    for(int i = 0; i<length; i++){
        cout<<array[i]<<endl;
    }
    
    return 0;
}
