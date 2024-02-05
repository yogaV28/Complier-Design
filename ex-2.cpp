#include<iostream>
#include<conio.h>
using namespace std;

int main() {
    int a[10][10], i, j, ns, ni;

    system("cls");
    cout << "\nEnter the number of states\n";
    cin >> ns;
    cout << "\nEnter the number of inputs\n";
    cin >> ni;

    cout << "\nEnter the states\n";
    for (i = 0; i < ns; i++)
        cin >> a[i][0];

    for (i = 0; i < ns; i++) {
        for (j = 1; j <= ni; j++) {
            cout << "Enter the value for state a" << i << " for input " << j - 1 << "\n";
            cin >> a[i][j];
        }
    }

    cout << "The transition table is:\n";
    cout << "States";
    for (i = 0; i < ni; i++)
        cout << "\tInput" << i;

    cout << "\n";
    for (i = 0; i < ns; i++) {
        for (j = 0; j <= ni; j++) {
            cout << a[i][j] << "\t";
        }
        cout << "\n";
    }

    getch();
    return 0;
}

