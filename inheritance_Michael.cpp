#include <iostream>


using namespace std;

class Student1  {
	private:
		string name;
		char gender;
	
	public:
		Student1();
		void setName (string name);

		void setGender (char gender);
 
		string getName(){
			return name;
		}
		char getGender(){
			return gender;
		}
};

class Teacher {
	private:
		int nik;
		string faculty;
	
	public:
		void setNik (int x){
			nik = x;
		}
		int getNik(){
		return nik;
		}
		void SetFaculty (string faculty);
		string getFaculty(){
		return faculty;
		}	
		void setData();
		void displayData();
};

class Student {
	private:
		int nim;
		string registration_number;
		string prodi;
	
	public:
		void setNim (int n){
		nim = n;
		}
		void SetRegistrationNumber (string registration_number);
		void setProdi (string prodi);
		int getNim(){
		return nim;
		}
		string getRegistrationNumber();
		string getProdi();
};


int main () {
	
	
	
	return 0;
}
