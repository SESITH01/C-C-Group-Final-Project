#include <iostream>
#include <string>
#include <fstream>
#include<vector>

using namespace std;

class Story {
private:
    // Initializing the strings for the input
    string adj1;
    string adj2;
    string noun1;
    string noun2;
    string verb1;
    string verb2;
    string place1;
    string place2;
    string file_name;
    vector<string> adjectives = { "funny", "happy", "silly", "blue", "bright", "loud", "quiet", "shy", "witty", "zany" };
    vector<string> nouns = { "apple", "banana", "car", "dog", "elephant", "fish", "hat", "ice cream", "jacket", "kite" };;
    vector<string> verbs = { "jump", "laugh", "play", "sing", "dance", "eat", "run", "swim", "talk", "write" };
    vector<string> places = { "beach", "city", "forest", "hospital", "library", "museum", "park", "restaurant", "school", "zoo" };

public:
    // Story methods for running the code
    void comedyStory() {
        file_name = "comedy_story.txt";
        opening_file(file_name);
    }
    void mysteryStory() {
        file_name = "mystery_story.txt";
        opening_file(file_name);
    }
    void romanceStory() {
        file_name = "romance_story.txt";
        opening_file(file_name);
    }
    void horrorStory() {
        file_name = "horror_story.txt";
        opening_file(file_name);
    }

    void opening_file(string filename) {
        ifstream storyFile(filename);
        if (!storyFile) {
            cout << "Error: could not open file " << filename << endl;
            return;
        }

        string line, updated_story;
        while (getline(storyFile, line)) {
            // Replacing all occurrences of variables in the line
            size_t pos;
            while ((pos = line.find("adj1")) != string::npos) {
                line.replace(pos, 4, adj1);
            }
            while ((pos = line.find("noun1")) != string::npos) {
                line.replace(pos, 5, noun1);
            }
            while ((pos = line.find("verb1")) != string::npos) {
                line.replace(pos, 5, verb1);
            }
            while ((pos = line.find("place1")) != string::npos) {
                line.replace(pos, 6, place1);
            }
            while ((pos = line.find("adj2")) != string::npos) {
                line.replace(pos, 4, adj2);
            }
            while ((pos = line.find("noun2")) != string::npos) {
                line.replace(pos, 5, noun2);
            }
            while ((pos = line.find("verb2")) != string::npos) {
                line.replace(pos, 5, verb2);
            }
            while ((pos = line.find("place2")) != string::npos) {
                line.replace(pos, 6, place2);
            }
            updated_story += line + "\n";
        }
        storyFile.close();

        cout << updated_story;
    }



