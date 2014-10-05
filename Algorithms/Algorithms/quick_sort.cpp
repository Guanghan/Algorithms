int partition(float* Array, int pp, int rr)   //p= 1; q= n
{
	int p= pp-1; 
	int r= rr-1;

	float temp;
	float x= Array[r];
	int i= p- 1;
    

	for(int j= p; j<= r-1; j++){
		if(Array[j]<= x){
			i++;
			temp= Array[i];
			Array[i]= Array[j];
			Array[j]= temp;
		}
	}
	temp = Array[r];
	Array[r]= Array[i+1];
	Array[i+1]= temp;

	return i+1;
}

void quick_sort(float* Array, int p, int r)
{
	int q;
	if(p< r){
		q= partition(Array, p, r) + 1;
		quick_sort(Array, p, q-1);
		quick_sort(Array, q+1, r);
	}
}