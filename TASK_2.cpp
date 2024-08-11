#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char opr;
    double result;
    char choice;
    
    cout<< "****************************************\n"
        << "     !!Welcome to the Calculator!!    \n"
        << "****************************************\n";
    do{   
        cout<< "\nChoose an OPERATIONS:\n"
            << " + : Addition\n"
            << " - : Subtraction\n"
            << " * : Multiplication\n"
            << " / : Division\n"
            << " % : Modulus (integer division)\n"
            << "Enter the operation (+, -, *, /, %): ";
        cin>> opr;

        cout<< "Enter the First Number: ";
        cin>> num1;

        cout<< "Enter the second number: ";
        cin>> num2;

        switch (opr) {
            case '+':
                result= num1 + num2;
                cout<< "Result: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case '-':
                result= num1 - num2;
                cout<< "Result: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case '*':
                result= num1 * num2;
                cout<< "Result: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case '/':
                if (num2 != 0) {
                    result= num1 / num2;
                    cout<< "Result: " << num1 << " / " << num2 << " = " << result << endl;
                } 
                else {
                    cout<< "Error: Division by Zero is not allowed!!!" << endl;
                }
                break;

            case '%':
                if (static_cast<int>(num2) != 0) {//static_cast is a C++ operator used for type conversion
                    result= static_cast<int>(num1) % static_cast<int>(num2);
                    cout<< "Result: " << static_cast<int>(num1) << " % " << static_cast<int>(num2) << " = " << result << endl;
                } 
                else {
                    cout<< "Error: Division by zero is not allowed!" << endl;
                }
                break;
            default:
                cout<< "Error: Invalid Operation selected!" << endl;
        }
        cout<< "Do you want to perform another Calculation?(y/n): ";
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');

    cout<< "\n****************************************\n";
    cout<< "   Thank you for using the Calculator!!\n";
    cout<< "****************************************\n";

    return 0;
}
