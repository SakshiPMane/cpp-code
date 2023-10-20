#include <iostream>
#include <string>
using namespace std;

typedef struct Transition {
    int fstate;
    char inp;
    int tstate;
}Transition;

Transition table[] = {
    {0, '0', 1}, 
    {1, '1', 1},    
};

int finalstates[] = {1}; 

int isAccepted(string input) {
    int currstate = 0; 
    int i;
    for (i = 0; i < input.length(); i++) {
        char currinput = input[i];
        int transitionfound = 0;

        int j;
        for (j = 0; j < 2; j++) {
            if (table[j].fstate == currstate && table[j].inp == currinput) {
                currstate = table[j].tstate;
                transitionfound = 1;
                break;
            }
        }
        if (!transitionfound) {
            return 0; 
        }
    }
    int nfinalStates = 1; 
    for (int i = 0; i < nfinalStates; i++) {
        if (currstate == finalstates[i]) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    string inputstring;
    cout << "Enter a string ";
    cin >> inputstring;

    if (isAccepted(inputstring)) {
        cout << "String Accepted" << endl;
    } else {
        cout << "Not Accepted" << endl;
    }
    return 0;
}