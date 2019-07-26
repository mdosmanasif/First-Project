#include <iostream>

using namespace std;

class Owner;
class Rider;
class Horse;

class Rider
{
public:
    Rider(string n, const Owner &o){
        name = n;
        owner = &o;
    }

    string getName() {return name;}
     const Owner** getOwner() {return &owner;}

private:
    const string name;
    const Owner *owner;
};


class Horse
{
public:
    Horse(string n, const Owner &o, const Rider &r){
        name = n;
        owner = &o;
        rider = &r;
    }

    string getName(){return name;}
    const Owner** getOwner() {return &owner;}
    const Rider** getRider() {return &rider;}
private:
    const string name;
    const Owner *owner;
    const Rider *rider;
};


class Owner {
    public:
    Owner(string n){
        name = n;
        vec_rider = NULL;
        vec_horse = NULL;
    }

    string getName(){return name;}

    void addHorse(Horse* horse){
        vec_horse.push_back(horse);
    }

    void addRider(Rider* rider){
        vec_rider.push_back(rider);
    }

    Horse* getHorse(int i) { // return NULL if value of i not valid
        if(i < vec_horse.size()){
            return vec_horse[i];
        } else {
            return NULL;
        }
    }

    Rider* getRider(int i) { // return NULL if value of i not valid
        if(i < vec_rider.size()){
            return vec_rider[i];
        } else {
            return NULL;
        }
    }

    int numHorses(){
        return vec_horse.size();
    }

    int numRiders(){
        return vec_rider.size();
    }

    private:
    const string name;
    vector<const Rider*> vec_rider; // vector of const pointers
    vector<const Horse*> vec_horse; // vector of const pointers
};



int main(){

    Owner Alice("Alice");
    Owner Bob("Bob");
    Rider Alpha("Alpha", Alice);
    Rider Beta("Beta", Alice);
    Rider Gamma("Gamma", Bob);

    Alice.addRider(&Alpha);
    Alice.addRider(&Beta);
    Bob.addRider(&Gamma);

    Horse **h = new Horse*[4];
    h[0] = ("Blue", Alice, Alpha); // pseudocode, write in full
    h[1] = ("Flash", Alice, Beta);
    h[2] = ("Gold", Bob, Gamma);
    h[3] = ("Silver", Bob, Gamma);


    Alice.addHorse(h[0]); // pseudocode, write in full
    Alice.addHorse(h[1]);
    Bob.addHorse(h[2]);
    Bob.addHorse(h[3]);

    cout << "output start here : ------------------------------" << endl;
    cout << Alice.getName() << ", " << Alice.numRiders() << ", " << Alice.numHorses() << endl;
    cout << Bob.getName() << ", " << Bob.numRiders() << ", " << Bob.numHorses() << endl;

    string races[] = { "Derby", "Preakness", "Belmont", "Ascot" };
    for (int i = 0; i < 4; ++i)
    {
        cout << "race: " << races[i] << endl;
        cout << "winning horse: " << h[i].getName();        // name of horse h[i]
        cout << "rider: " << h[i].getRider().getName();     // name of rider of horse h[i]
        cout << "owner: " << h[i].getOwner().getName();     // name of owner of horse h[i]
    }

    delete h;
}













