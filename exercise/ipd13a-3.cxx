#include "ipd13a-3.hxx"

namespace ipd {

/*
 * Since we aren't in a header here, this Using-declaration only
 * affects this file. For more on Using-declarations, see
 * <https://en.cppreference.com/w/cpp/language/using_declaration>
 *
 * (You can K-click the link above in CLion to open it in a browse,
 * where for X is Command on Mac, and [let me know] on Windows.)
 */
using std::swap;


bool sort_refs(int& a, int& b)
{

        if(a > b)
        {
            swap(a, b);
            return true;
        }
        return false;

}
    bool sort_refs(int& a, int& b, int& c)
    {
    if(a > b || a > c || b > c) {
        if (a > c) {
            swap(a, c);
        }
        if (a > b) {
            swap(a, b);
        }
        if (b > c) {
            swap(b, c);
        }
        return true;
    }
            // can do this also its simple
            //bool changes = false;
            //changes = sort_refs(a, c);
            //changes |= sort_refs(a, b);
            //changes |= sort_refs(b, c);
            //return changes;
    return false;
    }
}
