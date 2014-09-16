void insertion_sort(float* Array, int n){
	if(n> 0){
		insertion_sort(Array, n-1);

		int index= n-1;                   //points to the nth value
		float value= Array[index];
		while ((index> 0)&&(Array[index-1]> value)){
			Array[index]= Array[index-1]; //Bigger elements move right
            index= index-1;               //index points left 
		}
		Array[index]= value;              //insert the value
	}
	else
		return;
}



/*
//A more plain way to express it:

void insert(float* Array, int n){
		int index= n-1;
		float value= Array[index];
		while ((index>1)&&(Array[index-1]> value)){
			Array[index]= Array[index-1]; //Bigger elements move right
            index= index-1;               //index points left 
		}
		Array[index]= value;              //insert the value
		return;
}

void insertion_sort(float* Array, int n){
	if(n>1){
		insertion_sort(Array, n-1);
		insert(Array, n);
	}
	
	else 
		return;
}
*/