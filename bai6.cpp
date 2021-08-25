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
class KHTG : public KH{
	private:
		double st;
		float tg;
	public:
		KHTG (){}
			KHTG (char * ht , char * scm , char * gt , double st , float tg )
				:KH (ht,scm,gt){
				this -> st =st;
				this -> tg=tg;
			}
			~KHTG (){}
		void setKHTG(){
			KH :: set();
			cout<<"\tNhap so tien:";
			cin>>st;
			cout<<"\tNhap thoi gian:";
			cin>>tg;
			cin.ignore();
		}
		void getKHTG(){
			KH :: get();
			cout<<setw(20)<<st
				<<setw(15)<<tg;
		}
		void tieude2(){
			KH :: tieude();
			cout<<setw(20)<<"SO TIEN"
				<<setw(15)<<"THOI GIAN"
				<<setw(20)<<"XEP LOAI"<<endl;
		}
		void xeploai (){
			if ( st <= 10000000 && st >= 999999999)
			{
				cout<<setw(20)<<"loai TB";
			}
			else{
				cout<<setw(20)<<"loai VIP";
			}
		}
		friend bool operator > (KHTG &a , KHTG &b){
			return a.tg > b.tg;
		}
};
main(){
	int n;
	cout<<"\nNhap so khach hang:";
	cin>>n;
	KH * khachhang= new KH [n];
	cin.ignore();
	for(int i=0 ; i<n ; i++){
		cout<<"\nNhap thong tin khach hang thu "<<i+1<<": \n";
		khachhang[i].set();
	}
	cout<<"\nXuat thong tin khach hang: \n";
	khachhang -> tieude();
	cout<<endl;
	for(int i=0 ; i<n ; i++){
		cout<<"\nKhach hang thu "<<i+1<<": \n";
		khachhang[i].get();
	}
	
	int m;
	cout<<"\nNhap khach hang tien gui:";
	cin>>m;
	KHTG * tiengui = new KHTG[m];
	cin.ignore();
	for(int i=0 ; i< m ; i++){
		cout<<"\nNhap thong tin khach hang tien gui thu"<<i+1<<": \n";
		tiengui[i].setKHTG();
	}
	cout<<"\nDanh sach KHTG theo thu tu tang dan theo so thang gui: \n";
	tiengui ->tieude2();
	cout<<endl;
	for(int i=0 ; i< m ; i++){
			for(int j=i+1 ; j< m ; j++){
				if (tiengui[i]>tiengui[j]){
					KHTG temp = tiengui[i];
					tiengui[i] = tiengui[j];
					tiengui[j] = temp;
				}
			}
			tiengui[i].getKHTG();
			tiengui[i].xeploai();
	}
	
}
