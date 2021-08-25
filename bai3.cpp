#include<iostream.h>
#include<string.h>
#include<iomanip.h>
class Nguoi {
	private:
		char ht[30];
		char scm[10];
		char gt[3];
	public:
		Nguoi(){}
			Nguoi (char * ht , char * scm , char * gt){
				strcpy (this -> ht, ht);
				strcpy (this -> scm , scm);
				strcpy (this -> gt, gt);
			}
		~Nguoi (){};
	void set(){
	  
		cout<<"\tNhap ho ten :";
		cin.getline(ht,30);
		cout<<"\tNhap so chung minh:";
		cin.getline(scm,10);
		cout<<"\tNhap gioi tinh:";
		cin.getline(gt,3);
	}
	void get(){
		cout<<setw(35)<<ht;
		cout<<setw(20)<<scm;	
		cout<<setw(15)<<gt;	
	}
	void tieude(){
		cout<<setw(35)<<"HO TEN"
			<<setw(20)<<"SO CHUNG MINH"
			<<setw(15)<<"GIOI TINH";
	}
};
class Giangvien : public Nguoi{
	private:
		char tdcm[10];
		int thamnien;
	public:
		Giangvien(){}
			Giangvien(char * ht , char * scm , char * gt , char * tdcm , int thamnien)
			:Nguoi (ht , scm , gt){
				strcpy (this ->tdcm , tdcm);
						this ->thamnien = thamnien;
			}
		~Giangvien (){};
		friend istream &operator >> (istream &is , Giangvien &a)
		{
			a.set();		
			cout<<"\tNhap trinh do chuyen mon:";
			is.getline(a.tdcm,10);
			cout<<"\tNhap so nam cong tac:";
			is>>a.thamnien;
			cin.ignore();
			return is;
		}
		friend ostream &operator << (ostream &os , Giangvien &b)
		{
			b.get();
			os<<setw(15)<<b.tdcm;
			os<<setw(15)<<b.thamnien;
			os<<setw(25)<<b.tienthamnien()<<endl;
			return os;
		}
			void tieude2(){
	    	Nguoi::tieude();
	    	cout<<setw(15)<<"TRINH DO";
			cout<<setw(15)<<"THAM NIEN";
			cout<<setw(25)<<"TIEN THAM NIEN"<<endl;
			
      	}
      	
	float tienthamnien()
	{
		return 100 * thamnien;
	}
	
	friend bool operator >= (Giangvien &a , Giangvien &b)
	{
		if (a.thamnien >= b.thamnien)
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
	cout<<"Nhap so nguoi:";
	cin>>n;
	Nguoi * ng = new Nguoi[n];
	cin.ignore();
	for(int i = 0 ; i < n ; i++)
	{
	
		cout<<"\nNhap thong tin nguoi thu "<<i+1<<":"<<endl;
		ng[i].set();
	}
	cout<<"\nXuat thong tin nguoi : \n";
	ng->tieude();
	cout<<endl;
	for(int i=0 ; i< n ; i++)
	{
		cout<<"\nNguoi thu "<<i+1<<":"<<endl;
		ng[i].get();
	}
	
	int m;
	cout<<"\nNhap so giang vien :";
	cin>>m;
	Giangvien * gv = new Giangvien[m];
	cin.ignore();
	for(int i=0 ; i< m ; i++)
	{
		cout<<"\nNhap thong tin giang vien thu "<<i+1<<":"<<endl;
		cin>>gv[i];
	}
	
	cout<<"\nDanh sach giang vien theo thu tu tang dan : \n";
	gv->tieude2();
	cout<<endl;	
	for(int i=0 ; i<m ; i++){
		for(int j=i+1 ; j<m ; j++)
		{
		    if(gv[i]>=gv[j]){
    			Giangvien temp=gv[i];
    			gv[i]=gv[j];
    			gv[j]=temp;
    		}
		}
	}
	for(int i=0 ; i<m ; i++){
		cout<<gv[i];
	}
}