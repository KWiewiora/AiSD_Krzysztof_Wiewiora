#include <iostream>

void przesiej (double t[], int i, int n)
{
    int k;
    double x = t[i];
    while (
        ( (k = 2 * i + 2) < n && t[k] > x && t[k] > t[k - 1] ) 
                    || 
        (   --k < n && t[k] > x) )
    {
        t[i] = t[k];
        i = k;
    }
 
    t[i] = x;
}

void heap_sort (double t[], int n)
{
    int i = n / 2;
    while (i) 
    {
        przesiej (t, --i, n);
    }

    while (--n)
    {
        double x = t[n]; 
        t[n] = t[0]; 
        t[0] = x;
        przesiej (t, 0, n);
    }
}

void przesiej_w_gore (double t[],int i, double x)
{
  // początkowo x = t[i] 
  int k; // ojciec i 
  while( i && t[k=(i-1)/2] < x )
  {
       t[i] = t[k];
       i  =   k;
  }
  t[i] = x;
}

class PriorityQueue
{
    private:
    int size;
    int maxSize;
    double *queue;

    void buildHeap()
    {
        int i = size / 2;
        while (i) 
        {
            przesiej(queue, --i, size);
        }
    }

    public:
    PriorityQueue(double t[], int maxS, int s = 0) : queue(t), maxSize(maxS), size(s)
    {
        buildHeap();
    }

    void put(double element)
    {
        if (!isMax())
        {
            //queue[size] = element;
            przesiej_w_gore(queue, size, element);
            size += 1;
            // buildHeap();
        }
    }

    double getMax()
    {
        double res = -__DBL_MIN__;
        res = queue[0];
        queue[0] = queue[size - 1];
        size -= 1;
        przesiej(queue, 0, size);
        
        return res;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isMax()
    {
        return size == maxSize;
    }

    void print()
    {
        if (!isEmpty())
        {
            std::cout << "queue elements: ";
            for (int i = 0; i < size; i++)
            {
                std::cout << queue[i] << ", ";
            }
            std::cout << "\n";
        }
        else
        {
            std::cout << "queue is empty\n";
        }
    }
};

int main()
{
    double t[10];
    PriorityQueue pq(t, 10);
    pq.print();
    std::cout << pq.getMax() << "\n";
    pq.put(10);
    pq.print(); 
    pq.put(140);
    pq.print();
    pq.put(2);
    pq.print();
    pq.put(120);
    pq.print();
    std::cout << pq.getMax() << "\n";
    std::cout << pq.getMax() << "\n";
    std::cout << pq.getMax() << "\n";
    pq.print();

    std::cout << "============\n";
    double t1[] = { 1, 1, 1, 1, 100 };
    PriorityQueue pq2(t1, 5, 5);
    pq2.print();
    pq2.put(10);
    pq2.print(); 
    std::cout << pq2.getMax() << "\n";
    pq2.print(); 

    return 0;
}