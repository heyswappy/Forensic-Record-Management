class BloodType{
private:
	int blood;
	static char listBlood[8][4];
	void bloodSetter(char *s);
public:
	BloodType();
	BloodType(int n);
	BloodType(char *s, int n);
	void set();
	void set(char *s);
	char *get();
	void print();
	void values();
};
char BloodType :: listBlood[8][4] = {"A+","A-","B+","B-","O+","O-","AB+","AB-"};

class DepartmentType{
private:
	int dept;
	static char listDepartment[maxDept][10];
	int departmentSetter(char* s);
public:
	DepartmentType();
	DepartmentType(int n);
	DepartmentType(char *s, int n);
	void set();
	void set(char *s, int n=10);
	char *get();
	void print();
	void values();
};
char DepartmentType :: listDepartment[maxDept][10] = {"PHY","MOR","DED"};

class GenderType{
private:
	int gender;
	static char gList[3][7];
	int genderSetter(char *s);
public:
	GenderType();
	GenderType(int n);
	GenderType(char *t, int n=7);
	void set();
	void set(char *t, int n=7);
	char *get();
	void print();
	void values();
};
char GenderType :: gList[3][7] = {"MALE","FEMALE","TRANS"};

class Password{
private:
	long int data;
	void salt(char *s);
	bool saltCheck(char *s);
	void hashSet(char *s);
	bool hashCheck(char *s);
	void vetoSet(char *s);
public:
	Password();
	Password(int n);
	Password(char *s);
	bool checkPass();
	bool checkPass(char *s);
	bool resetPass();
	bool resetPass(char *a, char*b);
};

class User{
protected:
	char userName[31];
	char name[31];
	int session;
	int id;
	GenderType gender;
	BloodType blood;
	static int userCount;
public:
	User(int n);
	User(char *un, char *n, char *g, char *b);
	char* getName(int sess);
	char* getGender(int sess);
	char* getBlood(int sess);
	char* getUserName();
	int   getCount();
	bool  setName(int sess);
	bool  setName(char *s, int sess);
	bool  setGender(int sess);
	bool  setGender(char *g,int sess);
	bool  setBlood(int sess);
	bool  setBlood(char *b,int sess);
	bool  setUserName(int sess);
	bool  setUserName(char *un, int sess);
	bool  checkUserName();
	bool  checkUserName(char *s);
	char* type();
};
int   User :: userCount =0;

class Admin : public User{
private:
	Password pass;
	static int adminCount;
	/* NEW ENTITIES */
	void newAdmin(int s);
	void newDoctor(int s);
	void newInvestigator(int s);
	void newCriminal(int s);
	void newEternal(int s);
	/* SEARCH ENTITIES */
	void showDoctor(int s);
	void showInvestigator(int s);
	void showCriminal(int s);
	void showEternal(int s);
	/* DELETE ENTITIES */
	void delDoctor(int s);
	void delInvestigator(int s);
	void delCriminal(int s);
	void delEternal(int s);
public:
	Admin();
	Admin(char *un, char *p, char *g, char *b, char *s);
	bool checkPass();
	bool checkPass(char *pass);
	int getSess();
	void accessAccountHelp();
	void accessAccount(int sess);
	void signOut();
	int getCount();
	char *type();
};
int   Admin :: adminCount = 0;

class NonAdmin : public User{
protected:
	Password pass;
	static int nonAdminCount;
public:
	NonAdmin();
	NonAdmin(char *un, char *p, char *g, char *b, char *s);
	bool checkPass();
	bool checkPass(char *p);
	int getSess();
	int getCount();
	char *type();
};
int   NonAdmin :: nonAdminCount = 0;

class Doctor : public NonAdmin{
private:
	int medicalId;
	int cases;
	DepartmentType dept;
	static int doctorCount;
	void newEternal(int sess);
	void editEternal(int sess);
	void showEternal(int sess);
	void enlistAllEternal(int sess);
public:
	Doctor();
	Doctor(char *s, char *un, char *p, char *g, char *b, char *d, int id);
	char *getDept(int sess);
	int getId(int sess);
	bool setDept(int sess);
	bool setDept(char *d, int sess);
	bool setId(int sess);
	bool setId(int n, int sess);
	int getCount();
	char *type();
	void accessAccountHelp();
	void accessAccount(int sess);
	void showDetails();
	void signOut();
};
int   Doctor :: doctorCount = 0;

class Investigator : public NonAdmin{
private:
	int investigatorId;
	DepartmentType dept;
	int cases;
	static int investigatorCount;
	void newCriminal(int sess);
	void editCriminal(int sess);
	void showCriminal(int sess);
	void enlistAllCriminal(int sess);
public:
	Investigator();
	Investigator(char *s, char *un, char *p, char *g, char *b, char *d, int id);
	char *getDept(int sess);
	int getId(int sess);
	bool setDept(int sess);
	bool setDept(char *d, int sess);
	bool setId(int sess);
	bool setId(int n, int sess);
	int getCount();
	char *type();
	void accessAccountHelp();
	void accessAccount(int sess);
	void showDetails();
	void signOut();
};
int   Investigator :: investigatorCount = 0;

class Criminal{
private:
	bool alive;
	char name[31];
	GenderType gender;
	BloodType blood;
	char disease[100];
	char marks[100];
	char address[100];
	int finger;
	int head;
public:
	Criminal();
	char *getName();
	void editCriminal();
	void showDetails();
};

class Eternal{
private:
	char name[31];
	GenderType gender;
	BloodType blood;
	char whyDed[100];
	char motiveDed[100];
	int date[3];
	int time[2];
	char address[100];
	char disease[100];
	char phyMarks[100];
	char birthMarks[100];
	char belongingDed[100];
	int PIN;
	int finger;
	int head;
public:
	Eternal();
	char *getName();
	void editEternal();
	void showDetails();
};