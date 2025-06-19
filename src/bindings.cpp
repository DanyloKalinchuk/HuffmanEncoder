#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "file_handling/rw_encoding.hpp"

namespace py = pybind11;

PYBIND11_MODULE(huffman, m){
    m.def("decode_huffman", &decoder::decode_huffman, py::arg("decode_map"), py::arg("encoded_text"));

    m.def("huffman_encode", &huffman_coding::encode, py::arg("text"), py::arg("path"));
    m.def("huffman_decode", &huffman_coding::decode, py::arg("path"));

    m.def("lz77_encode", &lz77_coding::encode, py::arg("text"), py::arg("path"));
    m.def("lz77_decode", &lz77_coding::decode, py::arg("path"));
}