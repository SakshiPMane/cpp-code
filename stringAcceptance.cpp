
#include <iostream>
#include <string>
using namespace std;

struct Transition {
    int fstate;
    char inp;
    int tstate;
};

Transition table[] = {
    {0, '0', 1}, 
    {1, '1', 1},
    
};

int finalstates[] = {1}; 

int isAccepted(string input) {
    int currstate = 0; 

    for (char currinput : input) {
        int j;
        int transitionfound = 0;

       
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

   
    int num_final_states = 1; 
    for (int i = 0; i < num_final_states; i++) {
        if (currstate == finalstates[i]) {
            return 1; 
        }
    }

    return 0; 
}

int main() {
    string input_string;
    cout << "Enter a string : ";
    cin >> input_string;

    if (isAccepted(input_string)) {
        cout << "Accepted" << endl;
    } else {
        cout << "Not Accepted" << endl;
    }

    return 0;
}