#define maxDept 3 // references department.h
using namespace std;
class BloodType;
class DepartmentType;
class GenderType;
class Password;
class User;
class Admin;
class NonAdmin;
class Doctor;
class Investigator;
class Criminal;
class Eternal;
map<string,Admin*,less<string> > adminData;
map<string,Doctor*,less<string> > doctorData;
map<string,Investigator*,less<string> > investigatorData;
map<string,Criminal*,less<string> > criminalData;
map<string,Eternal*,less<string> > eternalData;

/***************************FORMATTING FUNCTIONS****************************/
void customContinue(){
	cout<<"HIT ANY KEY TO CONTINUE...";
	fflush(stdin);
	getchar();
	system("cls");
}
void customClr(){
	// utility
	system("cls");
}
void customWait(){
	// utility
	getch();
}
void customInput(char *ptr, int n = 0){
	char t;
	int count = 0;
	fflush(stdin);
	while(count<n){
		t = getchar();
		if(t=='\n'){
			ptr[count++] = '\0';
			return;
		}
		ptr[count++] = t;
	}
	return;
}