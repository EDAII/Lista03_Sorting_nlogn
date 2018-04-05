#include <vector>
#include <algorithm>

static int partition(std::vector<int> &array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i+1], array[high]);
    return (i + 1);
}

void quick_sort(std::vector<int> &array, int low, int high)
{
    if (low < high)
    {
        int partition_index = partition(array, low, high);

        quick_sort(array, low, partition_index - 1);
        quick_sort(array, partition_index + 1, high);
    }
}