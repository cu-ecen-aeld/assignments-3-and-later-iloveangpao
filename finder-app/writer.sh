#!/bin/bash

# Check if exactly two arguments are given
if [ $# -ne 2 ]; then
    echo "Usage: $0 <file path> <string to write>"
    exit 1
fi

# Assign arguments to named variables
writefile=$1
writestr=$2

# Create the directory path if it does not exist
mkdir -p "$(dirname "$writefile")"

# Attempt to write the string to the file
echo "$writestr" > "$writefile"
if [ $? -ne 0 ]; then
    echo "Error: Failed to write to $writefile"
    exit 1
fi

echo "Successfully wrote to $writefile"
