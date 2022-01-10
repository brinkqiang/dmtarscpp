#!/bin/bash

# - install depends tools
# sudo yum -y install zlib-devel flex bison psmisc libncurses5-dev
#

# - install depends tools
# sudo apt-get install zlib1g-dev flex bison psmisc ncurses-devel
#


# pushd thirdparty/depends_path
# libtoolize && aclocal && autoheader && autoconf && automake --add-missing
# sh configure
# popd

rm -rf build
mkdir -p build
pushd build

cmake -DCMAKE_BUILD_TYPE=relwithdebinfo ..
cmake --build . --config relwithdebinfo -- -j$(nproc)

popd

# popd

# echo continue && read -n 1
