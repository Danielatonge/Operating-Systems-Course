if test ! -f number_list
then
    echo 0 > number_list;
fi

#Just lock without any interrupt
if ln number_list number_list.lock
then
	for i in {1..30}
	do
		#Read and increase last number
		LAST_NUMBER=`tail -1 number_list`
		LAST_NUMBER=$((LAST_NUMBER+1))

		echo $LAST_NUMBER >> number_list
	done
  #Unlock
  rm number_list.lock
fi
