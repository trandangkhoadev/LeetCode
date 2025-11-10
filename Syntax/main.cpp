#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Sleeping for 2s...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Done!\n";
}