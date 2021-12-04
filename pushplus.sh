#!/bin/bash
input=passwd.txt
exec 6<&0
exec 0<$input
git push github master  
while [ $? -ne 0 ]
do
    git push github master  
done
