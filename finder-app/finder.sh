#!/bin/bash

# Check if exactly two arguments are given
if [ $# -ne 2 ]; then
    echo "Usage: $0 <directory path> <search string>"
    exit 1
fi

# Assign arguments to named variables
filesdir=$1
searchstr=$2

# Check if the provided filesdir is a directory
if [ ! -d "$filesdir" ]; then
    echo "Error: $filesdir is not a valid directory"
    exit 1
fi

# Find all files in the directory and subdirectories, count them
file_count=$(find "$filesdir" -type f | wc -l)

# Use grep to search for the string in all files and count matching lines
matching_lines_count=$(grep -r "$searchstr" "$filesdir" | wc -l)

# Output the results
echo "The number of files are $file_count and the number of matching lines are $matching_lines_count"
