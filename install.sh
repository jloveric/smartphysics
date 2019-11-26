#!/bin/bash
export SOURCE=`pwd`
[ ! -d "$SOURCE/jali" ] && git clone https://github.com/jloveric/jali.git

pushd .
cd jali
./install.sh
popd
cmake .
make -j8
exit