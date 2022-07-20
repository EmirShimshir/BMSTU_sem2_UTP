#!/bin/bash

opts="Os O0 O1 O2 O3"
progs="transpose_no transpose_first transpose_second"
count_tests=20
sizes="1 ""$(seq 5 5 100)"

if [ $# -ne 4 ]; then
	exit 1
fi

if [ ! "def" = "$1" ]; then
	opts="$1"
fi

if [ ! "def" = "$2" ]; then
	progs="$2"
fi

if [ ! "def" = "$3" ]; then
	count_tests="$3"
fi

if [ ! "def" = "$4" ]; then
	sizes="$4"
fi

for opt in $opts; do
	for prog in $progs; do
		for size in $sizes; do
			# echo -n -e "$prog $opt $size \r"
			i=0
			while [ "$i" -lt "$count_tests" ]; do
				../apps/main_"${opt}".exe "${size}" "${prog}" >> ../dataset/"${prog}"/"${opt}"/"${size}".txt
				i=$((i+1))
			done
		done
	done
done

echo "update_data.sh complite!"