#include <iostream>
#include<string>
#include<cstring>
#include<stack>

using namespace std;

class Orphans;
class Employees;
class Volunteers;
class Fundings;
class Functions;

class orphanNode
{
public:
    string name;
    int age;
    int admissionNo;
    string description;
    orphanNode *next;
    orphanNode *prev;
};

orphanNode* orphanHead= NULL;
orphanNode* orphanTail= NULL;

class Orphan
{
public:


    string name;
    int age;
    int admissionNo;
    string description;

    Orphan()
    {
        name="Default";
        age=0;
        admissionNo=NULL;
        description="";

        orphanHead=NULL;
        orphanTail=NULL;
    }

    void addOrphan(string name, int age, int admissionNo, string description)
    {
        orphanNode *temp=new orphanNode();
        temp->name=name;
        temp->age=age;
        temp->admissionNo=admissionNo;
        temp->description=description;

        if(orphanHead==NULL )
        {
            orphanHead=orphanTail=temp;
            temp->next=NULL;
            temp->prev=NULL;
        }
        else
        {
            orphanTail->next=temp;
            temp->prev=orphanTail;
            orphanTail=orphanTail->next;

        }
    }

    void addOrphan()
    {
        cout<<"Enter Orphan Details : "<<endl;
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter Age : ";
        cin>>age;
        cout<<"Enter Admission Number : ";
        cin>>admissionNo;
        cout<<"Enter description: ";
        cin>>description;

        orphanNode *temp=new orphanNode();
        temp->name=name;
        temp->age=age;
        temp->admissionNo=admissionNo;
        temp->description=description;

        if(orphanHead==NULL )
        {
            orphanHead=orphanTail=temp;
            temp->next=NULL;
            temp->prev=NULL;
        }
        else
        {
            orphanTail->next=temp;
            temp->prev=orphanTail;
            orphanTail=orphanTail->next;

        }
        cout<<"Welcome to your new home "<<temp->name<<endl;
    }

    void searchOrphan(int add)
    {
        cout<<endl<<endl;

        if(orphanHead==NULL)
        {
            cout<<"ERROR : Records Unavailable";
            return;
        }
        else
        {
            orphanNode *temp=orphanHead;
            while(temp)
            {
                if(temp->admissionNo==add)
                {
                    cout<<"ORPHAN RECORDS FOUND"<<endl;
                    cout<<"Name : "<<temp->name<<endl;
                    cout<<"Age : "<<temp->age<<endl;
                    cout<<"Admission Number : "<<temp->admissionNo<<endl;
                    cout<<"Description: "<<temp->description<<endl;
                    return;
                }
                temp=temp->next;
            }

            if(temp==NULL)
            {
                cout<<"ERROR : Record for Admission Number "<<add<<" does not exist "<<endl;
            }
        }
    }

    int deleteOrphan(int add)
    {
        orphanNode *temp=orphanHead;

        if(orphanHead->admissionNo==add)
        {
            orphanHead=temp->next;
            orphanHead->prev=NULL;
            delete temp;
            cout<<endl<<"Record Deleted "<<endl;

            return 0;
        }

        else if(orphanTail->admissionNo==add)
        {
            temp=orphanTail;
            orphanTail=orphanTail->prev;
            orphanTail->next=NULL;
            delete temp;
            cout<<endl<<"Record Deleted "<<endl;

            return 0;
        }

        else
        {

            while(temp!=orphanTail->next)
            {
                if(temp->admissionNo==add)
                {
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                    delete temp;
                    cout<<"Record Deleted"<<endl;
                    return 0;
                }

                temp=temp->next;
            }

        }
        if(temp==NULL)
            cout<<"Record does not exist"<<endl;

    }


};

class volunteerNode
{
public:
    string name;
    int age;
    int id;
    volunteerNode *next;
    volunteerNode *prev;
};

volunteerNode* volunteerHead=NULL;
volunteerNode* volunteerTail=NULL;

class Volunteer
{
public:


    string name;
    int age;
    int id;

    Volunteer()
    {
        name="Default";
        age=0;
        id=NULL;

        volunteerHead=NULL;
        volunteerTail=NULL;
    }

