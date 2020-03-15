#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include "Intersect.h"
using namespace std;

int main(int argc, char* argv[])
{
    FILE* stream;
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'o') {
            freopen_s(&stream, argv[i + 1], "w", stdout);
        }
        if (argv[i][0] == '-' && argv[i][1] == 'i') {
            freopen_s(&stream, argv[i + 1], "r", stdin);
        }
    }
    Intersect s;
    s.readdata("in.txt");
    s.calculate();
    cout << s.result() << endl;
    fclose(stdin);
    fclose(stdout);
}

