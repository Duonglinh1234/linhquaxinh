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
		Nguoi (char * ht , char * scm, char *gt){
			strcpy(this ->ht, ht);
			strcpy(this -> scm,scm);
			strcpy(this ->gt, gt);
			
		}
		~Nguoi (){};
		void nhap (){
		   
			cout<<"\nNhap ho ten: ";
			cin.getline(ht,30);
			cout<<"\nNhap so chung minh thu: ";
			cin.getline(scm,10);
			cout<<"\nNhap vao gioi tinh: ";
			cin.getline(gt,3);
		}
		void tieude(){
			cout<<setw(15)<<"Ho ten"
				<<setw(15)<<"Chung minh thu"
				<<setw(15)<<"Gioi tinh"<<endl;
		}
		void xuat(){
			cout<<setw(15)<<ht
				<<setw(15)<<scm
				<<setw(15)<<gt<<endl;
		}		
};
class HS : public Nguoi{
	private:
		char cn[20];
		float dtk;
	public:
		HS(){}
		HS(char * ht, char * scm , char*gt,	char * cn, float dtk)
		:Nguoi(ht, scm, gt){
			strcpy(this-> cn, cn);
			this -> dtk, dtk;
		}
		~HS(){}
		friend istream &operator >> (istream &is, HS &a){
			a.nhap();
		
			cout<<"\nNhap chuyen nganh:";
			cin.getline(a.cn,20);
			cout<<"\nNhap diem tong ket:";
			cin>>a.dtk;
			return is;
		}
		friend ostream &operator << (ostream &os , HS&b){
			b.xuat();
		    os<<b.cn;
		    os<<b.dtk;
		    return os;
  	}
};
int main()
{
	int n;
	cout<<"\nNhap vao so nguoi:";
	cin>>n;
	Nguoi * x = new Nguoi[n];
	cin.ignore();
	for(int i=0 ; i<n ; i++){ /////i++=i+1 sau thuc thi=run
		cout<<"\nNhap vao thong tin nguoi thu "<<i+1<<":"<<endl;
		x[i].nhap();
	
	}
	
	for(int i=0 ; i<n ; i++){
		x[i].tieude();
		x[i].xuat();
		cout<<endl;	
	}
	int m;
	cout<<"\nNhap vao so hoc sinh:";
	cin>>m;
	HS *y=new HS [m];
	cin.ignore();
	for(int i=0; i<m ; i++){
	
		cout<<"\nNhap vao thong tin HS thu "<<i+1<<":";
	    cin >> y[i];
		cout<<endl;
	}	
	for(int i=0; i<m ; i++){
		cout<<"\nxuat thong tin thu"<<i+1<<":";
		cout<< y[i];
	}
	
	
}