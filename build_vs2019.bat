
rmdir /S /Q build
mkdir build
pushd build
cmake -A x64 -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=relwithdebinfo ..
cmake --build . --config relwithdebinfo -- /m:%NUMBER_OF_PROCESSORS%
popd

rem pause