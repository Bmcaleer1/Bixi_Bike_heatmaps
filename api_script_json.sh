#!/bin/bash

function get_data() {
  url="http://api.citybik.es/v2/networks/bixi-montreal?fields=stations.latitude,stations.longitude,stations.free_bikes"
  fileName="./www-root/resources/0.json"
  curl "$url" > $fileName
}

function check_delete() {
  target="./www-root/resources"
  maxFiles=24
  fileVal=$(ls $target | wc -l)
  if (( $fileVal > $maxFiles )); then
    rm $(ls -t $target | tail -n 1)
  fi
}

function rename() {
	target="./www-root/resources"
	for file in $(ls -t $target | tac); do
		num=${file%.*}
		mv "${target}/${file}" "${target}/$((num + 1)).json"
	done
}

rename
check_delete
get_data

