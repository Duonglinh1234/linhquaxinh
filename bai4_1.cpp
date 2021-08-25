#include<iostream.h>
#include<iomanip.h>
class NGUOI {
	private:
		char ht[30];
		char scm[10];
		char gt[3];
	public:
		NGUOI(){}
			NGUOI(char * ht , char * scm , char * gt){
				strcpy(this -> ht, ht);
				strcpy(this -> scm , scm);
				strcpy(this -> gt, gt);
			}
		~NGUOI(){};
	void set(){
		cout<<"\tNhap ho ten:";
		cin.getline(ht,30);
		cout<<"\tNhap so chung minh:";
		cin.getline(scm,10);
		cout<<"\tNhap gioi tinh:";
		cin.getline(gt,3);
	}
	void get(){
		cout<<setw(25)<<ht;
		cout<<setw(15)<<scm;
		cout<<setw(13)<<gt;
	}
	void tieude(){
		cout<<setw(25)<<"HO TEN"
			<<setw(15)<<"SO CHUNG MINH"
			<<setw(13)<<"GIOI TINH";			
	}
};
class NV : public NGUOI{
	private:
		char tdcm[10];
		float sn;
	public:
		NV(){}
			NV(char * ht , char * scm , char * gt , char * tdcm , float sn)
				:NGUOI(ht,scm,gt){
					strcpy (this ->tdcm,tdcm);
							this ->sn=sn;				
			}
			~NV(){}
	void setNV(){
		NGUOI ::set();
		cout<<"\tNhap trinh do chuyen mon:";
		cin.getline(tdcm,10);
		cout<<"\tNhap so nam nop bao hiem xa hoi:";
		cin>>sn;
		cin.ignore();		
	}
	void getNV(){
		NGUOI :: get();
		cout<<setw(23)<<tdcm;
		cout<<setw(15)<<sn;
		cout<<setw(15)<<tienchedo();
		
	}
	void tieude2(){
		NGUOI :: tieude();
		cout<<setw(23)<<"TRINH DO CHUYEN MON"
			<<setw(15)<<"SO NAM NOP"
			<<setw(15)<<"TIEN CHE DO"<<endl;
	}
	float tienchedo(){
		return 50*sn;
	}
	
friend bool operator >=(NV &a, NV&b)
	{
		return (a.sn > b.sn);
	}
};
main(){
	 int n;	
	 cout<<"\nNhap so luong nguoi: ";
	 cin>>n;
	 
	 NGUOI * ng = new NGUOI[n];
	 cin.ignore();
	 for(int i=0 ; i< n ; i++){
 		cout<<"\nNHap thong tin nguoi thu"<<i+1<<": \n" ;
 		ng[i].set();
 	}
 	cout<<"\nXuat thong tin nguoi: \n";
 	ng->tieude();
 	cout<<endl;
 	 for(int i=0 ; i< n ; i++){
 	 	cout<<"\nNguoi thu"<<i+1<<": \n";
 	 	ng[i].get();
 	 }
 	 
 	 int m;
 	 cout<<"\nNhap so luong nhan vien:";
 	 cin>>m;
 	 NV * nhanvien = new NV[m];
 	 cin.ignore();
 	 for(int i=0 ; i< m ; i++){
 	 	cout<<"\nNhap thong tin nhan vien thu"<<i+1<<": \n";
 	    nhanvien[i].setNV();
 	 }
 	 cout<<"\nDanh sach nhan vien theo thu tu tang dan: \n";
 	 nhanvien->tieude2();
 	 cout<<endl;
 	 for(int i=0 ; i< m ; i++){
 	 	for(int j=i+1 ; j< m ; j++){
	 	 	if(nhanvien[i]>= nhanvien[j]){
	 	 		NV temp = nhanvien[i];
	 	 		nhanvien[i]=nhanvien[j];
	 	 		nhanvien[j]=temp;
	 	 	}
	 	 }
	 	 cout<<"\nNhan vien thu "<<i+1<<": \n";
	 	 nhanvien[i].getNV();
 	 }
 	 
}

