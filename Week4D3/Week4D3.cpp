
#include <iostream>
#include <thread>

using namespace std;

//Heap
static int HeapInt = 0;

//Stack
void HelloWorldThread() {
    cout << "Hello World Thread!" << endl;
}

int main()
{
    HeapInt = 5;
    cout << "Hello World!" << endl;
    HelloWorldThread();
    //std::thread Hello(HelloWorldThread);
    return 0;
}
