#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <assert.h>
#include <stdio.h>
using namespace std;
void headLine(vector<string> list);
void printArray(vector<int> list);

int roundUp(int numToRound, int multiple);
int main()
{
    vector<string> prices{"10tl: https://www.g2a.com/steam-gift-card-10-tl-steam-key-turkey-i10000000258168", "20tl: https://www.g2a.com/steam-gift-card-20-tl-steam-key-turkey-i10000000258189?aid=13307834", "50tl: https://www.g2a.com/steam-gift-card-50-tl-steam-key-turkey-i10000000258166", "100tl: https://www.g2a.com/steam-gift-card-100-tl-steam-key-turkey-i10000000258165", "200tl: https://www.g2a.com/steam-gift-card-western-asia-200-tl-steam-key-for-tl-currency-only-i10000000258110#", "250tl: https://www.g2a.com/steam-gift-card-250-tl-turkey-i10000083400011"};

    double gamePriceLira = 15;
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
    gamePriceLira = roundUp(gamePriceLira,10);
    for (size_t i = 6; i != -1; i--)
    {
    cashagain:
        if (gamePriceLira >= steamGiftCardUsd[i][0])
        {
            usedCards.push_back(steamGiftCardUsd[i][0]);
            cout << gamePriceLira << " - " << steamGiftCardUsd[i][0] << " = " << gamePriceLira - steamGiftCardUsd[i][0] << endl;
            gamePriceLira = gamePriceLira - steamGiftCardUsd[i][0];
            if (gamePriceLira > steamGiftCardUsd[i][0])
            {
                goto cashagain;
            }

            if (gamePriceLira < 10 && gamePriceLira != 0)
            {
                usedCards.push_back(steamGiftCardUsd[0][0]);
            }
        }
        else if (gamePriceLira < 10 && gamePriceLira !=0)
        {
            usedCards.push_back(steamGiftCardUsd[0][0]);
            break;
        }
    }
    printArray(usedCards);
}
void printArray(vector<int> list)
{
    sort(list.begin(), list.end());

    cout << '[';
    for (int i = 0; i < list.size(); i++)
    {
        if (i == list.size() - 1)
        {
            cout << list[i];
            break;
        }
        cout << list[i] << ',';
    }
    cout << ']';
    cout << endl;
}
// void headLine(vector<string> list)
// {
//     cout << "+" << setw(7 + list[0].length()) << setfill('-') << "" << setw(7) << ""
//          << "+" << endl;
//     cout.fill(' ');
//     cout << '|' << setw(7) << "" << list[0] << setw(7) << ""
//          << "|" << endl;
//     cout << "+" << setw(7 + list[0].length()) << setfill('-') << "" << setw(7) << ""
//          << "+" << endl;
// }

// 1,000tl [300,300,300,100]

int roundUp(int numToRound, int multiple) 
{
    assert(multiple);
    return ((numToRound + multiple - 1) / multiple) * multiple;
}