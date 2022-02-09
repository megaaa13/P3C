#!/bin/bash
if [ $# != 0 ]
then gcc $1.c -o $1.out
./$1.out
rm ./$1.out
fi
printf "\033[1;36mAll tasks done !\n"