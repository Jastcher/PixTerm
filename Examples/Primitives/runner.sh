#! /bin/bash

dir=$(dirname $(which $0 2>/dev/null || realpath ./$0))
cd $dir/../../
pwd
g++ $dir/app.cpp -o $dir/main -LBuild/ -lPixTerm -IInclude -IVendor
cd $dir

if [ $1 ] 
then
	echo ""
	echo "Executing"
	clear
	./main
fi

