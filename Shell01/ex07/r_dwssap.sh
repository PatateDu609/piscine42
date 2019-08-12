#!/bin/bash

cat /etc/passwd | grep -v '#' | awk 'NR%2' | sed 's/:.*//' | rev | sort -r | sed -ne "${FT_LINE1},${FT_LINE2}p" | tr "\n" "," | sed -E "s/,/, /g" | sed -E "s/, $/./" | tr -d "\n"
