#include<iostream.h>
#include<string.h>
class Nguoi {
	private:
		char hoten[30];
		int tuoi;
		char cmt[10];
	public:
		Nguoi (){}
			Nguoi (char * hoten , int tuoi , char * cmt){
				strcpy (this -> hoten, hoten);
						this -> tuoi 
			}
};