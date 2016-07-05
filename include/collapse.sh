#!/bin/bash

for source in *.h ; do
	cat ${source} | sed 's/#include <\([^/]*\)\"/#include <\1>/' > ${source}.bak
	mv ${source}.bak ${source}
done
