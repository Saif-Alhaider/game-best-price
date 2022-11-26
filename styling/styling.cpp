#include <iostream>
#include <assert.h>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
void printArray(vector<int> list)
{
    sort(list.begin(), list.end());

    cout << '[';
    for (int i = 0; i < list.size(); i++)
    {
        if (i == list.size() - 1)
        {
            cout << list[i]<<"tl";
            break;
        }
        cout << list[i] <<"tl"<< ',';
    }
    cout << ']';
    cout << endl;
}

void headLine(string title)
{
    cout << "+" << setw(7 + title.length()) << setfill('-') << "" << setw(7) << ""
         << "+" << endl;
    cout.fill(' ');
    cout << '|' << setw(7) << "" << title << setw(7) << ""
         << "|" << endl;
    cout << "+" << setw(7 + title.length()) << setfill('-') << "" << setw(7) << ""
         << "+" << endl;
}


void giftCard()
{
    vector<string> prices{"10tl: https://www.g2a.com/steam-gift-card-10-tl-steam-key-turkey-i10000000258168", "20tl: https://www.g2a.com/steam-gift-card-20-tl-steam-key-turkey-i10000000258189?aid=13307834", "50tl: https://www.g2a.com/steam-gift-card-50-tl-steam-key-turkey-i10000000258166", "100tl: https://www.g2a.com/steam-gift-card-100-tl-steam-key-turkey-i10000000258165", "200tl: https://www.g2a.com/steam-gift-card-western-asia-200-tl-steam-key-for-tl-currency-only-i10000000258110#", "250tl: https://www.g2a.com/steam-gift-card-250-tl-turkey-i10000083400011"};
    headLine("steam gift cards in g2a site");
    auto longestWord = max_element(prices.begin(), prices.end(),
                                   [](const auto &a, const auto &b)
                                   {
                                       return a.size() < b.size();
                                   });
    auto longestWord2 = *longestWord;
    for (size_t i = 0; i < prices.size(); i++)
    {
        cout << "+" << setw(7 + longestWord2.length()) << setfill('-') << "" << setw(7) << ""
             << "+" << endl;
        cout.fill(' ');
        cout << '|' << setw(7) << "" << prices[i] << setw((longestWord2.length() - prices[i].length()) + 7) << ""
             << "|" << endl;
    }
    cout << "+" << setw(7 + longestWord2.length()) << setfill('-') << "" << setw(7) << ""
         << "+" << endl;
}