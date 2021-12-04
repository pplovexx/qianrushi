#!/bin/bash
input=passwd.txt
git push github master  
while [ $? -ne 0 ]
do
    git push github master  
done<input
