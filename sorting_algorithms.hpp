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

static void merge(std::vector<int> &array, int start, int mid, int end)
{
    int pos = start, q = mid+1, k = 0;
    
    std::vector<int> temp;
    temp.reserve(end-start+1);

    for (int i = start; i <= end; i++)
    {
        if (pos > mid)
            temp[k++] = array[q++];
        else if (q > end)
            temp[k++] = array[pos++];
        else if (array[pos] < array[q])
            temp[k++] = array[pos++];
        else
            temp[k++] = array[q++];
    }

    for (int i = 0; i < k; i++)
        array[start++] = temp[i];
}

void merge_sort(std::vector<int> &array, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(array, start, mid);
        merge_sort(array, mid+1, end);

        merge(array, start, mid, end);
    }
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