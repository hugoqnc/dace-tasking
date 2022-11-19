FILE_EXEC=../../dace/codegen/targets/cpu.py
FILE_TASKING=../../dace/codegen/targets/cpu_tasking.py
FILE_FOR=../../dace/codegen/targets/cpu_save.py

RED='\033[0;31m'
NC='\033[0m' # No Color

if test -f "$FILE_FOR"; then
    # exec file contains tasking implementation
    mv $FILE_EXEC $FILE_TASKING;
    mv $FILE_FOR $FILE_EXEC;
    echo "$FILE_EXEC now contains ${RED}parallel for${NC} implementation";
else
    # exec file contains parallel for implementation
    mv $FILE_EXEC $FILE_FOR;
    mv $FILE_TASKING $FILE_EXEC;
    echo "$FILE_EXEC now contains ${RED}tasking${NC} implementation";
fi