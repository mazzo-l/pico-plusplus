# pico-plusplus
The aim of this project is to make C++ development for the Raspberry Pi Pico more appealing to the community by rendering it easier and more familiar. 

Simplicity might require some tradeoffs: if abstraction through classes and objects isn't possible (or excessively intricate), advanced and complex C-functions in the SDK can be left exposed as they are for the most expert users. Prefer to wrap more common functions, with a familiar C++-like syntax and style. 

All the headers should go in the designated "include" folder. If adding a new header, please update the README.md file explaining briefly the purpose of the new-added file under the section "Usage guide". 

Please avoid using C++20 features. 