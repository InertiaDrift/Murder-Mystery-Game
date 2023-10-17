
string shuffleWord(const string& word) {
    string shuffledWord = word;
    int length = static_cast<int>(shuffledWord.length());

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % length;
        swap(shuffledWord[i], shuffledWord[randomIndex]);
    }

    return shuffledWord;
}

bool jumble() {

    srand(static_cast<unsigned int>(time(0)));

    const string words[] = {"apple", "banana", "orange", "grape", "kiwi"};
    const int numWords = sizeof(words) / sizeof(words[0]);

    int totalScore = 0;
    int maxAttempts = 3;

    cout << "Welcome to Word Jumble!" << endl;
    cout << "Unscramble the letters to guess the word." << endl;

    while (totalScore < 3) {
        // Choose a random word from the list
        string originalWord = words[rand() % numWords];
        string shuffledWord = shuffleWord(originalWord);

        cout << "Here's the jumbled word: " << shuffledWord << endl;

        int attempts = 0;
        bool guessedIncorrectly = true;

        while (guessedIncorrectly) {
            // Player's guess
            string guess;
            cout << "Your guess (" << maxAttempts - attempts << " attempts remaining): ";
            cin >> guess;

            // Convert the guess to lowercase for case-insensitive comparison
            for (char& c : guess) {
                c = tolower(c);
            }

            if (guess == originalWord) {
                cout << "Congratulations! You guessed the word correctly." << endl;
                totalScore++;
                guessedIncorrectly = false;
                
            } else {
                cout << "Oops! That's not the correct word." << endl;
                attempts++;
            }
        }

        if (guessedIncorrectly) {
            cout << "The correct word is: " << originalWord << endl;
        }

        cout << "Current Score: " << totalScore << " out of 5" << endl;
        cout << "------------------------" << endl;
        return false;
    }

    cout << "Congratulations! You scored 3 out of 5. You win!" << endl;

    return true;
}
