/**
 * @file stencil.cpp
 * @brief A program implementing a stencil operation.
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

// array dimension
const int DIM = 1000;
const int SIZE = 4;

/**
 * @brief Calculates neighboring elements of a vector based on index.
 *
 * @param in The input vector.
 * @param index The index for which neighbors need to be calculated.
 * @param out The vector to store neighboring elements.
 * @return Returns 1 upon successful calculation.
 */
int calcNeighbours(vector<float> const &in, int index, vector<float> &out) {
    int amount = out.size();
    for (int i = 0; i < out.size(); ++i) {
        int k = i - amount / 2;
        if (k < 0) {
            k = in.size() + k; // wrap k around size of in vector
        } else if (k >= in.size()) {
            k = k - in.size();
        }
        out[i] = in[k];
    }
    return 1;
}

/**
 * @brief Applies a stencil operation on the input vector using a provided function.
 *
 * @param in The input vector.
 * @param out The output vector after applying the stencil operation.
 * @param f The function to be applied on the stencil.
 * @param size The size of the stencil.
 */
void stencil(vector<float> const &in, vector<float> &out, function<float(vector<float>)> f, int size) {
#pragma omp parallel for
    for (int i = 0; i < in.size(); ++i) {
        vector<float> neighbours(size);
        calcNeighbours(in, i, neighbours);
        out[i] = f(neighbours);
    }
}

/**
 * @brief Calculates the average value of a set of values.
 *
 * @param currentValues The set of values to calculate the average.
 * @return The average value of the set.
 */
float getNewValue(vector<float> currentValues) {
    float total = 0.0;
    for (auto const &value : currentValues) {
        total += value;
    }
    return total / currentValues.size();
}

/**
 * @brief Main function - Entry point of the program.
 *
 * @return Returns 0 upon successful execution.
 */
int main(void) {
    vector<float> first(DIM), second(DIM);
    // initialize vectors
    srand(time(NULL));

    for (auto &value : first) {
        value = (float)rand() / ((float)(RAND_MAX) + (float)(1));
    }
    for (auto it = second.begin(); it < second.end(); ++it) {
        *it = 0.0f;
    }
    //
    float sum = 0.0f;
    for (auto const &value : first) {
        sum += value;
    }
    cout << sum << endl;
    stencil(first, second, getNewValue, SIZE);
    sum = 0.0f;
    for (auto const &value : second) {
        sum += value;
    }
    cout << sum << endl;
    return 0;
}
// stencil.cpp ends here

