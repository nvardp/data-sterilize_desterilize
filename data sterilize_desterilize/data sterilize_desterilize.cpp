#include <iostream>
#include <string>
#include<fstream>
#include<vector>
using namespace std;
class Person {
public:
    Person(const string& name) {
        this->name = name;
        this->age = NULL;
        this->average = NULL;
    };
    Person(const string& name, int age, int ave)
    {
        this->name = name;
       this-> age = age;
       this-> average = ave;
    }

  
    void setAge(int other)
    {
        age = other;
    }
    void setName(const string& other)
    {
        name = other;
    }
    void setAverage(int other)
    {
        average = other;
    }
    int getAge() const
    {
        return age;
    }
    int getAverage() const
    {
        return average;
    }
    string getName() const
    {
        return name;
    }
private:
    string name;
    int age;
    int average;
};
ostream& operator<<(ostream& os, const Person& dt)
{
    os << dt.getName() << '/' << dt.getAge() << '/' << dt.getAverage()<<endl;
    return os;
}

template<typename T>
void write_in_file(vector<T>* vp)
{
    ofstream FDB;
    FDB.open("Person.txt");
    for (auto& x : *vp) 
    {
        FDB << "name: " << x.getName()<<endl;
        FDB << "age: " << x.getAge()<<endl;
        FDB << "average: " << x.getAverage()<<endl;
        FDB << "^\n";
   }
}

template<typename T>
vector<T> read_from_file(string ClassName)
{
    fstream FDB;
    FDB.open(ClassName+".txt");
    string tmp;
    vector<T> vec;
    Person obj("John", 18, 20);
        while(!FDB.eof())
        {
            FDB >> tmp;
            if (tmp == "name:")
            {
                FDB >> tmp;
               obj.setName(tmp);
                FDB >> tmp;
            }
            if (tmp == "age:")
            {
                FDB >> tmp; 
                obj.setAge(stoi(tmp));
                FDB >> tmp;
            }
            if (tmp == "average:")
            {
                FDB >> tmp; 
                obj.setAverage(stoi(tmp));
                FDB >> tmp;
            }
            vec.push_back(obj);
        }
       
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
    }
    return vec;
}


int main()
{
    Person obj1("John", 18, 20);
    Person obj2("Anush", 44, 31);
    Person obj3("Levon", 12, 22);
    Person obj4("Maneh");
    Person obj5("Garnik", 47, 21);
    vector<Person> vec{ obj1, obj2, obj3, obj4, obj5 };
    write_in_file(&vec);
    read_from_file<Person>("Person");
    
}