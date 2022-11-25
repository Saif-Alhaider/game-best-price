#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
void printArray(vector<int> list);
double leastPriceUsd(double gamePriceLira);
// void printArray(auto *usedlist, int sizeOfList);
int main()
{
    string gameTitle;
    double steamPriceLira;
    double g2aGamePriceUsd;
    double g2aGameGlobalKeyPrice;
    //{{tl card,price in usd}}

    cout << "please enter the game title: ";
    cin >> gameTitle; // cyberpunk 2077
    cout << "Enter " + gameTitle << " price in steam in lira: ";
    cin >> steamPriceLira; // 124,50 tl
    leastPriceUsd(steamPriceLira);
    cout << "Enter " + gameTitle << " global key price in g2a in usd: ";
    cin >> g2aGameGlobalKeyPrice; // 33.92 usd
}

double leastPriceUsd(double gamePriceLira)
{
    double steamGiftCardUsd[7][2] = {
        {10, 1.33},
        {20, 2.01},
        {50, 3.95},
        {100, 7.39},
        {200, 14.83},
        {250, 17.90},
        {300, 21.96},
    };
    vector<int> usedCards;
    for (size_t i = 6; i != 0; i--)
    {
        if (gamePriceLira > steamGiftCardUsd[i][0])
        {
            cout << gamePriceLira<<" - " << steamGiftCardUsd[i][0] << " = " << gamePriceLira - steamGiftCardUsd[i][0]<<endl;
        gamePriceLira = gamePriceLira - steamGiftCardUsd[i][0];
        }
    }
    cout << string(100, '-') << endl;
    // cout<<gamePriceLira;
    // printArray(usedCards);
    return 0;
}

void printArray(vector<int> list)
{
    cout << '[';
    for (auto const &i : list)
    {
        if (i == list[list.size() - 1])
            cout << i;
        else
            cout << i << ',';
    }
    cout << ']';
    cout << endl;
}