//
// Created by kenny on 5/18/18.
//
#include <gtest/gtest.h>
#include <fstream>
#include "numt/bigint.h"

using namespace knylaw::math;

TEST(BigIntegerTest, SubtractionSample) {
    std::string s1 = "598745986543675986789";
    std::string s2 = "237685800001232470000000000095400006";
    std::string s3 = "-237685800001231871254013456419413217";

    auto b1 = BigInteger::valueOf(s1);
    auto b2 = BigInteger::valueOf(s2);

    EXPECT_EQ(s1, to_string(b1));
    EXPECT_EQ(s2, to_string(b2));

    b1 -= b2;
    EXPECT_EQ(s3, to_string(b1));
}

TEST(BigIntegerTest, Subtraction) {

    std::ifstream in2("./SubtractionTest.in");

    std::string s1, s2, s3;
    if (!in2) {
        throw std::runtime_error("File not opened.");
    }
    while (std::getline(in2, s1) &&
           std::getline(in2, s2) && std::getline(in2, s3))
    {
        auto b1 = BigInteger::valueOf(s1);
        auto b2 = BigInteger::valueOf(s2);
        EXPECT_EQ(s1, to_string(b1));
        EXPECT_EQ(s2, to_string(b2));
        b1 -= b2;
        EXPECT_EQ(s3, to_string(b1)) << s1 << "-" << s2;
    }
}

/*
import random
numeric = "1234567890"

def random_bigintstr(count=32, maxlen=1024):
    ret = []
    for i in range(count):
        l = random.randint(0, maxlen)
        string = "".join([random.choice(numeric) for j in range(0, l)]).lstrip("0")
        if string:
            sign = "-" if random.choice((True, False)) else ""
            string = sign + string
        else:
            string = "0"
        ret.append(string)
    return ret

with open("SubtractionTest.in", mode="w") as f:
    a = random_bigintstr(32, 1024)
    b = random_bigintstr(32, 1024)
    for i, j in zip(a,b):
        c = int(i) - int(j)
        _ = f.write("%s\n%s\n%d\n" % (i,j,c))


*/
