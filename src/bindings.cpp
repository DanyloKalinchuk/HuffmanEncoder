#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "file_handling/rw_encoding.hpp"

namespace py = pybind11;

PYBIND11_MODULE(huffman, m){
    m.def("encode", &en_decoding::encode, py::arg("text"), py::arg("path"), py::arg("type"));
    m.def("decode", &en_decoding::decode, py::arg("path"));
}