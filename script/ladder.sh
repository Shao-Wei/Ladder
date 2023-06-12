#!/bin/bash

# usage
if [[ ( $@ == "--help") ||  $@ == "-h" ]]
then 
	echo "Usage: $0 <mode>"
	exit 0
fi 

# benchmark list
# You can access them using echo "${arr[0]}", "${arr[1]}"
declare -a iscas85=( "c432"
                     "c499"
                     "c880"
                     "c1355"
                     "c1908"
                     "c2670"
                     "c3540"
                     "c5315"
                     "c6288"
                     "c7552")         

# options
mode=$1

# basic setting
pathbench="benchmarks/"

if [[ $mode == "sizeRatio" ]]
then
   echo "Run script on iscas85 for mapped cut ratio..."
   for i in "${iscas85[@]}"
   do
      echo "$i"
      commandLine1="r $pathbench$i.blif; &get; &if -n -K 8; dsd_filter -l"
      ./abc -c "$commandLine1"
   done
fi
