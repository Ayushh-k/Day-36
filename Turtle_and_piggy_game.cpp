#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int playGame(vector<int> sequence)
{
    while (sequence.size() > 1)
    {
        for (int i = 0; i < sequence.size() - 1; ++i)
        {
            if (i % 2 == 0)
            {
                // Turtle's turn: maximize
                sequence[i] = max(sequence[i], sequence[i + 1]);
            }
            else
            {
                // Piggy's turn: minimize
                sequence[i] = min(sequence[i], sequence[i + 1]);
            }
        }
        sequence.pop_back();
    }
    return sequence[0];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> sequence(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> sequence[i];
        }

        cout << playGame(sequence) << endl;
    }

    return 0;
}
