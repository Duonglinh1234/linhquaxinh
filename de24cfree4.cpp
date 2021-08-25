#include<iostream.h>
#include<string.h>
class Nguoi {
	private:
		char hoten[20];
		int tuoi ;
		char cmt [10];
	public:
		Nguoi (){}
		  	Nguoi (char * hoten , int tuoi , char * cmt){
		  		strcpy (this -> hoten , hoten);
		  				this -> tuoi = tuoi ;
  				strcpy (this -> cmt , cmt);
		  	}
 	   ~ Nguoi (){}
 	   
 	   void set(){
 	   		cin.ignore();
 	   		cout<<"\nNhap ho ten :";
 	   		cin.getline(hoten,20);
 	   		cout<<"\nNhap chung minh thu :";
 	   		cin.getline(cmt,10);
 	   		cout<<"\nNhap tuoi:";
 	   		cin>>tuoi;
 	   }
 	   void get (){
 	   		cout<<"\nHo ten :"<<hoten<<endl;
 	   		cout<<"\nChung minh thu :"<<cmt<<endl;
 	   		cout<<"\nTuoi:"<<tuoi<<endl;	   		
 	   }
 	   int gettuoi(){
   	 	return tuoi;
   	 }
};
class Giangvien : public Nguoi{
	private:
		char magv[10];
		int tuoivaocoquan;
		char trinhdo[20];
		float hesoluong;
	public:
	    Giangvien(){}
	    	Giangvien(char * hoten , int tuoi , char * cmt , char * magv , int tuoivaocoquan , char * trinhdo , float hesoluong)
				:Nguoi(hoten , tuoi , cmt){
					strcpy (this -> magv, magv);
							this -> tuoivaocoquan= tuoivaocoquan;
					strcpy (this -> trinhdo, trinhdo);
							this -> hesoluong=hesoluong;
	    			
	    	}
    	~Giangvien(){};
    	friend istream &operator >>(istream &is , Giangvien	 &a){
    		
    			a.set();
    			cin.ignore();
    			cout<<"\nNhap ma giang vien:";
    			is.getline(a.magv,10);
    			cout<<"\nNhap trinh do:";
    			is.getline(a.trinhdo,20);
    			cout<<"\nNhap so tuoi vao co quan:";
    			is>> a.tuoivaocoquan;
    			cout<<"\nNhap he so luong:";
    			is>>a.hesoluong;
    			return is;
    	}
    	friend ostream &operator <<(ostream &os , Giangvien	 &b){
    		    b.get();
				os<<"\nMa giang vien:"<<b.magv<<endl;
				os<<"\nTrinh do:"<<b.trinhdo<<endl;
				os<<"\nSo tuoi vao co quan:"<<b.tuoivaocoquan<<endl;
				os<<"\nHe so luong:"<<b.hesoluong<<endl;
				os<<"\nLuong:"<<b.Luong()<<endl;
				return os;
    	}
    	float Luong(){
	    	float sonamcongtac = gettuoi()- tuoivaocoquan;
	    	float phucapthamnien = sonamcongtac*100;
	    	double Luong = hesoluong * 1490 - phucapthamnien;
	    	return Luong;
	    }
};

main(){
	int n;
	cout<<"\nNhap so luong nguoi :";
	cin>>n;
	Nguoi * nguoi = new Nguoi [n];
	cout<<"\n*****Nhap thong tin cua nguoi*****\n";
	for(int i=0 ; i<n ; i++){
		cout<<"\nNhap thong tin nguoi thu "<<i+1<<":";
		nguoi[i].set();		
	}
	cout<<"\n*****Xuat thong tin cua nguoi*****\n";
	for(int i=0 ; i<n ; i++){
		cout<<"\nXuat thong tin nguoi thu "<<i+1<<":";
		nguoi[i].get();		
	}
	
	int m;
	cout<<"\nNhap so giang vien:";
	cin>>m;
	Giangvien * gv = new Giangvien[m];
	cout<<"\n*****Nhap thong tin cua giang vien*****\n";
	for(int i=0 ; i<m ; i++){
		cout<<"\nNhap thong tin giang vien thu "<<i+1<<":";
		cin>>gv[i];	
	}
	cout<<"\n*****Xuat thong tin cua giangvien*****\n";
	for(int i=0 ; i<m ; i++){
		cout<<"\nXuat thong tin giang vien thu "<<i+1<<":";
	    cout<<gv[i];	
	}
}
