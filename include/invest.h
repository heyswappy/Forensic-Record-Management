Investigator :: Investigator(){
	cout<<"Investigator Id: ";
	cin>>investigatorId;
	dept.set();
	cases = 0;
	investigatorCount++;
	nonAdminCount++;
	userCount++;
	return;
}
Investigator :: Investigator(char *s, char *un, char *p, char *g, char *b, char *d, int id):NonAdmin( s, un, p, g, b){
	// use of intialiser list
	// constructor name, username, pass, gender, blood, dept, medId
	investigatorId = id;
	dept.set(d);
	investigatorCount++;
	nonAdminCount++;
	userCount++;
}
char* Investigator :: getDept(int sess){
	if ((session == -1) || (session != sess)){
		return NULL;
	}
	return dept.get();
}
int   Investigator :: getId(int sess){
	if ((session == -1) || (session != sess)){
		return 0;
	}
	return investigatorId;
}
bool  Investigator :: setDept(int sess){
	if ((session == -1) || (session != sess)){
		return false;
	}
	dept.set();
	return true;
}
bool  Investigator :: setDept(char *d, int sess){
	if ((session == -1) || (session != sess)){
		return false;
	}
	dept.set(d);
	return true;
}
bool  Investigator :: setId(int sess){
	if ((session == -1) || (session != sess)){
		return false;
	}
	cout<<"New Id:";
	cin>>investigatorId;
	return true;
}
bool  Investigator :: setId(int n, int sess){
	if ((session == -1) || (session != sess)){
		return false;
	}
	investigatorId = n;
	return true;
}
int   Investigator :: getCount(){
	// comment to hide
	return investigatorCount;
}
char* Investigator :: type(){
    char *ptr = (char*)calloc(sizeof(char),13);
	strcpy(ptr,"Investigator");
	return ptr;
}
void Investigator :: accessAccountHelp(){
	cout<<"YOU MAY\n"
		<<" 1. SET YOUR USERNAME USING \"SET UN\"\n"
		<<" 2. SET YOUR NAME USING \"SET NAME\"\n"
		<<" 3. SET YOUR GENDER USING \"SET GEN\"\n"
		<<" 4. SET YOUR BLOOD GROUP USING \"SET BLD\"\n"
		<<" 5. SET YOUR DEPARTMENT USING \"SET DPT\"\n"
		<<" 6. SET YOR INVESTIGATOR ID USING \"SET ID\"\n"
		<<" 7. CREATE LOG OF NEW CRIMINAL USING \"NEW CRIM\"\n"
		<<" 8. SEARCH A CRIMINAL USING \"SRCH CRIM\"\n"
		<<" 9. EDIT A CRIMINAL USING \"EDIT CRIM\"\n"
		<<"10. ENLIST ALL BODIES USING \"ALL CRIM\"\n"
		<<"7. SIGN OUT USING \"SIGN OUT\"\n"
		<<"8. GET HELP WITH USING \"/?\"\n";
		customContinue();
	return;
}
void Investigator :: accessAccount(int sess){
	if ((session == -1) || (session != sess)){
		return;
	}
	char com[40];
	// label to get commands again and again
	getCom:
	system("cls");
	cout<<"ENTER COMMAND: ";
	customInput(com,30);
	for(int i =0;(i<15)&&(com[i]!='\0');i++){
		com[i] = toupper(com[i]);
	}
	if(strcmp(com,"SET UN")==0){
		setUserName(sess);
		goto getCom;
	}
	else if(strcmp(com,"SET NAME")==0){
		setName(sess);
		goto getCom;
	}
	else if(strcmp(com,"SET GEN")==0){
		setGender(sess);
		goto getCom;
	}
	else if(strcmp(com,"SET BLD")==0){
		setBlood(sess);
		goto getCom;
	}
	else if(strcmp(com,"SET DPT")==0){
		setDept(sess);
		goto getCom;
	}
	else if(strcmp(com,"SET ID")==0){
		setId(sess);
		goto getCom;
	}
	else if(strcmp(com,"NEW CRIM")==0){
		newCriminal(sess);
		cout<<"wait";
		char s;
		cin>>s;
		goto getCom;
	}
	else if(strcmp(com,"SRCH CRIM")==0){
		showCriminal(sess);
		goto getCom;
	}
	else if(strcmp(com,"EDIT CRIM")==0){
		editCriminal(sess);
		goto getCom;
	}
	else if(strcmp(com,"ALL CRIM")==0){
		enlistAllCriminal(sess);
		goto getCom;
	}
	else if(strcmp(com,"SIGN OUT")==0){
		cout<<"SIGNED OUT";
		return;
	}
	else if(strcmp(com,"/?")==0){
		accessAccountHelp();
		goto getCom;
	}
	else{
		cout<<"YOU ENTERED SOMETHING ELSE\n";
		cout<<"PRESS /? TO GET HELP\n";
		customContinue();
		goto getCom;
	}
	cout<<"OOPS THAT DIDN'T END WELL !!";
	return;
}
void Investigator :: newCriminal(int sess){
	if(sess!=session){
		return;
	}
	Criminal *ptr = new Criminal;
	criminalData[string(ptr->getName())] = ptr;
	return;
}
void Investigator :: editCriminal(int sess){
	if(sess!=session){
		return;
	}
	Criminal *temp;
	char username[31];
	cout<<"ENTER THE NAME OF THE CRIMINAL: ";
	cin>>username;
	username[30] = '\0'; // prevent memory violation
	map <string,Criminal*,less<string> > :: iterator iter;
	iter = criminalData.find(username);
	if(iter != criminalData.end()){
		// body found
		iter->second->editCriminal();
		return;
	}
	cout<<"\nCRIMINAL NOT FOUND!";
	return;
}
void Investigator :: showCriminal(int sess){
	if(sess!=session){
		return;
	}
	Criminal *temp;
	char username[31];
	cout<<"ENTER THE NAME OF THE CRIMINAL: ";
	cin>>username;
	username[30] = '\0'; // prevent memory violation
	map <string,Criminal*,less<string> > :: iterator iter;
	iter = criminalData.find(username);
	if(iter != criminalData.end()){
		// body found
		iter->second->showDetails();
		customWait();
		return;
	}
	else{
		cout<<"\nCRIMINAL NOT FOUND!";
		customContinue();
	}
	return;
}
void Investigator :: enlistAllCriminal(int sess){
	if(sess!=session){
		return;
	}
	map <string,Criminal*,less<string> > :: iterator iter;
	if(criminalData.empty()){
		cout<<"\nNO CRIMINALS TO SHOW!!!";
		return;
	}

	for(iter = criminalData.begin(); iter != criminalData.end(); iter++){
		cout<<"\n"<<iter->second->getName();
	}
	return;
}
void Investigator :: showDetails(){
	cout<<"Name            : "<<name<<"\n";
	cout<<"UserName        : "<<userName<<"\n";
	cout<<"ID              : "<<id<<"\n";
	cout<<"Gender          : "<<gender.get()<<"\n";
	cout<<"Blood           : "<<blood.get()<<"\n";
	cout<<"Investigator ID : "<<investigatorId<<"\n";
	cout<<"Department      : "<<dept.get()<<"\n";
	return;
}
void Investigator :: signOut(){
	session = -1;
	return;
}