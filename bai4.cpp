#include<iostream.h>
#include<string.h>

class Nguoi {
	private:
		char ht[30];
		char scm[10];
		char gt[3];
	public:
		Nguoi (){}
			Nguoi(char* ht , char * scm , char * gt){
				strcpy (this -> ht , ht);
				strcpy (this -> scm , scm);
				strcpy (this -> gt , gt);
			}
		~Nguoi (){}
		void nhap (){
			cin.ignore();
			cout<<"\nNhap ho ten:";
			cin.getline(ht,30);
			cout<<"\nNhap so chung minh:";
			cin.getline(scm,10);
			cout<<"\nNhap gioi tinh:";
			cin.getline(gt,3);
			
		}
		void xuat(){
			cout<<"\nHo ten:"<<ht<<endl;
			cout<<"\nSo chung minh:"<<scm<<endl;
			cout<<"\nGioi tinh:"<<gt<<endl;
		}
	
};
class Nhanvien : public Nguoi {
	private:
		char tdcm[10];
		float sn;
	public:
		Nhanvien (){}
			Nhanvien (char* ht , char * scm , char * gt , char * tdcm , float sn)
				:Nguoi(ht , scm , gt){
					strcpy(this -> tdcm , tdcm);
							this -> sn = sn;
				}
		~ Nhanvien (){};
	friend istream &operator >>(istream &is , Nhanvien &a)
	{
		a.nhap();
		cin.ignore();
		cout<<"\nNhap trinh do chuyen mon:";
		is.getline(a.tdcm,10);
		cout<<"\nNhap so nam nop bao hiem xa hoi:";
		is>>a.sn;
	}
	friend ostream &operator <<(ostream &os , Nhanvien &b)
	{
		b.xuat();
		os<<"\nTrinh do chuyen mon:"<<b.tdcm<<endl;
		os<<"\nSo nam nop bao hiem xa hoi:"<<b.sn<<endl;
		os<<"\nNhap tin che do :"<<b.tienchedo()<<endl;		
	}
	float tienchedo(){
		float tcd;
		tcd=50*sn;
		return tcd;
	}
	friend bool operator >= (Nhanvien &a , Nhanvien &b)
	{
		if(a.sn >= b.sn)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
int main(){
	int n;
	cout<<"\nNhap so nguoi :";
	cin>>n;
	Nguoi * ngui = new Nguoi[n];
	cout<<"\n*******Nhap thong tin cua nguoi*******";
	for(int i=0 ; i< n ; i++){
		cout<<"\nNhap thong tin nguoi thu "<<i+1<<":";
		ngui[i].nhap();		
	}
	cout<<"\n*******Xuat thong tin cua nguoi*******";
	for(int i=0 ; i< n ; i++){
		cout<<"\nXuat thong tin nguoi thu "<<i+1<<":";
		ngui[i].xuat();		
	}
	
	int m;
	cout<<"\nNhap so nhan vien :";
	cin>>m;
	Nhanvien * nv = new Nhanvien[m];
	cout<<"\n*******Nhap thong tin cua nhan vien****";
	for(int i=0 ; i<m ; i++){
		cout<<"\nNhap thong tin cua nhan vien thu "<<i+1<<":";
		cin>>nv[i];
	}
	cout<<"\n*******Xuat thong tin cua nhan vien****";
	for(int i=0 ; i<m ; i++){
		cout<<"\nXuat thong tin cua nhan vien thu "<<i+1<<":";
		cout<<nv[i];
	}
	cout<<"\n*****Danh sach nhan vien duoc huong che do cua tien luong duoc huong che do *****:";
		for(int i=0 ; i<m ; i++)
		{
			for(int j=i+1 ; j<m ; j++)
			{
				if(nv[i]>=nv[j])
				{
					Nhanvien temp=nv[i];
					nv[i]=nv[j];
					nv[j]= temp;
				}
			}
		}
		for(int i=0 ; i<m ; i++)
		{
			cout<<nv[i];
		}
}