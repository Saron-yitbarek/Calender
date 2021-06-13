//Project done by Saron Yitbarek 
#include<iostream>
#include<iomanip>
#include<ctime>
using namespace std;
#include<stdlib.h>
int main()
{  int choice;
    cout<<"Press 1 if you want the current date and time."<<endl<<"Press 2 if you want to convert EC date to GC"<<endl
         <<"Press 3 if you want to add n dates on GC"<<endl<<"Press 4 if you want the difference between two EC dates"<<
       endl<<"Press 5 if you want the the difference two GC dates"<<endl<<"Press 6 if you want to know the name of the EC year"<<endl<<
       "Press 7 if you want to know if a given year is leap year"<<endl<<
       "Press 8 if you want to know the weekday for a given date based on GC"<<endl<<"Press 9 to exit"<<endl;
   cin>>choice;
   if(choice>12||choice<=0){
    cout<<"Incorrect input please try again";}
   do{
        system("cls");
    switch(choice){
case 1: //show time and date
    {
        int tmp;

    time_t now;
    struct tm  nowLocal;
    now=time(NULL);
    nowLocal=*localtime(&now);
    cout<<"Today is:"<<nowLocal.tm_mday<<"-"<<nowLocal.tm_mon+1<<"-"<<(nowLocal.tm_year+1900)<<endl;
    cout<<"The time is: "<<nowLocal.tm_hour-12<<":"<<nowLocal.tm_min<<":"<<nowLocal.tm_sec<<endl;
    cin.get();


    break;}
    case 2:{ //change EC to GC
        int date,month,year,n,q,p,k;
    cout<<"Enter date based on Ethiopian calender"<<endl;
    cin>>date>>month>>year;
    if(month>13||month<=0||date<=0||date>30){
        cout<<"Invalid input try again!!!";}
    else if(month==13&&date>6){
        cout<<"Invalid input try again!!!";}
    else{
     n=year/100;
     k=year/400;
     p=26+(n-k);
     if(p>=30){
       month++;
        q=p-30;
        date+=q;}
        else if(p<30)
            date+=p;

      if(date>31){
        month+=date/31;
        date-=(date/31)*31;
      }
      month+=7;
      year+=7;
      if(month>12){
        year+=month/12;
        month-=(month/12)*12;
      }

        cout<<date-2<<"/"<<month<<"/"<<year<<endl;}
   break; }

        case 3:{ //Add n days to GC
            int date,month,year,n,q;
    cout<<"Enter date based on Gregorian Calender"<<endl;
    cin>>date>>month>>year;
    cout<<"Enter the number of days you want to add"<<endl;
    cin>>n;
    if(date>31||month>12||date<=0||month<=0){
        cout<<"Invalid input please try again"<<endl;}
   else{ if(year%4==0||year%400==0||year%100==0){
        if(month==2){
            date+=n;
            if(date>29){
                month+=(date/29);
                date-=((date/29)*29);
                if(date==0){
                    date=29;}

            }}
        }else if(year%4!=0||year%400!=0||year%100!=0){
                  if(month==2){
                    date+=n;
                    if(date>28){
                            q=date/28;
                       date-=((q)*28);
                       if(q>1) month+=(q);

                        if(date==0){
                            date=28;}
                    }
                  }}
                           if(month==1||month==3||month==7||month==8||month==10||month==12){
                                   date+=n;
                                   if(date>31){
                                    month+=(date/31);
                                    date-=((date/31)*31);
                                   // if(date==0){
                                        //date=31;}
                                   }

                           }else if(month==4||month==5||month==6||month==9||month==11){
                                    date+=n;
                                   if(date>30){
                                    month+=(date/30);
                                    date-=((date/30)*30);
                                    if(date==0){
                                        date=30;}
                           }}
    if(month>12){
        year+=month/12;
        month-=((month/12)*12);
    }
    cout<<date<<"/"<<month<<"/"<<year<<endl;}
       break; }
        case 4:{ //The date difference between two EC
            int date,date1,month,month1,year,year1,def,total,total1;
    cout<<"Enter a date based on Ethiopian calender"<<endl;
    cin>>date>>month>>year;
    cout<<"Enter the second date based on Ethiopian calender"<<endl;
    cin>>date1>>month1>>year1;
     if(month==13&&date>6){
        cout<<"Invalid input try again!!!"<<endl;}
     else if(month1==13&&date1>6){
        cout<<"Invalid input try again!!!"<<endl;}
        else if(month>13||month<=0||date>30||date<=0||year<=0){
            cout<<"Invalid input try again!!!"<<endl;
        }
    else{
     if(date>30||date<=0||month>13||month<=0){
        cout<<"Invalid input please try again!!!"<<endl;}
        else{
                if(year%4==0||year%400==0||year%100==0){
                    if(month==13){
                        month*=6;
                        year*=366;}}
                    else if(year&4!=0||year%400!=0||year%100!=0){
                        if(month==13){
                            month*=5;
                            year*=365;}}}

                       if(date1>30||date1<=0||month1>13||month1<=0){
        cout<<"Invalid input please try again!!!"<<endl;}
        else{
                        if(year1%4==0||year1%400==0||year1%100==0){
                    if(month1==13){
                        month1*=6;
                        year1*=366;}}
                    else if(year1%4!=0||year1%400!=0||year1%100!=0){
                        if(month1==13){
                            month1*=5;
                            year1*=365;}}}

                if(month!=13&&year%4==0||year%400==0||year%100==0){
                    month*=30;
                    year*=366;}
                    else if(month!=13&&year%4!=0||year%400!=0||year%100!=0){
                        month*=30;
                        year*=365;}

                       if(month1!=13&&year1%4==0||year1%400==0||year1%100==0){
                    month1*=30;
                    year1*=366;}
                    else if(month1!=13&&year1%4!=0||year1%400!=0||year1%100!=0){
                        month1*=30;
                        year1*=365;}
                total=date+month+year;
                total1=date1+month1+year1;
                if(total>=total1){
                    def=total-total1;}
                else{def=total1-total;}
             cout<<"The difference between the two days is "<<def<<" days"<<endl;
       break; }
       case 5:{ //The date difference between two GC days
            int date,date1,month,month1,year,year1,total,total1,dif;
cout<<"Enter the first date based on Gregorian calender"<<endl;
cin>>date>>month>>year;
cout<<"Enter the second date based on Gregorian calender"<<endl;
cin>>date1>>month1>>year1;

     if(date>31||date<=0||month>12||month<=0){
        cout<<"Invalid input please try again!!!"<<endl;}
        else{
                if(year%4==0||year%400==0||year%100==0){
                    if(month==2){
                        month*=29;
                        }}
                        else if(year%4!=0||year%400!=0||year%100!=0){
                            if(month==2){
                                month*=28;}}
                   if(month==1||month==3||month==7||month==8||month==10||month==12){
                    month*=31;}
                    else if(month==4||month==5||month==6||month==9||month==11){
                        month*=30;}

                     if(year%4==0||year%400==0||year%100==0){
                        year*=366;
                        total=date+month+year;}
                        else if(year%4!=0||year%400!=0||year%100!=0){
                            year*=365;
                            total=date+year+month;}}



              if(date1>31||date1<=0||month1>12||month1<=0){
        cout<<"Invalid input please try again!!!"<<endl;}
        else{
                if(year1%4==0||year1%400==0||year%100==0){
                    if(month1==2){
                        month1*=29;}}
                        else if(year1%4!=0||year1%400!=0||year%100!=0){
                            if(month1==2){
                                month1*=28;}}
                   if(month1==1||month1==3||month1==7||month1==8||month1==10||month1==12){
                    month1*=31;}
                    else if(month1==4||month1==5||month1==6||month1==9||month1==11){
                        month1*=30;}

                     if(year1%4==0||year1%400==0||year%100==0){
                        year1*=366;
                        total1=date1+month1+year1;}
                        else if(year1%4!=0||year1%400!=0||year%100!=0){
                            year1*=365;
                            total=date1+month1+year1;}}
            if(total>=total1){
                dif=total-total1;}
                else{dif=total1-total;}
             cout<<"The difference between the two days are "<<dif<<" days"<<endl;
       }break;}
       case 6:{ //Show name year EC
           int year;
           cout << "Enter Ethiopian year" << endl;
        cin >> year;




        if((year-7)%4 == 0)
        {
            cout << "ZEMENE YOHANESS" << endl;
        }
        else if((year-7)%4 == 1)
        {
            cout << "ZEMENE MATEWOS" << endl;
        }
        else if((year-7)%4 == 2)
        {
            cout << "ZEMENE MAREQOS" << endl;
        }
        else
        {
            cout << "ZEMENELUQAS" << endl;
        }
       break;}
       case 7:{
           int year;
    cout<<"Enter the year"<<endl;
    cin>>year;
    if(year<0){
        cout<<"Invalid input try again!!!"<<endl;
    }
    else{if(year%4==0||year%400==0||year%100==0){
        cout<<"The given year is a leap year"<<endl;}
        else{cout<<"The given year is not a leap year"<<endl;}}
       }
       case 8://The weekday for a given date
        int date,month,year,k;
   cout<<"Enter the date based on GC"<<endl;
   cin>>date>>month>>year;
   if(date<=0||date>31||month<=0||month>12){
    cout<<"Invalid input please try again!!!"<<endl;
   }else {
    static int t[]={0,3,2,5,0,3,5,1,4,6,2,4};
    year-=month<3;
    k=(year+(year/4)-(year/100)+(year/400)+t[month-1]+date)%7;
   switch(k){
   case 1:
       cout<<"The day is Monday"<<endl;
       break;
   case 2:
   cout<<"The day is Tuesday"<<endl;
       break;
   case 3:
 cout<<"The day is Wednesday"<<endl;
       break;
       case 4:
  cout<<"The day is Thursday"<<endl;
       break;
       case 5 :
      cout<<"The day is Friday"<<endl;
       break;
       case 6:
       cout<<"The day is Saturday"<<endl;
       break;
       case 7:
         cout<<"The day is Sunday"<<endl;
       break;}
   } }
       system("pause");}while(choice!=9);

   return 0;
}
