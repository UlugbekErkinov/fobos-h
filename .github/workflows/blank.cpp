#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include <sstream>
using namespace std;
string replace(string data,char first, char second){
int len;
	
		len = data.size();
			for (int i = 0; i < len; i++)
{
     if (data[i] == first)
          data[i] = second;            
}
return data;
}
class drivername{
	protected:
		string name;
};
class adresses{
	protected:
	string firstaddress,secondaddress;
};
class roaddetails{
	protected:
	int milage,price;
};

class order: private adresses, private drivername, private roaddetails{

	public:
		
order(){
	name="Shahzod Uralov";
	firstaddress="275-apartment,Zhandar, Bukhara";
	secondaddress="22-apartment,Yunuabad district, Tashkent city";
	milage=419;
	price=5000;
	
}
		void setname(){
			string name_t;
			cout<<"\t\t\t\tEnter the name of the driver:\n"<<endl;
			getline(cin,name_t);
		    name=replace(name_t,' ','&');
		}
		string getname(){
			setname();
			return name;
		}
		
		void setfirstaddress(){
			string firstaddress_t;
			cout<<"\t\t\t\tEnter the First Address:\n"<<endl;
			getline(cin,firstaddress_t);
			firstaddress=replace(firstaddress_t,' ','&');
			
		}
		string getfristadress(){
			setfirstaddress();
			return firstaddress;
		}
		
		void setsecondaddress(){
			string secondaddress_t;
			cout<<"\t\t\t\tEnter the Second Address:\n"<<endl;
			getline(cin,secondaddress_t);
			secondaddress=replace(secondaddress_t,' ','&');
		}
		string getsecondaddress(){
			setsecondaddress();
			return secondaddress;
		}
		
		void setmilage(){
			cout<<"\t\t\t\tEnter How many miles Driver should drive:\n ";
			cin>>milage;
		}
		int getmilage(){
			setmilage();
			return milage;
		}
		
		setprice(){
			cout<<"\t\t\t\tEnter the Price of the order:\n ";
			cin>>price;
		}
		int getprice(){
			setprice();
			return price;
		}	
		
		
		void savedata(){
			
		cout<<"\t\t\t	******* Please Enter The Credentials *******"<<endl<<endl;
        		
		setname();
		setfirstaddress();
		setsecondaddress();
		setmilage();
		setprice();
	
  		  ofstream fout;  // Create Object of Ofstream
    ifstream fin;
    fin.open("example.txt");
    fout.open ("example.txt",ios::app); // Append mode
    if(fin.is_open())
        fout<<"Driver name:"<<name<<" First address:"<<firstaddress<<" Second address:"<<secondaddress<<" Total mile:"<<milage<<" Price:"<<price<<"$"<<endl; // Writing data to file
    cout<<"\n Data has been appended to file";
    fin.close();
    fout.close(); // Closing the file
		}
	
};

