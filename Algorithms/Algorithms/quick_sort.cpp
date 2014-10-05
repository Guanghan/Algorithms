int partition(float* Array, int p, int r)   //p= 1; q= n
{
	float temp;
	int i= p- 2;
	for(int j= p-1; j< r-1; j++){
		if(Array[j]<= Array[r-1]){
			i++;
			temp= Array[i];
			Array[i]= Array[j];
			Array[j]= temp;
		}
	}
	temp = Array[r-1];
	Array[r-1]= Array[i];
	Array[i]= Array[r-1];

	return i+1;
}

void quick_sort(float* Array, int p, int r)
{
	int q;
	if(p< r){
		q= partition(Array, p, r);
		quick_sort(Array, p, q-1);
		quick_sort(Array, p, q+1);
	}
}