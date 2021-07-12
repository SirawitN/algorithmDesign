#include <iostream>

using namespace std;

void genBarcode(string text, int a, int b)
{
    if (text.length() == b)
    {
        if (a != 0)
            return;
        cout << text << "\n";
        return;
    }

    text.push_back('0');
    genBarcode(text, a, b);

    if (a != 0)
    {
        text.at(text.length() - 1) = '1';
        genBarcode(text, a - 1, b);
    }
}

int main()
{
    int A, B;
    string text = "";
    cin >> A >> B;
    genBarcode(text, A, B);
    return 0;
}

/*  test cases

5 5 : 11111

4 7 : 0001111 0010111 0100111 1000111 0011011 0101011 1001011 0110011 1010011 1100011 0011101 0101101 1001101 0110101 1010101 1100101 0111001 1011001
1101001 1110001 0011110 0101110 1001110 0110110 1010110 1100110 0111010 1011010 1101010 1110010 0111100 1011100 1101100 1110100 1111000

20 20 : 11111111111111111111

0 20 : 00000000000000000000

*/