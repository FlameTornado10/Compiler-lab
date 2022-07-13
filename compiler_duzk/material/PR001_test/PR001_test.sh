#!/bin/bash
result_array=(0 1 0 1 1
              1 1 1 1 1
              1 1 0 1 0
              0 1 1 0 1
              1 1 1 1 1
              1 1)

echo "Error log:" > log.txt

# Clone projects
number="26"
dir_name="compiler${number}"
rm -rf $dir_name
# Fill in the 'username:password' by yourself.
addr="http://compiler26:12345678@124.16.71.65/$dir_name/compiler.git"
git clone $addr
mv compiler $dir_name
cd $dir_name

# Build
rm -rf build
mkdir -p build && cd build
cmake ../
make -j8

# Test
all_files=27
passed_files=0
index=0
dir=`ls ../../samples_lex_and_syntax/*.cact`
for test_file in $dir
do
    echo "Test $test_file"
    ./compiler $test_file
    command_stat=$?
    if [[ $command_stat == 0 && ${result_array[$index]} == 0 ]] \
    || [[ $command_stat != 0 && ${result_array[$index]} == 1 ]];
    then
        let "passed_files++"
    else
        echo "$index: should be: ${result_array[$index]}, is $command_stat" >> ../../log.txt
    fi
    let "index++"
done

echo -e "compiler${number}: $passed_files / $all_files"