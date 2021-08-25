#include<iostream.h>
#include<string.h>
class Dientu{
	private:
		char mahang[10];
		char tensanxuat[20];
		float dongia;
	public:
		Dientu(){}
	       Dientu(char * mahang , char * tensanxuat , float dongia){
       		strcpy (this -> mahang, mahang);
       		strcpy (this -> tensanxuat, tensanxuat);
       		     	this -> dongia=dongia;
       	}
		
		void set(){
			cin.ignore();
			cout<<"\nNhap ma hang:";
			cin.getline(mahang,10);
			cout<<"\nNhap ten san xuat:";
			cin.getline(tensanxuat,20);
			cout<<"\nNhap don gia:";
			cin>>dongia;
		}
		void get(){
			cout<<"\nMa hang:"<<mahang<<endl;
			cout<<"\nTen san xuat:"<<tensanxuat<<endl;
			cout<<"\nDon gia:"<<dongia<<endl;
		}		
};
class Tulanh : public Dientu{
	private:
		float dungtich;
		float dienap;
	public:
		Tulanh(){}
			Tulanh(char * mahang , char * tensanxuat , float dongia , float dungtich , float dienap)
			:Dientu( mahang, tensanxuat , dongia){
				this ->dungtich=dungtich;
				this -> dienap=dienap;
			}
			
		friend istream & operator >>( istream& is , Tulanh &i){
			i.set();
			cout<<"\nNhap dung tich :";
		    is>>i.dungtich;
			cout<<"\nNhap dien ap:";
			is>>i.dienap;
			return is;
		}
		friend ostream & operator << (ostream &os , Tulanh &o){
			o.get();
			cout<<"\nDung tich:"<<o.dungtich<<endl;
			cout<<"\nDien ap:"<<o.dienap<<endl;
			cout<<"\nPhi van chuyen: "<<o.vanchuyen()<<endl;
			return cout;
		
		}
		
		int vanchuyen(){
			if( dungtich >=70){
				return 500000;
			}
			else if( dungtich >55){
				return 400000;
			}
			else{
				return 100000;
			}
		}
		
		friend bool operator <( Tulanh a , Tulanh b)
		{
			return a.dungtich < b.dungtich;
		}
};
int main(){
	int n ;
	cout<<"\nNhap so luong tu lanh:";
	cin>>n;
	Tulanh * tl = new Tulanh[n];
	cout<<"****Nhap thong tin tu lanh****";
	for(int i=0 ; i<n ; i++){
		cout<<"\nTu lanh thu "<<i+1<<":";
		cin>>tl[i];
	}
	cout<<"****Xuat thong tin tu lanh****";
	for(int i=0 ; i<n ; i++){
		cout<<"\nXuat tu lanh thu "<<i+1<<":";
		cout<<tl[i];
	}
	cout<<"***Tu lanh co dung tich nho nhat***";
	Tulanh min=tl[0];
	for(int i=0 ; i<n ; i++)
	{
	     if(tl[i]<min)
		{
			min = tl[i];
		}
	}
	cout<<min;
}