#include<iostream.h>
#include<string.h>
class GV{
     private:
	 	char ht[30];
		char cn[20];
		float bl;
	 public:
	 	GV (){}
		  GV(char* ht , char * cn , float bl){
  			strcpy (this ->ht,ht);
  			strcpy (this ->cn,cn);
  					this ->bl=bl;
  		}	
  		~ GV (){}
  		void set(){
		  	cin.ignore();
		  	cout<<"\nNhap ho ten:";
		  	cin.getline(ht,30);
		  	cout<<"\nNhap chuyen nganh:";
		  	cin.getline(cn,20);
		  	cout<<"\nNhap bac luong:";
		  	cin>>bl;
		  }
	    void get(){
  			cout<<"\nHo ten:"<<ht<<endl;
		  	cout<<"\nChuyen nganh:"<<cn<<endl;
		  	cout<<"\nBac luong:"<<bl<<endl;
    	}
    	float getbl(){
	    	return bl;
	    }
};
class GVTH : public GV{
	    private:
	    	char l[5];
	    	float lpc;
    	public:
    		GVTH(){}
    			GVTH(char* ht , char * cn , float bl,char *l , float lpc)
    			  :GV(ht,cn,bl){
  			    	strcpy (this ->l,l);
  			    			this ->lpc=lpc;
  			    }
	        ~GVTH(){}
	        friend istream &operator >>(istream &is , GVTH &a){
        		a.set();
       			cin.ignore();
        		cout<<"\nNhap lop:";
        		is.getline(a.l,5);
        		cout<<"\nNhap luong phu cap:";
        		is>>a.lpc;
        		return is;
        	}
        	friend ostream &operator <<(ostream &os , GVTH &b){
	        	b.get();
	        	os<<"\nLop:"<<b.l<<endl;
	        	os<<"\nLuong phu cap:"<<b.lpc<<endl;
	        	os<<"\nLuong phu cap bang :"<<b.lpc()<<endl;
	        	return os;
	        }
	        
};
int main(){
	int n;
	cout<<"\nNhap so giao vien:";
	cin>>n;
	GV * giaovien=new GV[n];
	for(int i=0 ; i<n ; i++)
	{
		cout<<"\nNhap thong tin giao vien thu "<<i+1<<":"<<endl;
		giaovien[i].set();
	}
	for(int i=0 ; i<n ; i++)
	{
		cout<<"\nXuat thong tin giao vien thu "<<i+1<<":"<<endl;
		giaovien[i].get();
	}
	
	int m;
	cout<<"\nNhap so giao vien tieu hoc :";
	cin>>m;
	GVTH * gvth=new GVTH[m];
	for(int i=0 ; i<m ; i++)
	{
	
		cout<<"\nNhap thong tin gvth thu "<<i+1<<":";
		cin>> gvth[i];
	}
		for(int i=0 ; i<m ; i++)
	{
		cout<<"\nXuat thong tin gvth thu "<<i+1<<":";
		cout<< gvth[i];
	}
}