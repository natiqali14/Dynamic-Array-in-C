#!/bin/bash

gcc -o program \
    $(find src/ -name '*.c')
if [ $? -eq 0 ]; then
    echo "Success!!!!"
    echo "----------------------------------------------------------"
    ./program
else
    echo "Failed!!!!!"
fi