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
class CN : public NGUOI{
	private:
		char cv[20];
		float sn;
	public:
		CN (){}
			CN (char * ht , char * scm , char * gt , char * cv , float sn)
				: NGUOI (ht , scm , gt){
				strcpy (this -> cv , cv);
						this -> sn=sn;
			}
	void setCN(){
		NGUOI :: set();
		cout<<"\tNhap cong viec:";
		cin.getline(cv,20);
		do{
			cout<<"\tNhap so nam lam viec:";
		    cin>>sn;
		    if(sn >10 || sn < 0)
		    {
    			cout<<"\tBan nhap sai , vui long nhap lai !!!! \n";
    		}
		}while(sn >10 || sn < 0);
		cin.ignore();
	}
	void getCN(){
		NGUOI :: get();
		cout<<setw(25)<<cv
		    <<setw(20)<<sn;
	}
	void tieude2(){
		NGUOI :: tieude();
		cout<<setw(25)<<"CONG VIEC"
			<<setw(20)<<"SO NAM"
			<<setw(20)<<"XEP LOAI";
	}
	void xeploai(){
		if(sn >= 0.0 && sn <= 2.9){
		    cout<<setw(20)<<"so cap";
		}
		else if(sn >=3.0 && sn <= 9.9){
			cout<<setw(20)<<"trung cap"; 
		}
		else{
			cout<<setw(20)<<"cao cap";
		}
	}
	friend bool operator > (CN &a , CN &b){
		return a.sn > b.sn; 
	}
	
};
int main(){
	int n;
	cout<<"\nNhap so luong nguoi:";
	cin>>n;
	NGUOI * ng = new NGUOI [n];
	cin.ignore();
	for(int i=0 ; i < n ; i++){
		cout<<"\nNhap thong tin nguoi thu"<<i+1<<": \n";
		ng[i].set();
	}
	cout<<"\nXuat thong tin nguoi : \n";
	ng -> tieude();
	cout<<endl;
	for(int i=0 ; i < n ; i++){
		cout<<"\nNguoi thu "<<i+1<<": \n";
		ng[i].get();
	}
	
	int m;
	cout<<"\nNhap so cong nhan:";
	cin>>m;
	CN * congnhan = new CN [m];
	cin.ignore();
	for(int i=0 ; i < m ; i++){
		cout<<"\nNhap thong tin cong nhan thu"<<i+1<<": \n";
		congnhan[i].setCN();
	}
	cout<<"\nDanh sach cong nhan theo thu tu tang dan: \n";
	congnhan -> tieude2();
	cout<<endl;
	for(int i=0 ; i < m ; i++){
			for(int j=i+1 ; j < m ; j++){
				if(congnhan	 [i] > congnhan	[j]){
					CN temp = congnhan[i];
					congnhan [i] = congnhan[j];
					congnhan[j] = temp;
				}
			}
			congnhan[i].getCN();
			congnhan[i].xeploai();
			cout<<endl;
	}
}