#!/bin/bash

function get_data() {
  url="http://api.citybik.es/v2/networks/bixi-montreal?fields=stations.id,stations.name,stations.free_bikes,stations.empty_slots"
  cTime=$(date +%Y%m%d_%H%M)
  fileName="./api_data/data_${cTime}.txt"
  curl "$url" > $fileName
  sed -i 's/:\[{/:\[\n{/g' ${fileName}
  sed -i 's/},{/},\n{/g' ${fileName}
  sed -i 's/"//g' ${fileName}
  sed -i 's/{id://g' ${fileName}
  sed -i 's/name://g' ${fileName}
  sed -i 's/free_bikes://g' ${fileName}
  sed -i 's/empty_slots://g' ${fileName}
  sed -i 's/}//g' ${fileName}
}

function check_delete() {
  target="./api_data"
  maxFiles=104
  fileVal=$(ls $target | wc -l)
  if (( $fileVal > $maxFiles )); then
    rm $(ls -t | tail -n 1)
  fi
}

check_delete
get_data