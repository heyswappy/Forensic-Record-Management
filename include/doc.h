Doctor :: Doctor(){
	cout<<"Medical Id: ";
	cin>>medicalId;
	dept.set();
	cases = 0;
	doctorCount++;
	nonAdminCount++;
	userCount++;
	return;
}
Doctor :: Doctor(char *s, char *un, char *p, char *g, char *b, char *d, int id):NonAdmin( s, un, p, g, b){
	// use of intialiser list
	// constructor name, username, pass, gender, blood, dept, medId
	medicalId = id;
	dept.set(d);
	doctorCount++;
	nonAdminCount++;
	userCount++;
}
char* Doctor :: getDept(int sess){
	if ((session == -1) || (session != sess)){
		return NULL;
	}
	return dept.get();
}
int   Doctor :: getId(int sess){
	if ((session == -1) || (session != sess)){
		return 0;
	}
	return medicalId;
}
bool  Doctor :: setDept(int sess){
	if ((session == -1) || (session != sess)){
		return false;
	}
	dept.set();
	return true;
}
bool  Doctor :: setDept(char *d, int sess){
	if ((session == -1) || (session != sess)){
		return false;
	}
	dept.set(d);
	return true;
}
bool  Doctor :: setId(int sess){
	if ((session == -1) || (session != sess)){
		return false;
	}
	cout<<"New Id:";
	cin>>medicalId;
	return true;
}
bool  Doctor :: setId(int n, int sess){
	if ((session == -1) || (session != sess)){
		return false;
	}
	medicalId = n;
	return true;
}
int   Doctor :: getCount(){
	// comment to hide
	return doctorCount;
}
char* Doctor :: type(){
    char *ptr = (char*)calloc(sizeof(char),7);
	strcpy(ptr,"Doctor");
	return ptr;
}
void  Doctor :: accessAccountHelp(){
	cout<<"YOU MAY\n"
		<<" 1. SET YOUR USERNAME USING \"SET UN\"\n"
		<<" 2. SET YOUR NAME USING \"SET NAME\"\n"
		<<" 3. SET YOUR GENDER USING \"SET GEN\"\n"
		<<" 4. SET YOUR BLOOD GROUP USING \"SET BLD\"\n"
		<<" 5. SET YOUR DEPARTMENT USING \"SET DPT\"\n"
		<<" 6. SET YOR MEDICAL ID USING \"SET ID\"\n"
		<<" 7. CREATE LOG OF NEW BODY USING \"NEW BDY\"\n"
		<<" 8. SEARCH A BODY USING \"SRCH BDY\"\n"
		<<" 9. EDIT A BODY USING \"EDIT BDY\"\n"
		<<"10. ENLIST ALL BODIES USING \"ALL BDY\"\n"
		<<"11. SIGN OUT USING \"SIGN OUT\"\n"
		<<"12. GET HELP WITH USING \"/?\"\n";
		customContinue();
	return;
}
void  Doctor :: accessAccount(int sess){
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
	else if(strcmp(com,"NEW BDY")==0){
		newEternal(sess);
		goto getCom;
	}
	else if(strcmp(com,"SRCH BDY")==0){
		showEternal(sess);
		goto getCom;
	}
	else if(strcmp(com,"EDIT BDY")==0){
		editEternal(sess);
		goto getCom;
	}
	else if(strcmp(com,"ALL BDY")==0){
		enlistAllEternal(sess);
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
void Doctor :: newEternal(int sess){
	if(sess!=session){
		return;
	}
	Eternal *ptr = new Eternal;
	eternalData[string(ptr->getName())] = ptr;
	return;
}
void Doctor :: editEternal(int sess){
	if(sess!=session){
		return;
	}
	Eternal *temp;
	char username[31];
	cout<<"ENTER THE NAME OF THE BODY: ";
	cin>>username;
	username[30] = '\0'; // prevent memory violation
	map <string, Eternal*, less<string> > :: iterator iter;
	iter = eternalData.find(string(username));
	if(iter != eternalData.end()){
		// body found
		iter->second->editEternal();
		return;
	}
	cout<<"\nBODY NOT FOUND!";
	return;
}
void Doctor :: showEternal(int sess){
	if(sess!=session){
		return;
	}
	Eternal *temp;
	char username[31];
	cout<<"ENTER THE NAME OF THE BODY: ";
	cin>>username;
	username[30] = '\0'; // prevent memory violation
	map <string,Eternal*,less<string> > :: iterator iter;
	iter = eternalData.find(username);
	if(iter != eternalData.end()){
		// body found
		iter->second->showDetails();
		customWait();
		return;
	}
	cout<<"\nBODY NOT FOUND!";
	return;
}
void Doctor :: enlistAllEternal(int sess){
	if(sess!=session){
		return;
	}
	map <string,Eternal*,less<string> > :: iterator iter;
	if(eternalData.empty()){
		cout<<"\nNO BODIES TO SHOW!!!";
		customContinue();
		return;
	}
	for(iter = eternalData.begin(); iter != eternalData.end(); iter++){
		cout<<"\n"<<iter->second->getName();
	}
	customWait();
	return;
}
void Doctor :: showDetails(){
	cout<<"Name            : "<<name<<"\n";
	cout<<"UserName        : "<<userName<<"\n";
	cout<<"ID              : "<<id<<"\n";
	cout<<"Gender          : "<<gender.get()<<"\n";
	cout<<"Blood           : "<<blood.get()<<"\n";
	cout<<"Medical ID      : "<<medicalId<<"\n";
	cout<<"Cases           : "<<cases<<"\n";
	cout<<"Department      : "<<dept.get()<<"\n";
	return;
}
void Doctor :: signOut(){
	session = -1;
	return;
}