# description

A warp of cpython api in which two interfaces are implemented. One is for base type (int, float, array) interact with python, another (cvinterface) for cv usage. `demo.cpp` is to show how to call a python script which converts color images to grey from c++. 

# project tree

```
├── CMakeLists.txt
├── demo.cpp
├── include
│   ├── cpythonCVInterface.h
│   └── cpythonInterface.h
├── pscript.py
└── src
    ├── cpythonCVInterface.cpp   # cv interface
    └── cpythonInterface.cpp     # basic type interface
```
# requirment

+ python3
+ numpy
+ opencv (optional)

notice: more details can find in .vscode configuration folder
  
# how to use

```
mkdir build
cd build
cmake ..
make
./demo
```
