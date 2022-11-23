# !/bin/bash

help() {
cat << EOF
Usage:
    -h ... help
    -t ... is tasking
    -d ... empty OR subdir in tests/npbench_cpu OR file in tests/npbench_cpu
EOF
}

TASKING="false"
# read opts
while getopts ":htd:" opt
do
    case $opt in
        h) help; exit 1;;
        t) TASKING="true";;
        d) TARGET=$OPTARG;;
    esac
done
    
if [ "$TASKING" != "true" ] && [ "$TASKING" != "false" ]; then
    help; exit 1;
fi

TESTS="../tests/npbench_cpu/$TARGET"
if [ ! -d $TESTS ] && [ ! -f $TESTS ]; then 
    echo "no such tests: $TESTS"; exit 1;
fi

# compiler.cpu.openmp_tasing: true
# does need a .dace.conf file
echo "... tasking: $TASKING"
export DACE_compiler_cpu_openmp_tasking=$TASKING

# run tests
DATE=$(date +"%Y-%m-%d")
COMMIT=$(git rev-parse --short HEAD)
echo "... date: $DATE, commit: $COMMIT"

echo "... running tests: $TESTS" 
pytest -m "cpu" $TESTS

# CONFIG="$HOME/.dace.conf"
# if [ ! -f $CONFIG ]; then 
#     echo "file doesn't exist: $CONFIG"; exit 1;
# fi

# Set the default schedule in codegen.py:
# Use `None` for original behavior with parallel for loops
# Use `dtypes.ScheduleType.CPU_Multicore_Tasking_Default` for tasking
# NEWLINE="openmp_tasking: $TASKING"
# if [ "$TASKING" == "true" ]; then
#     OLDLINE="openmp_tasking: false"
# else
#     OLDLINE="openmp_tasking: true"
# fi

# if ! grep -Fxq "$NEWLINE" $CONFIG; then
#     echo "... $OLDLINE => $NEWLINE"
# 	sed -i '' -e "s/$OLDLINE/$NEWLINE/g" $CONFIG
# fi



