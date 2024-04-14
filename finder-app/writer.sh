#!/bin/bash

# Should be called with ./writer.sh <file> <writestr>
# Checking if atleast 2 arguments are there
if [ $# -lt 2 ]
then
    echo "Usage: ./writer.sh <file> <writestr>"
    exit 1
fi

file=$1
filedir=$(dirname $file)
writestr=$2

# Overwrite or create a new file and write the writestr into it
# If the directory of the file does not exist then create it
if ! [ -d $filedir ]
then
    mkdir -p $filedir
fi
echo $writestr > $file

# Check for error in writing / creating of file
if [ $? -ne 0 ]
then
    echo "Error: could not write to or create the file"
    exit 1
fi

exit 0