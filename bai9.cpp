#include<iostream.h>
#include<iomanip.h>

class GV {
	private:
		char ht[30];
		char cn[20];
		float bl;
	public:
		GV (){}
			GV (char * ht , char * cn , float bl){
				strcpy (this -> ht , ht );
				strcpy (this -> cn , cn);
						this -> bl=bl;
			}
		~ GV (){}
	void nhap (){
		cout << "\tNhap ho ten:";
		cin.getline(ht,30);
		cout << "\tNhap chuyen nganh:";
		cin.getline(cn,20);
		cout << "\tNhap bac luong:";
		cin>>bl;
		cin.ignore();
	}
	void xuat (){
		cout << setw(35) << ht
			 << setw(25) <<cn
			 << setw(20) <<bl;
			 
	}
	void tieude1 (){
		cout << setw(35) << "HO TEN"
			 << setw(25) <<"CHUYEN NGANH"
			 << setw(20) <<"BAC LUONG";		
	}
};
class GVDH : public GV {
	private :
		char chuyenmon [20];
		float sn;
	public :
		GVDH (){}
			GVDH (char * ht , char * cn , float bl , char * chuyenmon , float sn)
				: GV ( ht, cn , bl){
					strcpy (this -> chuyenmon , chuyenmon);
							this -> sn=sn;
				}
		~ GVDH (){}
	void nhapGVDH (){
		GV :: nhap();
		cout << "\tNhap chuyen mon:";
		cin.getline(chuyenmon,20);
		cout << "\tNhap so nam cong tac:";
		cin >> sn;
		cin.ignore();
	}
	const char * xeploai (){
		if ( sn >= 0.0 && sn <= 4.9){
			return "gv tap su";
		}
		else if ( sn >= 5.0 && sn <= 9.9){
			return " gv chinh";
		}
		else{
			return "gv cao cap";
		}
	}
	void xuatGVDH (){
		GV :: xuat();
		cout << setw(25)<<chuyenmon
			 << setw(25)<<sn;
	}
	void tieude2(){
		GV :: tieude1();
		cout << setw(25)<<"CHUYEN NGANH"
			 << setw(25)<<"SO NAM";
	}
	friend bool operator >= (GVDH &a , GVDH &b){
		return a.sn >= b.sn;
	}
};
main(){
	int n;
	do {
		cout<<"\nNhap so giao vien:";
		cin>>n;
		
		if( n <= 0){
			cout<<"\nBan nhap sai vui long nhap lai !!! \n";
		}
	}while( n <= 0);
	
	GV * giaovien = new GV[n];
	cin.ignore();
	for (int i=0 ; i<n ; i++){
		cout<<"\nNhap thong tin giao vien thu "<<i+1<<":\n";
		giaovien[i].nhap();
	}
	cout<<"\nXuat thong tin giao vien: \n";
	giaovien ->tieude1();
	cout<<endl;
	for (int i=0 ; i<n ; i++){
		cout<<"\nGiao vien thu "<<i+1<<":\n";
		giaovien[i].xuat();
	}
	
	int m;
	
	do {
		cout<<"\nNhap so giao vien:";
		cin>>m;
		if( m <= 0){
			cout<<"\nBan nhap sai vui long nhap lai !!! \n";
		}
	}while( m <= 0);
		
	GVDH * daihoc = new GVDH [m];
	cin.ignore();
	for(int i=0 ; i < m ; i++ ){
		cout<<"\nNhap so giang vien dai hoc: \n";
		daihoc [i].nhapGVDH();
	}
	cout<<"\nDanh sach gvdh la giang vien cao cap: \n";
	daihoc -> tieude2();
	cout << endl;
	for(int i=0 ; i < m ; i++ ){
		if (daihoc[i].xeploai() == "loai cao cap"){
			daihoc[i].xuatGVDH();
		}
			daihoc[i].xuatGVDH();
	}
}