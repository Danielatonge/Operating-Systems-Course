if test ! -f number_list
then
    #create the numbers file
    echo 0 > number_list
fi

for i in {1..30}
do
	#Read and increase last number
	LAST_NUMBER=`tail -1 number_list`
	LAST_NUMBER=$((LAST_NUMBER+1))

	echo $LAST_NUMBER >> number_list
done
