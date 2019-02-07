User :: User(int n = -1){
	if (n==-1){
		userCount++;
		return;
	}
	cout<<"Enter the Name: ";
	cin>>name;
	name[30] = '\0'; // prevent memeory violation
	gender.set();
	blood.set();
	userCount++;
	return;
}
User :: User(char *un, char *n, char *g, char *b){
	// ArgList: username, name, gender, blood
	strcpy(userName,un);
	strcpy(name,n);
	gender.set(g);
	blood.set(b);
	name[30] = '\0'; // prevent memeory violation
	userName[30] = '\0'; // prevent memeory violation
	userCount++;
	return;
}
char* User :: getName(int sess)
{
	if ((session == -1) || (session != sess)){
		return NULL;
	}
	char *arr = (char*)calloc(sizeof(char),31);
	strcpy(arr,name);
	return arr;
}
char* User :: getGender(int sess)
{
	if ((session == -1) || (session != sess)){
		return NULL;
	}
	// return the object
	return gender.get();
}
char* User :: getBlood(int sess)
{
	if ((session == -1) || (session != sess)){
		return NULL;
	}
	// return the object
	return blood.get();
}
char* User :: getUserName()
{
	char *ptr = (char*)calloc(sizeof(char),31);
	strcpy(ptr,userName);
	return ptr;
}
int   User :: getCount()
{
	// returns the number of users
	return userCount;
}
bool  User :: setName(int sess)
{
	if ((session == -1) || (session != sess)){
		return false;
	}
	char arr[31];
	cout<<"Enter the Name: ";
	arr[30] = '\0'; // prevent memory violation
	cin>>arr;
	strcpy(name,arr);
	return true;
}
bool  User :: setName(char *s, int sess)
{
	if ((session == -1) || (session != sess)){
		return false;
	}
	char arr[31];
	strcpy(arr,s);
	arr[30] = '\0'; // prevent memory violation
	strcpy(name,arr);
	return true;
}
bool  User :: setGender(int sess)
{
	if ((session == -1) || (session != sess)){
		return false;
	}
	// internal method
	gender.set();
	return true;
}
bool  User :: setGender(char *g, int sess)
{
	if ((session == -1) || (session != sess)){
		return false;
	}
	// internal method
	gender.set(g);
	return true;
}
bool  User :: setBlood(int sess)
{
	if ((session == -1) || (session != sess)){
		return false;
	}
	// internal method
	blood.set();
	return true;
}
bool  User :: setBlood(char *b, int sess)
{
	if ((session == -1) || (session != sess)){
		return false;
	}
	// internal method
	blood.set(b);
	return true;
}
bool  User :: setUserName(int sess)
{
	if ((session == -1) || (session != sess)){
		return false;
	}
	char newname[31];
	cout<<"Enter new username: ";
	cin>>newname;
	newname[30] = '\0'; // prevent memory error
	strcpy(userName,newname);
	return true;
}
bool  User :: setUserName(char *s, int sess)
{
	if ((session == -1) || (session != sess)){
		return false;
	}
	char newname[31];
	strcpy(newname,s);
	newname[30] = '\0'; // prevent memory error
	strcpy(userName,newname);
	return true;
}
char* User :: type()
{
	char *ptr = (char*)calloc(sizeof(char),5);
	strcpy(ptr,"User");
	return ptr;
}
bool  User :: checkUserName()
{
	char un[31];
	cout<<"Enter username: ";
	cin>>un;
	un[30] = '\0'; //prevent memory violation
	if(strcmp(userName,un)==0){
		return true;
	}
	return false;
}
bool  User :: checkUserName(char *un)
{
	if(strcmp(userName,un)==0){
		return true;
	}
	return false;
}