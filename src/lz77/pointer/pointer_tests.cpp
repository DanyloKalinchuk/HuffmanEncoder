#include "pointer.cpp"

#define BOOST_TEST_MODULE pointer_tests
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(get_offset_test){
    Pointer test_pointer = Pointer(3, 4, 't');

    BOOST_CHECK(3 == test_pointer.get_offset());
}

BOOST_AUTO_TEST_CASE(get_length_test){
    Pointer test_pointer = Pointer(3, 4, 't');

    BOOST_CHECK(4 == test_pointer.get_length());
}

BOOST_AUTO_TEST_CASE(get_character_test){
    Pointer test_pointer = Pointer(3, 4, 't');

    BOOST_CHECK('t'== test_pointer.get_character());   
}

BOOST_AUTO_TEST_CASE(empty_character){
    Pointer test_pointer = Pointer(3, 4, '\0');

    BOOST_CHECK(test_pointer.get_character() == '\0');
}

BOOST_AUTO_TEST_CASE(large_input){
    Pointer test_pointer = Pointer(10000000, 9000000, 'a');

    BOOST_CHECK(test_pointer.get_offset() == 10000000);
    BOOST_CHECK(test_pointer.get_length() == 9000000);
}

BOOST_AUTO_TEST_CASE(special_char){
    Pointer test_pointer = Pointer(3, 4, '$');

    BOOST_CHECK(test_pointer.get_character() == '$');
}