void makehtml(){
	string data[100][5];
	string b,test;
	int f1,f2,i=0;
	ifstream readfile;
    readfile.open("example.txt");
		while(getline(readfile,b))
	{
		f1=0;
		f1 = b.find(":", 0);
		f2 = b.find(" ", f1); 
		test = replace(b.substr(f1+1, f2-f1),'&',' ');
		data[i][0]=test;
		
	f1 = b.find(":", f2);
		f2 = b.find(" ", f1); 
		test = replace(b.substr(f1+1, f2-f1),'&',' ');
		data[i][1]=test;
		
		f1 = b.find(":", f2);
		f2 = b.find(" ", f1); 
		test = replace(b.substr(f1+1, f2-f1),'&',' ');
		data[i][2]=test;
		
		f1 = b.find(":", f2);
		f2 = b.find(" ", f1); 
		test = replace(b.substr(f1+1, f2-f1),'&',' ');
		data[i][3]=test;
		
		f1 = b.find(":", f2);
		f2 = b.find("$", f1); 
		test = replace(b.substr(f1+1, f2-f1+1),'&',' ');
		data[i][4]=test;
		
		i++;
	}
	readfile.close();
	
	
	
	 ofstream html; 
	html.open("data.html");
	
	html<<"<!DOCTYPE html>"<<endl;
	html<<"<html lang=\"en\">"<<endl;
html<<"<head>"<<endl;
	html<<"<title>Table V04</title>"<<endl;
	html<<"<meta charset=\"UTF-8\">"<<endl;
	html<<"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"<<endl;	
	html<<"<link rel=\"icon\" type=\"image/png\" href=\"images/icons/favicon.ico\"/>"<<endl;
	html<<"<link rel=\"stylesheet\" type=\"text/css\" href=\"vendor/bootstrap/css/bootstrap.min.css\">"<<endl;
	html<<"<link rel=\"stylesheet\" type=\"text/css\" href=\"fonts/font-awesome-4.7.0/css/font-awesome.min.css\">"<<endl;
	html<<"<link rel=\"stylesheet\" type=\"text/css\" href=\"vendor/animate/animate.css\">"<<endl;
	html<<"<link rel=\"stylesheet\" type=\"text/css\" href=\"vendor/select2/select2.min.css\">"<<endl;
	html<<"<link rel=\"stylesheet\" type=\"text/css\" href=\"vendor/perfect-scrollbar/perfect-scrollbar.css\">"<<endl;
	html<<"<link rel=\"stylesheet\" type=\"text/css\" href=\"css/util.css\">"<<endl;
	html<<"<link rel=\"stylesheet\" type=\"text/css\" href=\"css/main.css\">"<<endl;
html<<"</head>"<<endl;
html<<"<body>"<<endl;
	
	html<<"<div class=\"limiter\">"<<endl;
		html<<"<div class=\"container-table100\">"<<endl;
			html<<"<div class=\"wrap-table100\">"<<endl;
				
				
				

				html<<"<div class=\"table100 ver3 m-b-110\">"<<endl;
					html<<"<div class=\"table100-head\">"<<endl;
						html<<"<table>"<<endl;
							html<<"<thead>"<<endl;
							
							
								html<<"<tr class=\"row100 head\">"<<endl;
									html<<"<th class=\"cell100 column1\">Driver name</th>"<<endl;
									html<<"<th class=\"cell100 column2\">Pickup location</th>"<<endl;
									html<<"<th class=\"cell100 column3\">Delivery location</th>"<<endl;
									html<<"<th class=\"cell100 column4\">Milage</th>"<<endl;
									html<<"<th class=\"cell100 column5\">Price</th>"<<endl;
								html<<"</tr>"<<endl;
						
						
							html<<"</thead>"<<endl;
						html<<"</table>"<<endl;
					html<<"</div>"<<endl;

					html<<"<div class=\"table100-body js-pscroll\">"<<endl;
						html<<"<table>"<<endl;
							html<<"<tbody>"<<endl;
							
							
							for(int i=0;i<=100;i++){
							html<<"<tr class=\"row100 body\">"<<endl;
									html<<"<td class=\"cell100 column1\">"<<data[i][0]<<"</td>"<<endl;
									html<<"<td class=\"cell100 column2\">"<<data[i][1]<<"</td>"<<endl;
									html<<"<td class=\"cell100 column3\">"<<data[i][2]<<"</td>"<<endl;
									html<<"<td class=\"cell100 column4\">"<<data[i][3]<<"</td>"<<endl;
									html<<"<td class=\"cell100 column5\">"<<data[i][4]<<"</td>"<<endl;
								html<<"</tr>"<<endl;
								if(data[i][0]==""){
									  break;
								}
	}
							
							
							html<<"</tbody>"<<endl;
						html<<"</table>"<<endl;
					html<<"</div>"<<endl;
				html<<"</div>"<<endl;

			

				
			html<<"</div>"<<endl;
		html<<"</div>"<<endl;
	html<<"</div>"<<endl;

	
	html<<"<script src=\"vendor/jquery/jquery-3.2.1.min.js\"></script>"<<endl;
	html<<"<script src=\"vendor/bootstrap/js/popper.js\"></script>"<<endl;
	html<<"<script src=\"vendor/bootstrap/js/bootstrap.min.js\"></script>"<<endl;
	html<<"<script src=\"vendor/select2/select2.min.js\"></script>"<<endl;
	html<<"<script src=\"vendor/perfect-scrollbar/perfect-scrollbar.min.js\"></script>"<<endl;
	html<<"<script>"<<endl;
		html<<"$('.js-pscroll').each(function(){"<<endl;
			html<<"var ps = new PerfectScrollbar(this);"<<endl;

			html<<"$(window).on('resize', function(){"<<endl;
				html<<"ps.update();	})});"<<endl;
			
		
	html<<"</script>"<<endl;
	html<<"<script src=\"js/main.js\"></script>"<<endl;

html<<"</body>"<<endl;
html<<"</html>"<<endl;

html.close();
	
	
	
}

int main(){
	
	order admin;
	string a;
	while(5){

  admin.savedata();
	cout<<endl<<"\t\t\t\t******IF you want to add another Order Input ' 1 ' , Otherwise You have to exit data adding ********\n"<<endl;
	cin>>a;
if(a=="1"){
	cin.ignore();continue;
}else{
	break;
}
	
	
		}	
		
			cout<<endl<<"\t\t\t\t<========All data have added successfully!!!========>"<<endl<<"<=========You can see all the List of Orders in HTML file ( data.html ) below=========>"<<endl;

makehtml();


system("pause");
return 0;
}
