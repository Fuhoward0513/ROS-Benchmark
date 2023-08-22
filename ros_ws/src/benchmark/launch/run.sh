#!/bin/bash

pub_num=1
sub_num=2
fre=10
payload=8
T=$((10/fre+5))

for ((i=0; i<pub_num; i++)); do
    roslaunch benchmark single_pub.launch pub_id:=$i fre:=$fre payload:=$payload &
    
    for ((j=0; j<sub_num; j++)); do
        timeout $T roslaunch benchmark single_sub.launch pub_id:=$i sub_id:=$j &
    done
done
wait
rosrun benchmark file.py $sub_num $pub_num $fre $payload

