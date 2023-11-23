/**
 * @file quicksort.cpp
 * @brief Quicksort algorithm using OpenMP.
 * @author Joseph Kehoe (Doxygen Comments added by Sebastian Firsaev)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <stdlib.h>    
#include <complex>      
#include <time.h>       
#include <functional>   
#include <vector>       

using namespace std;

const int LENGTH = 2000;

/**
 * @brief Partitions the array for Quicksort based on a pivot element.
 *
 * @param myArray The array to be partitioned.
 * @param low The lowest index of the partition.
 * @param high The highest index of the partition.
 * @return Returns the index of the pivot element.
 */
int partition(vector<int> &myArray, int low, int high) {
    int pivot = myArray[high];
    int k = high;
    int i = low;
    int temp = 0;
    while (i < k) {
        while (myArray[i] < pivot && i < k) ++i;
        while (myArray[k] > pivot && i < k) --k;
        if (i < k) {
            temp = myArray[i];
            myArray[i] = myArray[k];
            myArray[k] = temp;
            i++; // do not decrement k here OR ELSE!!
        }
    }
    return i - 1;
}

/**
 * @brief Implements the Quicksort algorithm.
 *
 * @param myArray The array to be sorted.
 * @param low The lowest index of the array.
 * @param high The highest index of the array.
 * @return Returns 1 upon successful sorting.
 */
int quicksort(vector<int> &myArray, int low, int high) {
    if (low < high) {
        int pivot = partition(myArray, low, high);
        // really we should only do this if each partition is above a certain size (1000 elements?)
        // otherwise, the overhead outweighs any gains from using threads
#pragma omp task shared(myArray)
        quicksort(myArray, low, pivot);
        quicksort(myArray, pivot + 1, high);
#pragma omp taskwait
        return 1;
    }
    // Implicit return if low >= high
}

/**
 * @brief Main function - Entry point of the program.
 *
 * @return Returns 0 upon successful execution.
 */
int main(void) {
    srand(time(NULL));
    vector<int> data(LENGTH);
    for (auto &value : data) {
        value = rand() % 1000;
    }
    for (auto &value : data) {
        cout << value << " ";
    }
    cout << endl << "*******************************" << endl;
    quicksort(data, 0, data.size() - 1);
    for (auto &value : data) {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}
// quicksort.cpp ends here

