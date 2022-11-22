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

CODEGEN="../dace/codegen/codegen.py"
if [ ! -f $CODEGEN ]; then 
    echo "file doesn't exist: $CODEGEN"; exit 1;
fi

# Set the default schedule in codegen.py:
# Use `None` for original behavior with parallel for loops
# Use `dtypes.ScheduleType.CPU_Multicore_Tasking_Default` for tasking
OLDLINE="default_schedule = "
NEWLINE="default_schedule = "
if [ "$VERSION" == "for" ]; then
    OLDLINE+="dtypes\.ScheduleType\.CPU_Multicore_Tasking_Default"
    NEWLINE+="None"
else
    OLDLINE+="None"
    NEWLINE+="dtypes\.ScheduleType\.CPU_Multicore_Tasking_Default"
fi

if ! grep -Fxq "$OLDLINE" $CODEGEN; then
    echo "... $OLDLINE => $NEWLINE"
	sed -i '' -e "s/$OLDLINE/$NEWLINE/g" $CODEGEN
fi

# run tests
DATE=$(date +"%m%d")
COMMIT=$(git rev-parse --short HEAD)
echo "... running tests $TESTS" 
echo "... date: $DATE, commit: $COMMIT"

pytest -m "cpu" $TESTS


