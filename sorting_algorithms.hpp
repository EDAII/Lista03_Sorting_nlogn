#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

int getdigit(int i, int d)
{
    while (d > 1) {
        d--;
        i/=10;
    }

    return i%10;
}

int getnumofdigit(int i)
{
    int d = 0;
    while(i) {
        i/=10;
        d++;
    }
    return d;
}

void countingsort(vector<int> &vi, int d)
{
    vector<int> out(vi.size(),0);
    vector<int> c(10,0); // 0 to 9

    for (int i=0;i<vi.size();i++) {
        c[getdigit(vi[i],d)]++;
    }
    // c[i] now contains the number of elements equal to i.

    for (int i=1;i<10;i++) {
        c[i] += c[i-1];
    }
    // c[i] now contains the number of elements less than or equal to i

    for (int i=vi.size()-1;i>=0;i--) {
        out[c[getdigit(vi[i],d)]-1] = vi[i];
        c[getdigit(vi[i],d)]--;
    }
    vi = out;
}

void radixsort(vector<int> &vi)
{
    // first assume all int have same number of digits
    int d = getnumofdigit(vi[0]);
    for (int i=1;i<=d;i++) {
        countingsort(vi,i);
    }
}

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
