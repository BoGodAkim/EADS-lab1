#include <bits/stdc++.h>
#include "src/dictionary.hpp"
#include "src/sequence.hpp"

// #include "src/dictionary.cpp"
// #include "src/sequence.cpp"
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
        catch (const exception &e)
        {
            cout << "   Success: " << e.what() << endl;
        }

        cout << endl
             << "   Creating sequence with incorrect Info" << endl;
        try
        {
            Sequence<int, IncorrectClass> seq;
            cout << "   Failed to throw exception" << endl;
        }
        catch (const exception &e)
        {
            cout << "   Success: " << e.what() << endl;
        }

        cout << endl
             << "   Creating sequence with correct Key and Info" << endl;
        try
        {

            Sequence<int, int> seq;
            cout << "   Success" << endl;
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
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
                assert(seq.size() == 1);
                assert(seq.has(1));
                assert(seq[1] == 1);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Insert at the end" << endl;
            try
            {
                seq.insert(2, 2);
                assert(seq.size() == 2);
                assert(seq.has(2));
                assert(seq[2] == 2);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Insert at the beginning" << endl;
            try
            {
                seq.insert(3, 3, false);
                assert(seq.size() == 3);
                assert(seq.has(3));
                assert(seq[3] == 3);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Insert with  non-unique key" << endl;
            try
            {
                seq.insert(1, 3);
                assert(seq.size() == 4);
                assert(seq.has(1));
                assert(seq[1] == 1);
                assert(seq(1, 1) == 3);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Insert after some key" << endl;
            try
            {
                seq.insert(4, 4, 2);
                assert(seq.size() == 5);
                assert(seq.has(4));
                assert(seq[4] == 4);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Insert after non-existing key" << endl;
            try
            {
                seq.insert(4, 4, 5);
                cout << "       Failed to throw exception" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Success: " << e.what() << endl;
            }

            cout << endl
                 << "       Insert after some key with occurrence " << endl;
            try
            {
                seq.insert(5, 5, 1, 1);
                assert(seq.size() == 6);
                assert(seq.has(5));
                assert(seq[5] == 5);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Insert after some key with non-existing occurrence" << endl;
            try
            {
                seq.insert(6, 6, 1, 5);
                cout << "       Failed to throw exception" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Success: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Creating sequence with copy-constructor" << endl;
        try
        {
            Sequence<int, int> seq2(seq);
            assert(seq2.size() == 6);
            assert(seq2.has(1));
            assert(seq2[1] == 1);
            assert(seq2.has(2));
            assert(seq2[2] == 2);
            assert(seq2.has(3));
            assert(seq2[3] == 3);
            assert(seq2.has(4));
            assert(seq2[4] == 4);
            assert(seq2.has(5));
            assert(seq2[5] == 5);
            assert(seq2.occurrences(1) == 2);
            assert(seq2(1, 1) == 3);
            cout << "   Success" << endl;
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking operator[]" << endl;
        try
        {
            cout << endl
                 << "       Access to existing key" << endl;
            try
            {
                assert(seq[1] == 1);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Access to non-existing key" << endl;
            try
            {
                seq[6];
                cout << "       Failed to throw exception" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Success: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking operator()" << endl;
        try
        {
            cout << endl
                 << "       Access to existing key" << endl;
            try
            {
                assert(seq(1) == 1);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Access to non-existing key" << endl;
            try
            {
                seq(6, 1);
                cout << "       Failed to throw exception" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Success: " << e.what() << endl;
            }

            cout << endl
                 << "       Access to existing key with existing occurrence" << endl;
            try
            {
                assert(seq(1, 1) == 3);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Access to non-existing occurrence" << endl;
            try
            {
                seq(1, 5);
                cout << "       Failed to throw exception" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Success: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking operator==" << endl;
        try
        {
            cout << endl
                 << "       Comparing with same sequence" << endl;
            try
            {
                Sequence<int, int> seq2(seq);
                assert(seq == seq2);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Comparing with different sequence" << endl;
            try
            {
                Sequence<int, int> seq2;
                seq2.insert(1, 1);
                seq2.insert(2, 2);
                seq2.insert(3, 3);
                seq2.insert(4, 4);
                seq2.insert(5, 5);
                assert(!(seq == seq2));
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking occurrences" << endl;
        try
        {
            cout << endl
                 << "       Occurrences of existing key" << endl;
            try
            {
                assert(seq.occurrences(1) == 2);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Occurrences of non-existing key" << endl;
            try
            {
                assert(seq.occurrences(6) == 0);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking has" << endl;
        try
        {
            cout << endl
                 << "       Has existing key" << endl;
            try
            {
                assert(seq.has(1));
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Has non-existing key" << endl;
            try
            {
                assert(!seq.has(6));
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking size" << endl;
        try
        {

            assert(seq.size() == 6);
            seq.insert(0, 0);
            assert(seq.size() == 7);
            cout << "       Success" << endl;
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking remove" << endl;
        try
        {
            cout << endl
                 << "       Remove existing key" << endl;
            try
            {
                seq.remove(2);
                assert(seq.size() == 6);
                assert(!seq.has(2));
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Remove non-existing key" << endl;
            try
            {
                seq.remove(6);
                cout << "       Failed to throw exception" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Success: " << e.what() << endl;
            }

            cout << endl
                 << "       Remove existing key with existing occurrence" << endl;
            try
            {
                seq.remove(1, 1);
                assert(seq.size() == 5);
                assert(seq.occurrences(1) == 1);
                assert(seq[1] == 1);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Remove existing key with non-existing occurrence" << endl;
            try
            {
                seq.remove(1, 5);
                cout << "       Failed to throw exception" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Success: " << e.what() << endl;
            }

            cout << endl
                 << "       Remove first element" << endl;
            try
            {
                seq.remove(1);
                assert(seq.size() == 4);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Remove last element" << endl;
            try
            {
                seq.remove(0);
                assert(seq.size() == 3);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking Iterator" << endl;
        try
        {
            cout << endl
                 << "       Iterator constructor" << endl;
            try
            {
                seq.begin();
                seq.end();
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator copy constructor" << endl;
            try
            {
                auto it = seq.begin();
                Sequence<int, int>::Iterator it2(it);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator assignment operator" << endl;
            try
            {
                auto it = seq.begin();
                Sequence<int, int>::Iterator it2;
                it2 = it;
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator prefix operator++" << endl;
            try
            {
                auto it = seq.begin();
                assert((*it).first == 3);
                assert((*it).second == 3);
                ++it;
                assert((*it).first == 4);
                assert((*it).second == 4);
                ++it;
                assert((*it).first == 5);
                assert((*it).second == 5);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator postfix operator++" << endl;
            try
            {
                auto it = seq.begin();
                assert((*it).first == 3);
                assert((*it).second == 3);
                it++;
                assert((*it).first == 4);
                assert((*it).second == 4);
                it++;
                assert((*it).first == 5);
                assert((*it).second == 5);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator operator==" << endl;
            try
            {
                auto it = seq.begin();
                auto it2 = seq.begin();
                assert(it == it2);
                ++it;
                assert(!(it == it2));
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator operator!=" << endl;
            try
            {
                auto it = seq.begin();
                auto it2 = seq.begin();
                assert(!(it != it2));
                ++it;
                assert(it != it2);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator operator*" << endl;
            try
            {
                auto it = seq.begin();
                assert((*it).first == 3);
                assert((*it).second == 3);
                ++it;
                assert((*it).first == 4);
                assert((*it).second == 4);
                ++it;
                assert((*it).first == 5);
                assert((*it).second == 5);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    cout << endl
         << "Testing dictionary" << endl;
    try
    {
        Dictionary<int, int> dict;

        cout << endl
             << "   Checking constructor" << endl;
        try
        {
            cout << endl
                 << "       Default constructor" << endl;
            try
            {
                Dictionary<int, int> dict2;
                assert(dict2.size() == 0);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Constructor with incorrect Key" << endl;
            try
            {
                Dictionary<IncorrectClass, int> dict2;
                cout << "       Failed" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Success: " << e.what() << endl;
            }

            cout << endl
                 << "       Constructor with incorrect Value" << endl;
            try
            {
                Dictionary<int, IncorrectClass> dict2;
                cout << "       Failed" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Success: " << e.what() << endl;
            }

            cout << endl
                 << "       Copy constructor" << endl;
            try
            {

                Dictionary<int, int> dict2;
                dict2.insert(3, 3);
                dict2.insert(4, 4);
                dict2.insert(5, 5);
                Dictionary<int, int> dict3(dict2);
                assert(dict3.size() == 3);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking insert" << endl;
        try
        {
            cout << endl
                 << "       Insert with unique key" << endl;
            try
            {
                dict.insert(3, 3);
                dict.insert(4, 4);
                dict.insert(5, 5);
                assert(dict.size() == 3);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Insert with duplicate key" << endl;
            try
            {
                dict.insert(3, 3);
                cout << "       Failed" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Success: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking operator[]" << endl;
        try
        {
            cout << endl
                 << "       Get Info with key which already exist" << endl;
            try
            {
                assert(dict[3] == 3);
                assert(dict[4] == 4);
                assert(dict[5] == 5);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Insert with key which does not exist" << endl;
            try
            {
                dict[6] = 6;
                assert(dict[6] == 6);
                assert(dict[7] == 0);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking size" << endl;
        try
        {
            cout << endl
                 << "       Size of empty dictionary" << endl;
            try
            {
                Dictionary<int, int> dict2;
                assert(dict2.size() == 0);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Size of dictionary with 1 element" << endl;
            try
            {
                assert(dict.size() == 5);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking operator=" << endl;
        try
        {

            Dictionary<int, int> dict2;
            dict2 = dict;
            assert(dict2[3] == 3);
            assert(dict2[4] == 4);
            assert(dict2[5] == 5);
            assert(dict2[6] == 6);
            assert(dict2[7] == 0);
            assert(dict2.size() == 5);
            cout << "       Success" << endl;
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking remove" << endl;
        try
        {
            cout << endl
                 << "       Remove with key which does not exist" << endl;
            try
            {
                dict.remove(8);
                cout << "       Failed" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Success: " << e.what() << endl;
            }

            cout << endl
                 << "       Remove with key which exist" << endl;
            try
            {
                dict.remove(3);
                assert(dict.size() == 4);
                assert(!dict.has(3));
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking has" << endl;
        try
        {
            cout << endl
                 << "       Has with key which does not exist" << endl;
            try
            {
                assert(!dict.has(8));
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Has with key which exist" << endl;
            try
            {
                assert(dict.has(4));
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking Iterator" << endl;
        try
        {
            cout << endl
                 << "       Iterator constructor" << endl;
            try
            {
                dict.begin();
                dict.end();
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator copy constructor" << endl;
            try
            {
                auto it = dict.begin();
                Dictionary<int, int>::Iterator it2(it);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator assignment operator" << endl;
            try
            {
                auto it = dict.begin();
                Dictionary<int, int>::Iterator it2;
                it2 = it;
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator prefix operator++" << endl;
            try
            {
                auto it = dict.begin();
                assert((*it).first == 4);
                assert((*it).second == 4);
                ++it;
                assert((*it).first == 5);
                assert((*it).second == 5);
                ++it;
                assert((*it).first == 6);
                assert((*it).second == 6);
                ++it;
                assert((*it).first == 7);
                assert((*it).second == 0);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator postfix operator++" << endl;
            try
            {
                auto it = dict.begin();
                assert((*it).first == 4);
                assert((*it).second == 4);
                it++;
                assert((*it).first == 5);
                assert((*it).second == 5);
                it++;
                assert((*it).first == 6);
                assert((*it).second == 6);
                it++;
                assert((*it).first == 7);
                assert((*it).second == 0);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator operator==" << endl;
            try
            {
                auto it = dict.begin();
                auto it2 = dict.begin();
                assert(it == it2);
                ++it;
                assert(!(it == it2));
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator operator!=" << endl;
            try
            {
                auto it = dict.begin();
                auto it2 = dict.begin();
                assert(!(it != it2));
                ++it;
                assert(it != it2);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }

            cout << endl
                 << "       Iterator operator*" << endl;
            try
            {
                auto it = dict.begin();
                assert((*it).first == 4);
                assert((*it).second == 4);
                it++;
                assert((*it).first == 5);
                assert((*it).second == 5);
                it++;
                assert((*it).first == 6);
                assert((*it).second == 6);
                it++;
                assert((*it).first == 7);
                assert((*it).second == 0);
                cout << "       Success" << endl;
            }
            catch (const exception &e)
            {
                cout << "       Failed: " << e.what() << endl;
            }
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }

        cout << endl
             << "   Checking clear" << endl;
        try
        {
            dict.clear();
            assert(dict.size() == 0);
            assert(dict.begin() == dict.end());
            cout << "   Success" << endl;
        }
        catch (const exception &e)
        {
            cout << "   Failed: " << e.what() << endl;
        }
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }
}