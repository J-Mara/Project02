#!/usr/bin/env bash

dir=$1
nfiles=$2
nlines=$3

mkdir -p ${dir}
for i in $(seq 1 $nfiles)
do
    echo $i > ${dir}/${i}.txt
    echo "this is a test" >> ${dir}/${i}.txt
    for j in $(seq 1 $nlines)
    do
	echo $RANDOM | base64 | head -c 20 >> ${dir}/${i}.txt
    done
done
