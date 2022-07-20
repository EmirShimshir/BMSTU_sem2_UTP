#!/bin/bash

files="../apps/*.exe"

for file in $files; do
	rm -f "$file" 
done

echo "clean_apps.sh complite!"
