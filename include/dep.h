DepartmentType :: DepartmentType(){
	// do nothing
	return;
}
DepartmentType :: DepartmentType(int n){
	char t[10];
	cout<<"Enter the department: ";
	cin>>t;
	t[10] = '\0'; // prevent memory violation
	for(int i =0;((t[i]!='\n')&&(i<10));i++){
		t[i] = toupper(t[i]);
	}
	departmentSetter(t);
	return;
}
DepartmentType :: DepartmentType(char *t, int n = 10){
	for(int i =0;((t[i]!='\n')&&(i<n));i++){
		t[i] = toupper(t[i]);
	}
	departmentSetter(t);
	return;
}
void DepartmentType :: set(){
	char t[10];
	cout<<"Enter the department: ";
	cin>>t;
	t[9] = '\0'; // prevent memory violation
	for(int i =0;((t[i]!='\n')&&(i<10));i++){
		t[i] = toupper(t[i]);
	}
	int k = departmentSetter(t);
	cout<<"Department set to "<<listDepartment[k]<<".";
	return;
}
void DepartmentType :: set(char *t, int n){
	t[9] = '\0'; // prevent memory violation
	for(int i =0;((t[i]!='\n')&&(i<10));i++){
		t[i] = toupper(t[i]);
	}
	int k = departmentSetter(t);
	cout<<"Department set to "<<listDepartment[k]<<".";
	return;
}
char *DepartmentType :: get(){
	char *arr = (char*)calloc(sizeof(char),10);
	strcpy(arr,listDepartment[dept]);
	return arr;
}
int DepartmentType :: departmentSetter(char *s){
	dept = -1;
	int i;
	for(i=0;i<maxDept;i++){
		if(strcmp(s,listDepartment[i])==0){
			dept = i;
			return i;
		}
	}
	if(dept==-1){
		dept = 0;
		cout<<"Department not found.";
		return -1;
	}
	return 0;
}
void DepartmentType :: print(){
	cout<<listDepartment[dept];
	return;
}
void DepartmentType :: values(){
	for(int i = 0; i<maxDept;i++){
		cout<<listDepartment[i]<<" ";
	}
	cout<<".";
	return;
}