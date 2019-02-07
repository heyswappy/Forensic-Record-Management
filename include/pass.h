Password :: Password(){
    // do nothing
    return;
}
Password :: Password(int n){
    data = 0;
	char pass[31];
	cout<<"Enter the Password (if pass greater then 30 characters then only first 30 characters are treated as pass): ";
	cin>>pass;
	pass[30] = '\0'; // prevent memory violation
	salt(pass);
}
Password :: Password(char *p){
    data = 0;
	char pass[31];
	strcpy(pass,p);
	pass[30] = '\0'; // prevent memory violation
	salt(pass);
}
void Password :: salt(char *p){
	char temp[100];
	int p_i = 0;
	int t_i = 0;
	for(p_i = 0;((p[p_i]!='\0')&&(p_i<=30)&&(t_i<=99)); p_i++,t_i++){
		temp[t_i] = p[p_i];
		{
			temp[++t_i] = 'S';
			temp[++t_i] = 'A';
			temp[++t_i] = 'L';
			temp[++t_i] = 'T';
		}
	}
	temp[t_i] = '\0';
	temp[99] = '\0'; // prevent memory violation
	hashSet(temp);
	return;
}
bool Password :: saltCheck(char *p){
	char temp[100];
	int p_i = 0;
	int t_i = 0;
	for(p_i = 0;((p[p_i]!='\0')&&(p_i<=30)&&(t_i<=99)); p_i++,t_i++){
		temp[t_i] = p[p_i];
		{
			temp[++t_i] = 'S';
			temp[++t_i] = 'A';
			temp[++t_i] = 'L';
			temp[++t_i] = 'T';
		}
	}
	temp[t_i] = '\0';
	temp[99] = '\0'; // prevent memory violation
	if(hashCheck(temp)){
		return true;
	}
	return false;
}
void Password :: hashSet(char *p){
	int t = 0;
	p[99] = '\0'; // prevent memeory violation
	for(int i = 0;((p[i]!='\0'));i++){
		t += p[i]*(i+1);
	}
	data = t;
	return;
}
bool Password :: hashCheck(char *p){
	int t = 0;
	p[99] = '\0'; // prevent memeory violation
	for(int i = 0;((p[i]!='\0'));i++){
		t += p[i]*(i+1);
	}
	if(data == t){
		return true;
	}
	return false;
}
bool Password :: checkPass(){
	char temp[31];
	cout<<"Enter existing password: ";
	cin>>temp;
	temp[30] = '\0'; // prevent memeory violation
	if(saltCheck(temp)){
		return true;
	}
	return false;
}
bool Password :: checkPass(char *s){
	char temp[31];
	strcpy(temp,s);
	temp[30] = '\0'; // prevent memeory violation
	if(saltCheck(temp)){
		return true;
	}
	return false;
}
bool Password :: resetPass(){
	if(checkPass()){
		char temp[31];
		cout<<"Enter new password: ";
		cin>>temp;
		salt(temp);
		return true;
	}
	cout<<"\nWrong Password !!";
	return false;
}
bool Password :: resetPass(char *o_p, char *n_p){
	if(checkPass(o_p)){
		char temp[31];
		strcpy(temp,n_p);
		temp[30] = '\0'; // prevent memeory violation
		salt(temp);
		return true;
	}
	return false;
}
void Password :: vetoSet(char *p){
	// would be used later so that admin can use vetoset
	// to change password w\o orignal password
	char pass[31];
	strcpy(pass,p);
	pass[30] = '\0'; // prevent memory violation
	salt(pass);
	return;
}