    void addVolunteer(string name, int age, int id)
    {
        volunteerNode*temp=new volunteerNode();
        temp->name=name;
        temp->age=age;
        temp->id=id;

        if(volunteerHead==NULL )
        {
            volunteerHead=volunteerTail=temp;
            temp->next=NULL;
            temp->prev=NULL;
        }
        else
        {
            volunteerTail->next=temp;
            temp->prev=volunteerTail;
            volunteerTail=volunteerTail->next;

        }
    }

    void addVolunteer()
    {
        cout<<"Enter Volunteer Details : "<<endl;
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter Age : ";
        cin>>age;
        cout<<"Enter Id : ";
        cin>>id;

        volunteerNode *temp=new volunteerNode();
        temp->name=name;
        temp->age=age;
        temp->id=id;

        if(volunteerHead==NULL )
        {
            volunteerHead=volunteerTail=temp;
            temp->next=NULL;
            temp->prev=NULL;
        }
        else
        {
            volunteerTail->next=temp;
            temp->prev=volunteerTail;
            volunteerTail=volunteerTail->next;

        }
        cout<<temp->name<<" Volunteer successfully added!"<<endl;
    }

    void searchVolunteer(int iD)
    {
        cout<<endl<<endl;

        if(volunteerHead==NULL)
        {
            cout<<"ERROR : Records Unavailable";
            return;
        }
        else
        {
            volunteerNode *temp=volunteerHead;
            while(temp)
            {
                if(temp->id==iD)
                {
                    cout<<"VOLUNTEER RECORDS FOUND"<<endl;
                    cout<<"Name : "<<temp->name<<endl;
                    cout<<"Age : "<<temp->age<<endl;
                    cout<<"Id : "<<temp->id<<endl;
                    return;
                }
                temp=temp->next;
            }

            if(temp==NULL)
            {
                cout<<"ERROR : Record for Id "<<iD<<" does not exist "<<endl;
            }
        }
    }
};
class employeeNode
{
public:
    string name;
    int age;
    int id;
    int phoneNo;
    string address;
    int salary;
    employeeNode *next;
    employeeNode *prev;
};

employeeNode* employeeHead=NULL;
employeeNode* employeeTail=NULL;

class Employee
{
public:


    string name;
    int age;
    int id;
    int phoneNo;
    string address;
    int salary;

    Employee()
    {
        name="Default";
        age=0;
        id=NULL;
        phoneNo=NULL;
        address="";
        salary=NULL;

        volunteerHead=NULL;
        volunteerTail=NULL;
    }

    void addEmployee(string name, int age, int id,int phoneNo,string address,int salary)
    {
        employeeNode*temp=new employeeNode();
        temp->name=name;
        temp->age=age;
        temp->id=id;
        temp->phoneNo=phoneNo;
        temp->address=address;
        temp->salary=salary;

        if(employeeHead==NULL )
        {
            employeeHead=employeeTail=temp;
            temp->next=NULL;
            temp->prev=NULL;
        }
        else
        {
            employeeTail->next=temp;
            temp->prev=employeeTail;
            employeeTail=employeeTail->next;

        }
    }

    void addEmployee()
    {
        cout<<"Enter Employee Details : "<<endl;
        cout<<"Enter Name : ";
        cin>>name;
        cout<<"Enter Age : ";
        cin>>age;
        cout<<"Enter Id : ";
        cin>>id;
        cout<<"Enter Phone Number : ";
        cin>>phoneNo;
        cout<<"Enter Address : ";
        cin>>address;
        cout<<"Enter Salary : ";
        cin>>salary;

        employeeNode *temp=new employeeNode();
        temp->name=name;
        temp->age=age;
        temp->id=id;
        temp->phoneNo=phoneNo;
        temp->address=address;
        temp->salary=salary;

        if(employeeHead==NULL )
        {
            employeeHead=employeeTail=temp;
            temp->next=NULL;
            temp->prev=NULL;
        }
        else
        {
            employeeTail->next=temp;
            temp->prev=employeeTail;
            employeeTail=employeeTail->next;

        }
        cout<<temp->name<<" Employee successfully added!"<<endl;
    }

