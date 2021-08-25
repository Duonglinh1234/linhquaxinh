#include<iostream.h>
#include<string.h>
class Sanpham{
	private:
		char masp[10];
		char tensp[20];
		int loaisp;
		float dongia;
	public:
		Sanpham(){};
			Sanpham(char * masp , char * tensp , int loaisp , float dongia){
				strcpy (this -> masp , masp);
				strcpy (this -> tensp, tensp);
						this -> loaisp = loaisp;
						this -> dongia = dongia;		
			}
		~ Sanpham(){};
		void set (){
			cin.ignore();
			cout <<"\nNhap ma san pham:";
			cin.getline(masp,10);
			cout <<"\nNhap ten san pham:";
			cin.getline(tensp,20);
			cout <<"\nNhap loai san pham:";
			cin>>loaisp;
			cout<<"\nNhap don gia san pham:";
			cin>>dongia;
		}
		void get(){
		    cout <<"\nNhap ma san pham:"<<masp;
			cout <<"\nNhap ten san pham:"<<tensp;
			cout <<"\nNhap loai san pham:"<<loaisp;
			cout<<"\nNhap don gia san pham:"<<dongia;
		}
		float getdongia(){
			return dongia;
		}
};

class Hoadon:public Sanpham{
	private:
		char mahoadon[20];
		int ngaylaphoadon;
		float soluong;
	public:
		Hoadon(){}
			Hoadon(char * masp , char * tensp , int loaisp , float dongia , char * mahoadon , int ngaylaphoadon , float soluong )
			:Sanpham(masp , tensp	, loaisp, dongia){
				strcpy ( this -> mahoadon , mahoadon);
						 this -> ngaylaphoadon = ngaylaphoadon;
						 this -> soluong = soluong;
			}
	    ~ Hoadon (){};
	    friend istream &operator >>(istream &is, Hoadon&a){
	    	a.set();
	    	cin.ignore();
	    	cout<<"\nNhap ma hoa don:";
	    	is.getline(a.mahoadon,20);
	    	cout<<"\nNhap ngay lap hoa don:";
	    	is>>a.ngaylaphoadon;
	    	cout<<"\nNhap so luong:";
	    	is>>a.soluong; 
			return is; 		
    	}
	    friend ostream &operator <<(ostream &os , Hoadon&b){
    		b.get();
    		os<<"\nMa hoa don :"<<b.mahoadon<<endl;
    		os<<"\nNgay lap hoa don:"<<b.ngaylaphoadon<<endl;
    		os<<"\nSo luong "<<b.soluong<<endl;
    		cout<<"\nThanh tien: "<<b.thanhtien()<<endl;
    		return os;
    	}
    	float thanhtien (){
	    	float tt;
	    	tt = soluong * getdongia();
	    	return tt;
	    }
	    friend bool operator <(Hoadon &a , Hoadon &b)
	    {
    		return a.thanhtien()< b.thanhtien();
    	}
	    
	
};
int main(){
	int n; 
	cout<<"\nNhap so san pham :";
	cin>>n;
	Sanpham * sp = new Sanpham[n];
	for(int i=0 ; i<n ; i++){
		cout<<"\nNhap so san pham thu "<<i+1<<":";
		sp[i].set();		
	}
		for(int i=0 ; i<n ; i++){
		cout<<"\nXuat so san pham thu "<<i+1<<":";
		sp[i].get();		
	}

int m;
	cout<<"\n\n\nNhap so hoa don :";
	cin>>m;
	Hoadon * hd = new Hoadon[m];
	for(int i=0 ; i<m ; i++)
		{
	 cout<<"\nNhap thong tin hoa don thu "<<i+1<<":";
	 cin>>hd[i];	
		}
	for(int i=0 ; i<m ; i++)
		{
		 cout<<"\nXuat thong tin hoa don thu "<<i+1<<":";
	      cout<<hd[i];	
		}
	cout<<"\nHoa don co thanh tien lon nhat:";	
	Hoadon max= hd[0];
	for(int i=0 ; i<m ; i++){
		if(hd[i] < max){
			max=hd[i];
		}
	}
	cout<<max;
	
}