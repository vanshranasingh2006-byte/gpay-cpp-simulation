#include <bits/stdc++.h>
using namespace std;

struct Students
{
    long long int student_reg;
    string name;

    Students(string name, long long student_reg)
    {
        this->name=name;
        this->student_reg=student_reg;
    }
};

int main()
{
    int reg;
    string name;
    cin >> name;
    cin >> reg;

    Students s1(name,reg);

    cout << s1.name << endl << s1.student_reg << endl;
}