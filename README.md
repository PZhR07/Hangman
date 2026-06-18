# Hangman
🎮 Hangman Game (C++)

A simple console-based Hangman game written in C++ with multiple features like difficulty levels, categories, and hints.

📌 Features
🎯 Word guessing or letter-by-letter gameplay
📚 Multiple categories:
Fruits
Animals
Car Brands
Football Clubs
Basketball Clubs
⚙️ Difficulty levels:
Easy (8 attempts)
Medium (6 attempts)
Hard (4 attempts)
💡 Random hint system during gameplay
🔁 Play again option without restarting program
🧠 Win condition based on correctly guessed letters

🕹️ How to Play
1.Run the program
2.Choose a difficulty level
3.Choose a category
4.Try to guess:
5.Either the full word
6.Or individual letters
7.You lose if you exceed allowed attempts
8.You win by revealing all letters of the word

🧪 Game Logic
Each wrong guess reduces attempts
Correct letters are tracked internally
Game automatically checks win condition after each guess
Hint is triggered automatically when half of attempts are used

📂 Project Structure
hangman.cpp   → Main game source code

Compile:
g++ hangman.cpp -o hangman
Run:
./hangman
Windows:
hangman.exe

⚠️ Notes
Game runs in console only (no GUI)
Requires C++ compiler supporting C++11 or higher
Random seed is based on system time
📈 Possible Future Improvements
Display actual hangman ASCII art
Better word display (_ a _ p p _ e style)
Score system
Save/load game progress
Improved hint system
Input validation improvements

👨‍💻 Author
Developed as a programming practice project to learn:
OOP in C++
Game loops
Basic game logic design
Randomization and state handling
