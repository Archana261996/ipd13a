#include "ipd13a-4.hxx"
#include <catch.hxx>

using namespace ipd;


TEST_CASE("sum_prefixes")
{
    Int_vec v{1, 0, 0, 0, 0};

    sum_prefixes(v);
    REQUIRE(v == Int_vec{1, 1, 1, 1, 1});

    sum_prefixes(v);
    REQUIRE(v == Int_vec{1, 2, 3, 4, 5});

    sum_prefixes(v);
    REQUIRE(v == Int_vec{1, 3, 6, 10, 15});

    sum_prefixes(v);
    REQUIRE(v == Int_vec{1, 4, 10, 20, 35});
//===================================================
     Int_vec v1 {1, 2, 3, 5, 7};
     sum_prefixes(v1);
     CHECK( v1 == Int_vec{1, 3, 6, 11, 18});
     sum_prefixes(v1);
     CHECK( v1 == Int_vec{1, 4, 10, 21, 39});
     sum_prefixes(v1);
     CHECK( v1 == Int_vec{1, 5, 15, 36, 75});
//===================================================
     Int_vec v2 {0, 1, 0};
     sum_prefixes(v2);
     CHECK(v2 == Int_vec{0, 1, 1});
     sum_prefixes(v2);
     CHECK(v2 == Int_vec{0, 1, 2});
     sum_prefixes(v2);
     CHECK(v2 == Int_vec{0, 1, 3});
//===================================================
    Int_vec v3 {0, 0};
    sum_prefixes(v3);
    sum_prefixes(v3);
    CHECK(v3 == Int_vec{0, 0});
//===================================================
    Int_vec v4 {1};
    sum_prefixes(v4);
    CHECK(v4 == Int_vec{1});
//===================================================
    Int_vec v5 { };
    sum_prefixes(v5);
    CHECK(v5 == Int_vec{ });

}


TEST_CASE("unsum_prefixes_into")
{
    Int_vec v{1, 4, 10, 20, 35};

    unsum_prefixes(v);
    REQUIRE(v == Int_vec{1, 3, 6, 10, 15});

    unsum_prefixes(v);
    REQUIRE(v == Int_vec{1, 2, 3, 4, 5});

    unsum_prefixes(v);
    REQUIRE(v == Int_vec{1, 1, 1, 1, 1});

    unsum_prefixes(v);
    REQUIRE(v == Int_vec{1, 0, 0, 0, 0});
//===================================================
    Int_vec v1 = {1, 5, 15, 36, 75} ;
    unsum_prefixes(v1);
    CHECK( v1 == Int_vec {1, 4, 10, 21, 39});
    unsum_prefixes(v1);
    CHECK( v1 == Int_vec {1, 3, 6, 11, 18});
    unsum_prefixes(v1);
    CHECK( v1 == Int_vec{1, 2, 3, 5, 7});
//===================================================
    Int_vec v2 {0, 1, 3};
    unsum_prefixes(v2);
    CHECK(v2 == Int_vec{0, 1, 2});
    unsum_prefixes(v2);
    CHECK(v2 == Int_vec{0, 1, 1});
    unsum_prefixes(v2);
    CHECK(v2 == Int_vec{0, 1, 0});
//===================================================
    Int_vec v3 {0, 0};
    unsum_prefixes(v3);
    unsum_prefixes(v3);
    CHECK(v3 == Int_vec{0, 0});
//===================================================
    Int_vec v4 {1, 3, 6, 11, 18};
    unsum_prefixes(v4);
    CHECK( v4 == Int_vec{1, 2, 3, 5, 7});
}


TEST_CASE("sum_prefixes_into")
{
    Int_vec v1 {2, 4, 6};
    Int_vec v2;

    sum_prefixes_into(v2, v1);
    CHECK( v2 == Int_vec{2, 6, 12} );
    unsum_prefixes(v2);
    CHECK( v1 == v2 );

    sum_prefixes_into(v2, v1);
    CHECK( v1 == Int_vec{2, 4, 6} );
    CHECK( v2 == Int_vec{2, 4, 6, 2, 6, 12} );

    sum_prefixes_into (v1, v2);
    CHECK (v2 == Int_vec{2, 4, 6, 2, 6, 12} );
    CHECK (v1 == Int_vec{2, 4, 6, 2, 6, 12, 14, 20, 32});
//==========================================================
    Int_vec v3={1, 0, 0, 0};
    Int_vec v4;

    sum_prefixes_into(v4, v3);
    CHECK(v3 == Int_vec{1, 0, 0 ,0});
    CHECK(v4 == Int_vec{1, 1, 1 ,1});

    sum_prefixes_into(v4, v3);
    CHECK(v3 == Int_vec{1, 0, 0 ,0});
    CHECK(v4 == Int_vec{1, 1, 1 ,1, 1, 1, 1, 1});

    sum_prefixes_into(v3, v4);
    CHECK(v4 == Int_vec{1, 1, 1 ,1, 1, 1, 1, 1});
    CHECK(v3 == Int_vec{1, 0, 0 ,0, 1, 2, 3, 4, 5, 6, 7, 8});

}


TEST_CASE("contains_prefix_sums") {
    Int_vec v1{1, 1, 1, 2, 1};
    Int_vec v2{1, 2, 3, 5, 6};

    CHECK(contains_prefix_sums(v2, v1));
    CHECK_FALSE(contains_prefix_sums(v1, v2));
    CHECK_FALSE(contains_prefix_sums(v1, v1));
    CHECK_FALSE(contains_prefix_sums(v2, v2));


    /*
     * This will try all combinations of a and b in the code that follows.
     */
    int a = GENERATE(0, 1, 7);
    int b = GENERATE(-9, 2, 4);

    v1.push_back(a);
    CHECK_FALSE(contains_prefix_sums(v2, v1));

    v2.push_back(a + v2.back());
    CHECK(contains_prefix_sums(v2, v1));

    v2.push_back(b + v2.back());
    CHECK_FALSE(contains_prefix_sums(v2, v1));

    v1.push_back(b);
    CHECK(contains_prefix_sums(v2, v1));
}
