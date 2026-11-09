#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/CountWords.hpp"

TEST_CASE( "Benchmark 17 words" ) {
    CountWords words;
    BENCHMARK("17 words") {
    words.fileinside("../tests/test1.txt");
    };
}

TEST_CASE( "Benchmark 50 words" ) {
    CountWords words;
    BENCHMARK("50 words") {
    words.fileinside("../tests/test2.txt");
    };
}

TEST_CASE( "Benchmark 188 words" ) {
    CountWords words;
    BENCHMARK("188 words") {
    words.fileinside("../tests/test3.txt");
    };
}

TEST_CASE( "Benchmark 465 words" ) {
    CountWords words;
    BENCHMARK("465 words") {
    words.fileinside("../tests/test4.txt");
    };
}

TEST_CASE( "Benchmark 930 words" ) {
    CountWords words;
    BENCHMARK("930 words") {
    words.fileinside("../tests/test5.txt");
    };
}
TEST_CASE( "Benchmark 9300 words" ) {
    CountWords words;
    BENCHMARK("9300 words") {
    words.fileinside("../tests/test6.txt");
    };
}
TEST_CASE( "Benchmark 18600 words" ) {
    CountWords words;
    BENCHMARK("18600 words") {
    words.fileinside("../tests/test7.txt");
    };
}
