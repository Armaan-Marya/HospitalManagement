#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

using namespace std;
//////////////////////////////////////////Classes////////////////////////////////////////
class Patient{
protected:
    char name[20];
    string number;
    int age;
    string bg;
public:
    void getdata();
    void showdata();
};
void Patient :: getdata(){
    cout<<"Enter name of patient :"<<endl;
    cin>>name;
    cout<<"Enter Phone number of patient :"<<endl;
    cin>>number;
    cout<<"Age of Patient: "<<endl;
    cin>>age;
    cout<<"Blood Group of Patient: "<<endl;
    cin>>bg;
    ofstream file("patients.txt", ios::app);
    file<<name<<" " <<number<<" "<<age<<" "<<bg<<" ";
    file.close();

    system("cls");
}

void Patient :: showdata(){
    system("cls");
    cout<<"The List of Patients are :- "<<endl;
    ifstream file("patients.txt");
    while(file >> name >> number >> age >> bg)
        cout << "Name: " << name << ", Phone Number: " << number << ", Age: "<<age<<", Blood Group: "<<bg<<endl;
    file.close();
}

class Appointment{
protected:
    char name[20];
    string time;
    int ch;
public:
    void bookdoctor();
    void cardiovascularappointment();
    void entappointment();
    void generalappointment();
    void showappointment();
};
//////////////////////////////////////////////////////////////////////////////////////////
class ShowApp : public Appointment{

public:
    void appointmentmenu();
    void cvshowapp();
    void entshowapp();
    void generalshowapp();
};
void ShowApp :: appointmentmenu(){
    ShowApp show;
    do {
        cout<<"Which Specialist's Appointment do u want to see:"<<endl;
        cout<<"1- Cardiologist"<<endl;
        cout<<"2- ENT (ear nose throat)"<<endl;
        cout<<"3- General "<<endl;
        cout<<"4- Go back"<<endl;
        cout<<"Enter Choice: "<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                show.cvshowapp();
                break;
            case 2:
                show.entshowapp();
                break;
            case 3:
                show.generalshowapp();
                break;
            case 4:
                cout<<"going back";
            default:
                cout<<"enter correct input"<<endl;
                break;
        }
    }while(ch!=4);
    system("cls");
}
//////////////////////////////////Functions///////////////////////////////////////////////
void Appointment :: bookdoctor(){
    Appointment app;
    do {
        cout<<"Which Specialist do u need"<<endl;
        cout<<"1- Cardiologist"<<endl;
        cout<<"2- ENT (ear nose throat)"<<endl;
        cout<<"3- General "<<endl;
        cout<<"4- Go back"<<endl;
        cout<<"Enter Choice: "<<endl;
        cin>>ch;
        switch(ch){
            case 1:
                app.cardiovascularappointment();
                break;
            case 2:
                app.entappointment();
                break;
            case 3:
                app.generalappointment();
                break;
            case 4:
                cout<<"going back";
            default:
                cout<<"enter correct input"<<endl;
                break;
        }
    }while(ch!=4);
    system("cls");
    //goto jump;

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Appointment :: cardiovascularappointment(){
    cout <<"Enter name of Patient"<<endl;
    cin>>name;

    cout<<"Enter time of Appointment (9AM - 5PM)"<<endl;
    cin>>time;
    int TA = stoi(time); //----------------------Explicit TypeCasting-----------------------------------//
    if(TA<5&& TA>12){
        cout<<"Pls ENter a Valid Time: "<<endl;
        cin>>time;
        TA = stoi(time);
    }
    static int arr[10] = {0};
    for(int i=0;i<10;i++){
        if (TA == arr[i]){
            cout<<"Time Slot Taken pls change"<<endl;
            break;
        }
        else if (arr[i]==0){
            arr[i]= TA;
            cout<<"Appointment Booked "<<endl;
            break;
        }
    }

    ofstream file("cardiovascular_appointments.txt", ios::app);
    file<<name<<" "<<time<<" ";
    file.close();

}
void ShowApp :: cvshowapp(){
    system("cls");
    cout<<"The List of Appointments are :- "<<endl;
    ifstream file("cardiovascular_appointments.txt");
    while(file >> name >> time)
        cout << "Name: " << name << ", Time: " << time << endl;
    file.close();
}

void Appointment :: entappointment(){
    cout <<"Enter name of Patient"<<endl;
    cin>>name;

    cout<<"Enter time of Appointment (9AM - 5PM)"<<endl;
    cin>>time;
    int TA = stoi(time);                                             //----------------------Explicit TypeCasting-----------------------------------//
    if(TA<5&& TA>12){
        cout<<"Pls ENter a Valid Time: "<<endl;
        cin>>time;
        TA = stoi(time);
    }
    static int arr[10] = {0};
    for(int i=0;i<10;i++){
        if (TA == arr[i]){
            cout<<"Time Slot Taken pls change"<<endl;
            break;
        }
        else if (arr[i]==0){
            arr[i]= TA;
            cout<<"Appointment Booked "<<endl;
            break;
        }
    }

    ofstream file("ent_appointments.txt", ios::app);
    file<<name<<" "<<time<<" ";
    file.close();

}
void ShowApp :: entshowapp(){
    system("cls");
    cout<<"The List of Appointments are :- "<<endl;
    ifstream file("ent_appointments.txt");
    while(file >> name >> time)
        cout << "Name: " << name << ", Time: " << time << endl;
    file.close();
}

void Appointment :: generalappointment(){
    cout <<"Enter name of Patient"<<endl;
    cin>>name;

    cout<<"Enter time of Appointment (9AM - 5PM)"<<endl;    //9 10 11 12 1 2 3 4
    cin>>time;
    int TA = stoi(time);                                             //----------------------Explicit TypeCasting-----------------------------------//
    if(TA<5&& TA>12){
        cout<<"Pls ENter a Valid Time: "<<endl;
        cin>>time;
        TA = stoi(time);
    }
    static int arr[10] = {0};
    for(int i=0;i<10;i++){
        if (TA == arr[i]){
            cout<<"Time Slot Taken pls change"<<endl;
            break;
        }
        else if (arr[i]==0){
            arr[i]= TA;
            cout<<"Appointment Booked "<<endl;
            break;
        }
    }

    ofstream file("general_appointments.txt", ios::app);
    file<<name<<" "<<time<<" ";
    file.close();

}
void ShowApp :: generalshowapp(){
    system("cls");
    cout<<"The List of Appointments are :- "<<endl;
    ifstream file("general_appointments.txt");
    while(file >> name >> time)
        cout << "Name: " << name << ", Time: " << time << endl;
    file.close();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Appointment :: showappointment(){
    system("cls");
    cout<<"The Appointments are =>"<<endl;
    ifstream file("appointments.txt");

    while(file >> name >> time)
        cout << "Name: " << name << ", Time: " << time << endl;
    file.close();
}

//-------------------------------------------------------------------------
int main(){
    int choice;
    Patient obj;
    Appointment app;

//jump:
    do{
        cout<<"|==============================|"<<endl;
        cout<<"|The Hospital Management System|"<<endl;
        cout<<"|==============================|"<<endl;
        cout<<"1- Register Patient"<<endl;
        cout<<"2- Display Patients"<<endl;
        cout<<"3- Take Appointments"<<endl;
        cout<<"4- Show Appointments"<<endl;
        cout<<"5- EXIT"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                obj.getdata();
                break;
            case 2:
                obj.showdata();
                break;
            case 3:
                app.bookdoctor();
                break;
            case 4:
                app.showappointment();
                break;
            case 5:
                cout<<"EXITTING PROGRAM";
                break;
            default:
                cout<<"enter correct input"<<endl;
                break;
        }
    }while(choice !=5);
    system("cls");
    cout<<"==============================";
    cout<<"\n End of Main"<<endl;
    cout<<"==============================";
    return 0;
}
