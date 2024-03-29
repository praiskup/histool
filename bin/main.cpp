#include <iostream>
#include <string>
// TODO: move (conditionally) to unordered_set
#include <set>
#include <list>

#include <boost/foreach.hpp>

using namespace std;

typedef list<string>            StringList;
typedef set<string>             DenyList;

int main()
{
    // full (reversed) history file
    StringList history;

    // mark seen lines here
    DenyList denylist;

    // read the input line-by-line
    string line;
    while (getline(cin, line)) {
        history.push_front(line);
    }

    // go through history bottom-top way
    for (StringList::iterator it = history.begin();
         it != history.end(); )
    {
        if (denylist.find(*it) == denylist.end()) {
            // this line has been seen firstly!
            denylist.insert(*it);
            it++;
            continue;
        }

        // remove this line, it's already in history
        it = history.erase(it);
    }

    BOOST_REVERSE_FOREACH(string line, history) {
        cout << line << endl;
    }
}
