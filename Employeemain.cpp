#include<iostream>
#include<iomanip>
#include<stdexcept>
#include<bitset>
#include<string>
#include <iostream>
#include <fstream>
using namespace std;

class Employee {
private:
    string name;
    int id;
    float salary;
    int experience;
    static float total; // static variable for total salary
public:
    // Default constructor
    Employee(string name = "", int id = 0, float salary = 0, int experience = 0) {
        this->name = name;
        this->id = id;
        this->salary = salary;
        this->experience = experience;
        this->showTotal();
    // File Handling
        ofstream file("employee.txt", ios::app);
    file<<name<<" " <<id<<" "<<salary<<" "<<experience<<" ";
    file.close();
    }

    // Parameterized constructor
    Employee(int experience, float salary) {
        this->experience = experience;
        this->salary = salary;
    }

    // Copy constructor
    Employee(const Employee& emp) {
        this->salary = emp.salary;
        this->experience = emp.experience;
    }

    // Member function to get employee details
    void get() {
        cout << "Enter your name, id, salary, and experience: ";
        cin >> name >> id >> salary >> experience;
    }

    // Member function to display employee details
    void show() {
        cout << "Your details are:" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
        cout << "Experience: " << experience << endl;
    }

    // Member function to calculate amount
    float amount(int x = 10000) {
        cout<<"joining perks 10000 provided :)";
        return (salary * experience)+x;
    }

    // Static member function to show total salary
    static void showTotal() {
        float securityCharges = 5000;
        total = total - securityCharges;
        cout << "Total insurance (after deducting security charges from insurance): " << total << endl;
    }

    // Friend function to calculate average salary
    friend float calAvgSalary(Employee E1, Employee E2, Employee E3) {
        return (E1.salary + E2.salary + E3.salary) / 3;
    }

    // Inline function to calculate bonus
    inline float calculateBonus(float percentage) {
        return salary * (percentage / 100);
    }

    // Function overloading to calculate bonus
    float calculateBonus(int years) {
        if (years >= 5) {
            return salary * 0.1;
        } else {
            return salary * 0.05;
        }
    }

    // Typecasting operator
    operator float() {
        return salary;
    }

    // Destructor
    ~Employee() {
        cout << "Bye" << endl;
    }
};

float Employee::total = 40000;
//inheritance
class Details : public Employee {
 protected : int workhr, workdays;
 public: void getinput()
 {
 Employee :: get();
 cout<<" enter working hours per day and working days";
 cin>>workhr>>workdays;
 } 
 void totalwork() {
 int z;
 z=workhr*workdays;
 }
    virtual void Check()      //virtual function
    {
        cout<< "VIRTUAL NOT WORKING";
    }
};
 
 class previous : public Details {
     private : string comp;
     public : void hello(){
         Details :: getinput();
     cout<<"enter your previous company name,,,if freshiee,type none :  ";
     cin>>comp;
     Employee::show();
     int z;
     z=workhr*workdays;
     cout<<"working time : " << z <<endl;
     cout<<"Company name : "<<comp<<endl;
     }
     void saee()
     {
         cout<<"VIRTUAL WORKING";
     }
 };
class Complex {
public:
    Complex(double tax, double gst) : tax(tax), gst(gst) {}

    Complex operator+(const Complex& other) const {
        return Complex(tax + other.tax,gst + other.gst);
    }

    void display() const {
        std::cout << tax << " + " << gst << std::endl;
    }

private:
    double tax;
    double gst;
};

struct Employer {
    string name1;
    int age1;
    string position;
};

//template
template <typename T> T myincrement(T x, T y)
{
    return (x + y);
}
int main() {
    const int SIZE = 3;
    previous *arr[SIZE];
//array of objects
    for (int i = 0; i < SIZE; i++) {
        arr[i]=new previous();
        arr[i]->hello();
        arr[i]->totalwork();
        cout << "Amount: " << arr[i]->amount() << endl;
        cout << "Bonus (using percentage): " << arr[i]->calculateBonus(15) << endl;
        cout << "Bonus (using years): " << arr[i]->calculateBonus(3) << endl;
    }

    Employee::showTotal();

    float avg = calAvgSalary(*arr[0], *arr[1], *arr[2]);
    cout << "Average Salary: " << avg << endl;

    float totalSalary = 0;
    for (int i = 0; i < SIZE; i++) {
        totalSalary += static_cast<float>(*arr[i]);
        delete arr[i];
    }
    cout << "Total Salary (using typecasting): " << totalSalary << endl;
    Complex c1(5.0, 4.0);
    Complex c2(13.9, 7.5);

    Complex sum = c1 + c2;

    cout << "total tax percentage to be submitted(income tax + gst) = ";
    sum.display();
    
    
    cout << "Set fill: " << std::setfill('*') << std::setw(30) << "THIS CODE IS MINE" << std::endl;
    cout<<endl;
    cout<<endl;
    
    cout<<endl;
    cout<<endl;
    Details * virtlptr;
    Details baseobj;
    previous derobj;
    virtlptr = &derobj;
    virtlptr->Check();
    cout<<endl;
    cout<<endl;
  
    // Call myincrement for int
    cout<<"increment by percent every year in sal:";
    cout << myincrement<int>(3, 11) << endl;
    // call myincrement for double
    cout << myincrement<double>(3.0, 7.0) << endl;
    // call myincrement for char
    cout << myincrement<char>('a', 'm') << endl;
    
    // exception handling 
    int x=-1;
    cout<<"details if you are a new employee here:"<<endl;
    cout<<"error in details";
    cout << "Before try \n";
   try {
      cout << "Inside try \n";
      if (x < 0)
      {
         throw x;
         cout << "After throw (Never executed) \n";
      }
   }
   catch (int x ) {
      cout << "Exception Caught \n";
   }
 
   cout << "After catch (Will be executed) \n";
   
   //invalid argument 
     try {    
      bitset<8> mybitset (string("89657456325"));
   }
   catch (const std::invalid_argument& ia) {
      cerr << "ERROR: " << ia.what() << '\n';
   }
   
   ifstream inputFile("employee.txt");
    
    if (inputFile.is_open()) {

        Employer employer;
        
        // Read the employer information from the file
        while (inputFile >> employer.name1 >> employer.age1 >> employer.position) {
            // Process the employer information
            cout << "Name: " << employer.name1 << endl;
            cout << "Age: " << employer.age1 << endl;
            cout << "Position: " << employer.position << endl;
            cout << endl;
        }
        
        // Close the file
        inputFile.close();
    } else {
        cout << "Unable to open the file." << endl;
        return 1;
    }
    return 0;

}