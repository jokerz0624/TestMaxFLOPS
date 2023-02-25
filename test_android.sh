#!/bin/bash
../build_android.sh
TEST_DIR=/data/local/tmp
TEST_NUM=$1
if [ $1x = x ]; then
    echo "You should type in a number.";
    exit 1;
fi
adb push sample $TEST_DIR/sample
adb shell LD_LIBRARY_PATH=$TEST_DIR $TEST_DIR/sample $TEST_NUM