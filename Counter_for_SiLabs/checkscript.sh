#!/bin/bash

count=0
while :
do
	./counter
	((count++));
	cmp --silent actual_output.txt ideal_output/ideal1.txt && continue || cmp --silent actual_output.txt ideal_output/ideal2.txt && continue || break
done
echo $'\n'
echo "Variable 'counter' is incremented non-uniformly after $count executions"
