#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include "classes.h"
using namespace std;
//all function prototype
float InputValidation(float,float,float);
int ReadTextfile(DerivedData[]);
void ModifyData(DerivedData&,int);
int AddData(DerivedData[],int);
void SearchSpecific(DerivedData[],int,int);
void SearchByRange(DerivedData[],int,int);
void Statistic(DerivedData[],int);
void CreateTextfile(DerivedData[],int);
int main(){
	cout<<fixed<<showpoint<<setprecision(2);
	long long int id;
	int n=1000,c,C,p,search,m;
	string name;
	DerivedData obj[n];
	DerivedData();
	//display front page of the application
	cout<<"\n\n\t-----------------------------------------------------------\n\t\t\t\tWELCOME TO ";
	cout<<"\n\t\t\tLET'S GET FIT APPLICATION\n\t-----------------------------------------------------------\n\n\t";
	system("pause");system("CLS");
	//loop until user enter 1 to read the text file (validation)
	do{
		cout<<"\n\n\t-----------------------------------------------------------\n\t\t\tLET'S GET FIT APPLICATION";
		cout<<"\n\t-----------------------------------------------------------\t";		
		cout<<"\n\t\tChoose the following option :\n\t\t[1]-Read Staff Data text file."<<"\n\n\t\tOption : ";
		cin>>c;
		system("CLS");
		if (c==1){
			n=ReadTextfile(obj);//set number of staff as n by call function readtextfile.
			cout<<"\n   \t\t\tNAME\t\t       ID\t     GENDER     AGE\t   HEIGHT      WEIGHT";
			cout<<"\n----------------------------------------------------------------------------------------------------------\n  ";
			//display all staff data
			for(int i=0;i<n;i++)
				obj[i].Display_Data1();
			cout<<"\n\n  # User must UPDATE / ADD data if some of the data become 0.\n\n";
			system("pause");
			system("CLS");}
		else{
			system("CLS");
			cout<<"Wrong option,Please re-enter again!";}
	}while(c!=1);
	//display manu and condition that choosen by user to do task.
	do{	//display menu
		cout<<"\n\n\t---------------------------------------------------------------------------------\n\t\t\t\tLET'S GET FIT APPLICATION";
		cout<<"\n\t---------------------------------------------------------------------------------\t";	
		cout<<"\n\n\t\tChoose the following option :\n\n\t\t[1]-List of Staff & Information."<<"\n\t\t[2]-Body Mass Index(BMI).";
		cout<<"\n\t\t[3]-Basal Metabolic Rate(BMR) "<<"and Resting Metabolic Rate(RMR)."<<"\n\t\t[4]-Update Staff Information.";
		cout<<"\n\t\t[5]-Add new staff data."<<"\n\t\t[6]-Search Staff by NAME or  ID.";
		cout<<"\n\t\t[7]-Search Staff by range of AGE/HEIGHT/WEIGHT/BMI/BMR/RMR."<<"\n\t\t[8]-Staff Statistic.";
		cout<<"\n\t\t[9]-Exit."<<"\n\n\t\tOption : ";	
		cin>>C;system("CLS");
		//task that provide by the program 
		switch(C){
			case 1: //display again all staff data for user to review
					cout<<"\n   \t\t\tNAME\t\t       ID\t     GENDER     AGE\t   HEIGHT      WEIGHT";
					cout<<"\n----------------------------------------------------------------------------------------------------------\n  ";
					for(int i=0;i<n;i++)
						obj[i].Display_Data1();
					system("pause");system("CLS");
					break;
			case 2:	//display body mass index and weight category
					cout<<"\n\t\t\tNAME             BMI        CATEGORY";
					cout<<"\n---------------------------------------------------------------------\n  ";
					for(int i=0;i<n;i++){
						obj[i].Calculate_BMI();//calculate bmi of staff in DerivedData class.
						cout<<setw(25)<<obj[i].Get_Name();//display name by get staff name from DerivedData class.
						cout<<"\t\t"<<obj[i].Get_BMI();//display bmi by get staff bmi from DerivedData class.
						obj[i].WeightCategory();//display weight category by get it from DerivedData class.
					}system("pause");system("CLS");
					cout<<"  Do you want to check calory suggestion ? [1-Yes,2-No]"<<endl<<"  ";
					cin>>p;
					p=InputValidation(p,1,2);//call input validation function
					system("CLS");
					//give user calories intake suggestion for a day.
					do{
					if(p==1){
						cout<<"\n  Enter ID :";cin>>id;cout<<"------------------------------------------------------"<<endl;
						for(int i=0;i<n;i++){
							if(id==obj[i].Get_ID()){
								obj[i].Weight_Plan();
								cout<<"------------------------------------------------------\n";
								break;}}}
					else{
						system("CLS");break;}
					cout<<"\n  Do you want to check calory suggestion again? [1-Yes,2-No]\n  Option : ";
					cin>>p;
					p=InputValidation(p,1,2);//call input validation function.
					system("CLS");
					}while(p!=2);
					system("CLS");break;
			case 3: //display staff's basal metabolic rate and resting metabolic rate.
					cout<<"\n\t\t    NAME          BMR        RMR";
					cout<<"\n---------------------------------------------------------------------\n";
					for(int i=0;i<n;i++){
						obj[i].Calculate_BMR();obj[i].Calculate_RMR();//calculate bmr & rmr through object from DerivedData class
						cout<<setw(25)<<obj[i].Get_Name();
						cout<<"\t"<<obj[i].Get_BMR();
						cout<<"     "<<obj[i].Get_RMR()<<endl;
					}system("pause");system("CLS");
					break;
			case 4: //Update/modify/add staff data.
					do{ cout<<"Which data do you want to update?\n  1-Staff ID\n  2-Age,Weight(Kg),Height(cm)\n\nChoice : ";
						cin>>m;
						if(m==2){
							cout<<"\n  Enter ID :";cin>>id;
							for(int i=0;i<n;i++){
								//search id key-in by user inside an array of object of DeriveData class
								if(id==obj[i].Get_ID()){
									//display staff data before modify
									obj[i].Display_Data2();
									cout<<"\n---------------------------------------------\n";
									ModifyData(obj[i],m);system("CLS");//call modify function
									cout<<"\n---------------------------------------------\n";
									//display staff data after modify
									obj[i].Display_Data2();
									cout<<"\n---------------------------------------------\n";
									break;}
							}
							cout<<"  Do you want to MODIFY/UPDATE again? [1-Yes,2-No]"<<endl<<"  Option : ";cin>>p;
							p=InputValidation(p,1,2);}
						else if(m==1){
							cout<<"\n  Enter FULL NAME :";cin.ignore();
							getline(cin,name);
							for(int i=0;i<n;i++){
								//search name key-in by user inside an array of object of DeriveData class
								if(name==obj[i].Get_Name()){
									//display staff data before modify
									obj[i].Display_Data2();
									cout<<"\n---------------------------------------------\n";
									ModifyData(obj[i],m);system("CLS");//call modify function
									cout<<"\n---------------------------------------------\n";
									//display staff data after modify
									obj[i].Display_Data2();
									cout<<"\n---------------------------------------------\n";
									break;}
							}
						cout<<"  Do you want to MODIFY/UPDATE again? [1-Yes,2-No]"<<endl<<"  Option : ";cin>>p;
						p=InputValidation(p,1,2);//call input validation function.
						}
						else
							m=InputValidation(m,1,2);//call input validation function.
						system("pause");system("CLS");
					}while(p!=2);system("CLS");break;
			case 5: //add new staff data.
					n=AddData(obj,n);//set n as new number of staff by call add data function
					system("pause");
					system("CLS");break;
			case 6: //search data by name or id.
					do{	cout<<"\n  Do you want to search staff by ID or NAME? [1-ID,2-NAME]\n  ";
						cin>>search;
						SearchSpecific(obj,search,n);//call function to search staff
						cout<<"\n---------------------------------------------\n";
						system("pause");
						system("CLS");
						cout<<"\n\n  Do you want to search again? [1-Yes,2-No]"<<endl<<"  Option : ";cin>>p;
						p=InputValidation(p,1,2);//call input validation function.
						system("CLS");
					}while(p!=2);
					system("CLS");break;
			case 7: //search data by range of age/weight/height/bmi/bmr/rmr.
					do{	cout<<"\n  Which data you want review?\n  [1-AGE,2-WEIGHT,3-HEIGHT,4-BMI,5-BMR,6-RMR]\n  Choice: ";
						cin>>search;system("CLS");
						SearchByRange(obj,search,n);//call function to search staffs data
						cout<<"\n\n  Do you want to review again? [1-Yes,2-No]"<<endl<<"  Option : ";cin>>p;
						p=InputValidation(p,1,2);//call input validation function.
						system("CLS");
					}while(p!=2);
					system("CLS");break;
			case 8:	//display the statistic about staff
					cout<<"\n\t\t\t\t\tSTAFF STATISTIC\n\n-------------------------------------------------------------------------------------------\n";
					cout<<"          \t  |\t  GENDER \t|\t \t \t  AGE  \t  \t  \t |\n CATEGORY \t  |------------------------------------------------------------------------\n";
					cout<<"          \t  |   MALE   |  FEMALE  |    30 & Less   |     31-50     |   51 & Above  |";
					cout<<"\n-------------------------------------------------------------------------------------------";
					Statistic(obj,n);//call function 
					system("pause");
					system("CLS");
					break;
			case 9: //end or exit the program
					cout<<"\n   \t\t\tNAME\t\t       ID\t     GENDER     AGE\t   HEIGHT      WEIGHT";
					cout<<"\n----------------------------------------------------------------------------------------------------------\n  ";
					//display the latest staffs data before add it to new text  file
					for(int i=0;i<n;i++)
						obj[i].Display_Data1();
					CreateTextfile(obj,n);//open new text file by call function
					system("pause");
					break;
			default:cout<<"\tChoice is not valid...\nEnter again\n";
		}
	}while(C!=9);
}
//input validation function with parameter of valid chacker's variable and the limits
float InputValidation(float x,float LowLimit,float HighLimit){
	while(x<LowLimit||x>HighLimit){
		cout<<"  WRONG INPUT !!\n\t Enter Again : ";
		cin>>x;
	}
	return x;
}
//add new staff data function with parameter of object of DerivedData class and num of staff 
int AddData(DerivedData obj[],int n){
	//variables declaration
	int staff,p;
	long long int id;
	string name,g;
	float w,h;
	cout<<"\n  How many staff do you want to add?\n  ";cin>>staff;
	for(int i=0;i<staff;i++){
		p=0;
		//get new staff name
		cout<<" Student "<<i+1<<":-\n\tName :";
		cin.ignore();
		getline(cin,name);
		//get new staff id
		cout<<"\tID :";cin>>id;	
		//check if the id entered by user is 12 digits
		do{ if(id/1000000000000!=0){
				cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
			else
				p++;
		}while(p!=1);
		//check if the id entered by user is valid 
		do{
			int day=(id/1000000)%100,month=(id/100000000)%100;
			int state=(id/10000)%100;
			if(month>=1&&month<=12){
				if(month==2){
					if(day>=1&&day<=29){
						if(state>0&&state<17)
							p++;
						else if(state>20&&state<59)
							p++;
						else if(state==82)
							p++;
						else{
							cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
						}
					else{
						cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
				}
				else if(month%2==0){
					if(day>=1&&day<=30){
						if(state>0&&state<17)
							p++;
						else if(state>20&&state<59)
							p++;
						else if(state==82)
							p++;
						else{
							cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
						}
					else{
						cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
				}
				else if(month%2==1){
					if(day>=1&&day<=31){
						if(state>0&&state<17)
							p++;
						else if(state>20&&state<59)
							p++;
						else if(state==82)
							p++;
						else{
							cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
						}
					else{
						cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
				}
				else{
					cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
			}
			else{
			cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
		}while(p!=2);
		//get new staff gender
		cout<<"\tGender :";cin>>g;
		//get new staff weight
		cout<<"\tWeight :";cin>>w;
		w=InputValidation(w,30,150);//input validation for height
		//get new staff height
		cout<<"\tHeight :";cin>>h;
		h=InputValidation(h,80,210);//input validation for weight
		cout<<"--------------------------------\n";
		//set new staff data in DerivedData class
		obj[n+i].DataSet_1(name,id,g);obj[n+i].DataSet_2(id,h,w);
		//calculate new staff age,bmi,bmr,rmr in DerivedData class.
		obj[n+i].Calculate_Age();obj[n+i].Calculate_BMI();
		obj[n+i].Calculate_BMR();obj[n+i].Calculate_RMR();
	}
	return n+staff;
}
//function for read the textfile with parameter of object of DerivedData class.
int ReadTextfile(DerivedData obj[]){
	//variable declaration and initialization
	ifstream readData;
	long long int clon_id,id,id2;
	int i=0,j=0,x=1000;
	string name,space,g;
	float w,h;
	//opening the personal staff data textfile
	readData.open("PersonalInfo.txt");
	while(!readData.eof()){
		if(readData.eof()==true)
			break;
		else{
			readData>>id;
			//check the id to 12 digits, if not set to 0.
			if(id/1000000000000!=0)
				id=0;
			int day=(id/1000000)%100,month=(id/100000000)%100;
			int state=(id/10000)%100;
			//check the id if it valid as a id based on month,day and state of birth, if not set to 0.
			if(month>=1&&month<=12){
				if(month==2){
					if(day>=1&&day<=29){
						if(state>0&&state<17)
							id=id;
						else if(state>20&&state<59)
							id=id;
						else if(state==82)
							id=id;
						else
							id=00000000;
					}
					else
						id=00000000;}
				else if(month%2==0){
					if(day>=1&&day<=30){
						if(state>0&&state<17)
							id=id;
						else if(state>20&&state<59)
							id=id;
						else if(state==82)
							id=id;
						else
							id=00000000;
					}
					else
						id=00000000;}
				else if(month%2==1){
					if(day>=1&&day<=31){
						if(state>0&&state<17)
							id=id;
						else if(state>20&&state<59)
							id=id;
						else if(state==82)
							id=id;
						else
							id=00000000;
					}
					else
						id=00000000;}
				else
					id=000000000;
			}
			else
				id=0;
			getline(readData,space,'\t');
			getline(readData,name,'\t');
			getline(readData,g,'\n');
			obj[i].DataSet_1(name,id,g);
			i++;}
	}readData.close();
	//close the personal staff data textfile
	x=i;
	//open the fitness staff data textfile
	readData.open("FitnessInfo.txt");
	while(!readData.eof()){
		if(readData.eof()==true)
			break;
		else{
			readData>>clon_id;
				for(int x=0;x<i;x++){
					//find id get from fitness textfile from personal textfile 
					id2=obj[x].Get_ID();
					if(clon_id==id2){
						readData>>w>>h;
						//validation for weight(w)
						if(w<30||w>150)
							w=0;
						//validation for height(h)
						if(h<80||h>210)
							h=0;
						obj[x].DataSet_2(clon_id,h,w);
						break;}
				}
			j++;}		
	}
	readData.close();
	//close fitness staff data textfile
	//calculate age,bmi,bmr,rmr in DerivedData class
	for(int p=0;p<x;p++){
		obj[p].Calculate_Age();obj[p].Calculate_BMI();
		obj[p].Calculate_BMR();obj[p].Calculate_RMR();
	}
	return x;
}
//modify staff data function with parameter of object of DerivedData class and which daya user want to modify
void ModifyData(DerivedData& obj,int m){
	long long int id;
	int c,p=0;
	float weight,height;
	if(m==1){
		cout<<"  Enter ID: ";cin>>id;	
		//input validation for id not more than 12 digits,if wrong reenter id.
		do{ if(id/1000000000000!=0){
				cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
			else
				p++;
		}while(p!=1);
		//input validation for id based on month, day and state of staff's birth,if wrong reenter id.
		do{ int day=(id/1000000)%100,month=(id/100000000)%100;
			int state=(id/10000)%100;
			if(month>=1&&month<=12){
				if(month==2){
					if(day>=1&&day<=29){
						if(state>0&&state<17)
							p++;
						else if(state>20&&state<59)
							p++;
						else if(state==82)
							p++;
						else{
							cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
						}
					else{
						cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
				}
				else if(month%2==0){
					if(day>=1&&day<=30){
						if(state>0&&state<17)
							p++;
						else if(state>20&&state<59)
							p++;
						else if(state==82)
							p++;
						else{
							cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
						}
					else{
						cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
				}
				else if(month%2==1){
					if(day>=1&&day<=31){
						if(state>0&&state<17)
							p++;
						else if(state>20&&state<59)
							p++;
						else if(state==82)
							p++;
						else{
							cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
						}
					else{
						cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
				}
				else{
					cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
			}
			else{
			cout<<"  Wrong input !!\n\tEnter Again : ";cin>>id;}
		}while(p!=2);
		obj.Change_ID(id);}
	else{
		cout<<"\n  Which one you want to UPDATE/MODIFY ?"<<endl;
		cout<<"  1-Age\n  2-Weight(Kg)\n  3-Height(cm)\n\nChoice : ";cin>>c;
		c=InputValidation(c,1,3);//call function for input validation
		if(c==1){
			cout<<"  Enter Latest Age: ";cin>>obj.age;//change age value in DerivedData class
			obj.age=InputValidation(obj.age,2,120);}
		else if(c==2){
			cout<<"  Enter Latest Weight: ";
			cin>>weight;
			weight=InputValidation(weight,30,150);
			obj.Change_Weight(weight);}//change weight value in DerivedData class 
		else if(c==3){
			cout<<"  Enter Latest Height: ";
			cin>>height;
			height=InputValidation(height,80,210);
			obj.Change_Height(height);}//change height value in DerivedData class
		//recalculate the latest data.
		obj.Calculate_Age();obj.Calculate_BMI();
		obj.Calculate_BMR();obj.Calculate_RMR();
	}
}
//search staff data function with parameter of object of DerivedData class, search and number of staff.
void SearchSpecific(DerivedData obj[],int Search,int Staff){
	long long int ID;
	string Name;
	//search staff by their id
	if(Search==1){
		cout<<"\n  Enter staff ID : ";cin>>ID;
		system("CLS");cout<<endl;
		for(int i=0;i<Staff;i++){
			if(ID==obj[i].Get_ID()){
				//display their data
				obj[i].Display_Data2();
				obj[i].Display_BMI_BMR_RMR();}
		}
	}
	//search staff by their name
	if(Search==2){
		cout<<"\n  Enter staff FULL NAME : ";
		cin.ignore();
		getline(cin,Name);
		system("CLS");cout<<endl;
		for(int i=0;i<Staff;i++){
			if(Name==obj[i].Get_Name()){
				//display their data
				obj[i].Display_Data2();
				obj[i].Display_BMI_BMR_RMR();}
		}
	}
}
//combinational search function with parameter of object of DerivedData class, search and number of staff.
void SearchByRange(DerivedData obj[],int Search,int Staff){
	float First_bmi,First_bmr,First_rmr,First_weight,First_height;
	float Last_bmi,Last_bmr,Last_rmr,Last_weight,Last_height;
	int First_age,Last_age;
	//search staffs by range of age
	if(Search==1){
		cout<<"\n  Enter AGE range : \n"<<"\tFROM -> ";
		cin>>First_age;
		cout<<"\tTO   -> ";
		cin>>Last_age;
		cout<<"\n---------------------------------------------------------------------------------------------------------------";
		cout<<"\n   \t\t\tNAME\t\t       ID\t     GENDER     AGE\t   HEIGHT      WEIGHT";
		cout<<"\n---------------------------------------------------------------------------------------------------------------\n  ";
		for(int i=0;i<Staff;i++){
			if(obj[i].Get_Age()<=Last_age&&obj[i].Get_Age()>=First_age){
				obj[i].Display_Data1();}
		}
	}
	//search staffs by range of weight
	if(Search==2){
		cout<<"\n  Enter WEIGHT range : \n"<<"\tFROM -> ";
		cin>>First_weight;
		cout<<"\tTO   -> ";
		cin>>Last_weight;
		cout<<"\n----------------------------------------------------------------------------------------------------------------";
		cout<<"\n   \t\t\tNAME\t\t       ID\t     GENDER     AGE\t   HEIGHT      WEIGHT";
		cout<<"\n----------------------------------------------------------------------------------------------------------------\n  ";
		for(int i=0;i<Staff;i++){
			if(obj[i].Get_Weight()<=Last_weight&&obj[i].Get_Weight()>=First_weight){
				obj[i].Display_Data1();}
		}
	//search staffs by range of height
	}if(Search==3){
		cout<<"\n  Enter HEIGHT range : \n"<<"\tFROM -> ";
		cin>>First_height;
		cout<<"\tTO   -> ";
		cin>>Last_height;
		cout<<"\n-----------------------------------------------------------------------------------------------------------------";
		cout<<"\n   \t\t\tNAME\t\t       ID\t     GENDER     AGE\t   HEIGHT      WEIGHT";
		cout<<"\n-----------------------------------------------------------------------------------------------------------------\n  ";
		for(int i=0;i<Staff;i++){
			if(obj[i].Get_Height()<=Last_height&&obj[i].Get_Height()>=First_height){
				obj[i].Display_Data1();}
		}
	//search staffs by range of bmi
	}if(Search==4){
		cout<<"\n  Enter BMI range : \n"<<"\tFROM -> ";
		cin>>First_bmi;
		cout<<"\tTO   -> ";
		cin>>Last_bmi;
		cout<<"\n---------------------------------------------------------------------------------------------";
		cout<<"\n   \t\t\tNAME\t\tID\t\tGENDER\t  AGE\t BMI";
		cout<<"\n---------------------------------------------------------------------------------------------\n  ";
		for(int i=0;i<Staff;i++){
			if(obj[i].Get_BMI()<=Last_bmi&&obj[i].Get_BMI()>=First_bmi){
				cout<<setw(25)<<obj[i].Get_Name()<<"\t     "<<obj[i].Get_ID()<<"\t";
				cout<<obj[i].Get_Gender();
				cout<<"\t   "<<obj[i].Get_Age()<<"\t"<<obj[i].Get_BMI()<<"\n  ";}
		}
	//search staffs by range of bmr
	}if(Search==5){
		cout<<"\n  Enter BMR range : \n"<<"\tFROM -> ";
		cin>>First_bmr;
		cout<<"\tTO   -> ";
		cin>>Last_bmr;
		cout<<"\n---------------------------------------------------------------------------------------------";
		cout<<"\n   \t\t\tNAME\t\tID\t\tGENDER\t  AGE\t BMR";
		cout<<"\n---------------------------------------------------------------------------------------------\n  ";
		for(int i=0;i<Staff;i++){
			if(obj[i].Get_BMR()<=Last_bmr&&obj[i].Get_BMR()>=First_bmr){
				cout<<setw(25)<<obj[i].Get_Name()<<"\t     "<<obj[i].Get_ID()<<"\t";
				cout<<obj[i].Get_Gender();
				cout<<"\t   "<<obj[i].Get_Age()<<"\t"<<obj[i].Get_BMR()<<"\n  ";}
		}
	//search staffs by range of rmr
	}if(Search==6){
		cout<<"\n  Enter RMR range : \n"<<"\tFROM -> ";
		cin>>First_rmr;
		cout<<"\tTO   -> ";
		cin>>Last_rmr;
		cout<<"\n---------------------------------------------------------------------------------------------";
		cout<<"\n   \t\t\tNAME\t\tID\t\tGENDER\t  AGE\t RMR";
		cout<<"\n---------------------------------------------------------------------------------------------\n  ";
		for(int i=0;i<Staff;i++){
			if(obj[i].Get_RMR()<=Last_rmr&&obj[i].Get_RMR()>=First_rmr){
				cout<<setw(25)<<obj[i].Get_Name()<<"\t     "<<obj[i].Get_ID()<<"\t";
				cout<<obj[i].Get_Gender();
				cout<<"\t   "<<obj[i].Get_Age()<<"\t"<<obj[i].Get_RMR()<<"\n  ";}
		}
	}
}
//statictic of staff data function with parameter of object of DerivedData class and number of staff
void Statistic(DerivedData obj[],int n){
	int WeightCategory=0,Obese=0,Male=0,Female=0,AgeLess=0,AgeMiddle=0,AgeMore=0;
	//collect the data of staffs for each weight category 
	for(int i=0;i<n;i++){
		if(obj[i].Get_BMI()<20){
			WeightCategory++;
			if(obj[i].Get_Gender()=="M"||obj[i].Get_Gender()=="m"||obj[i].Get_Gender()=="Male"||obj[i].Get_Gender()=="male"||obj[i].Get_Gender()=="MALE")
				Male++;
			else
				Female++;
			if(obj[i].Get_Age()<31)
				AgeLess++;
			else if(obj[i].Get_Age()>30&&obj[i].Get_Age()<51)
				AgeMiddle++;
			else
				AgeMore++;
		}
	}
	cout<<"\n UNDER WEIGHT ("<<WeightCategory<<")      "<<Male<<"    \t  "<<Female;
	cout<<"\t\t"<<AgeLess<<"\t  \t"<<AgeMiddle<<"\t  \t "<<AgeMore<<"\t ";
	WeightCategory=0;Obese=0;Male=0;Female=0;AgeLess=0;AgeMiddle=0;AgeMore=0;
	for(int i=0;i<n;i++){
		if(obj[i].Get_BMI()>=20&&obj[i].Get_BMI()<25){
			WeightCategory++;
			if(obj[i].Get_Gender()=="M"||obj[i].Get_Gender()=="m"||obj[i].Get_Gender()=="Male"||obj[i].Get_Gender()=="male"||obj[i].Get_Gender()=="MALE")
				Male++;
			else
				Female++;
			if(obj[i].Get_Age()<31)
				AgeLess++;
			else if(obj[i].Get_Age()>30&&obj[i].Get_Age()<51)
				AgeMiddle++;
			else
				AgeMore++;
		}
	}
	cout<<setw(18)<<"\n NORMAL WEIGHT("<<WeightCategory<<")      "<<Male<<"    \t  "<<Female;
	cout<<"\t\t"<<AgeLess<<"\t  \t"<<AgeMiddle<<"\t  \t "<<AgeMore<<"\t ";
	WeightCategory=0;Obese=0;Male=0;Female=0;AgeLess=0;AgeMiddle=0;AgeMore=0;
	for(int i=0;i<n;i++){
		if(obj[i].Get_BMI()>=25&&obj[i].Get_BMI()<=30){
			WeightCategory++;
			if(obj[i].Get_Gender()=="M"||obj[i].Get_Gender()=="m"||obj[i].Get_Gender()=="Male"||obj[i].Get_Gender()=="male"||obj[i].Get_Gender()=="MALE")
				Male++;
			else
				Female++;
			if(obj[i].Get_Age()<31)
				AgeLess++;
			else if(obj[i].Get_Age()>30&&obj[i].Get_Age()<51)
				AgeMiddle++;
			else
				AgeMore++;
		}
	}
	cout<<"\n OVER WEIGHT  ("<<WeightCategory<<")      "<<Male<<"    \t  "<<Female;
	cout<<"\t\t"<<AgeLess<<"\t  \t"<<AgeMiddle<<"\t  \t "<<AgeMore<<"\t ";
	WeightCategory=0;Obese=0;Male=0;Female=0;AgeLess=0;AgeMiddle=0;AgeMore=0;
	for(int i=0;i<n;i++){
		if(obj[i].Get_BMI()>30){
			WeightCategory++;
			if(obj[i].Get_Gender()=="M"||obj[i].Get_Gender()=="m"||obj[i].Get_Gender()=="Male"||obj[i].Get_Gender()=="male"||obj[i].Get_Gender()=="MALE")
				Male++;
			else
				Female++;
			if(obj[i].Get_Age()<31)
				AgeLess++;
			else if(obj[i].Get_Age()>30&&obj[i].Get_Age()<51)
				AgeMiddle++;
			else
				AgeMore++;
		}
	}
	cout<<"\n OBESE WEIGHT ("<<WeightCategory<<")      "<<Male<<"    \t  "<<Female;
	cout<<"\t\t"<<AgeLess<<"\t  \t"<<AgeMiddle<<"\t  \t "<<AgeMore<<"\t \n\n";
}
//create new text file function with parameter of object of DerivedData class and number of staff
void CreateTextfile(DerivedData obj[],int n){
	ofstream outData;
	//open new textfile
 	outData.open ("AllStaffData.txt");
		outData<<" Name\t\t\tID      Gender   Age    Weight   Height   BMI     BMR    \tRMR\n";
		outData<<"-----------------------------------------------------------------------------------------\n";
 	for(int i=0;i<n;i++){
 		//put all the latest data of all staffs inside the textfile.
 		outData<<obj[i].Get_Name()<<"\t"<<obj[i].Get_ID()<<"\t"<<obj[i].Get_Gender()<<"\t"<<obj[i].Get_Age()<<"\t";
		outData<<obj[i].Get_Weight()<<"\t"<<obj[i].Get_Height()<<"\t"<<obj[i].Get_BMI()<<"\t";
		outData<<obj[i].Get_BMR()<<"\t"<<obj[i].Get_RMR()<<endl;
	}
 	outData.close();
}
