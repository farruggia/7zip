#!/bin/bash

target_dir="${1}"

make -j 6
mv bin/7za "${target_dir}"
make clean
