/*
	C++ PROGRAM FOR FORENSIC RECORD STORAGE
	AUTHOR: SWAPNIL SAXENA
	COMPUTER SCIENCE AND ENGINEERING
	JAYPEE INSTITUTE OF INFORMATION TECHNOLOGY
*/

#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string>
#include<map>
#include<string.h>
#include<ctype.h>
#include<conio.h>
#include "include/global.h"
#include "include/prototype.h"
#include "include/blood.h"
#include "include/dep.h"
#include "include/gender.h"
#include "include/pass.h"
#include "include/user.h"
#include "include/admin.h"
#include "include/nadmin.h"
#include "include/doc.h"
#include "include/invest.h"
#include "include/crim.h"
#include "include/et.h"

/***************************UTILITY FUNCTIONS****************************/
void importAdmin();
void importDoctor();
void importInvestigator();
void importCriminal();
void importEternal();
void exportAdmin();
void exportDoctor();
void exportInvestigator();
void exportCriminal();
void exportEternal();
void mainFunctionsHelp();
void mainFunctions();
void logInToAccountHelp();
void logInToAccount();

/***************************MAIN FUNCTION****************************/

int main(){
	importAdmin();
	importDoctor();
	importInvestigator();
	importCriminal();
	importEternal();
	/****************************WRITE HERE************************************/
	/*Admin *p  = new Admin;
	adminData[p->getUserName()]=p;*/
	mainFunctions();
	/****************************WRITE HERE************************************/
	exportAdmin();
	exportDoctor();
	exportInvestigator();
	exportCriminal();
	exportEternal();
	cout<<"EXPORT SUCCESSFUL";
	return 1;
}

