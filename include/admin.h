Admin :: Admin(){
	session = rand();
	setName(session);
	setUserName(session);
	setGender(session);
	setBlood(session);
	pass = Password(1); // default constructor set it as -1
	adminCount++;
	userCount++;
	return;
}
Admin :: Admin(char *un, char *n, char *p, char *g, char *b){
	// username, name, passowrd, gender, blood
	session = rand();
	setUserName(un,session);
	setName(n,session);
	pass = Password(p);
	setGender(g,session);
	setBlood(b,session);
	adminCount++;
	userCount++;
	return;
}
bool  Admin :: checkPass(){
	// comment to hide the function
	return pass.checkPass();
}
bool  Admin :: checkPass(char *p){
	// comment to hide the function
	return pass.checkPass(p);
}
int   Admin :: getSess(){
	if(checkPass()){
		int key = rand();
		session = key;
		return key;
	}
	return 0;
}
void  Admin :: accessAccountHelp(){
	system("cls");
	cout<<"YOU MAY\n"
		<<" 1. SET YOUR USERNAME USING \"SET UN\"\n"
		<<" 2. SET YOUR NAME USING \"SET NAME\"\n"
		<<" 3. SET YOUR GENDER USING \"SET GEN\"\n"
		<<" 4. SET YOR BLOOD GROUP USING \"SET BLD\"\n"
		<<" 5. ADD ADMIN USING \"ADD ADMIN\"\n"
		<<" 6. ADD DCOTOR USING \"ADD DOC\"\n"
		<<" 7. ADD INVESTIGATOR USING \"ADD INV\"\n"
		<<" 8. ADD CRIMINAL USING \"ADD CRIM\"\n"
		<<" 9. LOG A NEW BODY USING \"ADD BDY\"\n"
		<<"10. SEARCH A DOCTOR USING \"SRCH DOC\"\n"
		<<"11. SEARCH A INVESTIGATOR USING \"SRCH INV\"\n"
		<<"12. SEARCH A CRIMINAL USING \"SRCH CRIM\"\n"
		<<"13. SEARCH A BODY USING \"SRCH BDY\"\n"
		<<"14. REMOVE A DOCTOR USING \"DEL DOC\"\n"
		<<"15. REMOVE A INVESTIGATOR USING \"DEL INV\"\n"
		<<"16. REMOVE A CRIMINAL USING \"DEL CRIM\"\n"
		<<"17. REMOVE A BODY USING \"DEL BDY\"\n"
		<<"18. SIGN OUT USING \"SIGN OUT\"\n"
		<<"19. GET HELP WITH USING \"/?\"\n";
		customContinue();
	return;
}
void  Admin :: accessAccount(int sess){
	if (session != sess){
		cout<<"\nWRONG KEY";
		customContinue();
		return;
	}
	char com[30];
	int i; // for loop
	// label to get commands again and again
	getCom:
	system("cls");
	cout<<"ENTER COMMAND: ";
	customInput(com,30);
	for(i =0;(i<30)&&(com[i]!='\0');i++){
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
	else if(strcmp(com,"ADD ADMIN")==0){
		newAdmin(sess);
		goto getCom;
	}
	else if(strcmp(com,"ADD DOC")==0){
		newDoctor(sess);
		goto getCom;
	}
	else if(strcmp(com,"ADD INV")==0){
		newInvestigator(sess);
		goto getCom;
	}
	else if(strcmp(com,"ADD CRIM")==0){
		newCriminal(sess);
		goto getCom;
	}
	else if(strcmp(com,"ADD BDY")==0){
		newEternal(sess);
		goto getCom;
	}
	else if(strcmp(com,"SRCH DOC")==0){
		showDoctor(sess);
		goto getCom;
	}
	else if(strcmp(com,"SRCH INV")==0){
		showInvestigator(sess);
		goto getCom;
	}
	else if(strcmp(com,"SRCH CRIM")==0){
		showCriminal(sess);
		goto getCom;
	}
	else if(strcmp(com,"SRCH BDY")==0){
		showEternal(sess);
		goto getCom;
	}
	else if(strcmp(com,"DEL DOC")==0){
		delDoctor(sess);
		goto getCom;
	}
	else if(strcmp(com,"DEL INV")==0){
		delInvestigator(sess);
		goto getCom;
	}
	else if(strcmp(com,"DEL CRIM")==0){
		delCriminal(sess);
		goto getCom;
	}
	else if(strcmp(com,"DEL BDY")==0){
		delEternal(sess);
		goto getCom;
	}
	else if(strcmp(com,"SIGN OUT")==0){
		cout<<"SIGNED OUT\n";
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
	// unexpected if-else construct exit
	cout<<"OOPS THAT DIDN'T END WELL !!";
	return;
}
int   Admin :: getCount(){
	// comment to hide
	return adminCount;
}
char* Admin :: type(){
	char *ptr = (char*)calloc(sizeof(char),6);
	strcpy(ptr,"Admin");
	return ptr;
}
void  Admin :: newAdmin(int sess){
	customClr();
	if (session != sess){
		cout<<"\nWRONG KEY";
		return;
	}
	cout<<"ADD NEW ADMINISTRATOR\n\n";
	Admin *ptr = new Admin;
	adminData[string(ptr->getUserName())] = ptr;
	cout<<"\n\nADDED";
	customContinue();
	return;
}
void  Admin :: newDoctor(int sess){
	customClr();
	if (session != sess){
		cout<<"\nWRONG KEY";
		return;
	}
	cout<<"\nADD NEW DOCTOR\n";
	Doctor *ptr = new Doctor;
	doctorData[string(ptr->getUserName())] = ptr;
	cout<<"\n\nADDED";
	customContinue();
	return;
}
void  Admin :: newInvestigator(int sess){
	customClr();
	if (session != sess){
		cout<<"\nWRONG KEY";
		return;
	}
	cout<<"\nADD NEW INVESTIGATOR\n";
	Investigator *ptr = new Investigator;
	investigatorData[string(ptr->getUserName())] = ptr;
	cout<<"\n\nADDED";
	customContinue();
	return;
}
void Admin :: newCriminal(int sess){
	customClr();
	if(sess!=session){
		return;
	}
	cout<<"ADD NEW CRIMINAL\n\n";
	Criminal *ptr = new Criminal;
	criminalData[string(ptr->getName())] = ptr;
	cout<<"\n\nADDED";
	customContinue();
	return;
}
void Admin :: newEternal(int sess){
	customClr();
	if(sess!=session){
		return;
	}
	cout<<"ADD NEW BODY\n\n";
	Eternal *ptr = new Eternal;
	eternalData[string(ptr->getName())] = ptr;
	cout<<"\n\nADDED";
	customContinue();
	return;
}
void Admin :: showDoctor(int sess){
	customClr();
	if(sess!=session){
		return;
	}
	Doctor *temp;
	char username[31];
	cout<<"ENTER THE NAME OF THE DOCTOR: ";
	cin>>username;
	username[30] = '\0'; // prevent memory violation
	map <string,Doctor*,less<string> > :: iterator iter;
	iter = doctorData.find(username);
	if(iter != doctorData.end()){
		// doctor found
		iter->second->showDetails();
		customWait();
		return;
	}
	else{
		cout<<"\nDOCTOR NOT FOUND!";
		customContinue();
	}
	return;
}
void Admin :: showInvestigator(int sess){
	customClr();
	if(sess!=session){
		return;
	}
	Investigator *temp;
	char username[31];
	cout<<"ENTER THE NAME OF THE INVESTIGATOR: ";
	cin>>username;
	username[30] = '\0'; // prevent memory violation
	map <string,Investigator*,less<string> > :: iterator iter;
	iter = investigatorData.find(username);
	if(iter != investigatorData.end()){
		// investigator found
		iter->second->showDetails();
		customWait();
		return;
	}
	else{
		cout<<"\nINVESTIGATOR NOT FOUND!";
		customContinue();
	}
	return;
}
void Admin :: showCriminal(int sess){
	customClr();
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
void Admin :: showEternal(int sess){
	customClr();
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
	else{
		cout<<"\nBODY NOT FOUND!";
		customContinue();
	}
	return;
}
void Admin :: delDoctor(int sess){
	customClr();
	if(sess!=session){
		return;
	}
	Doctor *temp;
	char username[31];
	cout<<"ENTER THE NAME OF THE DOCTOR: ";
	cin>>username;
	username[30] = '\0'; // prevent memory violation
	map <string,Doctor*,less<string> > :: iterator iter;
	iter = doctorData.find(username);
	if(iter != doctorData.end()){
		// doctor found
		cout<<"DOCTOR FOUND!!!\n\nCONFIRM DELETE Y/N ?";
		char d = getch();
		d = toupper(d);
		if(d == 'Y'){
			free(iter->second);
			doctorData.erase(iter);
			cout<<"DOCTOR: "<<username<<"DELETED\n";
			customContinue();
			return;
		}
		else{
			cout<<"ABORTED!!!\n";
			customContinue();
			return;
		}
		return;
	}
	cout<<"\nDOCTOR NOT FOUND!";
	customContinue();
	return;
}
void Admin :: delInvestigator(int sess){
	customClr();
	if(sess!=session){
		return;
	}
	Doctor *temp;
	char username[31];
	cout<<"ENTER THE NAME OF THE INVESTIGATOR: ";
	cin>>username;
	username[30] = '\0'; // prevent memory violation
	map <string,Investigator*,less<string> > :: iterator iter;
	iter = investigatorData.find(username);
	if(iter != investigatorData.end()){
		// investigator found
		cout<<"INVESTIGATOR FOUND!!!\n\nCONFIRM DELETE Y/N ?";
		char d = getch();
		d = toupper(d);
		if(d == 'Y'){
			free(iter->second);
			investigatorData.erase(iter);
			cout<<"INVESTIGATOR: "<<username<<"DELETED\n";
			customContinue();
			return;
		}
		else{
			cout<<"ABORTED!!!\n";
			customContinue();
			return;
		}
		return;
	}
	cout<<"\nINVESTIGATOR NOT FOUND!";
	customContinue();
	return;
}
void Admin :: delCriminal(int sess){
	customClr();
	if(sess!=session){
		return;
	}
	Doctor *temp;
	char username[31];
	cout<<"ENTER THE NAME OF THE CRIMINAL: ";
	cin>>username;
	username[30] = '\0'; // prevent memory violation
	map <string,Criminal*,less<string> > :: iterator iter;
	iter = criminalData.find(username);
	if(iter != criminalData.end()){
		// criminal found
		cout<<"CRIMINAL FOUND!!!\n\nCONFIRM DELETE Y/N ?";
		char d = getch();
		d = toupper(d);
		if(d == 'Y'){
			free(iter->second);
			criminalData.erase(iter);
			cout<<"INVESTIGATOR: "<<username<<"DELETED\n";
			customContinue();
			return;
		}
		else{
			cout<<"ABORTED!!!\n";
			customContinue();
			return;
		}
		return;
	}
	cout<<"\nCRIMINAL NOT FOUND!";
	customContinue();
	return;
}
void Admin :: delEternal(int sess){
	customClr();
	if(sess!=session){
		return;
	}
	Doctor *temp;
	char username[31];
	cout<<"ENTER THE NAME OF THE BODY: ";
	cin>>username;
	username[30] = '\0'; // prevent memory violation
	map <string,Eternal*,less<string> > :: iterator iter;
	iter = eternalData.find(username);
	if(iter != eternalData.end()){
		// criminal found
		cout<<"BODY FOUND!!!\n\nCONFIRM DELETE Y/N ?";
		char d = getch();
		d = toupper(d);
		if(d == 'Y'){
			free(iter->second);
			eternalData.erase(iter);
			cout<<"BODY: "<<username<<"DELETED\n";
			customContinue();
			return;
		}
		else{
			cout<<"ABORTED!!!\n";
			customContinue();
			return;
		}
		return;
	}
	cout<<"\nBODY NOT FOUND!";
	customContinue();
	return;
}

void Admin :: signOut(){
	session = -1;
	return;
}