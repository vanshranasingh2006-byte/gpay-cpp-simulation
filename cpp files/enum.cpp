#include <bits/stdc++.h>
using namespace std;

enum Attendance
{
    Absent = 1,
    Present = 2,
    Blocked = 0
};

int main()
{
    Attendance a;
    a= Attendance::Absent;
    cout << a << endl;
    if(a == 2)
    {
        cout << "The student is present";
    }

    else if (a == 1)
    {
        cout << "The student is absent";
    }

    else 
    {
        cout << "The student is block";
    }
}