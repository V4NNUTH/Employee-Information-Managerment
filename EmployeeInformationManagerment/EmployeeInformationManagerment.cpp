#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <limits>
using namespace std;
int ID, choice;
char Con;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
const auto MaxIgnore =  numeric_limits<streamsize>::max();
void Welcome()
{
    again:
    system("cls");
    SetConsoleTextAttribute(h,10);
    cout << setw(20) << "" << "=====================================================================" << endl << endl;
    SetConsoleTextAttribute(h,15);
    cout << setw(20) << "" << "            ==>> Welcome to Employees Management System <<==         " << endl << endl;
    SetConsoleTextAttribute(h,10);
    cout << setw(20) << "" << "=====================================================================" << endl << endl;
    int n, x, y;
        string Username = "Manager" , Password = "12345", user, pass;
        SetConsoleTextAttribute(h,15);
        cout << setw(20) << "" << "                     ==>> Pleas login to System <<==                " << endl ;
        SetConsoleTextAttribute(h,10);
        do
        {
            cout << endl;
            cout << setw(20) << "" << "Please input Username: ";
            cin >> user;
            cout << setw(20) << "" << "Please input Password: ";
            cin >> pass;
            x = Username.compare(user);
            y = Password.compare(pass);
            if(x == 0 && y == 0)
            {
                break;
            }
            else
            {
                n++;
                goto again;
            }
        }while(n<=3);
}
void Department()
{
    system("cls");
    cout << endl << endl;
    SetConsoleTextAttribute(h,10);
    cout << setw(20) << "" << "=====================================================================" << endl;
    SetConsoleTextAttribute(h,15);
    cout << setw(20) << "" << "                     => Welcome to HOMESCREEN <=                     " << endl;
    SetConsoleTextAttribute(h,10);
    cout << setw(20) << "" << "=====================================================================" << endl;
    cout << setw(20) << "" << "                       1. Add Employee Data" << endl;
    cout << setw(20) << "" << "                       2. Show Employee Data" << endl;
    cout << setw(20) << "" << "                       3. Search Employee Data" << endl;
    cout << setw(20) << "" << "                       4. Delete Employee Data" << endl;
    cout << setw(20) << "" << "                       5. Update Employee Data" << endl;
    SetConsoleTextAttribute(h,12);
    cout << setw(20) << "" << "                       6. Exit " << endl;
    SetConsoleTextAttribute(h,10);
    cout << setw(20) << "" << "=====================================================================" << endl;
    cout << setw(20) << "" << "Pleas enter your choice: ";
    cin >> choice;
    fflush(stdin);
}

struct Emp
{
    int id;
    string name;
    string des;
    string exp;
    int age;
    int salary;
    long int phone;
};

