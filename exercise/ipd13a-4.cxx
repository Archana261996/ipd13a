#include "ipd13a-4.hxx"

namespace ipd
{


void sum_prefixes(Int_vec& in_place)
{
    for(ssize_t i = 1; i < in_place.size(); ++i) {
        in_place[i] = in_place[i] + in_place[i - 1];
    }

}


void unsum_prefixes(Int_vec& in_place)
{
    for(ssize_t i=in_place.size() - 1; i > 0 ; --i) {
           in_place[i] = in_place[i] - in_place[i - 1];
    }
}


void sum_prefixes_into(Int_vec& dst, Int_vec const& src)
{
    Int_vec v2 = src;
    sum_prefixes(v2);
    for(int i : v2)
        dst.push_back(i);
}


bool contains_prefix_sums(Int_vec const& summed, Int_vec const& unsummed)
{
     Int_vec temp = summed;

    unsum_prefixes(temp);

  if(temp == unsummed)
      return true;
  else
      return false;

}


} // end namespace ipd
