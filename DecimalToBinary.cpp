//#include<iostream>
//#include<math.h>
//using namespace std;
//int main(){
//	int n;
//	cin>>n;
//	int ans=0;
//	int i=0;
//	while(n!=0){
//		int bit=n&1;
//		ans=(bit*pow(10,i))+ans;
//		n=n>>1;
//		i++;
//	}
//	cout<< ans;
//}
#include <iostream>
using namespace std;
int main() {
    int decimalNumber;
    std::cout << "Enter a negative decimal number: ";
    std::cin >> decimalNumber;

    if (decimalNumber == 0) {
        std::cout << "Binary representation: 0" << std::endl;
        return 0;
    }

    int binaryNumber[32];  // Assuming int is 32 bits

    int i = 0;
    while (decimalNumber != 0) {
        binaryNumber[i] = decimalNumber % 2;
        decimalNumber /= 2;
        i++;
    }

    std::cout << "Binary representation: ";
    for (int j = i - 1; j >= 0; j--) {
        std::cout << binaryNumber[j];
    }
    std::cout << std::endl;

    return 0;
}


