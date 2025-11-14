#include <iostream>
#include <string>
using namespace std;

const int MAX_EMPLOYEES = 100;


string employeeNames[MAX_EMPLOYEES];
double payRates[MAX_EMPLOYEES];
double hoursWorked[MAX_EMPLOYEES];
double salaries[MAX_EMPLOYEES];
int numEmployees = 0;

void calculateSalary()
{
    salaries[numEmployees] = payRates[numEmployees] * hoursWorked[numEmployees];
}

void addEmployee()
{
    int numToAdd;
    cout << "How many employees do you want to add? ";
    cin >> numToAdd;
    cout<<endl;

    if (numEmployees + numToAdd > MAX_EMPLOYEES)
    {
        cout << "Cannot add that many employees. Maximum limit reached." << endl;
        return;
    }

    cin.ignore();

    for (int i = 0; i < numToAdd; i++)
    {
        string name;
        double payRate;
        double hours;

        cout << "Enter the employee's name: ";
        getline(cin, name);
        cout << "Enter the pay rate: ";
        cin >> payRate;
        cout << "Enter the hours worked: ";
        cin >> hours;
        cout<<endl;

        employeeNames[numEmployees] = name;
        payRates[numEmployees] = payRate;
        hoursWorked[numEmployees] = hours;
        calculateSalary();
        numEmployees++;

        cin.ignore();
    }

    cout << "Employees added successfully!" << endl;
}

void viewPayroll()
{
    if (numEmployees == 0)
    {
        cout << "No employees in the payroll system.\n" << endl;
        return;
    }

    cout << "Payroll Information:" << endl;
    cout<<endl;
    for (int i = 0; i < numEmployees; i++)
    {
        cout << "Name: " << employeeNames[i]<<endl;
        cout << "Pay Rate: $" << payRates[i]<<endl;
        cout << "Hours Worked: " << hoursWorked[i]<<endl;
        cout << "Salary: $" << salaries[i] << endl;
        cout<<endl;
    }
}

int main()
{
    cout << "    Welcome to  Payroll " << endl;
    cout << "    How can i help you  " << endl;
    cout << "    Please enter your choice\n" << endl;
    int choice;

    do
    {

        cout << "Payroll System Menu:" << endl;
        cout << "--------------------" << endl;
        cout << "1. Add Employee(s)" << endl;
        cout << "2. View Payroll" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addEmployee();
                break;
            case 2:
                viewPayroll();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
