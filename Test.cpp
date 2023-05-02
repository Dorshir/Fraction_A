#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

#include "sources/Fraction.hpp"

TEST_CASE("Constructor") {

    Fraction f(2, 4);
    Fraction t(3, 6);

    CHECK((f == t ==
           0.5)); // Operator should compare with the reduced fractions, therefor 'f' and 't' should act as equals as the reduced form
    CHECK_THROWS(Fraction(1, 0)); // Denominator 0 initialize check
    CHECK_NOTHROW(Fraction(0, 1)); // Numerator 0 initialize check
}

TEST_CASE("Addition") {

    SUBCASE("Fraction") {
        Fraction f(1, 2);
        Fraction t(2, 4);
        CHECK((f + t == 1)); // Correction
    }
    SUBCASE("Float") {
        Fraction f(1, 2);
        CHECK((f + 2 == 0.5 + 2)); // Correction
        CHECK(((1.5 + f) == 2)); // Fraction object as rvalue
    }
}

TEST_CASE("Subtraction") {

    SUBCASE("Fraction") {
        Fraction f(1, 2);
        Fraction t(2, 4);
        CHECK((f - t == 0)); // Correction
    }
    SUBCASE("Float") {
        Fraction f(1, 2);
        CHECK((f - 0.2 == 0.3)); // Fraction object as lvalue
        CHECK(((1.5 - f) == 1)); // Fraction object as rvalue
    }
}

TEST_CASE("Multiply") {

    SUBCASE("Fraction") {
        Fraction f(1, 2);
        Fraction t(2, 4);
        CHECK((f * t == 0.25)); // Correction
    }
    SUBCASE("Float") {
        Fraction f(1, 2);
        CHECK((f * 2 == 0.666)); // Returned with 3 numbers only after the dot, fraction object as lvalue
        CHECK((2.32 * f == 1.16)); // Fraction object as rvalue
        CHECK(((f * 0) == 0)); // Zero multiply
    }
}

TEST_CASE("Division") {

    SUBCASE("Fraction") {
        Fraction f(1, 1);
        Fraction t(9, 3);
        CHECK((f / t == 0.333)); // Correction with 3 numbers after dot
        Fraction temp(t.getNumerator(), t.getDenominator());
        t / 1;
        CHECK((temp == t)); // One division
        CHECK_THROWS(f / 0); // Zero division
    }
    SUBCASE("Float") {
        Fraction f(1, 2);
        CHECK((2.32 / f == 4.64)); // Fraction object as lvalue
        CHECK((f / 3.33 == 0.150)); // Fraction object as rvalue
    }
}

TEST_CASE("Increment") {
    Fraction f(1, 2);
    Fraction t(3, 2);
    Fraction s(5, 2);
    CHECK((++f == t)); // Prefix operate

    CHECK((f++ == t)); // Postfix operate
    CHECK((f == s)); // Correction after the postfix operation
}

TEST_CASE("Decrement") {
    Fraction f(1, 2);
    Fraction t(3, 2);
    Fraction s(-1, 2);
    CHECK((--t == f)); // Prefix operate

    CHECK((f-- == t)); // Postfix operate
    CHECK((f == s)); // Correction after the postfix operation
}

TEST_CASE("Relational operates") {

    SUBCASE("Equal to") {

        SUBCASE("Fraction") {
            Fraction f(1, 2);
            Fraction t(1, 2);
            Fraction s(5, 10);
            CHECK((f == t)); // Similar values
            CHECK((f == s)); // Correction with no reduced fraction
        }
        SUBCASE("Float") {
            Fraction f(1, 2);
            CHECK((f == 0.5)); // Fraction object as lvalue
            CHECK((0.5 == f)); // Fraction object as rvalue
        }
    }

    SUBCASE("Not equal to") {

        SUBCASE("Fraction") {
            Fraction f(1, 2);
            Fraction t(1, 3);
            CHECK((f != t)); // Unequal values of fraction objects
        }
        SUBCASE("Float") {
            Fraction f(1, 2);
            Fraction t(2, 4);
            CHECK((f != 0.3)); // Fraction object as lvalue
            CHECK((0.3 != f)); // Fraction object as rvalue
            CHECK_FALSE((f != t)); // Unreduced fraction
        }
    }

    SUBCASE("Greater than") {

        SUBCASE("Fraction") {
            Fraction f(1, 2);
            Fraction t(1, 3);
            CHECK((f > t));
        }
        SUBCASE("Float") {
            Fraction f(1, 2);
            CHECK((f > 0.33)); // Fraction object as lvalue
            CHECK((1.5 > f)); // Fraction object as rvalue
            CHECK((f > -0.5)); // Negative of 'f'
        }
    }

    SUBCASE("Less than") {

        SUBCASE("Fraction") {
            Fraction f(1, 2);
            Fraction t(1, 3);
            CHECK((t < f));
        }
        SUBCASE("Float") {
            Fraction f(1, 2);
            CHECK((f < 0.6)); // Fraction object as lvalue
            CHECK((0.2 < f)); // Fraction object as rvalue
            CHECK((-0.5 < f)); // Negative of 'f'
        }
    }

    SUBCASE("Greater than or equal to") {

        SUBCASE("Fraction") {
            Fraction f(1, 2);
            Fraction t(1, 3);
            Fraction s(2, 4);
            CHECK((f >= t)); // 'f' is greater than 't'
            CHECK((f >= s)); // 'f' is equal to 's'
        }
        SUBCASE("Float") {
            Fraction f(1, 2);
            CHECK((f >= 0.5)); // 'f' is equal, fraction as lvalue
            CHECK((f >= 0.2)); // 'f' is greater, fraction as lvalue
            CHECK((0.5 >= f)); // 'f' is equal, fraction as rvalue
            CHECK((0.6 >= f)); // 'f' is grater, fraction as rvalue
        }
    }

    SUBCASE("Less than or equal to") {

        SUBCASE("Fraction") {
            Fraction f(1, 3);
            Fraction t(1, 2);
            Fraction s(2, 4);
            CHECK((f <= t)); // 'f' is less than 't'
            CHECK((f <= s)); // 'f' is equal to 's'
        }
        SUBCASE("Float") {
            Fraction f(1, 2);
            CHECK((f <= 0.5)); // 'f' is equal, fraction as lvalue
            CHECK((f <= 0.6)); // 'f' is less than float value, fraction as lvalue
            CHECK((0.5 <= f)); // 'f' is equal, fraction as rvalue
            CHECK((0.2 <= f)); // 'f' is less than float value, fraction as rvalue
        }
    }

}

TEST_CASE("Iostream") {

    SUBCASE("Output") {
        Fraction f(1, 2);

        // Redirect cout to a stringstream
        std::stringstream output;
        std::streambuf *oldCoutStreamBuf = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());

        // Call the function
        std::cout << f;

        // Restore cout
        std::cout.rdbuf(oldCoutStreamBuf);


        CHECK((stof(output.str()) == f));
    }
    SUBCASE("Input") {
        Fraction f(1,3);
        std::stringstream input("5/7");
        input >> f;
        CHECK((f.getNumerator() == 5));
        CHECK((f.getDenominator() == 7));
    }
}


