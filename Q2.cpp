#include <iostream>

using namespace std;

class svec
{
private:
    string *ds; // dynamic array of strings
    int len; // length of array
    int num; // number of populated array items
    public:
    // *** WRITE CLASS CONSTRUCTORS ***
    //... size();
    //... front();
    //... back();
    //... get(int i); // ADDRESS of i^th array element (NULL if value of i not valid)
    //void push_back(... s);
    //cleanup(); // release dynamic memory

    svec()
    {
        ds = NULL;
        num = 0;
        len = 0;
    }

    svec(int n)
    {
        if(n <= 0)
        {
            ds = NULL;
            num = 0;
            len = 0;
        }
        else
        {
            ds = new string[n];
            num = n;
            len = n;
        }
    }

    svec(int n, string s)
    {
        if(n <= 0)
        {
            ds = NULL;
            num = 0;
            len = 0;
        }
        else
        {
            ds = new string[n];
            len = n;
            for(int i = 0; i < n; i++)
            {
                ds[i] = s;
            }
            num = len;
        }
    }

    //functions-------------

    string front()
    {
        if(num == 0) return "";
        return ds[0];
    }

    string back()
    {
        if(num == 0) return "";
        return ds[num];
    }

    string* get(int i)
    {
        if(i < 0 || i > num) return NULL;
        return &ds[i];
    }

    void push_back(string s)
    {
        if(len == 0)
        {
            len = 10;
            ds = new string[len];
            ds[0] = s;
            num = 1;
        } else if(num < len){
            ds[num] = s;
            num++;
        } else if(num == len){
            len = len + 10;
            string* new_array = new string[len];

            for(int i = 0; i < len - 10; i++){
                new_array[i] = ds[i];
            }

            new_array[len - 9] = s;
            num++;
            delete ds;
            ds = new_array;
            cout << we are here... << endl;

        }
    }

    void cleanup()
    {
        delete ds;
        ds = NULL;
        num = 0;
        len = 0;
    }

    int size(){
        return len;
    }


};

//---------------------------Main----------------------------------------

int main()
{
    int n;
    string s;
    cout << "Please enter a positive number and a string:" << endl;
    cin >> n >> s;
    // INSTANTIATE AN SVEC OBJECT "v" using n and s in constructor // WRITE CODE
    svec v(n, s);
    // PRINT THE SIZE OF v // WRITE CODE
    cout << v.size();
    while (true)
    {
        cout << "Please enter a string (type ÕÕendÕÕ to break):" << endl;
        cin >> s;
        if (s == "end") break;
        v.push_back(s);
    }
    // PRINT THE DATA IN THE FIRST AND LAST VALID ELEMENTS OF v // WRITE CODE
    cout<< "Front = "<< v.front() << "     Back = " << v.back() << endl;
    // WRITE A LOOP TO PRINT THE DATA IN ALL VALID ELEMENTS OF v // WRITE CODE
    for(int i =0; i< v.size(); i++) {
        cout << "Array[" << i << "] = " << v.get(i) << endl;
    }

    // RELEASE ALL DYNAMICALLY ALLOCATED MEMORY // WRITE CODE
    v.cleanup();
    //delete svec;
    return 0;
}
