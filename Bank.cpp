#include <bits/stdc++.h>
using namespace std;

//------------------------Few Instructions---------------------------------
//1) Having Space should be used with _ like om_prakash
//2)pincode is integer be sure to use int that dont start with 0 (will work on it later)

//----------------------------CLASS----------------------------------------//
class Gpay
{
    private:
        int upi_id, pin_code;
        long long phone_number;
        string name;
        float money;

    public:
        Gpay() // Default constructor: prevents uninitialized/garbage values.
        {
            upi_id = 0;
            phone_number = 0; 
            name = "";
            money = 0.0;
            pin_code=0; // avoid garbage value
        }

        void set_details(int upi_id, string name, long long phone_number, float money, int pin_code) // for setting user info
        {
            this->upi_id=upi_id;
            this->name=name;
            this->phone_number=phone_number;
            this->money=money;
            this->pin_code=pin_code;
        }

        int get_pin_code() // will be used in for checking authenticity
        {
            return this->pin_code;
        }

        string get_name() // name
        {
            return this->name;
        }

        void get_detail() // when user wanna know all details at once
        {
            cout << "\nUpi Id: "<< this->upi_id 
                 << "\nName: " << this->name 
                << "\nPhone Number: " << this-> phone_number
                << "\nMoney: " << this->money;
        }

        int get_upi_id() // to get upi_id of that person for money transaction
        {
            return this->upi_id;
        }

        void money_cdr(float mon_cdr) // money credit in account
        {
            this->money+=mon_cdr;
        }

        void money_dbr(float mon_dbr) // money debit in account
        {
            this->money-=mon_dbr;
        }

        bool check_balance(float money_sent) // check for balance 
        {
            return money_sent<= this->money;
        }

        ~Gpay() // destructor
        {
            cout<<"\nThankyou for using our bank service";
        }

};

//----------------------FUNCTION DECLARATION----------------------------------//

int find_upi(Gpay[], int, int); // func declaration for find if account exist if it is return 0 else 1
int is_pw_corr(Gpay[], int, int);// for valid password
void testing(Gpay[], int, string); // for testing purpose

//-------------------------MAIN----------------------------------------------//
int main()
{
    Gpay user[5];  // default constructor will be called;
    int upi_id;
    long long phone_number;
    string name;
    float money;
    int pincode;

    for(int i = 0; i < 5; i++)
    {
        cout << "Enter for " << i+1 << " member.\n";
        cout << "Enter Upi Id: ";
        cin >> upi_id;
        cout << "Name: ";
        cin  >> name;
        cout << "Phone Number: ";
        cin >> phone_number;
        cout << "Enter the Amount: ";
        cin >> money;
        cout << "Set Pin Code: ";
        cin >> pincode;

        user[i].set_details(upi_id, name, phone_number, money, pincode);  // details is set
        cout<<"\n";
    }

    string choice;   // for login or exit
    while(true)   // ----> Login loop
    {
        cout << "\n\nWelcome to Gpay How can I help you"
        <<"\nEnter 1 to login and any key for exit: ";
        cin >> choice;

        if(choice != "1" && choice != "$1890")   // Exit whole Program
        {
            break;   // exit login loop
        }

        else if(choice == "$1890")   // for testing purpose
        {
            string passcode;
            cout << "\nWelcome Tester Please Enter Your Passcode: " ;
            cin >> passcode;
            testing(user,5,passcode);
        }

        else
        {
            int log_upi;    // userinput upi_id
            int log_pin;     // user input pin code
            int valid_user;     // for 0 and 1 after pw confirmation

            cout << "\nEnter Your Upi Id: ";
            cin >> log_upi;

            int main_acc=find_upi(user, 5, log_upi); //return index of the userinput upi_id , if not found then -1

            if(main_acc == -1)
            {
                cout << "\nAccount does not exist " << log_upi;
            }

            else
            {
                cout << "\nAccount exist for " << log_upi;

                while(true)    // Valid upi_id now pincode checking ----> pin_loop
                {
                    cout << "\nEnter pin for " << log_upi << ": ";
                    cin >> log_pin;
                    valid_user= is_pw_corr(user, main_acc, log_pin);   //return 1 for valid pw else 0

                    if(valid_user)
                    {
                        cout << "\nHello " << user[main_acc].get_name() << " What would you like to do";

                        string choice_feature;   // for feature inputs

                        while(true)  // ----> Features_loop
                        {
                            cout << "\nPress 1 for deatil 2 for sending money any key for exit: ";
                            cin >> choice_feature;

                            if(choice_feature == "1")
                            {
                                user[main_acc].get_detail(); // get account detail
                            }

                            else if (choice_feature == "2")
                            {
                                int reci_upi;      // need 2nd person for transcation
                                cout << "\nEnter Upi Id for receiver account: ";
                                cin >> reci_upi;
                                int receiver_acc=find_upi(user,5,reci_upi);      // check if account exist

                                if(receiver_acc == -1)
                                {
                                    cout << "Receiver Account not Found !";
                                }

                                else
                                {
                                    float transcation; // Money to be sent

                                    cout << "Enter the amount you want to sent: ";
                                    cin >> transcation;

                                    if(user[main_acc].check_balance(transcation)) // check for sufficent fund
                                    {
                                        user[main_acc].money_dbr(transcation);//money debit from sender
                                        user[receiver_acc].money_cdr(transcation);//money credit to receiver

                                        cout << "Money Sent Successfully";
                                    }

                                    else
                                    {
                                        cout << "Insufficent Fund money Transcation fail";
                                    }
                                }
                            }

                            else
                            {
                                cout << "You Have Exited Successfully";
                                break; // exit Feature_loop
                            }
                        }
                        break; // exit pin_loop
                    }


                    else if(log_pin == 101101)//Pin not correct and wanna exit
                    {
                        break; // exit pin_loop
                    }

                    else
                    {
                        cout << "\n incorrect please try again or enter 101101 to exit and relogin";
                    }
                }
            }
        }    
    }
}

//---------------------------------Functions(Initalization)-------------------------------------------//

int find_upi(Gpay user[], int size, int log_upi) //  Finds the account index using the UPI ID; returns -1 if not found.
{
    for(int i = 0; i<size; i++)
    {
        if(log_upi == user[i].get_upi_id())
        {
            return i;
        }
    }
    return -1;
}


int is_pw_corr(Gpay user[], int acc_ind, int log_pin) // 1 -> valid 0-> invalid
{
    if(user[acc_ind].get_pin_code() == log_pin)
    {
        return 1;
    }

    return 0;
}

void testing(Gpay user[], int size, string passcode) // testing 
{
    if(passcode == "78901")
    {
        for(int i = 0; i<size; i++ )
        {
            user[i].get_detail();
            cout<<"\n------------------------------------------\n";
        }
    }

    else
    {
        cout << "You are not the tester";
    }
}

//--------------------------------------------End Of Code-------------------------------------------------------//