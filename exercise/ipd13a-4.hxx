#pragma once

#include <vector>
#include <algorithm>
#include <iterator>

namespace ipd
{


// A shorter name for a long-ish type name:
using Int_vec = std::vector<int>;


// Replaces each element of the given vector with the prefix sum up to
// and including itself.
//
// Example:
//
//     Int_vec v {1, 2, 3, 5, 7};
//     sum_prefixes(v);
//     CHECK( v == Int_vec{1, 3, 6, 11, 18});
//
void sum_prefixes(Int_vec& in_place);


// Undoes the effect of `sum_prefixes`.
//
// Example:
//
//     Int_vec v {1, 3, 6, 11, 18};
//     unsum_prefixes(v);
//     CHECK( v == Int_vec{1, 2, 3, 5, 7});
//
void unsum_prefixes(Int_vec& in_place);


// Extends `dst` with the prefix sum of `src`.
//
// Examples:
//
//     Int_vec v1 {2, 4, 6};
//     Int_vec v2;
//     sum_prefixes_into(v2, v1);
//     unsum_prefixes(v2);
//     CHECK( v1 == v2 );
//
//     sum_prefixes_into(v2, v1);
//     CHECK( v1 == Int_vec{2, 4, 6} );
//     CHECK( v2 == Int_vec{2, 4, 6, 2, 6, 12} );

void sum_prefixes_into(
        Int_vec&       dst,
        Int_vec const& src);


// Determines whether `summed` contains the prefix sums of `unsummed`.
//
// Examples:
//
//  - contains_prefix_sums(Int_vec{1, 2, 3}, Int_vec{1, 1, 1}) is true
//  - contains_prefix_sums(Int_vec{1, 2, 3}, Int_vec{0, 0, 5}) is false
//  - contains_prefix_sums(Int_vec{1, 2, 3}, Int_vec{1, 1})    is false
//
bool contains_prefix_sums(
        Int_vec const& summed,
        Int_vec const& unsummed);


} // end namespace ipd

