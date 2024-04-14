#!/bin/bash

# Should be called with ./finder.sh <filesdir> <searchstr>
# Checking if atleast 2 arguments are there
if [ $# -lt 2 ]
then
    echo "Usage: ./finder.sh <filesdir> <searchstr>"
    exit 1
fi

filesdir=$1
searchstr=$2

# Check if the first argument filesdir exists and is a directory
if ! [ -d $filesdir ]
then
    echo "filesdir is not a valid directory"
    exit 1
fi

# Print the number of files in the filesdir and its sub directories along with matched lines in all the respective files
# with -type f we only consider files and no directories
cd $filesdir
numfiles=$(find . -type f | wc -l) 
numlines=$(grep -r $searchstr * | wc -l)
echo "The number of files are" $numfiles "and the number of matching lines are" $numlines

exit 0