    void searchEmployee(int iD)
    {
        cout<<endl<<endl;

        if(employeeHead==NULL)
        {
            cout<<"ERROR : Records Unavailable";
            return;
        }
        else
        {
            employeeNode *temp=employeeHead;
            while(temp)
            {
                if(temp->id==iD)
                {
                    cout<<"EMPLOYEE RECORDS FOUND"<<endl;
                    cout<<"Name : "<<temp->name<<endl;
                    cout<<"Age : "<<temp->age<<endl;
                    cout<<"Id : "<<temp->id<<endl;
                    cout<<"Phone Number : "<<temp->phoneNo<<endl;
                    cout<<"Address : "<<temp->address<<endl;
                    cout<<"Salary : "<<temp->salary<<endl;
                    return;
                }
                temp=temp->next;
            }

            if(temp==NULL)
            {
                cout<<"ERROR : Record for Id "<<iD<<" does not exist "<<endl;
            }
        }
    }
};
class functionNode
{
public:
    int date;
    string month;
    int year;
    string Functions;
    functionNode *next;
    functionNode *prev;
};

functionNode* functionHead=NULL;
functionNode* functionTail=NULL;

class Function
{
public:


    int date;
    string month;
    int year;
    string Functions;

    Function()
    {
        date=NULL;
        month="";
        year=NULL;
        Functions="";

        functionHead=NULL;
        functionTail=NULL;
    }

    void addFunction(int date, string month, int year,string Functions)
    {
        functionNode*temp=new functionNode();
        temp->date=date;
        temp->month=month;
        temp->year=year;
        temp->Functions=Functions;

        if(functionHead==NULL )
        {
            functionHead=functionTail=temp;
            temp->next=NULL;
            temp->prev=NULL;
        }
        else
        {
            functionTail->next=temp;
            temp->prev=functionTail;
            functionTail=functionTail->next;

        }
    }

    void addFunction()
    {
        cout<<"Enter Function Details : "<<endl;
        cout<<"Enter date(int),month(string,lowercase),year(int) : ";
        cin>>date>>month>>year;
        cout<<"Enter Function : ";
        cin>>Functions;

        functionNode *temp=new functionNode();
        temp->date=date;
        temp->month=month;
        temp->year=year;
        temp->Functions=Functions;

        if(functionHead==NULL )
        {
            functionHead=functionTail=temp;
            temp->next=NULL;
            temp->prev=NULL;
        }
        else
        {
            functionTail->next=temp;
            temp->prev=functionTail;
            functionTail=functionTail->next;

        }
        cout<<temp->Functions<<" Function successfully added!"<<endl;
    }

    void searchFunction(int DATE,string MONTH,int YEAR)
    {
        cout<<endl<<endl;

        if(functionHead==NULL)
        {
            cout<<"ERROR : Records Unavailable";
            return;
        }
        else
        {
            functionNode *temp=functionHead;
            while(temp)
            {
                if(temp->date==DATE && temp->month==MONTH && temp->year==YEAR )
                {
                    cout<<"FUNCTION RECORDS FOUND"<<endl;
                    cout<<"Date : "<<temp->date<<endl;
                    cout<<"Month : "<<temp->month<<endl;
                    cout<<"Year : "<<temp->year<<endl;
                    cout<<"Function : "<<temp->Functions<<endl;
                    return;
                }
                temp=temp->next;
            }

            if(temp==NULL)
            {
                cout<<"ERROR : No function on the entered date!"<<endl;
            }
        }
    }
};
class fundingNode
{
public:
    int transactionId;
    float amount;
    string accountName;
    fundingNode *next;
    fundingNode *prev;
};

fundingNode* fundingHead=NULL;
fundingNode* fundingTail=NULL;

class Funding
{
public:


    int transactionId;
    float amount;
    string accountName;

    Funding()
    {
        transactionId=NULL;
        amount=NULL;
        accountName="";

        fundingHead=NULL;
        fundingTail=NULL;
    }

