#!/bin/bash

# Use to generate test scripts

get_seeded_random()
{
	seed="$1"
	openssl enc -aes-256-ctr -pass pass:"$seed" -nosalt \
		</dev/zero 2> /dev/null
}

if [ $# -eq 3 ] 
then
	shuf -i1-$1 -n$2 --random-source=<(get_seeded_random $3) > init_list.txt 
else 
	echo Usage: ./generate_test.sh upper_interval numbers_in_interval random_seed
fi
