
#include <iostream>
#include <thread>

using namespace std;

bool DidQuit = false;
int ThreadVar = 0;
int ThreadVar2 = 0;

void HelloWorldThread() {

    while(!DidQuit) {
        ThreadVar++;

        if (ThreadVar > 1000) {
            ThreadVar = 0;
        }
    }
}
void HelloWorldThread2() {

    while (!DidQuit) {
        ThreadVar2++;

        if (ThreadVar2 > 3000) {
            ThreadVar2 = 0;
        }
    }
}

int main()
{
    cout << "Hello World!" << endl;

    char UserInput;
    std::thread Hello(HelloWorldThread);
    std::thread Hello2(HelloWorldThread2);
    while (!DidQuit) {
        cout << "Enter any key to display counter " << endl;
        cout << "q to quit " << endl;
        cin >> UserInput;
        DidQuit = (UserInput == 'q');
        cout << "ThreadVar: " << ThreadVar << endl;
        cout << "ThreadVar2: " << ThreadVar2 << endl;
    }
    Hello.join();
    Hello2.join();

    return 0;
}
