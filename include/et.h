Eternal :: Eternal(){
	cout<<"Enter the Name: ";
	cin>>name;
	name[30] = '\0'; // prevent memeory violation
	gender.set();
	blood.set();
	cout<<"Enter space seperated date: ";
	cin>>date[0]>>date[1]>>date[2];
	cout<<"Enter space seperated time: ";
	cin>>time[0]>>time[1];
	cout<<"Enter the address: ";
	cin>>address;
	cout<<"Enter the reason of death: ";
	cin>>whyDed;
	cout<<"Enter the motive behind death: ";
	cin>>motiveDed;
	cout<<"Any diseases: ";
	cin>>disease;
	cout<<"Birth marks: ";
	cin>>birthMarks;
	cout<<"Physical marks: ";
	cin>>phyMarks;
	cout<<"Found dead at PIN number: ";
	cin>>PIN;
	cout<<"Fingerprints: ";
	cin>>finger;
	cout<<"Face: ";
	cin>>head;
	cout<<"DONE";
	return;
}
char* Eternal :: getName(){
	char *ptr = (char*)calloc(sizeof(char),31);
	strcpy(ptr,name);
	return ptr;
}
void Eternal :: editEternal(){
	char temp[100];
	int r;
	cout<<"Name: "<<name;
	cout<<"Change name: ";
	cin>>r;
	if(r){
		cout<<"New name: ";
		cin>>name;
	}
	cout<<"Gender: "<<gender.get();
	cout<<"Change gender: ";
	cin>>r;
	if(r){
		cout<<"New gender: ";
		gender.set();
	}
	cout<<"Blood: "<<blood.get();
	cout<<"Change blood: ";
	cin>>r;
	if(r){
		blood.set();
	}
	cout<<"Address: "<<address;
	cout<<"Change address: ";
	cin>>r;
	if(r){
		cout<<"New address: ";
		cin>>address;
	}
	cout<<"Reason of death: "<<whyDed;
	cout<<"Change reason: ";
	cin>>r;
	if(r){
		cout<<"New reason: ";
		cin>>whyDed;
	}
	cout<<"Motive for death: "<<whyDed;
	cout<<"Change motive: ";
	cin>>r;
	if(r){
		cout<<"New motive: ";
		cin>>motiveDed;
	}
	cout<<"Date: "<<date;
	cout<<"Change date: ";
	cin>>r;
	if(r){
		cout<<"New date: ";
		cin>>date[0]>>date[1]>>date[2];
	}
	cout<<"Time: "<<time;
	cout<<"Change time: ";
	cin>>r;
	if(r){
		cout<<"New time: ";
		cin>>time[0]>>time[1];
	}
	cout<<"Disease: "<<disease;
	cout<<"Change disease: ";
	cin>>r;
	if(r){
		cout<<"New disease: ";
		cin>>disease;
	}
	cout<<"Physical marks: "<<phyMarks;
	cout<<"Change physical marks: ";
	cin>>r;
	if(r){
		cout<<"New marks: ";
		cin>>phyMarks;
	}
	cout<<"Birth marks: "<<birthMarks;
	cout<<"Change birth marks: ";
	cin>>r;
	if(r){
		cout<<"New marks: ";
		cin>>birthMarks;
	}
	cout<<"Belongings: "<<belongingDed;
	cout<<"Change belongings: ";
	cin>>r;
	if(r){
		cout<<"New belongings: ";
		cin>>belongingDed;
	}
	cout<<"Location: "<<PIN;
	cout<<"Change location: ";
	cin>>r;
	if(r){
		cout<<"New location: ";
		cin>>PIN;
	}
	cout<<"Finger: "<<finger;
	cout<<"Change finger: ";
	cin>>r;
	if(r){
		cout<<"New finger: ";
		cin>>finger;
	}
	cout<<"Head: "<<head;
	cout<<"Change head: ";
	cin>>r;
	if(r){
		cout<<"New head: ";
		cin>>head;
	}
	cout<<"DONE";
	return;
}
void Eternal :: showDetails(){
	cout<<"Name            : "<<name<<"\n";
	cout<<"Gender          : "<<gender.get()<<"\n";
	cout<<"Blood           : "<<blood.get()<<"\n";
	cout<<"Address         : "<<address<<"\n";
	cout<<"Reason of death : "<<whyDed<<"\n";
	cout<<"Motive for death: "<<whyDed<<"\n";
	cout<<"Date            : "<<date<<"\n";
	cout<<"Time            : "<<time<<"\n";
	cout<<"Disease         : "<<disease<<"\n";
	cout<<"Physical marks  : "<<phyMarks<<"\n";
	cout<<"Birth marks     : "<<birthMarks<<"\n";
	cout<<"Belongings      : "<<belongingDed<<"\n";
	cout<<"Location        : "<<PIN<<"\n";
	cout<<"Finger          : "<<finger<<"\n";
	cout<<"Head            : "<<head<<"\n";
	return;
}