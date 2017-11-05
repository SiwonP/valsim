Valsim is the name of a brand new language I'm trying to invent.
I would like it to be a compiled language, as well as Object Oriented, a bit like Java actually.
There's a makefile to build the project : 
make build at the root should give you a valsim executable you call from your terminal with the name of your file as argument

```
git clone https://www.git.com/SiwonP/valsim
cd valsim
mkdir build
cd build
cmake -G"Unix Makefiles" ..
make
```
