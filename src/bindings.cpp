#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "huffmanEncoder.hpp"
#include "readWriteFiles.hpp"

namespace py = pybind11;

PYBIND11_MODULE(huffman, m){
    m.def("decode_huffman", &decode_huffman, py::arg("decode_map"), py::arg("encoded_text"));

    py::class_<HuffmanEncoder>(m, "HuffmanEncoder")
        .def(py::init<>())
        .def("encode", &HuffmanEncoder::encode)
        .def("get_encoded_text", &HuffmanEncoder::get_encoded_text)
        .def("get_decode_map", &HuffmanEncoder::get_decode_map);

    py::class_<ReadWriteFile>(m, "ReadWriteFiles")
        .def(py::init<>())
        .def("save_file", &ReadWriteFile::save_file)
        .def("read_file", &ReadWriteFile::read_file)
        .def("get_decode_map", &ReadWriteFile::get_decode_map)
        .def("get_encoded_text", &ReadWriteFile::get_encoded_text);
}