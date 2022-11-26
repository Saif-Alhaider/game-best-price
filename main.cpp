#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

#include "./currency functions/currency_functions.cpp"
#include "./currency functions/currency_functions.h"

#include "./styling/styling.cpp"
#include "./styling/styling.h"

#include "giftCards/steam gift cards/gameLeastPrice.h"
#include "giftCards/steam gift cards/gameLeastPrice.cpp"
void gameLeastPrice();

int main()
{
    int answer;
    headLine("please select what gift card you want to buy");
    cout << "1. Steam Gift Card" << endl
         << "2. Least Price Steam Game (buying steam key or gift card)" << endl
         << "3. Netflix Gift Card" << endl
         << "4. Xbox Game Pass Gift Card"<<endl;
    cin >> answer;
    if(answer == 1)
    gameLeastPrice();
}
