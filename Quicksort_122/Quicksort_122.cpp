#include <iostream>
using namespace std;


int arr[20];                        //array of integers to hold velues
int cmp_count = 0;                  // number of comparasion
int mov_count = 0;                  // number of data movement 
int n;

void input() { 
    while (true)
    {
        cout << "Masukan Panjang element array :";
        cin >> n;

        if (n <= 20)
            break;
        else 
            cout << "\nMasukan Panjang array adalah 20" << endl;

    }
    cout << "\n-------------------------" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "\n-------------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> arr[i]; 
    
    }
}
// swaps the element st index x with the element at index y
void swap(int x, int y) 
{
    int temp;

    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp; 
}
void q_short(int low, int high) 
{
    int pivot, i, j;
    if (low > high)                             //langkah Algoritma No.1
        return;

    //Partition the list into two parts:
    // one containing elements less the or equal to pivot
    // outher containing elements greather than pivot


    pivot = arr[low];                           //langkah Algoritma No.2

    i = low + 1;                                 //langkah Algoritma No.3
    j = high;                                    //langkah Algoritma No.4


    while (i <= j)                              //langkah Algoritma No.10
    {
        //search for an element greather than pivot
        while ((arr[i] <= pivot) && (i <= high))          //langkah Algoritma No.5
        {
            i++;                                  //langkah Algoritma No.6
            cmp_count++;
        }
        cmp_count++;

        //search for an element less than or equal pivot
        while ((arr[j] > pivot) && (j >= low))            //langkah Algoritma No.7
        {
            j--;                                           //langkah Algoritma No.8
            cmp_count++; 
        }
        cmp_count;

        // if the greater element is on  the left of the element
        if (i < j)                                         //langkah Algoritma No.9
        {
            //swap the element at index i with the element at index j
            swap(i, j);
            mov_count++;
        }
    }
    //j now containt the index of the last element in the sorted list
    if (low < j)                                      //langkah Algoritma No.11
    {
        //move the private to its correct position in the list
        swap(low, j);
        mov_count++;
    }
    //sort the list on the left pivot using quick sort
    q_short(low, j - 1);                              //langkah Algoritma No.12

    // sort the list on the right of pivot using quick sort
    q_short(j + 1, high);                                //langkah Algoritma No.13

}

void display() {
    cout << "\n-----------------" << endl;
    cout << "\nSorted Array" << endl;
    cout << "\n-----------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; 
    }

    cout << "\n\nNumber of comparasions :" << cmp_count << endl;
    cout << "Number of data movements :" << mov_count << endl;
}

int main()
{
    input();
    q_short(0, n - 1);              //sort the array using quick sort
    display();
    system("pause");
     
    return 0;
}