void addData()
{
    Emp e;
    cout << setw(20) << "" << "=====================================================================" << endl;
    SetConsoleTextAttribute(h,15);
    cout << setw(20) << "" << "                 => Welcome to Add Employee Data <=                  " << endl;
    SetConsoleTextAttribute(h,10);
    cout << setw(20) << "" << "=====================================================================" << endl;
    cout << setw(20) << "" << "Please enter employee's name: ";
    //cin.get();
    getline(cin, e.name);
    cout << setw(20) << "" << "Please enter employee's designation: ";
    cin >> e.des;
    //getline(cin, e.des);
    cout << setw(20) << "" << "Please enter employee's experience: ";
    cin >> e.exp;
    //getline(cin, e.exp);
    bool done1 = false;
    while(!done1)
    {
        int n = 1, a = 1;
        addAge:
        if((n <= 1) && (a <= 1))
        {
            SetConsoleTextAttribute(h,10);
            cout << setw(20) << "" << "Please enter employee's age: ";
            if(cin >> e.age)
            {
                int b = e.id;
                if((b >= 18) && (b <= 80))
                {
                    done1 = true;
                }
                else
                {
                    cin.clear();
                    cin.ignore(MaxIgnore, '\n');
                    n++;
                    a++;
                    goto addAge;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(MaxIgnore, '\n');
                n++;
                goto addAge;
            }
        }
        else if((n >= 2) && (a <= 1))
        {
            cout << setw(20) << "" << "Please enter employee's age ";
            SetConsoleTextAttribute(h,12);
            cout << "(Only Integer): ";
            SetConsoleTextAttribute(h,10);
            if(cin >> e.age)
            {
                int b = e.id;
                if((b >= 18) && (b <= 80))
                {
                    done1 = true;
                }
                else
                {
                    cin.clear();
                    cin.ignore(MaxIgnore, '\n');
                    n++;
                    a++;
                    goto addAge;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(MaxIgnore, '\n');
                n++;
                goto addAge;
            }
        }

        else if((n >= 2) && (a >=2))
        {
            cout << setw(20) << "" << "Please enter employee's age ";
            SetConsoleTextAttribute(h,12);
            cout << "(Between 18 -> 80): ";
            SetConsoleTextAttribute(h,10);
            if(cin >> e.age)
            {
                if(e.age >= 18 && e.age <= 80)
                {
                    done1 = true;
                }
                else
                {
                    cin.clear();
                    cin.ignore(MaxIgnore, '\n');
                    n++;
                    a++;
                    goto addAge;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(MaxIgnore, '\n');
                n++;
                a =1;
                goto addAge;
            }
        }


    }

    bool done2 = false;
    while(!done2)
    {
        int n = 1;
        addSalary:
        if(n == 1)
        {
            SetConsoleTextAttribute(h,10);
            cout << setw(20) << "" << "Please enter employee's salary: ";
            if(cin >> e.salary)
            {
                done2 = true;
            }
            else
            {
                cin.clear();
                cin.ignore(MaxIgnore, '\n');
                n++;
                goto addSalary;
            }
        }
        else
        {
            cout << setw(20) << "" << "Please enter employee's salary ";
            SetConsoleTextAttribute(h,12);
            cout << "(Only Integer): ";
            SetConsoleTextAttribute(h,10);
            if(cin >> e.salary)
            {
                done2 = true;
            }
            else
            {
                cin.clear();
                cin.ignore(MaxIgnore, '\n');
                n++;
                goto addSalary;
            }
        }
    }

    bool done3 = false;
    while(!done3)
    {
        int n = 1;
        addPhone:
        if(n == 1)
        {
            SetConsoleTextAttribute(h,10);
            cout << setw(20) << "" << "Please enter employee's phone: ";
            if(cin >> e.phone)
            {
                done3 = true;
            }
            else
            {
                cin.clear();
                cin.ignore(MaxIgnore, '\n');
                n++;
                goto addPhone;
            }
        }
        else
        {
            cout << setw(20) << "" << "Please enter employee's phone ";
            SetConsoleTextAttribute(h,12);
            cout << "(Only Integer): ";
            SetConsoleTextAttribute(h,10);
            if(cin >> e.phone)
            {
                done3 = true;
            }
            else
            {
                cin.clear();
                cin.ignore(MaxIgnore, '\n');
                n++;
                goto addPhone;
            }
        }
    }
    fstream read;
    read.open("id.txt");
    if(read)
    {
        while (!read.eof())
        {
            read >> ID;
        }
        ID++;
    }
    else if(!read)
    {
        ID++;
    }





















    ofstream write;
    write.open("emp.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << e.name ;
    write << "\n" << e.des ;
    write << "\n" << e.exp ;
    write << "\n" << e.age;
    write << "\n" << e.salary;
    write << "\n" << e.phone;
    write.close();

    write.open("id.txt");
    write << "\n" << ID;
    write.close();
    cout << endl;
    cout << setw(20) << "" << "Data Saved Successful!!!" << endl;
}

void print(Emp s)
{
    cout << setw(20) << "|" << setw(20) << s.id << "|";
    cout << setw(20) << s.name << "|";
    cout << setw(20) << s.des << "|";
    cout << setw(20) << s.exp << "|";
    cout << setw(20) << s.age << "|";
    cout << setw(20) << s.salary << "|";
    cout << setw(20) << s.phone << "|" << endl;
}

void readData()
{
    Emp e;
    cout << setw(20) << "" << "==================================================================================================================================================" << endl;
    SetConsoleTextAttribute(h,15);
    cout << setw(20) << "" << "                                                      => Welcome to Show Employee Data <=                                                         " << endl;
    SetConsoleTextAttribute(h,10);
    cout << setw(20) << "" << "==================================================================================================================================================" << endl;
    cout << setw(20) << "|" <<setw(21)<<"ID|"<<setw(21)<<"Name|"<<setw(21)<<"Designation|"<<setw(21)<<"Experience|"<<setw(21)<<"Age|"<<setw(21)<<"Salary|"<<setw(21)<<"Phone|"<< endl;
    cout << setw(20) << "" << "==================================================================================================================================================" << endl;
    ifstream read;
    read.open("emp.txt");
    if(read)
    {
        while (!read.eof())
        {
            read >> e.id;
            read.ignore();
            getline(read, e.name);
            read >> e.des;
            read >> e.exp;
            read >> e.age;
            read >> e.salary;
            read >> e.phone;
            print(e);
        }
    }
    else
    {
        SetConsoleTextAttribute(h,12);
        cout << setw(20) << "" << "Empty record!!!\n";
        SetConsoleTextAttribute(h,10);
    }
    read.close();
    cout << setw(20) << "" << "==================================================================================================================================================" << endl;

}

int searchData()
{
    int id;
    Emp e;
    ifstream read;
    read.open("emp.txt");
    cout << endl;
    cout << setw(20) << "" << "==================================================================================================================================================" << endl;
    cout << setw(20) << "|" <<setw(21)<<"ID|"<<setw(21)<<"Name|"<<setw(21)<<"Designation|"<<setw(21)<<"Experience|"<<setw(21)<<"Age|"<<setw(21)<<"Salary|"<<setw(21)<<"Phone|"<< endl;
    cout << setw(20) << "" << "==================================================================================================================================================" << endl;
    if(read)
    {
        while (!read.eof())
        {
            read >> e.id;
            read.ignore();
            getline(read, e.name);
            read >> e.des;
            read >> e.exp;
            read >> e.age;
            read >> e.salary;
            read >> e.phone;
            if (e.id == id)
            {
                print(e);
                return id;
            }
        }
    }


    else if(!read)
    {
        SetConsoleTextAttribute(h,12);
        cout << setw(20) << "" << "Empty record!!!\n";
        SetConsoleTextAttribute(h,10);
    }
    if(e.id != id)
    {
        SetConsoleTextAttribute(h,12);
        cout << setw(20) << "" << "Empty record!!!\n";
        SetConsoleTextAttribute(h,10);
    }
    read.close();
}

void deleteData()
{
    int id;
    cout << setw(20) << "" << "==================================================================================================================================================" << endl;
    SetConsoleTextAttribute(h,15);
    cout << setw(20) << "" << "                                                        => Welcome to Delete Employee Data <=                                                     " << endl;
    SetConsoleTextAttribute(h,10);
    cout << setw(20) << "" << "==================================================================================================================================================" << endl;
    cout << setw(20) << "" << "Enter student id want to delete: ";
    cin >> id;
    id = searchData();
    cout << setw(20) << "You want to delete record (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
        {
        Emp e;
        ofstream tempFile;
        tempFile.open("temp.txt");
        if(tempFile)
        {
            ifstream read;
            read.open("emp.txt");
            if(read)
            {
                while (!read.eof())
                {
                read >> e.id;
                read.ignore();
                getline(read, e.name);
                read >> e.des;
                read >> e.exp;
                read >> e.age;
                read >> e.salary;
                read >> e.phone;
                    if (e.id != id)
                    {
                        tempFile << "\n" << e.id;
                        tempFile << "\n" << e.name;
                        tempFile << "\n" << e.des;
                        tempFile << "\n" << e.exp;
                        tempFile << "\n" << e.age;
                        tempFile << "\n" << e.salary;
                        tempFile << "\n" << e.phone;
                    }
                }
                read.close();
                tempFile.close();
            }
            else
            {
                cout << endl;
                cout << setw(20) << "" << "Data Delete Successfully!!!!" << endl;
                read.close();
                tempFile.close();
            }

        }
        else
        {
            cout << endl;
            cout << setw(20) << "" << "Data Delete Successfully!!!!" << endl;
            tempFile.close();
        }
        remove("emp.txt");
        rename("temp.txt", "emp.txt");
        cout << endl;
        cout << setw(20) << "" << "Data Delete Successfully!!!!" << endl;
}
    else
    {
        cout << endl;
        SetConsoleTextAttribute(h,12);
        cout << setw(20) << "" << "Record not delete!!!!" << endl;
        SetConsoleTextAttribute(h,10);
    }
}

void updateData()
{
    int id;
    cout << setw(20) << "" << "==================================================================================================================================================" << endl;
    SetConsoleTextAttribute(h,15);
    cout << setw(20) << "" << "                                                      => Welcome to Modify Employee Data <=                                                       " << endl;
    SetConsoleTextAttribute(h,10);
    cout << setw(20) << "" << "==================================================================================================================================================" << endl;
    cout << setw(20) << "" << "Enter student id want to search: ";
    cin >> id;
    id = searchData();
    cout << setw(20) << "" << "You want to update record (y/n): ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        Emp New;
        cout << setw(20) << "" << "Please enter employee's name: ";
        cin.get();
        getline(cin, New.name);
        cout << setw(20) << "" << "Please enter employee's designation: ";
        cin >> New.des;
        cout << setw(20) << "" << "Please enter employee's experience: ";
        cin >> New.exp;
        bool done4 = false;
        while(!done4)
        {
            int n = 1;
            addAge:
            if(n == 1)
            {
                SetConsoleTextAttribute(h,10);
                cout << setw(20) << "" << "Please enter employee's age: ";
                if(cin >> New.age)
                {
                    done4 = true;
                }
                else
                {
                    cin.clear();
                    cin.ignore(MaxIgnore, '\n');
                    n++;
                    goto addAge;
                }
            }
            else
            {
                cout << setw(20) << "" << "Please enter employee's age ";
                SetConsoleTextAttribute(h,12);
                cout << "(Only Integer): ";
                SetConsoleTextAttribute(h,10);
                if(cin >> New.age)
                {
                    done4 = true;
                }
                else
                {
                    cin.clear();
                    cin.ignore(MaxIgnore, '\n');
                    n++;
                    goto addAge;
                }
            }
        }

        bool done5 = false;
        while(!done5)
        {
            int n = 1;
            addSalary:
            if(n == 1)
            {
                SetConsoleTextAttribute(h,10);
                cout << setw(20) << "" << "Please enter employee's salary: ";
                if(cin >> New.salary)
                {
                    done5 = true;
                }
                else
                {
                    cin.clear();
                    cin.ignore(MaxIgnore, '\n');
                    n++;
                    goto addSalary;
                }
            }
            else
            {
                cout << setw(20) << "" << "Please enter employee's salary ";
                SetConsoleTextAttribute(h,12);
                cout << "(Only Integer): ";
                SetConsoleTextAttribute(h,10);
                if(cin >> New.salary)
                {
                    done5 = true;
                }
                else
                {
                    cin.clear();
                    cin.ignore(MaxIgnore, '\n');
                    n++;
                    goto addSalary;
                }
            }
        }

        bool done6 = false;
        while(!done6)
        {
            int n = 1;
            addPhone:
            if(n == 1)
            {
                SetConsoleTextAttribute(h,10);
                cout << setw(20) << "" << "Please enter employee's phone: ";
                if(cin >> New.phone)
                {
                    done6 = true;
                }
                else
                {
                    cin.clear();
                    cin.ignore(MaxIgnore, '\n');
                    n++;
                    goto addPhone;
                }
            }
            else
            {
                cout << setw(20) << "" << "Please enter employee's phone ";
                SetConsoleTextAttribute(h,12);
                cout << "(Only Integer): ";
                SetConsoleTextAttribute(h,10);
                if(cin >> New.phone)
                {
                    done6 = true;
                }
                else
                {
                    cin.clear();
                    cin.ignore(MaxIgnore, '\n');
                    n++;
                    goto addPhone;
                }
            }
        }

        Emp e;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("emp.txt");
        while (!read.eof())
        {
            read >> e.id;
            read.ignore();
            getline(read, e.name);
            read >> e.des;
            read >> e.exp;
            read >> e.age;
            read >> e.salary;
            read >> e.phone;
            if (e.id != id)
            {
                tempFile << "\n" << e.id;
                tempFile << "\n" << e.name;
                tempFile << "\n" << e.des;
                tempFile << "\n" << e.exp;
                tempFile << "\n" << e.age;
                tempFile << "\n" << e.salary;
                tempFile << "\n" << e.phone;
            }
            else
            {
                tempFile << "\n" << e.id;
                tempFile << "\n" << New.name;
                tempFile << "\n" << New.des;
                tempFile << "\n" << New.exp;
                tempFile << "\n" << New.age;
                tempFile << "\n" << New.salary;
                tempFile << "\n" << New.phone;
            }
        }
        read.close();
        tempFile.close();
        remove("emp.txt");
        rename("temp.txt", "emp.txt");
        cout << endl;
        cout << setw(20) << "" << "Data Update Successfully!...";
    }
    else
    {
        cout << endl;
        SetConsoleTextAttribute(h,12);
        cout << setw(20) << "" << "Record Not Update!...";
        SetConsoleTextAttribute(h,10);
    }
}
int main()
{
Welcome();
department:
    Department();
    switch(choice)
    {
    case 1:// ADD ITEM
        do
        {
            system("cls");
            addData();
            cout << setw(20) << "" << "Do you want to add an other record?(y/n): ";
            cin >> Con;
            if(Con == 'n')
            {
                goto department;
            }
        }while(Con == 'y');


        break;
    case 2:// SHOW ITEM
        do
        {
            system("cls");
            readData();
            cout << setw(20) << "" << "Do you want main menu?(y/n): ";
            cin >> Con;
            if(Con == 'y')
            {
                goto department;
            }
        }while(Con == 'n');

        break;
    case 3:// SEARCH ITEM
        int id;
        do
        {
            system("cls");
            cout << setw(20) << "" << "==================================================================================================================================================" << endl;
            SetConsoleTextAttribute(h,15);
            cout << setw(20) << "" << "                                                      => Welcome to Search Employee Data <=                                                       " << endl;
            SetConsoleTextAttribute(h,10);
            cout << setw(20) << "" << "==================================================================================================================================================" << endl;
            cout << setw(20) << "" << "Enter student id want to search: ";
            cin >> id;

            searchData();
            cout << setw(20) << "" << "==================================================================================================================================================" << endl;
            cout << setw(20) << "" << "Do you want to search an other record?(y/n): ";
            cin >> Con;
            if(Con == 'n')
            {
                goto department;
            }
        }while(Con == 'y');

        break;
    case 4:// DELETE ITEM
        do
        {
            system("cls");
            deleteData();
            cout << endl;
            cout << setw(20) << "" << "Do you want to delete an other record?(y/n): ";
            cin >> Con;
            if(Con == 'n')
            {
                goto department;
            }
        }while(Con == 'y');
    case 5:// UPDATE ITEM
        do
        {
            system("cls");
            updateData();
            cout << setw(20) << "" << "Do you want to update an other record?(y/n): ";
            cin >> Con;
            if(Con == 'n')
            {
                goto department;
            }
        }while(Con == 'y');
    case 6:
        system("cls");
        cout << endl;
        cout << setw(20) << "" << "Thanks you for working on our program!!!!!" << endl;
        exit(0);

    default:
        system("cls");
        SetConsoleTextAttribute(h,12);
        cout << setw(20) << "" << "Your choice is wrong!!!" << endl;
        cout << setw(20) << "" << "Login again please!!!" << endl;
        SetConsoleTextAttribute(h,10);
    }


    return 0;
}
