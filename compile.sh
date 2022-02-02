#!/bin/bash
if [ $# != 0 ]
then gcc $1.c -o $1
./$1
rm ./$1
fi