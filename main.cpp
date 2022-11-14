#include <bits/stdc++.h>
#include "src/dictionary.hpp"
#include "src/dictionary.cpp"
#include "src/sequence.hpp"
#include "src/sequence.cpp"
using namespace std;

class IncorrectClass
{
};

int main()
{
    cout << "Testing sequence" << endl;
    try
    {
        cout << endl
             << "   Creating sequence with incorrect Key" << endl;
        try
        {
            Sequence<IncorrectClass, int> seq;
            cout << "   Failed to throw exception" << endl;
        }
        catch (const char *error)
        {
            cout << "   Success: " << error << endl;
        }

        cout << endl
             << "   Creating sequence with incorrect Info" << endl;
        try
        {
            Sequence<int, IncorrectClass> seq;
            cout << "   Failed to throw exception" << endl;
        }
        catch (const char *error)
        {
            cout << "   Success: " << error << endl;
        }

        cout << endl
             << "   Creating sequence with correct Key and Info" << endl;
        try
        {

            Sequence<int, int> seq;
            cout << "   Success" << endl;
        }
        catch (const char *error)
        {
            cout << "   Failed: " << error << endl;
        }

        Sequence<int, int> seq;

        cout << endl
             << "   Checking insert" << endl;
        try
        {
            cout << endl
                 << "       Insert in empty sequence" << endl;
            try
            {
                seq.insert(1, 1);
                cout << "       Success" << endl;
                assert(seq.size() == 1);
                assert(seq.has(1));
                assert(seq[1] == 1);
            }
            catch (const char *error)
            {
                cout << "       Failed: " << error << endl;
            }

            cout << endl
                 << "       Insert in the end" << endl;
            try
            {
                seq.insert(2, 2);
                cout << "       Success" << endl;
                assert(seq.size() == 2);
                assert(seq.has(2));
                assert(seq[2] == 2);
            }
            catch (const char *error)
            {
                cout << "       Failed: " << error << endl;
            }

            cout << endl
                 << "       Insert with  non-unique key" << endl;
            try
            {
                seq.insert(1, 3);
                cout << "       Success" << endl;
                assert(seq.size() == 3);
                assert(seq.has(1));
                assert(seq[1] == 1);
                assert(seq(1, 1) == 3);
            }
            catch (const char *error)
            {
                cout << "       Failed: " << error << endl;
            }

        }
        catch (const char *error)
        {
            cout << "   Failed: " << error << endl;
        }
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }
}