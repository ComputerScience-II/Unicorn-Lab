#include <iostream>
#include <cassert>
#include <vector>

using namespace std;


class Unicorn {

    private: 

        string name;
        bool life;
        static vector<string> namesTaken;

    public:

        Unicorn(string name2){

            for( auto a: namesTaken) {

                if( a == name2){

                    throw runtime_error("Name already exists for a different Unicorn");
                }
            }

            name = name2;
            life = true;
            namesTaken.push_back(name);

        }

        ~Unicorn() {

            death();
        }

        void death() {

            if(life) {

                life = false;
            }

            for (int i = 0; i < namesTaken.size(); i++) {

                if (namesTaken[i] == name) {

                    namesTaken.erase(namesTaken.begin() + i);

                    break;

                }
            }

        }

        string getName() {

            return name;

        }

        void setName(string a) {

            name = a;


        }

        bool isAlive() {

            return life;
        }

        static int getNumberOfNamesTaken() {

            return namesTaken.size();
        }

};

vector<string> Unicorn::namesTaken;



void testCases() {

    Unicorn x("test1");

    Unicorn y("test2");

    Unicorn z("test3");


    assert(x.isAlive());

    assert(y.isAlive());

    assert(z.isAlive());

    assert(Unicorn::getNumberOfNamesTaken() == 3);

    try{

        Unicorn a("test1");
    }
    catch(const exception& e) {

        cout << "name already exists!" << endl;
    }
    
    x.death();

    assert(!x.isAlive());

    assert(Unicorn::getNumberOfNamesTaken() == 2);

    Unicorn x2("test1");

    assert(x2.isAlive());

    assert(Unicorn::getNumberOfNamesTaken() == 3);

}

int main() {

    testCases();

    cout << "The code works." << endl;



    return 0;
}