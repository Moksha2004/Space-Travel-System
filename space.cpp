#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
#include<math.h>
#include<vector>
#include<cmath>

class Space_Traveller{
    private:
    string Astronaut;
    string Commander;
    vector<string> arr;
    vector<string> names;
    vector<string> id;
    public:
    string start_planet;
    string destination_planet;
    int NoOfDays;
    string date;
    int price;
    public:
    string Return_AstronautID();
    string Return_CommanderID();
    string Return_TravellerID(string traveller_id);
    string Return_TravellerName(string traveller_id);
    void List_All_Travellers();
    void Set_AstronautID();
    void Set_CommanderID();
    void Update_AstronautID();
    void Update_CommanderID();
};
class Planet{
private:
string name;
double x,y,z;
public:
Planet(string name,double x,double y,double z){
    this->name=name;
    this->x=x;
    this->y=y;
    this->z=z;
}
double PrintX(){
    return x;
}
double PrintZ(){
    return z;
}
double PrintY(){
    return y;
}
string PrintNAME(){
    return name;
}
double PrintDistance(Planet*destination) const{
    return sqrt(pow(this->x-destination->PrintX(),2)+pow(this->y-destination->PrintY(),2)+pow(this->z-destination->PrintZ(),2));
}
};
class Traveller{
    protected:
    int ID;
    public:
    vector<int>list_of_tickets;
    static int defined_id;
    string name;
    int traveller_id;
    string getName(){
        return name;
    }
    int getID(){
        return ID;
    }
    int getTravellerID(){
        return traveller_id;
    }
    void updateID(int ID){
        this->traveller_id=ID;
    }
};
class Astro:public Traveller{
    public:
    int experience;
    Astro(string name,int experience){
        defined_id++;
        this->name=name;
        this->experience=experience;
    }
    void setID(){
        this->ID=defined_id;
    }
};
class Commander:public Traveller{
  public:
  int experience;
  string license;
  Commander(int experience,string name,string license){
      this->experience=experience;
      this->license=license;
      this->name=name;
  }
};
class Passenger:public Traveller{
    int valid;
    public:
    Passenger(string name){
  this->name=name;
  this->valid=10;
  defined_id++;
    }
    void setID(){
        this->ID=defined_id;
    }
};
class ticket: public Traveller{
  int price;
  public:
  static int tickets;
  bool ReturnTrip;
  Traveller*Passenger;
  Planet*Source_Station;
  Planet*Destination_Station;
  int Date;
  int year;
  int month;
  ticket(Planet*Source_Station,Planet*Destination_Station,int Date,int year,int month,bool ReturnTrip,Traveller*Passenger){
      this->Source_Station=Source_Station;
      this->Destination_Station=Destination_Station;
      this->Date=Date;
      this->year=year;
      this->month=month;
      this->ReturnTrip=ReturnTrip;
      this->Passenger=Passenger;
      tickets++;
      std::cout << "yes" << std::endl;
  }
  void delete_ticket(){
      delete this;
      cout<<"no";
  }
  void UpdateTicket(Planet*Source_Station,Planet*Destination_Station,int Date,int year,int month,bool ReturnTrip){
      this->Source_Station=Source_Station;
      this->Destination_Station=Destination_Station;
      this->Date=Date;
      this->year=year;
      this->month=month;
      this->ReturnTrip=ReturnTrip;
      tickets++;
      std::cout << "Moksha" << std::endl;
  }
  double cost(){//Date Structure
      tm Traveldate={
         0,0,0,Date,month-1,year-1900,0,0,0     };
  time_t TravelTime=mktime(&Traveldate);
  double k=Source_Station->PrintDistance(Destination_Station);
  auto now=chrono::system_clock::now();
  time_t now_cc=chrono::system_clock::to_time_t(now);
  int days_left=ceil(difftime(now_cc,TravelTime)/(3600*24))+1;
  return k/days_left;
}
 void PrintTICKET(){
     cout<<"Name of Passenger:"<<this->Passenger->name<<endl;
     cout<<"Ticket ID:"<<this->tickets;
     cout<<"Source_Station:"<<this->Source_Station;
     cout<<"Destination_Station"<<this->Destination_Station;
     cout<<"date:"<<this->Date<<"/"<<this->month<<"/"<<this->year<<endl;
     
 }
 void add(){
     Passenger->list_of_tickets.push_back(this->tickets);
 }
 void push_global(ticket*Ticket);
 void getname(){
     cout<<Passenger->getName()<<endl;
 }
 void get_id(){
     cout<<Passenger->getID()<<endl;
 }
 void setprice(){
     price=cost();
 }
 int getprice(){
     return price;
 }
};
int ticket::tickets=0;
int Traveller::defined_id=0;
vector<ticket*>Tickets;
void ticket::push_global(ticket* Ticket){
    Tickets.push_back(Ticket);
}
int main(){
    Planet*P1=new Planet("Mars",0,0,0);
    Planet*P2=new Planet("Jupiter",1000*1000,1000*1000,1000*1000);
    Astro*s1=new Astro("hemsai",25);
    ticket*my=new ticket(P1,P2,1,2,2023,false,s1);
    cout<<my->cost()<<endl;
    my->add();
    cout<<s1->list_of_tickets[0];
}