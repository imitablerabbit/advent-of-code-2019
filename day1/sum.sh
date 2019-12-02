cat input | xargs -n 1 ./fuelfuel | awk '{s+=$1} END {print s}'
