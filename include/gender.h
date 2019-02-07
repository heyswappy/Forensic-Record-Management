GenderType :: GenderType(){
	// do nothing
	return;
}
GenderType :: GenderType(int n){
	char t[7];
	cout<<"Enter gender: ";
	cin>>t;
	t[6] = '\0'; // prevent memory violation
	for(int i =0;((t[i]!='\0')||(i<7));i++){
		t[i] = toupper(t[i]);
	}
	genderSetter(t);
	return;
}
GenderType :: GenderType(char *t, int n){
	t[6] = '\0';
	for(int i =0;((t[i]!='\0')||(i<n));i++){
		t[i] = toupper(t[i]);
	}
	genderSetter(t);
	return;
}
void GenderType :: set(){
	char t[7];
	cout<<"Enter gender: ";
	cin>>t;
	t[6] = '\0'; // prevent memory violation
	for(int i =0;i<7;i++){
		t[i] = toupper(t[i]);
	}
	genderSetter(t);
	return;
}
void GenderType :: set(char *t, int n){
	t[6] = '\0'; //prevent memory violation;
	for(int i =0;((t[i]!='\0')||(i<7));i++){
		t[i] = toupper(t[i]);
	}
	genderSetter(t);
	return;
}
char *GenderType :: get(){
	char *arr = (char*)calloc(sizeof(char),7);
	strcpy(arr,gList[gender]);
	return arr;
}
int GenderType :: genderSetter(char *s){
	if(strcmp(s,"MALE")==0){
		gender = 0;
		return gender;
	}
	else if(strcmp(s,"FEMALE")==0){
		gender = 1;
		return gender;
	}
	else if(strcmp(s,"TRANS")==0){
		gender = 2;
		return gender;
	}
	else{
		gender = 0;
		return gender;
	}
	return 0;
}
void GenderType :: print(){
	cout<<"Gender is: "<<gList[gender];
	return;
}
void GenderType :: values(){
	for(int i = 0; i<3; i++){
		cout<<gList[i]<<" ";
	}
	cout<<".\n";
	return;
}