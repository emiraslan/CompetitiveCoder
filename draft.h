#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric> //For accumulate operation
using namespace std;

int draft()
{
     // Initializing vector with array values
    int arr[] = {10, 20, 5, 23 ,42 , 15};

    // Calculating the size of arr
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> vect(arr, arr+n);

    // Sorting the Vector in Ascending order
    sort(vect.begin(), vect.end());

    // Reversing the Vector
    reverse(vect.begin(), vect.end());

    // Finding max element
    cout << "\nMaximum element of vector is: ";
    cout << *max_element(vect.begin(), vect.end());

    // Finding min element
    cout << "\nMinimum element of vector is: ";
    cout << *min_element(vect.begin(), vect.end());

    // Starting the summation from 0
    cout << "\nThe summation of vector elements is: ";
    cout << accumulate(vect.begin(), vect.end(), 0);

    // Counts the occurrences of 20 from 1st to
    // last element
    cout << "\nOccurrences of 20 in vector : ";
    cout << count(vect.begin(), vect.end(), 20);

    // find() returns iterator to last address if
    // element not present
    find(vect.begin(), vect.end(),5) != vect.end()?
                         cout << "\nElement found":
                     cout << "\nElement not found";

    int arr1[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    vector<int> vect1(arr1, arr1+n1);

    // Returns the first occurrence of 20
    vector<int>::iterator q = lower_bound(vect1.begin(), vect1.end(), 20);

    // Returns the last occurrence of 20
    vector<int>::iterator p = upper_bound(vect1.begin(), vect1.end(), 20);

    cout << "\nThe lower bound is at position: ";
    cout << q - vect1.begin() << endl;

    cout << "The upper bound is at position: ";
    cout << p - vect1.begin() << endl;


    int arr2[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    vector<int> vect2(arr2, arr2+n2);

    cout << "\nVector is :";
    for (int i=0; i<6; i++)
        cout << vect2[i]<<" ";

    // Delete second element of vector
    vect2.erase(vect2.begin()+1);

    cout << "\nVector after erasing the element: ";
    for (int i=0; i<5; i++)
        cout << vect2[i] << " ";

    // sorting to enable use of unique()
    sort(vect2.begin(), vect2.end());

    cout << "\nVector before removing duplicate "
             " occurrences: ";
    for (int i=0; i<5; i++)
        cout << vect2[i] << " ";

    // Deletes the duplicate occurrences
    vect2.erase(unique(vect2.begin(),vect2.end()),vect2.end());

    cout << "\nVector after deleting duplicates: ";
    for (int i=0; i< vect2.size(); i++)
        cout << vect2[i] << " ";


    // modifies vector to its next permutation order
    next_permutation(vect2.begin(), vect2.end());
    cout << "\nVector after performing next permutation: ";
    for (int i=0; i<vect2.size(); i++)
        cout << vect2[i] << " ";

    prev_permutation(vect2.begin(), vect2.end());
    cout << "\nVector after performing prev permutation: ";
    for (int i=0; i< vect2.size(); i++)
        cout << vect2[i] << " ";

    // Return distance of first to maximum element
    cout << "\nDistance between first to max element: ";
    cout << distance(vect2.begin(),
                     max_element(vect2.begin(), vect2.end()));

    return 0;
}
