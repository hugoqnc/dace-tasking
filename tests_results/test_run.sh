# !/bin/bash

help() {
cat << EOF
Usage:
    -h ... help
    -v ... for OR tasking
    -d ... empty OR subdir in tests/npbench_cpu OR file in tests/npbench_cpu
EOF
}

# read opts
while getopts ":hv:d:" opt
do
    case $opt in
        h) help; exit 1;;
        v) VERSION=$OPTARG;;
        d) TARGET=$OPTARG;;
    esac
done

if [ "$VERSION" != "for" ] && [ "$VERSION" != "tasking" ]; then
    help; exit 1;
fi

TESTS="../tests/npbench_cpu/$TARGET"
if [ ! -d $TESTS ] && [ ! -f $TESTS ]; then 
    echo "no such tests: $TESTS"; exit 1;
fi

DTYPES="../dace/dtypes.py"
if [ ! -f $DTYPES ]; then 
    echo "file doesn't exist: $DTYPES"; exit 1;
fi

# Set the default schedule in codegen.py:
# Use `None` for original behavior with parallel for loops
# Use `dtypes.ScheduleType.CPU_Multicore_Tasking_Default` for tasking
schedule_task="ScheduleType.CPU_Multicore_Tasking"
schedule_for="ScheduleType.CPU_Multicore"
OLDLINE="None: "
NEWLINE="None: "
if [ "$VERSION" == "for" ]; then
    OLDLINE+=$schedule_task
    NEWLINE+=$schedule_for
else
    OLDLINE+=$schedule_for
    NEWLINE+=$schedule_task
fi

if grep -Fxq "$NEWLINE" $DTYPES; then
    echo "... $OLDLINE => $NEWLINE"
	sed -i '' -e "s/$OLDLINE/$NEWLINE/g" $DTYPES
fi

# run tests
DATE=$(date +"%m%d")
COMMIT=$(git rev-parse --short HEAD)
echo "... running tests $TESTS" 
echo "... date: $DATE, commit: $COMMIT"

pytest -m "cpu" $TESTS


