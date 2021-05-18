::Release Compile Windows

if not exist bin mkdir bin
g++ -g src/*.cpp -o bin/temple -O3 -s -m64 -Wall -std=c++17
echo Compiled Release