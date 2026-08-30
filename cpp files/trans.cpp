#include <bits/stdc++.h>
using namespace std;

class Transcation
{
    private:
        int upi_id;
        string name;
        float money;

    public:

        Transcation(int upi, string uname, float umoney)
        {
            upi_id=upi;
            name=uname;
            money=umoney;
        }

        void mon_dbr(float mon)
        {
            this->money-=mon;
        }

        void mon_cdr(float mon)
        {
            this->money+=mon;
        }

        bool check_balance(float mon)
        {
            return this->money >=mon;
        }
        void get_money()
        {
            cout<< this->money;
        }
};

int main()
{
    Transcation u1(1234,"vansh",20000);
    Transcation u2(1222,"hello",30980);

    int acc_choice;
    cout<<"enter which user u1 or u2 by 1 or 2: ";
    cin>> acc_choice;

    int mon_choice;

    if(acc_choice==1)
    {
        cout<<"Money to be send: ";
        cin>>mon_choice;

        if(u1.check_balance(mon_choice))
        {
            u1.mon_dbr(mon_choice);
            u2.mon_cdr(mon_choice);
            cout<<"Money send successfully";
        }

        else{
            cout<<"Insufficent fund";
        }
    }

     else if(acc_choice==2)
    {
        cout<<"Money to be send: ";
        cin>>mon_choice;

        if(u2.check_balance(mon_choice))
        {
            u2.mon_dbr(mon_choice);
            u1.mon_cdr(mon_choice);
            cout<<"Money send successfully";
        }

        else{
            cout<<"Insufficent fund";
        }
    }

    else 
    {
        cout << "account not found";
    }

    cout << "\nu1 money : ";
    u1.get_money();

    cout<< "\nu2 money : ";
    u2.get_money();
}