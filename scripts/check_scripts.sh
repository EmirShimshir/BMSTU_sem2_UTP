#!/bin/bash

this_path="./*.sh"

for file in $this_path; do
	shellcheck "$file"
done

echo "check_scripts.sh complite!"
