#! /bin/bash

dir=$(dirname $(which $0 2>/dev/null || realpath ./$0))
cd $dir/Build
cmake ../
mv compile_commands.json ../

cmake --build .

if [ $1 ] 
then
	echo ""
	echo "Executing"
	clear
	./Application
fi

cd ..

