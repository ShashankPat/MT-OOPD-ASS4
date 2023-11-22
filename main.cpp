#include <bits/stdc++.h>
using namespace std;

struct Person{
    string first_name;
    string last_name;
    int age;
    string gender;
    string address;
};

class Vehicle_Owner{

    string Vehicle_Number;
    string First_Name;
    string Last_Name;
    int Age;
    string Gender;
    string Address;

    public:

    // getter functions //
    string getVehiclenumber(){return Vehicle_Number;}
    string getFirstname(){return First_Name;}
    string getlastname(){return Last_Name;}
    int getage(){return Age;}
    string getgender(){return Gender;}
    string getAddress(){return Address;}

    void ReadandStorePeopleData(vector<Vehicle_Owner>& v)
    {
        fstream f("A4-Q1.csv");
        if(!f.is_open())
        {
            cerr << "error while opening file\n";
        }
        string line;
        getline(f,line); //// reading header line ////

        while(getline(f,line,'\n'))
        {
            Vehicle_Owner vo;
            string temp;
            stringstream ss(line);
            getline(ss,temp,',');
            vo.Vehicle_Number = temp;
            getline(ss,temp,',');
            temp = "," + temp ;
            vo.Vehicle_Number += temp;
            getline(ss,temp,',');
            vo.First_Name = temp;
            getline(ss,temp,',');
            vo.Last_Name = temp;
            getline(ss,temp,',');
            vo.Age = stoi(temp);
            getline(ss,temp,',');
            vo.Gender = temp;
            getline(ss,temp,',');
            vo.Address = temp;
            v.push_back(vo);
        }
        f.close();
    }
    void Edit_Vehicle_Info(vector<Vehicle_Owner>& v)
    {
        Vehicle_Owner temp;
        cout<<"Enter Vehicle number with state code which you want to edit:  ";
        cin>>temp.Vehicle_Number;
        cout<<"Enter first name: ";
        cin>> temp.First_Name;
        cout<<"Enter Last Name: ";
        cin>> temp.Last_Name;
        cout<<"Enter Gender : ";
        cin>> temp.Gender;
        cout<<"Enter age: ";
        cin>> temp.Age;
        cout<<"Enter Address : ";
        getchar();
        getline(cin,temp.Address);

        for(int i=0;i<v.size();i++)
        {
            if(v[i].Vehicle_Number == temp.Vehicle_Number)
            {
                v[i] = temp;
                break;
            }
        }

    }

    void Add_New_Vehicle(vector<Vehicle_Owner>& v)
    {
        Vehicle_Owner temp;
        cout<<"Enter Vehicle number with state code: ";
        cin>> temp.Vehicle_Number;
        cout<<"Enter first name: ";
        cin>> temp.First_Name;
        cout<<"Enter Last Name: ";
        cin>> temp.Last_Name;
        cout<<"Enter Gender : ";
        cin>> temp.Gender;
        cout<<"Enter age: ";
        cin>> temp.Age;
        cout<<"Enter Address : ";
        getchar();
        getline(cin,temp.Address);
        v.push_back(temp);
    }

    void Delete_Vehicle(vector<Vehicle_Owner>& v)
    {
        string s;
        cout<<"Enter Vehicle Number to be deleted with state code: ";
        cin>>s;

        int index=-1;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].Vehicle_Number == s)
            {
                index = i;
                break;
            }
        }

        if(index==-1)
        {
            cout<<"NO such vehicle exists \n";
            cout<<"Delete aborted\n";
            return;
        }

        v.erase(v.begin()+index);
    }
    void Displaydata(vector<Vehicle_Owner> v)
    {
        for(auto i:v)
        {
            cout<<i.Vehicle_Number <<" "<<i.First_Name <<" "<<i.Last_Name<<" "<<i.Gender<<" "<<i.Age<<" "<<i.Address<<"\n";
        }
    }
};

class Traffic_Violation
{
    string vehicle_number;
    string type;
    string location;
    public:

    // getter functions
    string getVehiclenumber(){return vehicle_number;}
    string gettype(){return type;}
    string getlocation(){return location;}

    void Readand_Store_violations(vector<Traffic_Violation> &v)
    {
        fstream f("A4-Q2.csv");
        if(!f.is_open())
        {
            cerr << "error while opening file\n";
        }

        Traffic_Violation t;
        string line;
        getline(f,line); // reading header line

        while(getline(f,line,'\n'))
        {
            stringstream ss(line);
            getline(ss,t.vehicle_number,'"');
            getline(ss,t.vehicle_number,'"');
            getline(ss,t.type,',');
            getline(ss,t.type,',');
            getline(ss,t.location);

            //cout<<t.location<<"\n";
            size_t endPos = t.location.find_last_not_of(" \t\n\r\f\v");
            // erase the trailing spaces
            if (endPos != std::string::npos)
            t.location.erase(endPos + 1);
            v.push_back(t);
        }
        f.close();
    }

