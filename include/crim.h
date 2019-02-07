Criminal :: Criminal()
{
	cout<<"Enter the Name: ";
	cin>>name;
	name[30] = '\0'; // prevent memeory violation
	cout<<"Is dead:";
	int t;
	cin>>t;
	if(t){
            alive=true;
    }
    else{
            alive=false;
    }
	gender.set();
	blood.set();
	cout<<"Any diseases: ";
	cin>>disease;
	cout<<"Any physical marks: ";
	cin>>marks;
	cout<<"Enter address: ";
	cin>>address;
	cout<<"Fingerprints: ";
	cin>>finger;
	cout<<"Face: ";
	cin>>head;
	cout<<"DONE";
	return;
}
char* Criminal :: getName(){
	char *ptr = (char*)calloc(sizeof(char),31);
	strcpy(ptr,name);
	return ptr;
}
void Criminal :: editCriminal()
{
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
	if(alive){
	    cout<<"Is alive: Yes\nChange status: ";
        int t;
        cin>>t;
        if(t){
                alive=true;
        }
        else{
                alive=false;
        }
    }
	cout<<"Blood: "<<blood.get();
	cout<<"Change blood: ";
	cin>>r;
	if(r){
		blood.set();
	}
	cout<<"Disease: "<<disease;
	cout<<"Change disease: ";
	cin>>r;
	if(r){
		cout<<"New disease: ";
		cin>>disease;
	}
	cout<<"Physical marks: "<<marks;
	cout<<"Change physical marks: ";
	cin>>r;
	if(r){
		cout<<"New marks: ";
		cin>>marks;
	}
	cout<<"Address: "<<address;
	cout<<"Change address: ";
	cin>>r;
	if(r){
		cout<<"New address: ";
		cin>>address;
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
void Criminal :: showDetails()
{
	cout<<"Name          : "<<name<<"\n";
	cout<<"Gender        : "<<gender.get()<<"\n";
	cout<<"Blood         : "<<blood.get()<<"\n";
    cout<<"Is alive      : "<<alive<<"\n";
	cout<<"Disease       : "<<disease<<"\n";
	cout<<"Physical marks: "<<marks<<"\n";
	cout<<"Address       : "<<address<<"\n";
	cout<<"Finger        : "<<finger<<"\n";
	cout<<"Head          : "<<head<<"\n";
	return;
}