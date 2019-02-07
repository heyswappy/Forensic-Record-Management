NonAdmin :: NonAdmin(){
	session = rand();
	setName(session);
	setUserName(session);
	pass = Password(1); // default constructor set it as -1
	setGender(session);
	setBlood(session);
	nonAdminCount++;
	userCount++;
}
NonAdmin :: NonAdmin(char *un, char* n, char *p, char *g, char *b){
	// username, name ,passowrd, gender, blood ,name
	session = rand();
	setUserName(un,session);
	setName(n,session);
	pass = Password(1);
	setGender(g,session);
	setBlood(b,session);
	nonAdminCount++;
	userCount++;
	return;
}
bool  NonAdmin :: checkPass(){
	// comment to hide the function
	return pass.checkPass();
}
bool  NonAdmin :: checkPass(char *p){
	// comment to hide the function
	return pass.checkPass(p);
}
int   NonAdmin :: getSess(){
	int key = rand();
	if(checkPass()){
		session = key;
		return key;
	}
	return 0;
}
int   NonAdmin :: getCount(){
	// comment to hide
	return nonAdminCount;
}
char* NonAdmin :: type(){
	char *ptr = (char*)calloc(sizeof(char),9);
	strcpy(ptr,"NonAdmin");
	return ptr;
}