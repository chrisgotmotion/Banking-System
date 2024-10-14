#include <iostream>
#include <conio.h> //for getch()

using namespace std;

class Bank
{
    char name[100], address[100], pin[4], accountType; int balance;

public:
    void open_account();
    void deposit_money();
    void withdraw_money();
    void display_account();
};
string username;
string userpin;
string correctpin;



//Function to open an account
void Bank::open_account()
{
    cout<<"Create a username: ";
    cin>>username;
    cin.getline(name, 100);

    cout<<"Create an account number: ";
    cin.getline(address, 100);

    cout<<"Create a pin for your account: ";
    cin>>correctpin;

    cout<<"What type of account woulds you like to open? Saving (s) or Current (c): ";
    cin>>accountType;

    cout<<"Enter amount to deposit: ";
    cin>>balance;

    cout<<"Your account is created.\n";
}

//Function to deposit money
void Bank::deposit_money()
{
    int amount;
    cout<<"Enter amount to deposit: ";
    cin>>amount;
    while (true)
        {
            cout<<"Enter your pin: ";
            cin>>userpin;
        if (userpin == correctpin)
        {
            cout<<"Correct pin. Access granted!" <<endl;
            break;
        }
        else
        {
            cout<<"Incorrrect pin."<<endl;
            cout<<"Please try again."<<endl;

        }
        }
    balance += amount;
    cout<<"Total amount in your account: " <<balance<<endl;
}

//Function to display account details
void Bank::display_account()
{
       cout<<"Please enter correct username: "<<endl;
       cin>>username;
    if (name == username)
    {
        cout<<"Access granted."<<endl;

    }
    else
    {
        cout<<"Invalid username"<<endl;
        cout<<"Try again: ";
        cin>>username;
    }


    cout<<"Your username: "<<username<<endl;
    cout<<"Type of account: "<<(accountType == 's' ? "Saving" : "Current")<<endl;
    cout<<"Amount in account: "<<balance<<endl;
}

//Function to withdraw money
void Bank::withdraw_money()
{
    int amount;
    cout<<"Enter withdrawal amount: ";
    cin>>amount;
    while (true)
        {
            cout<<"Enter your pin: ";
            cin>>userpin;
        if (userpin == correctpin)
        {
            cout<<"Correct pin. Access granted!" <<endl;
            break;
        }
        else
        {
            cout<<"Incorrrect pin. Please try again. "<<endl;

        }
        }

    if (amount>balance)
    {
        cout<<"Insufficient balance.\n";
    }
    else
    {
        balance -= amount;
        cout<<"Remaining balance: "<<balance<<endl;
    }
}

int main()
{
    Bank obj;
    int choice;
    char nextOption;

    cout<<"WELCOME TO BOMBACLATT BANK! PLEASE SELECT AN OPTION: "<<endl;

    do
    {
    cout<<"1) Open account\n";
    cout<<"2) Deposit money\n";
    cout<<"3) Withdraw money\n";
    cout<<"4) Dispay account\n";
    cout<<"5) Exit\n";
    cout<<"Select an option: ";
    cin>>choice;

    switch (choice)
    {
        case 1: obj.open_account();
        break;
        case 2: obj.deposit_money();
        break;
        case 3: obj.withdraw_money();
        break;
        case 4: obj.display_account();
        break;
        case 5: exit(0);
        default:
            cout<<"Invalid option. Try again.\n";
    }

    cout<<"\nDo you want to select another option? Press 'Y' to continue or 'N' to exit: "<<endl;
    nextOption = getch();
    //waits for user input without Enter key
    }
    while (nextOption == 'y' || nextOption == 'y');
    return 0;

}
