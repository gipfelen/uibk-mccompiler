int main()
{
	int first;
	int second;
	int third;

	first = 5;
	second = 7;
	third = 5;

	if(first > second){
		print("true");
		print_nl();
	}else{
		print("false");
		print_nl();
	}
	if(second > first){
		print("true");
		print_nl();
	}else{
		print("false");
		print_nl();
	}
	if(first > third){
		print("true");
		print_nl();
	}else{
		print("false");
		print_nl();
	}

	return 0;
}

