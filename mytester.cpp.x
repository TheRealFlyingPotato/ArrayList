#include "arraylist.h"
using namespace std;

int main()
{
    ArrayList<string> l1;
    bool n = 0;
    string name[] = {"b","a","t","m","a","n"};

    for (int k = 0; k < 6; k++)
        l1.insert(name[k], k);
    cout << l1 << endl;

    //insert tester
    n=0;
    if (n)
    {
      l1.insert("LAST", 0);
      l1.insert("1234", l1.size());
      cout << l1 << endl;
      l1.insert("lol", l1.size() + 1);
      l1.insert("XD", -1);
    }

    //first() test
    n=1;
    if (n)
    {
      ArrayList<int> l2;
      cout << l1.first() << endl;
      cout << l2.first() << endl;
      l1.clear();
      l1.first();
    }

    //insert_back test
    n = 0;
    if (n)
    {
      string asdf[] = {"u","r","m","o","m"}; //len = 5
      for (int k = 0; k < 5; k++)
        l1.insert_back(asdf[k]);
      cout << l1 << endl;
    }

    // operator[] test
    n = 0;
    if (n)
    {
    cout << "1\n";
    l1[2] = "YOLO2";
    cout << "2\n";
    l1[l1.size()] = "YOLO";
    cout << "3\n";
    l1[-1] = "YOLO";
    cout << "4\n";
    l1[0] = "YOLO";
    cout << "5\n";
    cout << l1[0] << endl; 
    cout << "6\n";
    cout << l1 [4] << endl;
    cout << "7\n";
    cout << l1[l1.size()] << endl; ////////////////////
    cout << "8\n";
    cout << l1[-4] << endl;
    cout << l1;
    }

    // find test
    n = 0;
    if (n)
    {
        cout << endl << "### FIND TEST: End input :: q" << endl;
        string inp;
        do
        {
            cin >> inp;
            cout << "loc: "<< l1.find(inp) << endl;
            cout << l1 << endl;
        } while (inp != "q");
        cin >> inp;
    }
    //swap test
    n = 0;
    if (n)
    {
      l1.swap(0,1);
      cout << l1 << endl;
      l1.swap(2,3);
      cout << l1 << endl;
      l1.swap(-1,0);
      cout << l1 << endl;
      l1.swap(0,900);
      cout << l1 << endl;
    }

    //append test
    n = 0;
    if (n)
    {
      ArrayList<string> l2;
      string face[] = {"a","b","c","d","e"}; //len = 5
      for (int k = 0; k < 5; k++)
        l2.insert_back(face[k]);
      l1.append(l2);
      cout << l1 << endl;
    }

    //remove test
    n = 0;
    if (n)
    {
      ArrayList<string> l2;
      string face[] = {"a","b","c","d","e"}; //len = 5
      for (int k = 0; k < 5; k++)
        l2.insert_back(face[k]);
      l1.append(l2); l1.append(l2); l1.append(l2); l1.append(l2); l1.append(l2); l1.append(l2); l1.append(l2); l1.append(l2); l1.append(l2); l1.append(l2); l1.append(l2); l1.append(l2); 

      while (l1.size() > 0)
      {
        l1.remove(0);
        cout << "s/m/l: " << l1.size() << "/" << l1.max() << l1 << endl;
      }
      l1.remove(0);
        cout << "s/m/l: " << l1.size() << "/" << l1.max() << l1 << endl; l1.remove(0);
        cout << "s/m/l: " << l1.size() << "/" << l1.max() << l1 << endl; l1.remove(0);
        cout << "s/m/l: " << l1.size() << "/" << l1.max() << l1 << endl; l1.remove(0);
        cout << "s/m/l: " << l1.size() << "/" << l1.max() << l1 << endl; l1.remove(0);
        cout << "s/m/l: " << l1.size() << "/" << l1.max() << l1 << endl;
      cout << "remove @ -1 :"; l1.remove(-1); cout << endl;
    }

    //resize test
    n=0;
    if (n)
    {
      l1.resize(3, "nothing");
      cout << l1 << endl;
      l1.resize(20, "bacon");
      cout << l1 << endl;
    }

    //operator= test
    n=0;
    if (n)
    {
      ArrayList<string> l2;
      l2.resize(5, "l2");
      ArrayList<string> l3;
      cout << "l2" << l2 << endl << "l3" << l3 << endl;
      l1 = l2;
      cout << "l1 = l2::" << l1 << endl;
      l3 = l1;
      cout << "l3 = l1::" << l3 << endl;      

    }

    //cpy constructor test
    n=0;
    if (n)
    {
      ArrayList<string> l2(l1);
      l2.resize(10, "0");
      cout << l2 << endl;
    }

    return 0;
}