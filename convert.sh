#!/bin/bash

for source in * ; do
	cat ${source} | sed 's/#include \"\([^"]*\)\"/#include <\1>/' > ${source}.bak
	mv ${source}.bak ${source}
done
