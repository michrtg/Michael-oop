#include<iostream>
#include<conio.h>
using namespace std;
class gradest{
private:
	int a,b,c,d,e;
	int pera,perb,perc,perd,pere,perfin;
public:
	void grade()
	{
	cout<<"\nAttendance"<<endl;
	cin>>a;
	cout<<"\nQuiz "<<endl;
	cin>>b;
	cout<<"\nAssigment"<<endl;
	cin>>c;
	cout<<"\nMid exam"<<endl;
	cin>>d;
	cout<<"\nFinal exam"<<endl;
	cin>>e;
	pera=(a*10)/100/100;
	perb=(b*10)/100/100;
	perc=(c*20)/100/100;
	perd=(d*30)/100/100;
	pere=(e*30)/100/100;
	perfin= pera+perb+perc+perd+pere;
		if(perfin>=91&& perfin<=100){
		cout<<"A grade\n";}
		else if(perfin>=85 && perfin <=90){
		cout<<"A- grade\n";}
		else if(perfin>=82 && perfin<=84){
		cout<<"B+ grade\n";}
		else if(perfin>=78 && perfin<=81){
		cout<<"B grade\n";}
		else if(perfin>=75 && perfin<=77){
		cout<<"B- grade\n";}
		else if(perfin>=70 && perfin<=74){
		cout<<"C+ grade\n";}
		else if(perfin>=67 && perfin<=69){
		cout<<"C grade\n";}
		else if(perfin>=60 && perfin<=66){
		cout<<"C- grade\n";}
		else if(perfin>=40 && perfin<=59){
		cout<<"D grade\n";}
		else{
			cout<<"F grade\n";
		}
}
	void student()
	{
		cout<<"\nAttendance : "<<a;
		cout<<"\nQuiz: "<<b;
		cout<<"\nAssigment: "<<c;
		cout<<"\nMid exam: "<<d;
		cout<<"\nFinal exam:"<<e;
	}
	};
	int main(){
		cout<<"Grading system ver1.0\n";
		cout<<"=======================\n";
		int z;
		int angka ['a'];
		gradest stn[z];
		cout<<"Enter number of students: \n";
		cin>>z;
			for(int i=1; i<=z; i++) {
				cout<<"Enter the grade for student ["<<i<<"] ";
			stn[i].grade();
			}	
		
			for(int i=1; i<=z; i++) {
			stn[i].student();
			}
	return 0;
	}
