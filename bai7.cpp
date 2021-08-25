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
				strcpy ( this -> ht, ht);
				strcpy ( this -> scm , scm);
				strcpy ( this -> gt , gt);
			}
			~ NGUOI (){}
		void set(){
			cout<<"\tNhap ho ten:";
			cin.getline(ht,35);
			cout<<"\tNhap so chung minh:";
			cin.getline(scm,10);
			cout<<"\tNhap gioi tinh:";
			cin.getline(gt,3);
		}
		void get(){
			cout<<setw(35)<<ht
				<<setw(20)<<scm
				<<setw(20)<<gt;
		}
		void tieude(){
			cout<<setw(35)<<"HO TEN"
				<<setw(20)<<"SO CHUNG MINH"
				<<setw(20)<<"GIOI TINH";
		}
};
class KH : public NGUOI{
	private:
		char th[30];
		float sl,dg;
	public:
		KH (){}
			KH (char * ht , char * scm , char * gt , char * th , float sl , float dg)
				: NGUOI (ht,scm,gt){
					strcpy (this -> th,th);
							this -> sl=sl;
							this -> dg=dg;				
			}
	void setKH(){
		NGUOI :: set();
		cout<<"\tNhap ten mat hang:";
		cin.getline(th,30);
		cout<<"\tNhap so luong:";
		cin>>sl;
		cout<<"\tNhap don gia:";
		cin>>dg;
		cin.ignore();
	}
	void getKH(){
		NGUOI :: get();
		cout<<setw(35)<<th
			<<setw(20)<<sl
			<<setw(20)<<dg
			<<setw(25)<<tinhtien()<<endl;
	}
	void tieude2(){
		NGUOI :: tieude();
		cout<<setw(35)<<"TEN HANG"
			<<setw(20)<<"SO LUONG"
			<<setw(20)<<"DON GIA"
			<<setw(25)<<"TIEN PHAI TRA"<<endl;
	}
	float tinhtien(){
		return sl*dg;
	}
	friend bool operator > (KH &a , KH &b){
		return a.tinhtien() > b.tinhtien();
	}
};
main(){
	int n;
	cout<<"\nNhap so nguoi:";
	cin>>n;
	NGUOI * ng = new NGUOI [n];
	cin.ignore();
	for(int i=0 ; i<n ; i++){
		cout<<"\nNhap thong tin nguoi thu"<<i+1<<": \n";
		ng[i].set();
	}
	cout<<"\nXuat thong tin nguoi: \n";
	ng -> tieude();
	cout<<endl;
	for(int i=0 ; i<n ; i++){
		cout<<"\nNguoi thu "<<i+1<<": \n";
		ng[i].get();
	}
	int m;
	cout<<"\nNhap so khach hang:";
	cin>>m;
	KH * khachhang = new KH [m];
	cin.ignore();
	for(int i=0 ; i< m ; i++){
		cout<<"\nNhap thong tin khach hang thu"<<i+1<<": \n";
		khachhang[i].setKH();	
		}
	cout<<"\nDanh sach khach hang theo thu tu tang dan cua so tien phai tra: \n";
	khachhang -> tieude2();
	cout<<endl;
	for(int i= 0 ; i < m ; i++){
		for(int j=i+1 ; j<m ; j++){
			if(khachhang[i]>khachhang[j]){
				KH temp = khachhang[i];
				khachhang[i] = khachhang[j];
				khachhang[j] = temp;
			}
		}
		cout<<"\nKhach hang thu "<<i+1<<":\n";
		khachhang[i].getKH();
	}
	

	
}