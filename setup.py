from setuptools import setup, Extension
import pybind11

ext_modules = [
    Extension(
        "huffman",
        ["src/bindings.cpp", "src/huffman_encoder/huffmanEncoder.cpp", "src/node/node.cpp", 
         "src/huffman_tree/huffman_tree.cpp", "src/file_handling/readWriteFiles.cpp",
         "src/lz77/lz77.cpp", "src/lz77/pointer/pointer.cpp", "src/file_handling/rw_encoding.cpp"],
        include_dirs=[pybind11.get_include()],
        language="c++",
        extra_compile_args=["/std:c++17"],
    )
]

setup(
    name="huffman",
    version="0.1",
    ext_modules=ext_modules,
)