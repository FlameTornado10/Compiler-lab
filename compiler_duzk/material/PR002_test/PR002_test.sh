#!/bin/bash
result_array=(0 0 0 1 1 
              1 0 1 0 0
              1 0 1 1 1
              1 1 1 1 1
              1 1 0 0 0
              1 1 1 1 0
              1 1 1 0 1
              1 0 1 1 1
              1 1 1 1 1
              0 1 0)

# result_array=(1)
#  1 1 0 0) 
#               1 0 1 0 0)
echo "Error log:" > log.txt

# Clone projects
number="26"
dir_name="compiler${number}"
rm -rf $dir_name
# Fill in the 'username:password' by yourself.
addr="http://compiler26:12345678@124.16.71.65/$dir_name/compiler.git"
git clone $addr
cd compiler

# Build
rm -rf build
mkdir -p build && cd build
cmake ../
make -j8
# cd ~/Work/compiler_dzk/compiler/build
# cd ~/Work/compiler_dzk/compiler_1/build
# cmake ../
# make -j8
cp compiler compiler1
mv compiler1 ~/Work/compiler_dzk/material/PR002_test
cd ~/Work/compiler_dzk/material/PR002_test
# Test
all_files=48
passed_files=0
index=0
dir=`ls samples_semantic/*.cact`
# dir=`ls sample/0.cact`
for test_file in $dir   
do
    echo "Test $test_file"
    ./compiler1 $test_file
    command_stat=$?
    if [[ $command_stat == 0 && ${result_array[$index]} == 0 ]] \
    || [[ $command_stat != 0 && ${result_array[$index]} == 1 ]];
    then
        let "passed_files++"
    else
        echo "$index: should be: ${result_array[$index]}, is $command_stat" >> log.txt
    fi
    let "index++"
done

echo -e "compiler${number}: $passed_files / $all_files"