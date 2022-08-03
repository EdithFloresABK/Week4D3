
#include <iostream>
#include <thread>

using namespace std;

//Stack
void HelloWorldThread() {
    cout << "Hello World Thread!" << endl;
}

int main()
{
    cout << "Hello World!" << endl;
    std::thread Hello(HelloWorldThread);
    Hello.join();
    return 0;
}
