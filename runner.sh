#! /bin/bash

cd Build
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

