#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "sorting_algorithms.hpp"

#define NO_OF_ELEMENTS_SIZE 17

using namespace std;

double test_sorting_algorithm(void (&sort_function)(std::vector<int> &, int, int), int elements);
std::vector<int> generate_vector(int elements);
void run();

const int noOfElements[] = {10, 100, 250, 500, 1000, 2500, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 1000000, 2500000, 5000000, 10000000};

int main()
{
    run();
}

double test_sorting_algorithm(void (&sort_function)(std::vector<int> &, int, int), int elements)
{
    std::vector<int> array = generate_vector(elements);
    double duration;
    std::clock_t start;

    start = std::clock();
    sort_function(array, 0, array.size() - 1);

    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    std::vector<int>().swap(array);
    return duration;
}

std::vector<int> generate_vector(int elements)
{
    std::vector<int> new_vector;
    new_vector.reserve(elements);

    std::random_device rd;
    std::mt19937 gen(rd());
    //it produces random numbers between 1 and 1,000,000
    std::uniform_int_distribution<> dis(1, 1000000);

    for (int i = 0; i < elements; i++)
        new_vector.push_back(dis(gen));

    return new_vector;
}

void run()
{
    std::ofstream output_file;
    output_file.open("data.txt");

    // Some double precision output constraints for the output file
    output_file << std::fixed << std::showpoint;
    output_file << std::setprecision(10);

    std::cout << "QUICK SORT\n";
    output_file << "quick\n";

    for (int i = 0; i < NO_OF_ELEMENTS_SIZE; i++)
    {
        double result = test_sorting_algorithm(quick_sort, noOfElements[i]);
        std::cout << noOfElements[i] << " elements: "
                  << result << std::endl;

        output_file << noOfElements[i] << ' ' << result << std::endl;
    }

    std::cout << "MERGE SORT\n";
    output_file << "merge\n";

    for (int i = 0; i < NO_OF_ELEMENTS_SIZE; i++)
    {
        double result = test_sorting_algorithm(merge_sort, noOfElements[i]);
        std::cout << noOfElements[i] << " elements: "
                  << result << std::endl;

        output_file << noOfElements[i] << ' ' << result << std::endl;
    }

    cout << "RADIX SORT\n";
    for (int i = 0; i < NO_OF_ELEMENTS_SIZE; i++)
    {
        auto start = chrono::steady_clock::now();
        vector<int> vi = {generate_vector(noOfElements[i])};
        radixsort(vi);

        auto end = chrono::steady_clock::now();

        // Store the time difference between start and end
        auto diff = end - start;
        cout << noOfElements[i] << " elements: "
             <<chrono::duration <float> (diff).count() << endl;

        output_file << noOfElements[i] << ' ' <<chrono::duration <float> (diff).count() << endl;
    }
    output_file.close();
}

