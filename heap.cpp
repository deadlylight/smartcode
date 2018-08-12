
#include <stdio.h>
#include <stdlib.h>

struct Heap
{
    static const int max = 8191;
    int array[max+1];
    int count;

    Heap()
    {
        count = 0;
    }

    int left(int x) { return 2 * x; }
    int right(int x) { return 2*x+1;}
    int parent(int x) { return x/2;}

    int size() { return count; }

    bool search(int v, int pos = 1)
    {
        if (pos > count) return false;
        if (array[pos] == v) return true;
        if (array[pos] > v) return false;
        if (search(v, left(pos))) return true;
        return search(v, right(pos));
    }

    void insert(int v)
    {
        count++;
        int pos = count;
        while (pos > 1) {
            int ppos = parent(pos);
            if (array[ppos] < v)
            {
                array[pos] = v;
                return;
            } else {
                array[pos] = array[ppos];
                pos = ppos;
            }
        }
        if (pos == 1) {
            array[1] = v;
        }
    }
    int get()
    {
        return array[1];
    }

    void remove()
    {
        int v = array[count];
        count--;
        int pos = 1;
        while(1) {
            int l = left(pos);
            int r = right(pos);
            int next = l;
            if (l > count) break;
            if ((r <= count) && (array[r] < array[l])) {
                next = r;
            }
            if (v < array[next]) {
                break;
            } else {
                array[pos] = array[next];
                pos = next;
            }
        }
        array[pos] = v;
    }

    void percolate_down(int pos)
    {
        while (pos < count) {
            int l = left(pos);
            int r = right(pos);
            int next = l;
            if (l > count) return;
            if ((r <= count) && (array[r] < array[l])) next = r;
            if (array[pos] <= array[next]) return;
            int tmp = array[pos];
            array[pos] = array[next];
            array[next] = tmp;
            pos = next;
        }
    }

    void build(int* arr, int len)
    {
        while (count < len) {
            count++;
            array[count] = arr[count-1];
        }

        for (int i = count/2; i > 0; i--) {
            percolate_down(i);
        }
    }
};

int main()
{
    srand(MAX);
    /*
    Heap h;
    for (int i = 0; i < MAX; i++) {
       h.insert(rand()%10000);
    }
    while(h.size() > 0) {
        printf("%.8d\n", h.get());
        h.remove();
    }
    */
    int arr[MAX];
    for (int i = 0; i < MAX; i++) {
        arr[i] = rand()%10000;
    }
    Heap h;
    h.build(arr, MAX);
    while (h.size()  > 0) {
        printf("%.8d\n", h.get());
        h.remove();
    }
    return 0;
}

