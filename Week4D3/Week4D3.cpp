
#include <iostream>
#include <thread>

using namespace std;

bool DidQuit = false;
bool ShouldDecrementLife = false;

struct Character {
    float Position = 0.0f;
    int Score = 0;
    int Lives = 1;

    void DisplayStats() {
        cout << "Lives: " << Lives << endl;
    }
};

Character Player;
void UpdateCharacter1() {
    while (!DidQuit) {
        if (ShouldDecrementLife) {
            if (Player.Lives>0) {

                //this_thread::sleep_for(chrono::milliseconds(500);
                //std::thirs_thread::yield();
                --Player.Lives;
            }
        }
    }
}
void UpdateCharacter2() {
    while (!DidQuit) {
        if (ShouldDecrementLife) {
            if (Player.Lives > 0) {

                //this_thread::sleep_for(chrono::milliseconds(500);
                //std::thirs_thread::yield();
                --Player.Lives;
            }
        }
    }
}

void ProcessInput() {
    while (!DidQuit) {
        cout << "'a' to decremenet player life" << endl;
        cout << "'d' to display player stats" << endl;
        cout << "'q' to quit" << endl;
        char UserInput;
        cin >> UserInput;

        switch (UserInput) {
        case'a':
            ShouldDecrementLife = true;
            break;
        case 'd':
            Player.DisplayStats();
            break;
        case 'q':
            DidQuit = true;
            break;
        default:
            break;
        }

        DidQuit = (UserInput == 'q');
    }
}

int main()
{
    std::thread InputHandler(ProcessInput);
    std::thread CharacterUpdate1(UpdateCharacter1);
    std::thread CharacterUpdate2(UpdateCharacter2);

    InputHandler.join();
    CharacterUpdate1.join();
    CharacterUpdate2.join();

    return 0;
}
