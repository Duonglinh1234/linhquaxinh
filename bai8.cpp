#include<iostream.h>
#include<iomanip.h>

class KH {
	private:
		char ht[30];
		char scm[10];
		char gt[3];
	public:
		KH (){}
			KH (char * ht , char * scm , char * gt){
				strcpy ( this -> ht, ht);
				strcpy ( this -> scm , scm);
				strcpy ( this -> gt , gt);
			}
			~ KH (){}
		void set(){
			cout<<"\tNhap ho ten:";
			cin.getline(ht,30);
			cout<<"\tNhap so chung minh:";
			cin.getline(scm,10);
			cout<<"\tNhap gioi tinh:";
			cin.getline(gt,3);
		}
		void get(){
			cout<<setw(35)<<ht
				<<setw(15)<<scm
				<<setw(10)<<gt;
		}
		void tieude(){
			cout<<setw(35)<<"HO TEN"
				<<setw(15)<<"SO CHUNG MINH"
				<<setw(10)<<"GIOI TINH";
		}
		
};
class KHTV : public KH {
	private:
		double st;
		float tg;
	public:
		KHTV (){}
			KHTV (char * ht , char * scm , char * gt , double st , float tg)
				: KH (ht, scm ,gt){
					this ->st=st;
					this ->tg=tg;
				}
	void setKHTV(){
		KH :: set();
		cout<<"\tNhap so tien vay:";
		cin>>st;
	 	do{
	 			cout<<"\tNhap thoi gian vay:";
				cin>>tg;
				if(tg <1 ){
					cout<<"\tBan nhap sai vui long nhap lai !!! \n";
				}
	 	}while(tg <1);
		cin.ignore();
	}
	const char * phanloai(){////hang khong thay doi.* tror den gia tri
		if (tg >=1 && tg <=12){
		   return "loai ngan han";
		}
		else if(tg >=13 && tg <=36){
			return "loai trung han";
		}
		else{
			return "loai dai han";
		}
	}
	void getKHTV(){
		KH :: get();
		cout<<setw(20)<<st
			<<setw(20)<<tg
			<<setw(15)<<phanloai()<<endl;
	}
	void tieude2(){
		KH :: tieude();
		cout<<setw(20)<<"SO TIEN VAY"
	 		<<setw(20)<<"THOI GIAN"
	        <<setw(15)<<"PHAN LOAI"<<endl;
	}
	friend bool operator > (KHTV &a , KHTV &b){
		return a.tg > b.tg;
	}
	  
};
main(){
	int n;
	do{
		cout<<"\nNhap so luong khach hang :";
		cin>>n;
		if(n<=0)
		{
			cout<<"\nBan nhap sai vui long nhap lai!!! \n";
		}
	}while(n<=0);
	
	KH * khachhang = new KH[n];
	cin.ignore();
	for(int i=0 ; i < n ; i++){
		
		cout<<"\nNhap thong tin khach hang thu "<<i+1<<":\n";
		khachhang[i].set();
		
	}
	
	cout<<"\nXuat thong tin khach hang: \n";
	khachhang -> tieude();
	cout << endl;
	
	for(int i=0 ; i<n ; i++){
		cout<<"\nKhach hang thu"<<i+1<<"\n";
		khachhang[i].get();
	}
	
	int m;
	do{
			cout<<"\nNhap so khach hang tien vay cua ngan hang:";
			cin>>m;
			if(m<=0){
					cout<<"\nBan nhap sai vui long nhap lai!!! \n";
			}
	}while(m<=0);
	KHTV * kh = new KHTV [m] ;
	cin.ignore();
  	for(int i=0 ; i < m ; i++){
		cout<<"\nNhap thong tin khach hang tien vay thu "<<i+1<<":\n";
		kh[i].setKHTV();
	}
	
	cout<<"\nDanh sach khach hang tien vay loai dai han:\n";
	kh -> tieude2();
	cout<<endl;
	
	for(int i=0 ; i < m ; i++){
		if(kh[i].phanloai() == "loai dai han"){
			kh[i].getKHTV();
		}
			kh[i].getKHTV();
	}
	cout<<endl;		
}          