/***************************UTILITY FUNCTIONS****************************/
void importAdmin(){
	FILE *fp;
	int objSize = sizeof(Admin);
	int fileSize = 0;
	int objNum = 0;
	Admin *temp;
	fp = fopen("admin.bin","r");
	// check if the file exists
	// if not make a file of such name
	if(!fp){
		fp = fopen("admin.bin","w");
		fclose(fp);
		fp = fopen("admin.bin","r");
	}
	// calculate size of file
	if (fp){
        fseek (fp, 0, SEEK_END);
        fileSize = ftell(fp);
        rewind(fp);
    }
    else{
    	// if file pointer is still null something's wrong
    	cout<<"FATAL ERROR: FILE POINTER NOT FOUND!!\n EXITING";
		exit(0);
    }
    // calculate the number of objects saved
    objNum = fileSize/objSize;
    // read them iteratively
    for(int i=0; i<objNum; i++){
    	temp = (Admin*)malloc(objSize);
		fread(temp,objSize,1,fp);
		adminData[string(temp->getUserName())] = temp;
    }
	fclose(fp);
	return;
}
void importDoctor(){
	FILE *fp;
	int objSize = sizeof(Doctor);
	int fileSize = 0;
	int objNum = 0;
	Doctor *temp;
	fp = fopen("doctor.bin","r");
	// check if the file exists
	// if not make a file of such name
	if(!fp){
		fp = fopen("doctor.bin","w");
		fclose(fp);
		fp = fopen("doctor.bin","r");
	}
	// calculate size of file
	if (fp){
        fseek (fp, 0, SEEK_END);
        fileSize = ftell(fp);
        rewind(fp);
    }
    else{
    	// if file pointer is still null something's wrong
    	cout<<"FATAL ERROR: FILE POINTER NOT FOUND!!\n EXITING";
		exit(0);
    }
    // calculate the number of objects saved
    objNum = fileSize/objSize;
    // read them iteratively
    for(int i=0; i<objNum; i++){
    	temp = (Doctor*)malloc(objSize);
		fread(temp,objSize,1,fp);
		doctorData[string(temp->getUserName())] = temp;
    }
	fclose(fp);
	return;
}
void importInvestigator(){
	FILE *fp;
	int objSize = sizeof(Investigator);
	int fileSize = 0;
	int objNum = 0;
	Investigator *temp;
	fp = fopen("investigator.bin","r");
	// check if the file exists
	// if not make a file of such name
	if(!fp){
		fp = fopen("investigator.bin","w");
		fclose(fp);
		fp = fopen("investigator.bin","r");
	}
	// calculate size of file
	if (fp){
        fseek (fp, 0, SEEK_END);
        fileSize = ftell(fp);
        rewind(fp);
    }
    else{
    	// if file pointer is still null something's wrong
    	cout<<"FATAL ERROR: FILE POINTER NOT FOUND!!\n EXITING";
		exit(0);
    }
    // calculate the number of objects saved
    objNum = fileSize/objSize;
    // read them iteratively
    for(int i=0; i<objNum; i++){
    	temp = (Investigator*)malloc(objSize);
		fread(temp,objSize,1,fp);
		investigatorData[string(temp->getUserName())] = temp;
    }
	fclose(fp);
	return;
}
void importCriminal(){
	FILE *fp;
	int objSize = sizeof(Criminal);
	int fileSize = 0;
	int objNum = 0;
	Criminal *temp;
	fp = fopen("criminal.bin","r");
	// check if the file exists
	// if not make a file of such name
	if(!fp){
		fp = fopen("criminal.bin","w");
		fclose(fp);
		fp = fopen("criminal.bin","r");
	}
	// calculate size of file
	if (fp){
        fseek (fp, 0, SEEK_END);
        fileSize = ftell(fp);
        rewind(fp);
    }
    else{
    	// if file pointer is still null something's wrong
    	cout<<"FATAL ERROR: FILE POINTER NOT FOUND!!\n EXITING";
		exit(0);
    }
    // calculate the number of objects saved
    objNum = fileSize/objSize;
    // read them iteratively
    for(int i=0; i<objNum; i++){
    	temp = (Criminal*)malloc(objSize);
		fread(temp,objSize,1,fp);
		criminalData[string(temp->getName())] = temp;
    }
	fclose(fp);
	return;
}
void importEternal(){
	FILE *fp;
	int objSize = sizeof(Eternal);
	int fileSize = 0;
	int objNum = 0;
	Eternal *temp;
	fp = fopen("eternal.bin","r");
	// check if the file exists
	// if not make a file of such name
	if(!fp){
		fp = fopen("eternal.bin","w");
		fclose(fp);
		fp = fopen("eternal.bin","r");
	}
	// calculate size of file
	if (fp){
        fseek (fp, 0, SEEK_END);
        fileSize = ftell(fp);
        rewind(fp);
    }
    else{
    	// if file pointer is still null something's wrong
    	cout<<"FATAL ERROR: FILE POINTER NOT FOUND!!\n EXITING";
		exit(0);
    }
    // calculate the number of objects saved
    objNum = fileSize/objSize;
    // read them iteratively
    for(int i=0; i<objNum; i++){
    	temp = (Eternal*)malloc(objSize);
		fread(temp,objSize,1,fp);
		eternalData[string(temp->getName())] = temp;
    }
	fclose(fp);
	return;
}
void exportAdmin(){
	FILE *fp;
	fp = fopen("admin.bin","w");
	int objSize = sizeof(Admin);
	Admin *temp;
	if(adminData.empty()){
		return;
	}
	map<string,Admin*,less<string> >::iterator iter;
	for(iter = adminData.begin(); iter != adminData.end(); iter++ ){
		temp = iter->second;
		fwrite(temp,objSize,1,fp);
	}
	fclose(fp);
	return;
}
void exportDoctor(){
	FILE *fp;
	fp = fopen("doctor.bin","w");
	int objSize = sizeof(Doctor);
	Doctor *temp;
	if(doctorData.empty()){
		return;
	}
	map<string,Doctor*,less<string> >::iterator iter;
	for(iter = doctorData.begin(); iter != doctorData.end(); iter++ ){
		temp = iter->second;
		fwrite(temp,objSize,1,fp);
	}
	fclose(fp);
	return;
}
void exportInvestigator(){
	FILE *fp;
	fp = fopen("investigator.bin","w");
	int objSize = sizeof(Investigator);
	Investigator *temp;
	if(doctorData.empty()){
		return;
	}
	map<string,Investigator*,less<string> >::iterator iter;
	for(iter = investigatorData.begin(); iter != investigatorData.end(); iter++ ){
		temp = iter->second;
		fwrite(temp,objSize,1,fp);
	}
	fclose(fp);
	return;
}
void exportCriminal(){
	FILE *fp;
	fp = fopen("criminal.bin","w");
	int objSize = sizeof(Criminal);
	Criminal *temp;
	if(criminalData.empty()){
		return;
	}
	map<string,Criminal*,less<string> >::iterator iter;
	for(iter = criminalData.begin(); iter != criminalData.end(); iter++ ){
		temp = iter->second;
		fwrite(temp,objSize,1,fp);
	}
	fclose(fp);
	return;
}
void exportEternal(){
	FILE *fp;
	fp = fopen("eternal.bin","w");
	int objSize = sizeof(Eternal);
	Eternal *temp;
	if(eternalData.empty()){
		return;
	}
	map<string,Eternal*,less<string> >::iterator iter;
	for(iter = eternalData.begin(); iter != eternalData.end(); iter++ ){
		temp = iter->second;
		fwrite(temp,objSize,1,fp);
	}
	fclose(fp);
	return;
}
void mainFunctionsHelp(){
	cout<<"YOU MAY\n"
		<<"1. SIGN IN TO AN ACCOUNT USING \"LOG\"\n"
		<<"2. GET HELP WITH USING \"/?\"\n"
		<<"3. EXIT USING \"EXIT\"\n";
	return;
}
void mainFunctions(){
	char com[10];
	// label to get commands again and again
	getCom:
	cout<<"ENTER YOUR COMMAND: ";
	cin>>com;
	for(int i =0;(i<10)&&(com[i]!='\0');i++){
		com[i] = toupper(com[i]);
	}
	if(strcmp(com,"LOG")==0){
		logInToAccount();
		goto getCom;
	}
	else if(strcmp(com,"EXIT")==0){
		return;
	}
	else if(strcmp(com,"/?")==0){
		mainFunctionsHelp();
		goto getCom;
	}
	else{
		cout<<"YOU ENTERED SOMETHING ELSE\n";
		cout<<"THIS MAY HELP YOU\n";
		mainFunctionsHelp();
		goto getCom;
	}
	return;
}
void logInToAccountHelp(){
	cout<<"YOU MAY\n"
		<<"1. SIGN IN TO ADMIN ACCOUNT USING \"ADMIN\"\n"
		<<"2. SIGN IN TO DOCTOR ACCOUNT USING \"DOCTOR\"\n"
		<<"3. SIGN IN TO INVESTIGATOR ACCOUNT USING \"INVESTIGATOR\"\n"
		<<"4. GO TO PREVIOUS MENU USING \"..\"\n"
		<<"5. GET HELP WITH USING \"/?\"\n"
		/*<<"6. EXIT USING \"EXIT\"\n"*/;
	return;
}
void logInToAccount(){
	char username[31];
	int session;
	int id;
	Admin *refA;
	Doctor *refD;
	Investigator *refI;
	cout<<"Enter Username: ";
	cin>>username;
	map<string,Admin*,less<string> >::iterator iterA;
	map<string,Doctor*,less<string> >::iterator iterD;
	map<string,Investigator*,less<string> >::iterator iterI;
	iterA = adminData.find(string(username));
	iterD = doctorData.find(string(username));
	iterI = investigatorData.find(string(username));

	if(iterA != adminData.end()){
		refA = iterA->second;
		session = refA->getSess();
		if(session != 0){
			// call with session key
			refA->accessAccount(session);
		}
		else{
			cout<<"\nWRONG KEY";
			return;
		}
	}
	else if(iterD != doctorData.end()){
		refD = iterD->second;
		session = refD->getSess();
		if(session != 0){
			// call with session key
			refD->accessAccount(session);
		}
		else{
			cout<<"\nWRONG KEY";
			return;
		}
	}
	else if(iterI != investigatorData.end()){
		refI = iterI->second;
		session = refI->getSess();
		if(session != 0){
			// call with session key
			refI->accessAccount(session);
		}
		else{
			cout<<"\nWRONG KEY";
			return;
		}
	}
	else{
		cout<<"INVALID USERNAME";
		return;
	}
	return;
}
