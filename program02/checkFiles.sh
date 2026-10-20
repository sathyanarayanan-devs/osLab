#!/bin/bash

echo -e "Number of Arguments: $#\n"

for item in "$@"
do
    if [ -f "$item" ]; then
        echo "$item is a file"
        line=$(wc -l < "$item")
        echo -e "Number of lines in $item: $line\n"
    elif [ -d "$item" ]; then
        echo "$item is a directory"
        files=$(ls -l $item)
        echo -e "Files in $item:\n $files\n"
    else
        echo "$item does not exists"
    fi
done