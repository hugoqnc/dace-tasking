# !/bin/bash

DATETIME=$(date +"%m%d-%H%M")
COMMIT=$(git rev-parse --short HEAD)
TESTDIR=$PWD/$DATETIME"-"$COMMIT

echo "... creating $TESTDIR. Save your test results here."

if [ ! -d $TESTDIR ]; then
    mkdir $TESTDIR
fi

# inspect.txt is a scratch pad
# original.txt is for the original unmodified DaCe
for file in "for.txt" "tasking.txt" "original.txt" "inspect.txt";
do
    if [ ! -f $TESTDIR/$file ]; then
        touch $TESTDIR/$file
    fi
done


