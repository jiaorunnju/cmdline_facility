#!/bin/bash
#########################################################################
# File Name: genMakefile.sh
# Author :Jiaorun
# Created Time: Thu 29 Dec 2016 02:07:17 PM CST
#########################################################################

if [ -f makefile ]
then
    rm makefile
fi

if [ ! -d "bin" ]
then
    mkdir bin
fi

FILETYPE='*.[c|cpp]'
FILES=`find . -name "$FILETYPE"`

echo -n "Obj= " >>makefile
for file in $FILES
do
    echo -n "${file%.*}.o " >>makefile
done
echo >>makefile
echo -n "bin/main: " >>makefile
echo '${Obj}'>>makefile
echo -ne '\t'>>makefile
echo 'g++ $(Obj) -o bin/main'>>makefile
echo "">>makefile

for file in $FILES
do
    echo -n "${file%.*}.o : ">>makefile
    gcc -MM $file | awk -F ":" '{print $2}'>>makefile
done

echo "">>makefile

echo '.PHONY : clean'>>makefile
echo 'clean:'>>makefile
echo -e '\t-rm $(Obj)'>>makefile