    void addFunding(int transactionId,float amount,string accountName)
    {
        fundingNode*temp=new fundingNode();
        temp->transactionId=transactionId;
        temp->amount=amount;
        temp->accountName=accountName;

        if(fundingHead==NULL )
        {
            fundingHead=fundingTail=temp;
            temp->next=NULL;
            temp->prev=NULL;
        }
        else
        {
            fundingTail->next=temp;
            temp->prev=fundingTail;
            fundingTail=fundingTail->next;

        }
    }

    void addFunding()
    {
        cout<<"Enter Funding Details : "<<endl;
        cout<<"Enter Transaction Id : ";
        cin>>transactionId;
        cout<<"Enter Amount : ";
        cin>>amount;
        cout<<"Enter Account Name : ";
        cin>>accountName;

        fundingNode *temp=new fundingNode();
        temp->transactionId=transactionId;
        temp->amount=amount;
        temp->accountName=accountName;

        if(fundingHead==NULL )
        {
            fundingHead=fundingTail=temp;
            temp->next=NULL;
            temp->prev=NULL;
        }
        else
        {
            fundingTail->next=temp;
            temp->prev=fundingTail;
            fundingTail=fundingTail->next;

        }
        cout<<" Funding successfully recieved!"<<endl;
    }

    void searchFunding(int id)
    {
        cout<<endl<<endl;

        if(fundingHead==NULL)
        {
            cout<<"ERROR : Records Unavailable";
            return;
        }
        else
        {
            fundingNode *temp=fundingHead;
            while(temp)
            {
                if(temp->transactionId==id)
                {
                    cout<<"FUNDING RECORDS FOUND"<<endl;
                    cout<<"Transaction Id : "<<temp->transactionId<<endl;
                    cout<<"Amount : "<<temp->amount<<endl;
                    cout<<"Account Name : "<<temp->accountName<<endl;
                    return;
                }
                temp=temp->next;
            }

            if(temp==NULL)
            {
                cout<<"ERROR : Record for Id "<<id<<" does not exist "<<endl;
            }
        }
    }

    void totalFunds()
    {
        stack <int> fun;
        int total=0;
        fundingNode* temp=new fundingNode();
        temp=fundingHead;
        while(temp)
        {
            fun.push(temp->amount);
            temp=temp->next;
        }
        while(!fun.empty())
        {
            total=total+fun.top();
            fun.pop();
        }
        cout<<"Total Funding in the institution right now is : "<<total;


    }



 /*   ~Volunteer()
    {
        volunteerNode* temp;
        while(volunteerHead!=NULL)
        {
            temp=volunteerHead;
            volunteerHead=volunteerHead->next;
            delete temp;
        }
    }*/

};


