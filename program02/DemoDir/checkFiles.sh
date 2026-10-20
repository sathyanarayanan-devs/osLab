#!/bin/bash

echo "Number of Arguments supplied: $#"

for item in "$@"
do
    if [ -f "$item" ]; then
        echo "$item is a File"
        lines=$(wc -l < "$item")
        echo "Number of lines in $item : $lines"
    elif [ -d "$item" ]; then
        echo "$item is a directory"
        contents=$(ls "$item")
        echo "Contents of $item: $contents"
    else
        echo "$item does not exists"
    fi 
done