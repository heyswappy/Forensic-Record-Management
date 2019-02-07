BloodType :: BloodType(){
	// do nothing
	return;
}
BloodType :: BloodType(int n){
	char t[5];
	cout<<"Enter bloodgroup: ";
	cin>>t;
	t[4]='\0'; // set null to prevent memory violation
	int i = 0;
	while((t[i]!='\0')&&(i<5)){
		t[i] = toupper(t[i]);
		i++;
	}
	char *temp = t;
	bloodSetter(temp);
	return;
}
BloodType :: BloodType(char *s, int n = 5){
	for(int i =0;i<n;i++){
		s[i] = toupper(s[i]);
	}
	s[n-1]='\0'; // set null to prevent memory violation
	bloodSetter(s);
	return;
}
void BloodType :: set(){
	char g[5];
	cout<<"Enter bloodgroup: ";
	cin>>g;
	for(int i =0;(i<5)&&(i!='\0');i++){
		g[i] = toupper(g[i]);
	}
	bloodSetter(g);
	return;
}
void BloodType :: set(char *g){
	bloodSetter(g);
	return;
}
char *BloodType :: get(){
	char *arr = (char*)calloc(sizeof(char),5);
	strcpy(arr,listBlood[blood]);
	return arr;
}
void BloodType :: bloodSetter(char *s){
	if(strcmp(s,"A+")==0){
            blood = 0;
	}
	else if(strcmp(s,"A-")==0){
            blood = 1;
	}
	else if(strcmp(s,"B+")==0){
            blood = 2;
	}
	else if(strcmp(s,"B-")==0){
            blood = 3;
	}
	else if(strcmp(s,"O+")==0){
            blood = 4;
	}
	else if(strcmp(s,"O-")==0){
            blood = 5;
	}
	else if(strcmp(s,"AB+")==0){
            blood = 6;
	}
	else if(strcmp(s,"AB-")==0){
            blood = 7;
	}
	else{
        blood = 0;
	}
	return;
}
void BloodType :: print(){
	cout<<get();
	return;
}
void BloodType :: values(){
	cout<<"Values: ";
	for(int i = 0;i<8;i++){
		cout<<listBlood[i]<<" ";
	}
	cout<<"\n";
}