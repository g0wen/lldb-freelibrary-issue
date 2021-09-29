mkdir build-llvm

rem Compile app
clang++ -g src/main.cpp -o build-llvm/app.exe

rem Compile shared_lib dll
clang++ -g -c -o build-llvm/shared_lib.o src/shared_lib.cpp 
clang++ -g -shared -v -o build-llvm/shared_lib.dll build-llvm/shared_lib.o