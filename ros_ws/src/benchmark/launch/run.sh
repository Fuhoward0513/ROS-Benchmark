#!/bin/bash

pub_num=10
sub_num=5
fre_lst=(100)
payload_lst=(8 80 200 500 1000 2000)
# payload_lst=(8)
lag=$((5+20))

for fre in "${fre_lst[@]}"
do
    T=$((505/fre+lag))
    for payload in "${payload_lst[@]}"
    do
        for ((i=0; i<pub_num; i++)); do
            roslaunch benchmark single_pub.launch pub_id:=$i fre:=$fre payload:=$payload sub_num:=$sub_num &
            for ((j=0; j<sub_num; j++)); do
                timeout $T roslaunch benchmark single_sub.launch pub_id:=$i sub_id:=$j fre:=$fre&
                # roslaunch benchmark single_sub.launch pub_id:=$i sub_id:=$j fre:=$fre&
            done
        done
        ../../system_status/sys_status "$payload" "$fre" "$sub_num" "$pub_num" "$lag"&
        wait
        rosrun benchmark file.py $sub_num $pub_num $fre $payload
    done
done


