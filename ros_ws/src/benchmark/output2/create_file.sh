#!/bin/bash

pub_num_lst=(1 2 5 10)
sub_num_lst=(1 2 5 10)

fre_lst=(100 50 30 10 1)
# pub_num_lst=(1)
# sub_num_lst=(1)

# fre_lst=(100)


for pub_num in "${pub_num_lst[@]}"
do
    for sub_num in "${sub_num_lst[@]}"
    do
        for fre in "${fre_lst[@]}"
        do
            mkdir N="$sub_num"_M="$pub_num"_fre="$fre"_small
            mkdir N="$sub_num"_M="$pub_num"_fre="$fre"_large
        done
    done
done