#include <iostream>
#include <chrono>

int main(){
	std::cout << "Hellow World!!" << std::endl;
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t t = std::chrono::system_clock::to_time_t(now);
	std::cout << std::ctime(&t) << std::endl;
}
