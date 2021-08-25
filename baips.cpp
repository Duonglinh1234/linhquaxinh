#include<iostream.h>
#include<string.h>
class Phanso{
		private:
			int t,m;
		public:
			Phanso(){}
			~Phanso(){};
		void set(){
			cin.ignore();
			cout<<"\nNhap tu so:";
			cin>>t;
			cout<<"\nNhap mau so:";
			cin>>m;
		}
		void get(){
			cout << t << "/" << m;
		}
		int gett(){
			return t;
		}
		
		int getm(){
			return m;
		}
		
};
int main(){
	Phanso ps [2];
	for(int i=1 ; i<=2 ; i++)
	{
		cout<<"\nNhap vao phan so thu "<< i <<":";
		ps[i].set();
	}
		for(int i=1 ; i<=2 ; i++)
	{
		cout<<"\nxuat ra phan so thu "<< i <<":";
		ps[i].get();
	}
	
	cout<<"\nTong phan so thu 1:";
	    ps[1].get();
    cout<<" va phan so thu 2 : ";
        ps[2].get();
    cout<<"la:";
    cout<<ps[1].gett()*ps[2].getm()+ps[2].gett()*ps[1].getm()<<"/"
        << ps[1].getm()*ps[2].getm();
    
    
    cout<<"\nHieu phan so thu 1:";
    	 ps[1].get();
    cout<<" va phan so thu 2 : ";
        ps[2].get();
    cout<<"  la:";
    cout<<ps[1].gett()*ps[2].getm()-ps[2].gett()*ps[1].getm()<<"/"
        << ps[1].getm()*ps[2].getm();
    
    												
      
    cout<<"\nTich phan so thu 1:";
    	 ps[1].get();
    cout<<" va phan so thu 2 : ";
        ps[2].get();
    cout<<"la:";
    cout<<ps[1].gett()*ps[2].gett()<<"/"
        <<ps[1].getm()*ps[2].getm();
    
 
 	cout<<"\nThuong phan so thu 1:";
    	 ps[1].get();
    cout<<" va phan so thu 2 : ";
        ps[2].get();
    cout<<"  la:";
    cout<<ps[1].gett()*ps[2].getm()<<"/"
    	<<ps[1].getm()*ps[2].gett();
    cout<<endl;
}