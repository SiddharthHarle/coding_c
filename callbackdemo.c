#include <stdio.h>

// Define a function pointer type for the callback
typedef void (*CallbackFunction)(int);

// Function that will be used as a callback
void myCallback(int data) {
    printf("Callback called with data: %d\n", data);
}

void myCallback1(int data) {
    printf("Callback1 called with data: %d\n", data);
}

// Function that registers and calls the callback
void registerCallback(CallbackFunction callback, int value) {
    printf("Registering callback...\n");
    if (callback != NULL) {
        callback(value);  // Invoke callback
    }
}

int main() {
    // Register and execute the callback
    registerCallback(myCallback, 42);
    registerCallback(myCallback1, 55);
    return 0;
}
