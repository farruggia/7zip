#!/bin/bash

list="source_list"

if [ $# -gt 0 ] ; then
	list="${1}"
fi

while read line ; do
	file="${line//..\/}"
	ext=$(echo ${file} | rev | cut -d '.' -f 1 | rev)
	if [ ${ext} = 'c' ] ; then
		cp "${file}" c
	elif [ ${ext} = 'cpp' ] ; then
		cp "${file}" c++
	fi
done < ${list}
