#pragma once

#include <utility>  /* for std::swap */


/*
 * Defining your functions (and structs, etc.) in a namespace means
 * that their names don't have to be globally unique. Instead, they
 * can coexist with other functions (etc.) with the same names but
 * in different namespaces.
 *
 * We'll define our functions (etc.) in the namespace `ipd`.
 */
namespace ipd {

// Sorts `a` and `b` such that `a <= b`.
//
// That is, this function swaps `a` with `b` if `a > b`. Returns `true` if
// swapping was necessary or `false` if the order was already correct.
bool sort_refs(int& a, int& b);


// Sorts `a`, `b`, and `c` such that `a <= b` && `b <= c`. Returns `true` if any
// swapping was necessary or `false` if the order was already correct.
bool sort_refs(int& a, int& b, int& c);


// Sorts `a`, `b`, and `c` such that `a <= b` && `b <= c`. Returns `true` if
// swapping was necessary or `false` if the order was already correct.
template <class T>
bool sort_refs(T& a, T& b, T& c) {
        /*
         * Brings std::swap into scope locally inside this function. (Doing it in
         * here is means we don't pollute clients' namespaces with things they
         * didn't ask for.)
         */
        using std::swap;
        if(a > b || a > c || b > c) {
            if (a > c) {
                std::swap(a, c);
            }
            if (a > b) {
                std::swap(a, b);
            }
            if (b > c) {
                std::swap(b, c);
            }
            return true;
        }
        return false;
    }
} // end namespace ipd