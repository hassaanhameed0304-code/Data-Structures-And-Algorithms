#include <iostream>
using namespace std;

int main(void){
    float ali[] = {3.66, 3.33, 4.0, 3.0, 2.66};
    float hiba[] = {3.33, 3.0, 3.66, 3.0};
    float asma[] = {4.0, 3.66, 2.66};
    float zain[] = {2.66, 2.33, 4.0};
    float faisal[] = {3.33, 3.66, 4.0, 3.0, 3.33};
	float sum;
	sum = 0;
    for (int i = 0; i < 5; i++)
        sum += ali[i];

    cout << "Ali GPA = " << sum / 5 << endl;

    sum = 0;
    for (int i = 0; i < 4; i++)
        sum += hiba[i];

    cout << "Hiba GPA = " << sum / 4 << endl;

    sum = 0;
    for (int i = 0; i < 3; i++)
        sum += asma[i];

    cout << "Asma GPA = " << sum / 3 << endl;

    sum = 0;
    for (int i = 0; i < 3; i++)
        sum += zain[i];

    cout << "Zain GPA = " << sum / 3 << endl;

    sum = 0;
    for (int i = 0; i < 5; i++)
        sum += faisal[i];

    cout << "Faisal GPA = " << sum / 5 << endl;

    return 0;
}