#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    Student(string n){// non-default constructor
        name = n;
        id = 0;
    }
    string getName(){return name;} // return name
    int getID(){return id;} // return id
    void setID(int i){id = i;} // set value of id

        void add((Student **pps, string s, int id, int n, int i) // write the code
        {
    // dynamically create Student object using input data
            Student stu(id);
    // assign object to i^th element of pps
            if(i < n){
                pps[i] = stu;
            }
    // do nothing if value of i out of bounds
        }
        void remove(string** pps, int n, int j) // write the code
        {
    // remove element at location j in pps
            if(j < n){
                pps[j] = NULL;
            }
    // do nothing if value of j out of bounds
        }
        void display(string** pps,int n) // write the code
        {
    // loop over elements of pps, print name and id as appropriate
            for(int i = 0; i < n; i++){
                cout << "Name: " << pps[i].getName() << "     ID: " << pps[i].getID();
            }
        }
        void release(string** pps,int n) // write the code
        {
    // release dynamic memory correctly
            for(int i = 0; i < n; i++){
                delete pps[i];
            }
            delete pps;

        }

private:
    const string name;
    int id;
};

int main()
{
    int n = 0;
    cout << "Please enter the number of students (positive integer): " << endl;
    cin >> n;
    Student **pps = new Student*[n]; // WRITE CODE, DYNAMIC ALLOCATION ARRAY OF POINTERS
                    for (int i = 0; i < n; i++)
    {
        string s;
        int id = 0;
        cout << "Please enter a name and id (positive integer): " << endl;
        cin >> s >> id;
        add(pps, s, id, n, i);
    }
    int j = 0;
    cout << "Please enter an integer >= 0: " << endl;
    cin >> j;
    remove(pps, n, j);
    display(pps,n);
    release(pps,n);
    return 0;
}