int main()
{
    cout <<endl<<endl<< "                                        WELCOME TO A.I.R. ORPHANAGE!" << endl<<endl<<endl<<endl;
    Orphan orphanll;
    orphanll.addOrphan("Ram",5,1,"Loves to sing");
    orphanll.addOrphan("Shyaam",10,2,"Great at art");
    orphanll.addOrphan("Sia",11,3,"Loves to dance");
    orphanll.addOrphan("Jia",11,4,"Good at music");
    orphanll.addOrphan("Dia",9,5,"Very responsible");

    Volunteer volunteerll;
    volunteerll.addVolunteer("Naina Talwar", 50, 1);
    volunteerll.addVolunteer("Kabir Thapar", 38, 2);
    volunteerll.addVolunteer("Tina Agarwal", 44, 3);
    volunteerll.addVolunteer("Aditi Thepla", 33, 4);
    volunteerll.addVolunteer("Jessica Sethi", 22, 5);

    Employee employeell;
    employeell.addEmployee("Anusha yadav",18,1,741917080,"Karnal, Haryana",500000);
    employeell.addEmployee("Ishita yadav",19,2,895623741,"Noida, Ghaziabad",550000);
    employeell.addEmployee("Rishima Gupta",19,2,9191919191,"Noida, Ghaziabad",560000);

    Function functionll;
    functionll.addFunction(12,"january",2021,"Home minister's visit");
    functionll.addFunction(23,"march",2021,"Annual party");

    Funding fundingll;
    fundingll.addFunding(1,50000,"ABC firms");
    fundingll.addFunding(2,1000.0,"jiit noida");
    fundingll.addFunding(3,1233.0,"jaypee");
    fundingll.addFunding(4,56000.0,"dsa");


    label:

    int x,c;

    cout<<"                                 Enter 1 to add a child to the orphanage system"<<endl;
    cout<<"                                 Enter 2 to access a child's details"<<endl;
    cout<<"                                 Enter 3 if a child has been adopted"<<endl;
    cout<<"                                 Enter 4 to add a volunteer "<<endl;
    cout<<"                                 Enter 5 to access any volunteer's details"<<endl;
    cout<<"                                 Enter 6 to add an employee "<<endl;
    cout<<"                                 Enter 7 to access any employee's details"<<endl;
    cout<<"                                 Enter 8 to add a function "<<endl;
    cout<<"                                 Enter 9 to access any function's details"<<endl;
    cout<<"                                 Enter 10 to add funding "<<endl;
    cout<<"                                 Enter 11 to access any funding details"<<endl;
    cout<<"                                 Enter 12 to view total funding"<<endl;


    cin>>x;
    switch(x)
    {
        case 1: orphanll.addOrphan();
                cout<<endl<<"Press\n 1 to continue\n 0 to exit: ";
                cin>>c;
                if(c==1)
                    goto label;
                else
                    break;

        case 2:
                int a;
                cout<<"Enter Admission Number : ";
                cin>>a;
                orphanll.searchOrphan(a);
                cout<<endl<<"Press\n 1 to continue\n 0 to exit: ";
                cin>>c;
                if(c==1)
                    goto label;
                else
                    break;

        case 3:
                int b;
                cout<<"Enter Admission Number : ";
                cin>>b;
                orphanll.deleteOrphan(b);
                cout<<endl<<"Press\n 1 to continue\n 0 to exit: ";
                cin>>c;
                if(c==1)
                    goto label;
                else
                    break;

        case 4: volunteerll.addVolunteer();
                cout<<endl<<"Press\n 1 to continue\n 0 to exit: ";
                cin>>c;
                if(c==1)
                    goto label;
                else
                    break;

        case 5:
                int h;
                cout<<"Enter ID: ";
                cin>>h;
                volunteerll.searchVolunteer(h);
                cout<<endl<<"Press\n 1 to continue\n 0 to exit: ";
                cin>>c;
                if(c==1)
                    goto label;
                else
                    break;

        case 6: employeell.addEmployee();
                cout<<endl<<"Press\n 1 to continue\n 0 to exit: ";
                cin>>c;
                if(c==1)
                    goto label;
                else
                    break;

        case 7:
                int m;
                cout<<"Enter ID: ";
                cin>>m;
                employeell.searchEmployee(m);
                cout<<endl<<"Press\n 1 to continue\n 0 to exit: ";
                cin>>c;
                if(c==1)
                    goto label;
                else
                    break;

        case 8: functionll.addFunction();
                cout<<endl<<"Press\n 1 to continue\n 0 to exit: ";
                cin>>c;
                if(c==1)
                    goto label;
                else
                    break;

        case 9:
            {   int j,k;
                string l;
                cout<<"Enter date,month and year of the function: ";
                cin>>j>>l>>k;
                functionll.searchFunction(j,l,k);
                cout<<endl<<"Press\n 1 to continue\n 0 to exit: ";
                cin>>c;
                if(c==1)
                    goto label;
                else
                    break;
             }

        case 10:
                fundingll.addFunding();
                cout<<endl<<"Press\n 1 to continue\n 0 to exit: ";
                cin>>c;
                if(c==1)
                    goto label;
                else
                    break;

        case 11:
                int p;
                cout<<"Enter ID: ";
                cin>>p;
                fundingll.searchFunding(p);
                cout<<endl<<"Press\n 1 to continue\n 0 to exit: ";
                cin>>c;
                if(c==1)
                    goto label;
                else
                    break;

        case 12:
            fundingll.totalFunds();
            cout<<endl<<"Press\n 1 to continue\n 0 to exit: ";
                cin>>c;
                if(c==1)
                    goto label;
                else
                    break;


    }

    return 0;

}

