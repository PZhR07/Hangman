#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string random_word(){
    string list[10]{"strawberry","apple","mango","cherry","lemon","orange","banana","peach","cucumber","greengage"};
    int random = rand()%10;
    return list[random];
}

char* split(string correct_word){
    char* arr = new char[correct_word.length() + 1];

    for(int i=0; i<correct_word.length(); i++){
        arr[i] = correct_word[i];
    }

    arr[correct_word.length()] = '\0';

    return arr;
}

int main(){

    srand(time(0));

    char x , l;
    string w;
    string correct_word = random_word();
    string guessed = "";

    for(int i=0; i<correct_word.length(); i++){
        cout<<"_ ";
    }
    cout<<endl;

    for (int fault_counter=0 ; fault_counter<6;){
        cout<<"Do you want to guess a word(y/n):";
        cin>>x;
        if (x == 'y'){
            cout<<"Now guess the word:";
            cin>>w;
            if (w == correct_word){
                cout<<"That's right! you win"<<endl;
                break;
            }
            else{
                fault_counter++;
                cout<<"Wrong guess, try again."<<endl;
                cout<<"You have "<<6 - fault_counter<<" attempts left."<<endl;
            }
        }
        if (x == 'n'){
            cout << "Now guess the letter:";
            cin >> l;

        char* arra = split(correct_word);
        bool found = false;

        for (int i = 0; i < correct_word.length(); i++){
            if (arra[i] == l){
                cout << l << " found in position " << i + 1 << endl;
                found = true;
            }
        }

        delete[] arra;

        if (found){
            if (guessed.find(l) == string::npos){
                guessed += l;
            }
        }

        bool win = true;

        for (int i = 0; i < correct_word.length(); i++){
            if (guessed.find(correct_word[i]) == string::npos){
                win = false;
                break;
            }
        }

        if (win){
            cout << "That's right(" << correct_word << ")! you win" << endl;
            break;
        }

        if (!found){
            fault_counter++;

            cout << "Wrong guess, try again." << endl;
            cout << "You have "
                << 6 - fault_counter
                << " attempts left." << endl;
        }

        if (fault_counter == 6){
            cout << "You lose! The correct word was: "
                << correct_word << endl;
            break;
        }
    }
}
    return 0;}
