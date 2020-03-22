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
    FILE* fp;
    int file = 0;
    char shit = '\0';
    char* NAME = &shit;
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][1] == 'o') {
            freopen_s(&fp, argv[i + 1], "w", stdout);
        }
        if (argv[i][0] == '-' && argv[i][1] == 'i') {
            file = 1;
            NAME = argv[i + 1];
        }
    }
    Intersect s;
    if (file == 0) {
        s.readdata();
    }
    else {
        s.readdata_File(NAME);
    }
    s.calculate();
    cout << s.result() << endl;
    fclose(stdout);
}

