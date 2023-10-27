#include <iostream>

using namespace std;

void Display(int arr[], int length);
void Insert(int arr[], int value, int pos, int length);
void Delete(int arr[], int pos, int length);

int main()
{
    int length;
    int pos; //position
    int val; //value
    const int size = 20;
   
    int arr[size];

    //Create Array's Length and Elements
    cout << "Enter number of elements of array: ";
    cin >> length;

    if (length >= size) {
        cout << "Array is not big enough to hold";
        return 0;
    }

    for (int i = 0; i < length; i++)
    {
        cout << "Enter element at index " << i << ": ";
        cin >> arr[i];
    }

    //Displaying elements
    Display(arr, length);
    
    cout << "Choose number for operation:\n";
    cout << "1. Insertion\n";
    cout << "2. Deletion\n";
    int choice;
    cin >> choice;


    switch (choice) {
    case 1:
        cout << "Which index do you want to insert to? ";
        cin >> pos;
        if (pos < 0 || pos > length - 1)
        {
            cout << "Out of bounds!\n";
            break;
        }
        cout << "Which element do you want to insert? ";
        cin >> val;
        if (pos == 0) {
            arr[0] = val;
            break;
        }
        if (pos == length - 1) {
            arr[length - 1] = val;
            break;
        }
       
        Insert(arr, val, pos, length);
        break;

    case 2:
        cout << "Which index do you want to delete from? ";
        cin >> pos;
        if (pos < 0 || pos > length - 1)
        {
            cout << "Out of bounds!\n";
            break;
        }
        if (pos == 0)
            for (int i = pos; i < length; i++)
                arr[0] = arr[i + 1];
        if (pos == length - 1)
            for (int i = length - 1; i > 0; i--)
                arr[length - 1] = arr[length - 2];
        Delete(arr, pos, length);
        break;
    }

    Display(arr, length);
    return 0;
}

void Display(int arr[], int length)
{
    cout << "The elements in the array are: ";
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Insert(int arr[], int value, int pos, int length)
{
    for (int i = length - 1; i > pos - 1; i--)
        arr[i + 1] = arr[i];
    arr[pos - 1] = value;
}

void Delete(int arr[], int pos, int length)
{
    for (int i = pos - 1; i < length - 1; i++)
        arr[i] = arr[i + 1];
    arr[length - 1] = 0;
}