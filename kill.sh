#!/bin/bash

FILES=`find . -name "Makefile" | sed 's/Makefile//p'`

for dir in $FILES
do
    make clean -C $$dir 2>/dev/null
done

echo "make clean in 
$FILES"