    void taking_inputs() {
        int ch;
       // Prompt for adjectives
        cout << "Do you want use adjectives from word bank or do you want to use your own words" << endl;
        cout << "Please enter 1 for word bank." << endl << "2 for own words" << endl;
        cin >> ch;
        if (ch == 1) {
            for (int i = 0; i < adjectives.size(); i++)
            {
                cout << i + 1 << "." << adjectives.at(i) << endl;
            }
            cout << "Please enter 2 corresponding number from the word bank of the words you want to use" << endl;
            int n1, n2;
            cin >> n1 >> n2;
            adj1 = adjectives.at(n1-1);
            adj2 = adjectives.at(n2-1);
            
        }
        else {
            // Prompt the user to enter their words
            cout << "Please enter 2 adjectives: " << endl;
            cin >> adj1 >> adj2;
        }
        cout << "Do you want use nouns from word bank or do you want to use your own words" << endl;
        cout << "Please enter 1 for word bank." << endl << "2 for own words" << endl;

        cin >> ch;
        if (ch == 1) {
            for (int i = 0; i < nouns.size(); i++)
            {
                cout << i + 1 << "." << nouns.at(i) << endl;
            }
            cout << "Please enter 2 corresponding number from the word bank of the words you want to use" << endl;
            int n1, n2;
            cin >> n1 >> n2;
            noun1 = nouns.at(n1-1);
            noun2 = nouns.at(n2-1);

        }
        else {
            // Prompt the user to enter their words
            cout << "Please enter 2 nouns: " << endl;
            cin >> noun1 >> noun2;
        }

        // Prompt for verbs
        cout << "Do you want use verbs from word bank or do you want to use your own words" << endl;
        cout << "Please enter 1 for word bank." << endl << "2 for own words" << endl;

        cin >> ch;
        if (ch == 1) {
            for (int i = 0; i < verbs.size(); i++)
            {
                cout << i + 1 << "." << verbs.at(i) << endl;
            }
            cout << "Please enter 2 corresponding number from the word bank of the words you want to use" << endl;
            int n1, n2;
            cin >> n1 >> n2;
            verb1 = verbs.at(n1-1);
            verb2 = verbs.at(n2-1);

        }
        else {
            // Prompt the user to enter their words
            cout << "Please enter 2 verbs: " << endl;
            cin >> verb1 >> verb2;
        }

        // Prompt for places
        cout << "Do you want use places from word bank or do you want to use your own words" << endl;
        cout << "Please enter 1 for word bank." << endl << "2 for own words" << endl;

        cin >> ch;
        if (ch == 1) {
            for (int i = 0; i < places.size(); i++)
            {
                cout << i + 1 << "." << places.at(i) << endl;
            }
            cout << "Please enter 2 corresponding number from the word bank of the words you want to use" << endl;
            int n1, n2;
            cin >> n1 >> n2;
            place1 = places.at(n1-1);
            place2 = places.at(n2-1);

        }
        else {
            // Prompt the user to enter their words
            cout << "Please enter 2 places: " << endl;
            cin >> place1 >> place2;
        }
   

        int storyChoice;
        // Prompt the user to choose a story
        cout << "Please choose a story: " << endl;
        cout << "Type '1' for Mystery: " << endl;
        cout << "Type '2' for Romance" << endl;
        cout << "Type '3' for Comedy" << endl;
        cout << "Type '4' for Horror" << endl;
        cin >> storyChoice;

        // Display the story with the user's input
        if (storyChoice == 1) {
            cout << "Here is the selected story with your input:" << endl;
            mysteryStory();
        }
        else if (storyChoice == 2) {
            cout << "Here is the selected story with your input:" << endl;
            romanceStory();
        }
        else if (storyChoice == 3) {
            cout << "Here is the selected story with your input:" << endl;
            comedyStory();
        }
        else if (storyChoice == 4) {
            cout << "Here is the selected story with your input:" << endl;
            horrorStory();
        }
        else {
            cout << "Please enter a valid selection" << endl;
        }

    }
    void making_changes() {
        char decision = 'Y'; // initialize decision to 'Y' to start the loop
        while (decision == 'Y') {
            cout << "Do you want to make any changes? Please enter 'Y' for yes and 'N' for no." << endl;
            cin >> decision;
            if (decision == 'Y') {
                cout << "Which word do you want to change?" << endl;
                cout << "Type '1' to change adjective 1." << endl;
                cout << "Type '2' to change adjective 2." << endl;
                cout << "Type '3' to change noun 1." << endl;
                cout << "Type '4' to change noun 2." << endl;
                cout << "Type '5' to change verb 1." << endl;
                cout << "Type '6' to change verb 2." << endl;
                cout << "Type '7' to change place 1." << endl;
                cout << "Type '8' to change place 2." << endl;
                int choice;
                cin >> choice;
                switch (choice) {
                case 1:
                    cout << "Please enter the new adjective 1: " << endl;
                    cin >> adj1;
                    break;
                case 2:
                    cout << "Please enter the new adjective 2: " << endl;
                    cin >> adj2;
                    break;
                case 3:
                    cout << "Please enter the new noun 1: " << endl;
                    cin >> noun1;
                    break;
                case 4:
                    cout << "Please enter the new noun 2: " << endl;
                    cin >> noun2;
                    break;
                case 5:
                    cout << "Please enter the new verb 1: " << endl;
                    cin >> verb1;
                    break;
                case 6:
                    cout << "Please enter the new verb 2: " << endl;
                    cin >> verb2;
                    break;
                case 7:
                    cout << "Please enter the new place 1: " << endl;
                    cin >> place1;
                    break;
                case 8:
                    cout << "Please enter the new place 2: " << endl;
                    cin >> place2;
                    break;
                default:
                    cout << "Please enter a valid choice." << endl;
                    break;
                }
                opening_file(file_name);
            }
            else if (decision == 'N') {
                cout << "Thank you for playing our game. See you soon!" << endl;
                break;
            }
            else {
                cout << "Please enter a valid choice." << endl;
            }
        }
    }

};

int main() {
    Story ss; // Creating a class object
    // Calling the methods of the class
    ss.taking_inputs();
    ss.making_changes();
    return 0;
}