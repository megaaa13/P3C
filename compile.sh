#!/bin/bash
if [ $# != 0 ]
then gcc $1.c -o $1.out
./$1.out
rm ./$1.out
fi
echo "All tasks done !"