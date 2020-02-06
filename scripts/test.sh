#!/bin/bash

ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`
echo "input is {$ARG}"
if [[ $1 -lt 0 ]]; then 
	var1=$(( 0 - $1 ))
else
	var1=$1
fi
if [[ $2 -lt 0 ]]; then 
	var2=$(( 0 - $2 ))
else
	var2=$2
fi

if [[ $2 -lt 0 ]]; then
	n=$(( $var1 - $var2 - 1 ))
else
	n=$(( $var1 + $var2 + 1 ))
fi

echo "param 1 = $var1"
echo "param 2 = $var2"


 echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-\n" ; ./push_swap $ARG 
 echo "\n-=-=-=-=-=-=-=-=-=-=-=-=-\n" ; ./push_swap $ARG | ./checker $ARG ;
