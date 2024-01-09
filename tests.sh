#!/bin/bash

home_dir=$HOME
uls_output="$home_dir/uls_output.txt"
ls_output="$home_dir/ls_output.txt"
success_count=0
failure_count=0

check_command() {
    ./uls $1 > $uls_output
    ls $1 > $ls_output
    diff_res=$(diff $uls_output $ls_output)
    if [ $? -eq 0 ]; then
        echo "\"uls $1\" OK"
        ((success_count++))
    else
        echo "\"uls $1\" FALSE"
        ((failure_count++))
        # echo "$diff_res"
    fi
}

cleanup() {
    rm -rf temp_folder_for_test temp_folder_for_test2 temp_folder_empty file1 file2 file3 ln_file1 file4 "file with spaces"
}

mkdir temp_folder_for_test
mkdir temp_folder_for_test2
mkdir temp_folder_empty
touch file1
touch file2
touch file3
ln -s file1 ln_file1
echo "contents of file4" > file4
chmod 000 file4
touch "file with spaces"

check_command ""
check_command "-R"
check_command "-a"
check_command "-l"
check_command "-C"
check_command "-1"
check_command "-la"
check_command "-al"
check_command "-C1"
check_command "-1C"
check_command "-1C"
check_command "-1Cl"
check_command "-l1C"
check_command "-Rl"
check_command "-RaC"
check_command "-l ln_temp_file1"
check_command "-l ln_temp_file1/"
check_command "temp_folder_for_test temp_folder_for_test2"
check_command "temp_folder_for_test temp_folder_for_test2"
check_command "-lh"
check_command "-Rlh"
check_command "-hl"
check_command "-l@"
check_command "-@l"
check_command "-l@h"
check_command "-Rl@"
check_command "-m"
check_command "-Rm"
check_command "-G"
check_command "-G1"
check_command "-1G"
check_command "-GC"
check_command "-Gl"
check_command "-RGl"
check_command "-RG1"
check_command "-RGC"
check_command "-RGm"
check_command "-p"
check_command "-lp"
check_command "-Cp"
check_command "-pC"
check_command "-p1"
check_command "-pm"
check_command "-pGm"
check_command "-Rp"
check_command "-Rpm"
check_command "-F"
check_command "-Fl"
check_command "-RF"
check_command "-RFm"
check_command "-S"
check_command "-Sr"
check_command "-Sl"
check_command "-SC"
check_command "-S1"
check_command "-1S"
check_command "-Sm"
check_command "-SR"
check_command "-RS"
check_command "-SRCGm"
check_command "-t"
check_command "-c"
check_command "-u"
check_command "-U"
check_command "-cu"
check_command "-UcS"
check_command "-RUc"
check_command "-f"
check_command "-fR"
check_command "-ft"
check_command "-tfa"
check_command "-tR"
check_command "-Rt"
check_command "-lg"
check_command "-lo"
check_command "-log"
check_command "-og"
check_command "-le"
check_command "-elg"
check_command "-go"
check_command "-x"
check_command "-lx"
check_command "-lxC"
check_command "-lxm"
check_command "-mmx"
check_command "-xml"
check_command "-Rx"
check_command "-RxmC"
check_command "-n"
check_command "-nC"
check_command "-ln"
check_command "-xn"
check_command "-i"
check_command "-li"
check_command "-il"
check_command "-iC"
check_command "-ix"
check_command "-i1"
check_command "-i1"

check_command "file1 file2 file3"
check_command "-l file1 file2 file3"
check_command "temp_folder_for_test temp_folder_for_test2 temp_folder_empty"
check_command "-l temp_folder_for_test temp_folder_for_test2 temp_folder_empty"
check_command "-l file1 file2 temp_folder_for_test"
check_command "-l file1 temp_folder_for_test2 temp_folder_empty"
check_command "-l file1 temp_folder_for_test2 temp_folder_empty"
check_command "-l file2 file4 temp_folder_for_test2 temp_folder_empty"
check_command "-S src inc uls"
check_command "-l temp_folder_empty"
check_command "file4"
check_command "-l file4"
check_command "-l file4"
check_command "nonexistent_file" 
check_command "nonexistent_directory/" 
check_command "-l non_existent_file" 
check_command "-Z" 

cleanup

echo "Total tests: $((success_count + failure_count))"
echo "Successful tests: $success_count"
echo "Failed tests: $failure_count"
