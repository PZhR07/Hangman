#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

class hangman {
    private:
        char x , l ,y;
        string w;
        string guessed;
        string correct_word;
        int attempt_counter = 6;

    public:
        string random_word();
        bool result(char l);
        void play();
        char* split(string correct_word);
        int level();
        void random_hint();
        void hint();
        void Score_System(int score);
        void saveScore(int score);
        int loadScore();
        void game_history();
        static int score;
};
int hangman::score = 0;

void hangman::game_history(){
    // placeholder for future implementation
}
void hangman::saveScore(int score){
    ofstream file("score.txt");
    file << score;
    file.close();
}
int hangman::loadScore(){
    ifstream file("score.txt");
    int s = 0;
    if (file.is_open()){
        file >> s;
    }
    return s;
}
void hangman::Score_System(int score){
    cout<<"your score is:"<<score<<endl;
    if (score >=20){
        random_hint();
        hangman::score -= 20;
    }
}
void hangman::random_hint(){
    int random_hints = rand()%3;
    switch(random_hints){
        case 0:cout<<"position 1 is:"<<correct_word[0];
                break;
        case 1:cout<<"position 2 is:"<<correct_word[1];
                break;
        case 2:cout<<"position 3 is:"<<correct_word[2];
                break;
    }
}
void hangman::hint(){
    cout<< "Do you want some help(y/n):";
    char y;
    cin>>y;
    if ( y == 'y'){
        random_hint();
    }
}
int hangman::level(){
    cout<<"Choose a level: 1. Easy 2. Medium 3. Hard: ";
    int level;
    cin >> level;
    switch(level){
        case 1: return 8;
        case 2: return 6;
        case 3: return 4;
        default: return 6;
    }
}
string hangman::random_word(){
    string fruits[10]{"strawberry","apple","mango","cherry","lemon","orange","banana","peach","cucumber","greengage"};
    string animals[10]{"dog","cat","lion","tiger","elephant","giraffe","monkey","bear","zebra","fox"};
    string car[10]{"mercedes","bmw","audi","volkswagen","honda","toyota","ford","nissan","hyundai","kia"};
    string football_club[10]{"real_madrid","barcelona","manchester_united","bayern_munich","juventus","liverpool","chelsea","paris_saint-germain","manchester_city","atletico_madrid"};
    string basketball_club[10]{"los_angeles_lakers","golden_state_warriors","chicago_bulls","boston_celtics","miami_heat","houston_rockets","san_antonio_spurs","toronto_raptors","philadelphia_76ers","oklahoma_city_thunder"};
    cout<<"Choose a category: 1. Fruits 2. Animals 3. Car Brands 4. Football Clubs 5. Basketball Clubs: ";
    int category;
    cin >> category;
    switch(category){
        case 1: return fruits[rand()%10];
        case 2: return animals[rand()%10];
        case 3: return car[rand()%10];
        case 4: return football_club[rand()%10];
        case 5: return basketball_club[rand()%10];
        default: return "valid category not chosen";
    }
}
char* hangman::split(string correct_word){
    char* arr = new char[correct_word.length() + 1];
    for(int i=0; i<(int)correct_word.length(); i++){
        arr[i] = correct_word[i];
    }
    arr[correct_word.length()] = '\0';
    return arr;
}
bool hangman::result(char l){
    if (guessed.find(l) == string::npos){
        guessed += l;
    }

    bool win = true;
    for (int i = 0; i < (int)correct_word.length(); i++){
        if (guessed.find(correct_word[i]) == string::npos){
            win = false;
            break;
        }
    }

    if (win){
        cout << "That's right(" << correct_word << ")! you win" << endl;
        score +=5;
        return true;
    }

    return false;
}
void hangman::play(){
    cout<<"if you win you get 5 points and if you lose you get 0 points"<<endl;
    cout<<"if you win 20 points you can get a hint in the next game"<<endl;
    attempt_counter = level();
    correct_word = random_word();
    guessed = "";

    // نمایش کلمه با _ در ابتدا
    for(int i=0; i<(int)correct_word.length(); i++){
        cout << "_ ";
    }
    cout << endl;

    for (int fault_counter=0 ; fault_counter<attempt_counter;){
        if (fault_counter == attempt_counter/2 && fault_counter > 0){
            hint();
        }
        cout << "Do you want to guess a word(y/n):";
        cin >> x;

        if (x == 'y'){
            cout << "Now guess the word:";
            cin >> w;

            if (w == correct_word){
                cout << "That's right! you win" << endl;
                score +=5;
                break;
            } else {
                fault_counter++;
                cout << "Wrong guess. Attempts left: " << attempt_counter - fault_counter << endl;
            }
        }

        if (x == 'n'){
            cout << "Now guess the letter:";
            cin >> l;

            char* arr = split(correct_word);
            bool found = false;

            for (int i = 0; i < (int)correct_word.length(); i++){
                if (arr[i] == l){
                    cout << l << " found in position " << i + 1 << endl;
                    found = true;
                }
            }
            delete[] arr;

            if (result(l)){
                break;
            }
            if (!found){
                fault_counter++;
                cout << "Wrong guess. Attempts left: " << attempt_counter - fault_counter << endl;
            }
            if (fault_counter == attempt_counter){
                cout << "You lose! The correct word was: " << correct_word << endl;
                break;
            }

            // نمایش پیشرفت کلمه بعد از هر حدس
            for(int i=0; i<(int)correct_word.length(); i++){
                if(guessed.find(correct_word[i]) != string::npos)
                    cout << correct_word[i] << " ";
                else
                    cout << "_ ";
            }
            cout << endl;
        }
    }

    // ذخیره score بعد از هر بازی
    saveScore(score);
    Score_System(score);
}

int main(){
    srand(time(0));
    hangman game;
    hangman::score = game.loadScore();

    char again;
    do {
        game.play();
        cout << "Do you want to play again? (y/n): ";
        cin >> again;
    } while(again == 'y');

    game.saveScore(hangman::score);
    return 0;
}
