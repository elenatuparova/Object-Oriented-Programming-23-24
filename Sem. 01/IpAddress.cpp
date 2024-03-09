#include <iostream>

union IpAddress {
	uint32_t address;
	unsigned char octets[4];
}; 

int main() {
	IpAddress myIp;

	myIp.address = 16777343;

	std::cout << (int)myIp.octets[0] << '.';
	std::cout << (int)myIp.octets[1] << '.';
	std::cout << (int)myIp.octets[2] << '.';
	std::cout << (int)myIp.octets[3] << std::endl;
}