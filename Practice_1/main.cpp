#include<Scrambler.h>

int main()
{
    Scrambler one;
    one.InputString();
    one.Encode();
    one.GetKey();
    one.Decode();
    one.GetKey();
    return 0;
}