    void Display_Violations(vector<Traffic_Violation> &v)
    {
        for(auto i:v)
        cout<<i.vehicle_number<<" "<<i.type<<" "<<i.location<<"\n";
    }

    void Add_Violation(vector<Traffic_Violation> &v)
    {
        Traffic_Violation t;
        cout<<"Enter vehicle number : ";
        cin>>t.vehicle_number;
        cout<<"Enter type of violation: ";
        cin>>t.type;
        cout<<"Enter location of violation : ";
        getchar();
        getline(cin,t.location);

        v.push_back(t);
    }

    void Delete_Violation(vector<Traffic_Violation> &v)
    {
        Traffic_Violation t;
        cout<<"Enter vehicle number : ";
        cin>>t.vehicle_number;
        cout<<"Enter type of violation: ";
        cin>>t.type;
        cout<<"Enter location of violation : ";
        getchar();
        getline(cin,t.location);

        for(int i=0;i<v.size();)
        {
            if(v[i].vehicle_number == t.vehicle_number && v[i].type== t.type && v[i].location == t.location)
            {
                v.erase(v.begin()+i);
            }
            else
            i++;
        }
    }

    void Edit_Violation(vector<Traffic_Violation> &v)
    {
        Traffic_Violation t1,t2;
        cout<<"Enter original vehicle number : ";
        cin>>t1.vehicle_number;
        cout<<"Enter type of violation: ";
        cin>>t1.type;
        cout<<"Enter location of violation : ";
        getchar();
        getline(cin,t1.location);

        cout<<"Enter new vehicle number : ";
        cin>>t2.vehicle_number;
        cout<<"Enter type of violation: ";
        cin>>t2.type;
        cout<<"Enter new location of violation : ";
        getchar();
        getline(cin,t2.location);

        
        for(int i=0;i<v.size();i++)
        {
            if(v[i].vehicle_number == t1.vehicle_number && v[i].type == t1.type && v[i].location == t1.location)
            v[i] = t2;
        }
    }
};

struct violation{
    string vehicle_number;
    string type;
    string location;
};

class Evidence{
    
    vector<Person> witnesses;
    struct violation violation_details;
    string response_text;
    string prior_info;
    
    public:
    Evidence(){}
    Evidence(vector<Person> u,struct violation v,string w,string x)
    {
        witnesses = u;
        violation_details = v;
        response_text = w;
        prior_info = x;
    }
    void addwitnesses()
    {
        Person p;
        cout<<"Enter first name : ";
        cin>>p.first_name;
        cout<<"Enter last name: ";
        cin>>p.last_name;
        cout<<"Enter age: ";
        cin>>p.age;
        cout<<"Enter gender: ";
        cin>>p.gender;
        cout<<"Enter address: ";
        getchar();
        getline(cin,p.address);

        witnesses.push_back(p);
    }
    void add_violation_details()
    {
        struct violation v;
        cout<<"Enter vehicle number: ";
        cin>>v.vehicle_number;
        cout<<"Enter type of violation: ";
        cin>>v.type;
        cout<<"Enter location of violation: ";
        getchar();
        getline(cin,v.location);

        violation_details = v;
    }
    void add_response_text()
    {
        string s;
        cout<<"enter response text: ";
        getchar();
        getline(cin,s);
        response_text = s;
    }
    void add_prior_info()
    {   
        string s;
        cout<<"Enter any prior information about the person: ";
        getchar();
        getline(cin,s);

        prior_info = s;
    }
    vector<Person> getwitnesses()
    {
        return witnesses;
    }
    struct violation getviolationdetails()
    {
        return violation_details;
    }
    string getrepsonsetext()
    {
        return response_text;
    }
    string getpriorinfo()
    {
        return prior_info;
    }
};

