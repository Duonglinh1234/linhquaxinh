#include<iostream.h>
#include<iomanip.h>
class NGUOI {
	private:
		char ht[30];
		char scm[10];
		char gt[3];
	public:
		NGUOI (){}
			NGUOI (char * ht , char * scm , char * gt){
				strcpy (this -> ht , ht);
				strcpy (this -> scm , scm);
				strcpy (this -> gt , gt);
			}
			~NGUOI (){}
		void set(){
			cout<<"\tNhap ho ten :";
			cin.getline(ht,30);
			cout<<"\tNhap so chung minh:";
			cin.getline(scm,10);
			cout<<"\tNhap gioi tinh:";
			cin.getline(gt,3);
		}
		void get(){
			cout<<setw(30)<<ht;
			cout<<setw(15)<<scm;
			cout<<setw(15)<<gt;
		}
		void tieude(){
			cout<<setw(30)<<"HO TEN"
				<<setw(15)<<"SO CHUNG MINH"
				<<setw(15)<<"GIOI TINH";
		}
};
class SV : public NGUOI {
	private:
		char cn[20];
		float dtl;
	public:
		SV (){}
			SV (char * ht , char * scm , char * gt , char * cn , float dtl)
				:NGUOI(ht , scm , gt){
				strcpy (this -> cn , cn);
						this -> dtl = dtl;
			}
			~ SV (){}
		void setSV (){
			NGUOI :: set();
			cout<<"\tNhap chuyen nganh:";
			cin.getline(cn,20);
			do {
				cout<<"\tNhap diem tich luy:";
				cin>>dtl;
				if(dtl>4.0 || dtl < 0.0)
				cout<<"\tBan nhap sai , vui long nhap lai !!! \n";
				
			}while(dtl>4.0 || dtl < 0.0);
			cin.ignore();
		}
		void getSV (){
			NGUOI :: get();
			cout<<setw(20)<<cn;
			cout<<setw(15)<<dtl;			
		}
		void tieude2 (){
			NGUOI :: tieude();
			cout<<setw(20)<<"CHUYEN NGANH"
			    <<setw(15)<<"DIEM TICH LUY"
				<<setw(20)<<"XEP LOAI";
		}
	
	  void xeploai (){
			if(dtl <=4.0 && dtl >= 3.0){
				cout<<setw(15)<<"hsg";
			}
			else if (dtl >= 2.0 && dtl < 3.0 ){
				cout<<setw(15)<<"hsk";
			}
			else {
				cout<<setw(16)<<"hstb";
			}
			
		}
		friend bool operator > ( SV &a , SV &b){
			return a.dtl > b.dtl;
		}
};
 int main(){
 	int n , m;
 	cout<<"\nNhap so nguoi :";
 	cin>>n;
 	NGUOI * ng = new NGUOI [n];
 	cin.ignore();
 	for(int i=0 ; i< n ; i++){
	 	cout<<"\nNhap thong tin nguoi thu "<<i+1<<": \n";
	 	ng[i].set();
	 }
	 cout<<"\nXuat thong tin nguoi: \n";
	 ng -> tieude();
	 cout<<endl;
	 for(int i=0 ; i< n ; i++){
	 	cout<<"\nNguoi thu"<<i+1<<":";
 		ng[i].get();
 		cout<<endl;
 	}
 	
 	cout<<"\nNhap thong tin sinh vien:";
 	cin>>m;
 	SV * sinhvien = new SV [m];
 	cin.ignore();
 	for(int i=0 ; i < m; i++ )
 	{
	 	cout<<"\nNhap thong tin sinh vien thu"<<i+1<<": \n";
	 	sinhvien[i].setSV();
	 }
	 
	 
 	cout<<"\nDanh sach sinh vien tang dan theo diem tich luy: \n";
 	sinhvien -> tieude2();
 	cout<<endl;
 	for(int i=0 ; i< m ; i++){
	 	for(int j=i+1 ; j<m ; j++){
	 		if(sinhvien[i] > sinhvien[j]){
	 			SV temp = sinhvien[i];
	 			sinhvien[i]=sinhvien[j];
	 			sinhvien[j]=temp;
	 	}
 	}
 	sinhvien[i].getSV();
 	sinhvien[i].xeploai();
 	cout<<endl;
 	}
 }