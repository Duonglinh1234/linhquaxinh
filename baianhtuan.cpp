#include<iostream.h>
#include<string.h>
class Students {
	private:
		char id[10];
		char name[20];
		int age;
		char address[30];
		float gpa;
	public:
		Students(){}
		~Students(){};
		Students(char * id , char * name , int age , char * address , float gpa){
			strcpy( this -> id , id);
			strcpy( this -> name , name);
					this -> age=age;
			strcpy( this -> address , address);
					this -> gpa=gpa;
		}
		
		void setID(char * id)
		{
				strcpy( this -> id , id);
		}
		char getID ()
		{
			return char(id);
		}
		
		void setName(char * name)
		{
				strcpy( this -> name , name);
		}
		char getName()
		{
			return char(name);
		}
		
		int setAge(int age)
		{
			this -> age=age;
		}
		int getAge()
		{
			return int(age);
		}
		
		void setAddress(char * address)
		{
			strcpy( this -> address , address);
		}
		char getAddress()
		{
			return char(address);		
		}
		
		float setGpa(float gpa)
		{
			this -> gpa=gpa;
		}
		float getGpa()
		{
			return float(gpa);
		}
		
		void xuat()
		{
			cout<<"\nNhap id:"<<id<<endl;
			cout<<"\nNhap name:"<<name<<endl;
			cout<<"\nNhap age:"<<age<<endl;
			cout<<"\nNhap address:"<<address<<endl;
			cout<<"\nNhap gpa:"<<gpa<<endl;
		}
};
class quanlisinhvien{
	public:
	  	quanlisinhvien(){}
	void addstudent(Students a[],int n)
	{
		char id[10];
		char name[20];	
		int age;
		char address[30];
		float gpa;
		cout<<"\nNhap sinh thu "<<n+1<<"la:";
		cin.ignore();
		cout<<"\nNhap id:";
		cin.getline(id,10);
		a[n].setID(id);
		cout<<"\nNhap name:";
		cin.getline(name,20);
		a[n].setName(name);
		cout<<"\nNhap address:";
		cin.getline(address,30);
		a[n].setAddress(address);
		cout<<"\nNhap age:";
		cin>>age;
		a[n].setAge(age);
		cout<<"\nNhap gpa:";
		cin>>gpa;
		a[n].setGpa(gpa);
	}
	void editstudentbyid(Students a[],int n,int id)
	{
	
		char name[20];	
		int age;
		char address[30];
		float gpa;
		int dem=0;
		for(int i=0 ; i<n ; i++)
		{
			if(a[i].getID() == id)
			dem++;
			{
				cout<<"\nNhap id:";
				cin.getline(id,10);
				a[n].setID(id);
				cout<<"\nNhap name:";
				cin.getline(name,20);
				a[n].setName(name);
				cout<<"\nNhap address:";
				cin.getline(address,30);
				a[n].setAddress(address);
				cout<<"\nNhap age:";
				cin>>age;
				a[n].setAge(age);
				cout<<"\nNhap gpa:";
				cin>>gpa;
				a[n].setGpa(gpa);
				break;
				if(dem==0)
				{
					cout<<"\nId nay khong ton tai!!";
				}
			}
		}
	}
	
	void deletestudentbyid(Students a[],int n,int id)
	{
		int dem=0;
		for(int i=0 ; i<n ; i++){
			if (a[i].getID()==id){
				dem++;
				for(int j=i ; j<n ; j++){
					a[j] = a[j+1];
				}
				cout<<"\nDa xoa sinh vien co id = "<<id;
				break;
				if(dem==0)
				{
					cout<<"\nId nay khong ton tai!!";
				}
			}
		}
	}
	void sortstudentbygpa(Students a[], int n)
	{
		for(int i=0 ; i<n ; i++)
		{
			for(int j=i+1; j<n ; j++)
			{
				if(a[i].getGpa()>a[j].getGpa()){
					Students temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		
		}
	}
	
	void sortstudentbyname(Students a[], int n)
	
};