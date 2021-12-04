#!/bin/bash
exec 6<&0
exec 0<passwd.txt
IFS_FLAG=$IFS
IFS=','
input=passwd.txt
git push github master  
while [ $? -ne 0 ]
do
    git push github master  
done<$input

IFS=$IFS_FLAG
