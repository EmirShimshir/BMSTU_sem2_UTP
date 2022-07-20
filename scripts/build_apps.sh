#!/bin/bash

files="../apps/*"

for file in $files; do
	rm -f "$file" 
done

opts="Os O0 O1 O2 O3"

# gcc -std=c99 -Wall -Werror -Wpedantic -Wextra path_prog -o path_app -opt

for opt in $opts; do
	path_app="../apps/main_""$opt"".exe"
	path_prog="../progs/main.c"
	command="gcc -std=c99 -Wall -Werror -Wpedantic -Wextra ""$path_prog"" -o ""$path_app"" -""$opt"
	$command
done

echo "build_apps.sh complite!"
