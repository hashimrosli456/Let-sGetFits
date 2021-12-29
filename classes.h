#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
using namespace std;
class PersonalData{
	private:
		string name,gender;
		long long int id;
	public:
		void SetData(string n,long long int ID,string g){name=n; id=ID; gender=g;}
		int CalculateAge();
		void DisplayID(int);
		void ChangeID(long long int ID){id=ID;}
		string DisplayName(){return name;}
		long long int GetId(){return id;}
		string GetGender(){return gender;}
		PersonalData(){name=" ";id=0;gender=' ';}//constructor
		~PersonalData(){name=" ";id=0;gender=' ';}//destructor
};
//CalculateAge is from class PersonalData to calculate staff birth year from staff id.
int PersonalData::CalculateAge(){
	int Year=id/10000000000;//formular to calculate birth year
	if(Year<=20)
		return 2020-(Year+2000);
	else
		return 2020-(Year+1900);
}
//DisplayID is from class PersonalData and display staff ID based on different situation.
void PersonalData::DisplayID(int a){
	if(id==0){
		cout<<"\t   "<<setw(14)<<id;
	}
	else{
		if(a==20){
			cout<<"\t     "<<"00"<<setw(10)<<id;}
		else{
			cout<<"\t   "<<setw(14)<<id;}
	}
}
class FitnessData{
	private:
		long long int Id;
		float height,weight;
	public:
		void SetData(long long int id,double h,double w){Id=id; height=h; weight=w;}
		void ChangeWeight(float W){weight=W;}//used to reset the value of weight
		void ChangeHeight(float H){height=H;}//used to reset the value of height
		float GetHeight(){return height;}
		float GetWeight(){return weight;}
		FitnessData(){Id=0;height=0;weight=0;}//constructor
		~FitnessData(){Id=0;height=0;weight=0;}//destructor
};
class DerivedData:public FitnessData{
	private:
		int age;string G;
		float bmi,rmr,bmr;
		PersonalData obj;
	public:
		void DataSet_1(string n,long long int ID,string g){obj.SetData(n,ID,g);}
		void DataSet_2(long long int ID,double h,double w){SetData(ID,h,w);}
		void Calculate_Age(){age=obj.CalculateAge();}
		void Display_Data1(){//display staff data
			cout<<setw(25)<<obj.DisplayName();obj.DisplayID(age);cout<<setw(18)<<obj.GetGender();
			cout<<"      "<<age<<setw(14)<<GetHeight()<<setw(12)<<GetWeight()<<"\n  ";}
		void Display_Data2();
		void Display_BMI_BMR_RMR();
		void Calculate_BMI(){bmi=GetWeight()/((GetHeight()/100)*(GetHeight()/100));}
		void Calculate_BMR(){
			G=obj.GetGender();
			if(G=="M"||G=="m"||G=="Male"||G=="male"||G=="MALE")
				bmr=(10*GetWeight())+(6.25*GetHeight())-(5*age)+5 ;
			else
				bmr=(10*GetWeight())+(6.25*GetHeight())-(5*age)-161 ;
		}
		void Calculate_RMR(){
			G=obj.GetGender();
			if(G=="M"||G=="m"||G=="Male"||G=="male"||G=="MALE")
				rmr=88.362+(13.397*GetWeight())+(4.799*GetHeight())-(5.677*age) ;
			else
				rmr=447.593+(9.247*GetWeight())+(3.098*GetHeight())-(4.330*age) ;
		}	
		void Weight_Plan();//Calories intake suggestion.
		void WeightCategory();//category based on body mass index.
		void Change_ID(long long int ID){obj.ChangeID(ID);}
		void Change_Height(float W){ChangeHeight(W);}//reset the value of height.
		void Change_Weight(float W){ChangeWeight(W);}//reset the value of weight.
		float Get_BMI(){return bmi;}
		float Get_BMR(){return bmr;}
		float Get_RMR(){return rmr;}
		int Get_Age(){return age;}
		float Get_Weight(){return GetWeight();}
		float Get_Height(){return GetHeight();}
		string Get_Gender(){return obj.GetGender();}
		string Get_Name(){return obj.DisplayName();}
		long long int Get_ID(){return obj.GetId();}
		friend int ReadTextfile(DerivedData);//friend function to read textfile
		friend void ModifyData(DerivedData&,int);//friend function to modify staff data
		friend int AddData(DerivedData,int);//friend function to add new staffs data
		friend void SearchSpecific(DerivedData,int,int);//friend function to search staff information
		friend void SearchByRange(DerivedData,int,int);//friend function to search staffs information
		friend void Statistic(DerivedData,int);//friend function to display staff data statisticly
		friend void CreateTextfile(DerivedData,int);//friend function to create new text file
		DerivedData(){PersonalData();FitnessData();age=0;bmi=0;bmr=0;rmr=0;}//contructor
		~DerivedData(){PersonalData();FitnessData();age=0;bmi=0;bmr=0;rmr=0;}//destructor
};
void DerivedData::Display_Data2(){
	cout<<"  Name : "<<obj.DisplayName();
	cout<<"\n  ID : "<<obj.GetId();
	cout<<"\n  Age : "<<age;
	cout<<"\n  Weight : "<<GetWeight();
	cout<<"\n  Height : "<<GetHeight();
}
void DerivedData::Display_BMI_BMR_RMR(){
	cout<<"\n  Body Mass Index(BMI) : "<<bmi;
	cout<<"\n  Basal Metabolic Rate(BMR) : "<<bmr;
	cout<<"\n  Resting Metabolic Rate(RMR) : "<<rmr;
}
void DerivedData::Weight_Plan(){
	int plan_weight,LossOrGain_weight,Exercise;
	float maintain,mild,moderate,extreme;
	cout<<"  Name : "<<obj.DisplayName();//display staff name.
	cout<<"  Body Mass Index : "<<bmi;//display staff bmi.
	//ask user if they exercise how much in a week.
	cout<<"\n\n  How often do you exercise ?\n  1-RARELY exercise in a week.\n  2-ONE to TWO days in a week.";
	cout<<"\n  3-THREE to FIVE days in a week.\n  4-SIX to SEVEN days in a week";
	cout<<"\n  5- EVERYDAY and have physical job or TWICE in a day.\n  Option : ";
	cin>>Exercise;
	//input validation for 'Exercise' variable.
	while(Exercise<1||Exercise>5){
		cout<<"Wrong Input, Enter it again!!\n  Option : ";
		cin>>Exercise;
	}
	cout<<"------------------------------------------------------\n";
	//calculate staff calories to maintain their weight and store in 'maintain'
	if(Exercise==1)
		maintain=bmr*1.2;
	else if(Exercise==2)
		maintain=bmr*1.375;
	else if(Exercise==3)
		maintain=bmr*1.55;
	else if(Exercise==4)
		maintain=bmr*1.725;
	else
		maintain=bmr*1.9;
	//selection for calories intake suggestion based on bmi value
	if(bmi<20){
		plan_weight=20*((GetHeight()/100)*(GetHeight()/100));
		LossOrGain_weight=plan_weight-GetWeight();
		cout<<"\n  Ideal Body Mass Index : 20.00"<<"\n  Ideal Weight : "<<plan_weight;
		cout<<"\n  Weight need to gain : "<<LossOrGain_weight;
		mild=maintain*1.13;//calculate staff calories to gain mildly their weight and store in 'mild'.
		moderate=maintain*1.27;//calculate staff calories to gain moderately their weight and store in 'moderate'.
		extreme=maintain*1.54;//calculate staff calories to gain extremely their weight and store in 'extreme'.
		//display all the calories intake suggestion.
		cout<<"\n\n  Suggestion Calories Intake in a Day :";
		cout<<"\n  MILD weight gain - "<<mild<<" Calories";
		cout<<"\n  MODERATE weight gain - "<<moderate<<" Calories";
		cout<<"\n  EXTREME weight gain - "<<extreme<<" Calories\n";
	}
	else if(bmi>=25){
		plan_weight=20*((GetHeight()/100)*(GetHeight()/100));
		LossOrGain_weight=GetWeight()-plan_weight;
		cout<<"\n  Ideal Body Mass Index : 24.00 "<<"\n  Ideal Weight : "<<plan_weight;
		cout<<"\n  Weight need to burn: "<<LossOrGain_weight;
		mild=maintain*0.87;//calculate staff calories to lose mildly their weight and store in 'mild'.
		moderate=maintain*0.73;//calculate staff calories to lose moderately their weight and store in 'moderate'.
		extreme=maintain*0.46;//calculate staff calories to lose extremely their weight and store in 'extreme'.
		//display all the calories intake suggestion.
		cout<<"\n\n  Suggestion Calories Intake in a Day :";
		cout<<"\n  MILD weight loss - "<<mild<<" Calories";
		cout<<"\n  MODERATE weight loss - "<<moderate<<" Calories";
		cout<<"\n  EXTREME weight loss - "<<extreme<<" Calories\n";
	}
	else if(bmi>=20&&bmi<25){
		cout<<"\t\tCONGRATULATION"<<"\n------------------------------------------------------\n";
		cout<<"\n  Your Body Mass Index is Normal.\n  Maintain your calories intake per day.";
		//display calories that the staff need to maintain their weight.
		cout<<"\n  To maintain you must consume "<<maintain<<" Calories in a day.\n";}
	else{
		//display below if data is not found or weight & weight is not update.
		cout<<"  Name : ";obj.DisplayName();
		cout<<"  Please UPDATE your height and weight to get the suggestion calories intake!!\n";
	}
}
void DerivedData::WeightCategory(){
	//differentiate staff to diffrent weight category based on body mass index.
	if(bmi<20)
		cout<<"\t   Underweight\n  ";
	else if(bmi>=20&&bmi<25)
		cout<<"\t   Normal weight\n  ";
	else if(bmi>=25&&bmi<=30)
		cout<<"\t   Overweight\n  ";
	else
		cout<<"\t   Obese\n  ";
}
