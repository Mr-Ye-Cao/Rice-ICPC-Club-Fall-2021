// C++ code to demonstrate the working of insert()
#include<iostream>
#include<set> // for set operations
using namespace std;

int main()
{
    // declaring set
    set<int> st;

    // declaring iterators
    set<int>::iterator it = st.begin();
    set<int>::iterator it1, it2;

    // declaring pair for return value of set containing
    // set iterator and bool
    pair< set<int>::iterator,bool> ptr;

    // using insert() to insert single element
    // inserting 20
    ptr = st.insert(20);

    // checking if the element was already present or newly inserted
    if (ptr.second)
        cout << "The element was newly inserted" ;
    else cout << "The element was already present" ;

    // printing set elements after insertion
    cout << "\nThe set elements after 1st insertion are : ";
    for (it1 = st.begin(); it1!=st.end(); ++it1)
        cout << *it1 << " ";

    // inserting set elements using hint
    st.insert(it, 24);

    // printing set elements after insertion
    cout << "\nThe set elements after 2nd insertion are : ";
    for (it1 = st.begin(); it1!=st.end(); ++it1)
        cout << *it1 << " ";

    // inserting array elements in set
    // 24 is not inserted again
    int arr[3] = { 25, 24, 26 };
    st.insert(arr, arr+3);

    // printing set elements after insertion
    cout << "\nThe set elements after 3rd insertion are : ";
    for (it1 = st.begin(); it1!=st.end(); ++it1)
        cout << *it1 << " ";

}