#include "ipd13a-3.hxx"
#include <catch.hxx>

using ipd::sort_refs;


TEST_CASE("sort_refs(int& a, int& b, int& c)")
{
    int a, b, c;

    SECTION ("a > b and a < c") {
        a = 5;
        b = 3;
        c = 6;

        CHECK (sort_refs(a, b, c));
        CHECK (a == 3);
        CHECK (b == 5);
        CHECK (c == 6);
    }

    SECTION ("a > b and a > c" ) {
        a = 6;
        b = 5;
        c = 4;

        CHECK (sort_refs(a, b, c));
        CHECK (a == 4);
        CHECK (b == 5);
        CHECK (c == 6);

    }
    SECTION ("a < b and a < c") {
        a = 2;
        b = 3;
        c = 5;

        CHECK_FALSE (sort_refs(a, b, c));
        CHECK (a == 2);
        CHECK (b == 3);
        CHECK (c == 5);
    }

    SECTION ("a < b and a > c") {
        a = 4;
        b = 9;
        c = 2;

        CHECK (sort_refs(a, b, c));
        CHECK (a == 2);
        CHECK (b == 4);
        CHECK (c == 9);
    }
}


TEST_CASE("sort_refs(float& a, float& b, float& c)")
{
    float a, b, c;

    SECTION ("a > b and a < c") {
        a = 5.78;
        b = 3.44;
        c = 5.90;

        CHECK (sort_refs(a, b, c));
        CHECK (a == 3.44f);
        CHECK (b == 5.78f);
        CHECK (c == 5.90f);
    }

    SECTION ("a > b and a > c" ) {
        a = 6.99;
        b = 6.77;
        c = 6.44;

        CHECK (sort_refs(a, b, c));
        CHECK (a == 6.44f);
        CHECK (b == 6.77f);
        CHECK (c == 6.99f);

    }
    SECTION ("a < b and a < c") {
        a = 2.89;
        b = 2.90;
        c = 5.66;

        CHECK_FALSE (sort_refs(a, b, c));
        CHECK (a == 2.89f);
        CHECK (b == 2.90f);
        CHECK (c == 5.66f);
    }

    SECTION ("a < b and a > c") {
        a = 4.7;
        b = 9.2;
        c = 2.0;

        CHECK (sort_refs(a, b, c));
        CHECK (a == 2.0f);
        CHECK (b == 4.7f);
        CHECK (c == 9.2f);
    }
}


TEST_CASE ("sort_refs(int& a, int& b)")
{
    int a, b;

    SECTION ("a > b") {
        a = 5;
        b = 3;

        CHECK (sort_refs(a, b));
        CHECK (a == 3);
        CHECK (b == 5);

        CHECK (sort_refs(b, a));
        CHECK (b == 3);
        CHECK (a == 5);
    }

    SECTION ("a < b") {
        a = 3;
        b = 5;

        CHECK_FALSE (sort_refs(a, b));
        CHECK (a == 3);
        CHECK (b == 5);

        std::swap(a, b);

        CHECK_FALSE (sort_refs(b, a));
        CHECK (b == 3);
        CHECK (a == 5);
    }

    SECTION ("a == b") {
        a = 4;
        b = 4;

        CHECK_FALSE (sort_refs(a, b));
        CHECK (a == 4);
        CHECK (b == 4);

        CHECK_FALSE (sort_refs(b, a));
        CHECK (a == 4);
        CHECK (b == 4);
    }
}
