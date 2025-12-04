#include <iostream>
using namespace std;

// Function for Linear Search
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Function for Binary Search
int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int scores[20];
    int sum = 0;
    int n = 10;

    cout << "Enter 10 student scores:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
        sum += scores[i];
    }

    // Display scores
    cout << "\nStudent Scores:\n";
    for (int i = 0; i < n; i++)
    {
        cout << scores[i] << " ";
    }

    // Average
    float average = (float)sum / n;
    cout << "\n\nAverage score = " << average << endl;

    // Insert new score at 5th position
    int newScore;
    cout << "\nEnter new score to insert at 5th position: ";
    cin >> newScore;

    for (int i = n; i > 4; i--)
    {
        scores[i] = scores[i - 1];
    }
    scores[4] = newScore;
    n++;

    // Find lowest score
    int minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (scores[i] < scores[minIndex])
        {
            minIndex = i;
        }
    }

    // Delete lowest score
    for (int i = minIndex; i < n - 1; i++)
    {
        scores[i] = scores[i + 1];
    }
    n--;

    // Display updated array
    cout << "\nUpdated Scores:\n";
    for (int i = 0; i < n; i++)
    {
        cout << scores[i] << " ";
    }

    // Linear Search
    int key;
    cout << "\n\nEnter score to search (Linear Search): ";
    cin >> key;

    int result1 = linearSearch(scores, n, key);
    if (result1 != -1)
        cout << "Score found at position: " << result1 + 1 << endl;
    else
        cout << "Score not found" << endl;

    // Binary Search (works properly if array is sorted)
    int result2 = binarySearch(scores, 0, n - 1, key);
    if (result2 != -1)
        cout << "Score found using Binary Search at position: " << result2 + 1 << endl;
    else
        cout << "Score not found using Binary Search" << endl;

    return 0;
}