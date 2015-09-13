#include <iostream>
#include <string>
#include <map>
#include <list>

#include <boost/foreach.hpp>

using namespace std;

typedef list<string>            StringList;
typedef map<string, bool>       BlackMap;

int main()
{
    // complete list of lines (reversed)
    StringList history;

    // mark seen lines here
    BlackMap blackmap;

    // read the input line/by/line
    string line;
    while (getline(cin, line)) {
        history.push_front(line);
    }

    // remove duplicite lines
    for (StringList::iterator it = history.begin();
         it != history.end(); )
    {
        if (!blackmap[*it]) {
            // this line was seen firstly!
            blackmap[*it] = true;
            it++;
            continue;
        }

        // remove this line, it was there already
        it = history.erase(it);
    }

    BOOST_REVERSE_FOREACH(string line, history) {
        cout << line << endl;
    }
}
