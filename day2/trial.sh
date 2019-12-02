#! /bin/bash

declare min=0
declare max=99
declare needed=19690720

for noun in $(seq ${min} ${max}); do
    for verb in $(seq ${min} ${max}); do
        out=$(./opcodes-trial $noun $verb $(cat ./input))
        if [[ $out == $needed ]]; then
            (( result=100*noun+verb ))
            echo "$result"
            exit 0
        fi
    done
done

