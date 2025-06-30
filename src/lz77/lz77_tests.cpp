#include "lz77.cpp"
#include "pointer/pointer.cpp"

#define BOOST_TEST_MODULE pointer_tests
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(one_character){
    std::string sample = "a";
    auto pointers = lz77::encode(sample);

    BOOST_CHECK(pointers.size() == 1);
    BOOST_CHECK(pointers[0]->get_character() == 'a');
    BOOST_CHECK(pointers[0]->get_offset() == 0);
    BOOST_CHECK(pointers[0]->get_length() == 0);
}

BOOST_AUTO_TEST_CASE(empty_input){
    std::string sample = "";
    auto pointers = lz77::encode(sample);

    BOOST_CHECK(pointers.size() == 1);
    BOOST_CHECK(pointers[0]->get_character() == '\0');
    BOOST_CHECK(pointers[0]->get_offset() == 0);
    BOOST_CHECK(pointers[0]->get_length() == 0);
}

BOOST_AUTO_TEST_CASE(two_unique_characters){
    std::string sample = "ab";
    auto pointers = lz77::encode(sample);

    BOOST_CHECK(pointers.size() == 2);
    BOOST_CHECK(pointers[0]->get_character() == 'a');
    BOOST_CHECK(pointers[0]->get_offset() == 0);
    BOOST_CHECK(pointers[0]->get_length() == 0);

    BOOST_CHECK(pointers[1]->get_character() == 'b');
    BOOST_CHECK(pointers[1]->get_offset() == 0);
    BOOST_CHECK(pointers[1]->get_length() == 0);
}

BOOST_AUTO_TEST_CASE(two_repeated_characters){
    std::string sample = "aa";
    auto pointers = lz77::encode(sample);

    BOOST_CHECK(pointers.size() == 2);
    BOOST_CHECK(pointers[0]->get_character() == 'a');
    BOOST_CHECK(pointers[0]->get_offset() == 0);
    BOOST_CHECK(pointers[0]->get_length() == 0);

    BOOST_CHECK(pointers[1]->get_character() == '\0');
    BOOST_CHECK(pointers[1]->get_offset() == 1);
    BOOST_CHECK(pointers[1]->get_length() == 1);
}

BOOST_AUTO_TEST_CASE(repeatition){
    std::string sample = "abab";
    auto pointers = lz77::encode(sample);

    BOOST_CHECK(pointers.size() == 3);
    BOOST_CHECK(pointers[0]->get_character() == 'a');
    BOOST_CHECK(pointers[0]->get_offset() == 0);
    BOOST_CHECK(pointers[0]->get_length() == 0);

    BOOST_CHECK(pointers[1]->get_character() == 'b');
    BOOST_CHECK(pointers[1]->get_offset() == 0);
    BOOST_CHECK(pointers[1]->get_length() == 0);

    BOOST_CHECK(pointers[2]->get_character() == '\0');
    BOOST_CHECK(pointers[2]->get_offset() == 2);
    BOOST_CHECK(pointers[2]->get_length() == 2);
}

BOOST_AUTO_TEST_CASE(decoding){
    std::vector<std::unique_ptr<Pointer>> pointers;
    pointers.push_back(std::move(std::make_unique<Pointer>(0, 0, 'H')));
    pointers.push_back(std::move(std::make_unique<Pointer>(0, 0, 'e')));
    pointers.push_back(std::move(std::make_unique<Pointer>(0, 0, 'l')));
    pointers.push_back(std::move(std::make_unique<Pointer>(1, 1, 'o')));
    pointers.push_back(std::move(std::make_unique<Pointer>(0, 0, ' ')));
    pointers.push_back(std::move(std::make_unique<Pointer>(6, 5, '\0')));

    std::string expected_string = "Hello Hello";

    BOOST_CHECK(lz77::decode(pointers) == expected_string);
}