int main()
{
    ///////////// Question 1 ////////////////////
    Vehicle_Owner V;
    vector<Vehicle_Owner> v;
    V.ReadandStorePeopleData(v);

    while(1)
    {
        char choice;
        cout<<"\tPress 1 to display Vehicles data:\n\t";
        cout<<"Press 2 for adding new Vehicle:\n\t";
        cout<<"Press 3 for deleting vehicle:\n\t";
        cout<<"Press 4 for editing a vehicle:\n\t";
        cin>>choice;

        switch(choice)
        {
            case '1':
            V.Displaydata(v);
            break;
            case '2':
            V.Add_New_Vehicle(v);
            break;
            case '3':
            V.Delete_Vehicle(v);
            break;
            case '4':
            V.Edit_Vehicle_Info(v);
            break;
            default:
            cout<<"Exiting question 1\n";
            goto label1;
            break;
        }
    }
    
    ////////// Question 2 ///////////////
    label1:
    Traffic_Violation T;
    vector<Traffic_Violation> t;
    T.Readand_Store_violations(t);

    while(1)
    {
        char choice;
        cout<<"\tPress 1 to display Violations data\n\t";
        cout<<"Press 2 for adding new Violation\n\t";
        cout<<"Press 3 for deleting Violation\n\t";
        cout<<"Press 4 for editing a Violation\n\t";
        cin>>choice;

        switch(choice)
        {
            case '1':
            T.Display_Violations(t);
            break;
            case '2':
            T.Add_Violation(t);
            break;
            case '3':
            T.Delete_Violation(t);
            break;
            case '4':
            T.Edit_Violation(t);
            break;
            default:
            cout<<"Exiting question 2\n";
            goto label2;
            break;
        }
    }

    label2:
    //////// Question 3 /////////////
    vector<Person> P;
    fstream f("A4-Q3.csv");
    if(!f.is_open())
    {
        cerr << "error while opening file\n";
    }
    string line;
    getline(f,line);
    while(getline(f,line))
    {
        Person p;
        stringstream ss(line);
        getline(ss,p.first_name,',');
        getline(ss,p.last_name,',');
        getline(ss,line,',');
        p.age = stoi(line);
        getline(ss,p.gender,',');
        getline(ss,p.address,',');

        P.push_back(p);
    }

    f.close();
    
    cout<<"The Probable Address are : \n";
    for(int i=0;i<t.size();i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(t[i].getVehiclenumber() == v[j].getVehiclenumber())
            {
                for(int k=0;k<P.size();k++)
                {
                    if(P[k].first_name == v[j].getFirstname() && P[k].last_name == v[j].getlastname() && P[k].age == v[j].getage()
                     && P[k].gender == v[j].getgender() && P[k].address!=v[j].getAddress() )
                    cout<<P[k].first_name <<" "<<P[k].last_name <<" "<<P[k].age <<" "<<P[k].address<<"\n";
                }
            }
        }
    }



    cout<<"\n\n";
    ////////// Question 4////////////////
    
    vector<Evidence> e;

    while(1)
    {
        int x;
        cout<<"Enter the number of witnesses for the accident: ";
        cin>>x;
        Evidence E;
        while(x--)
        {
            E.addwitnesses();
        }
        E.add_violation_details();
        E.add_response_text();
        E.add_prior_info();
        vector<Person> witnesses = E.getwitnesses();
        struct violation violation_details = E.getviolationdetails();
        string response_text = E.getrepsonsetext();
        string prior_info = E.getpriorinfo();

        Evidence copy(witnesses,violation_details,response_text,prior_info);
        e.push_back(copy);

        char choice;
        cout<<"for adding more evidence for other accidents press Y/y\n";
        cin>>choice;

        if(choice!='Y' && choice !='y')
        break;
    }

    for(int i=0;i<e.size();i++)
    {
        vector<Person> witnesses = e[i].getwitnesses();
        struct violation violation_details = e[i].getviolationdetails();
        string response_text = e[i].getrepsonsetext();
        string prior_info = e[i].getpriorinfo();

        cout<<"list of witnesses are\n";
        for(int j=0;j<witnesses.size();j++)
        {
            cout<<"first name : "<<witnesses[j].first_name<<"\n";
            cout<<"last name : "<<witnesses[j].last_name<<"\n";
            cout<<"age : "<<witnesses[j].age<<"\n";
            cout<<"gender : "<<witnesses[j].gender<<"\n";
            cout<<"Address : "<<witnesses[j].address<<"\n";
        }

        cout<<"\nViolation details\n";
        cout<<"vehicle number : "<< violation_details.vehicle_number<<"\n";
        cout<<"type : "<<violation_details.type<<"\n";
        cout<<"location of violation : "<<violation_details.location<<"\n";

        cout<<"response text : "<<response_text<<"\n";

        cout<<"prior information : "<<prior_info<<"\n";
        
    }
    return 0;
}
