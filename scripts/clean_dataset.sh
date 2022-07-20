#!/bin/bash

files_dataset="../dataset/*/*/*.txt"
files_prep_data="../dataset/prep_data/*.txt"

for file in $files_dataset $files_prep_data; do
	rm -f "$file" 
done

echo "clean_dataset.sh complite!"
