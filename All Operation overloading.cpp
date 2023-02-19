//Name :Syed Ali Ahmed                          department: FBAS/BSSE/F-21
//Roll No :4308                                 university:International Islamic University Islamabad
                           
//here we overloads the operator 

#include <iostream>
#include<windows.h>
#include<vector>
using namespace std;
class AirTime {
	int hrs, min, sec;
public:
	AirTime() { 
		hrs = 0, min = 0;
		unsigned int sec = 0;
	}
	void setTime();
	void dispTime();
	void normalize();
	bool operator>(AirTime);
	AirTime operator-(AirTime);
	AirTime operator++();
	AirTime operator++(int);
	AirTime operator--();
	AirTime operator--(int);
	AirTime operator+=(AirTime);
	AirTime operator-=(AirTime);
	AirTime operator*=(AirTime);
	AirTime operator%=(AirTime);
};
bool AirTime :: operator>(AirTime t) {
	if (hrs > t.hrs) {
		return true;
	}
	else {
		if (hrs == t.hrs && min > t.min) {
			return true;
		}
		else {
			if (hrs == t.hrs && min == t.min && sec > t.sec) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

void AirTime::normalize() {
    min = min + sec/ 60;
	 sec = sec % 60;
	hrs = hrs + min / 60;
	 min = min % 60;
	 hrs = hrs % 12;
}

AirTime AirTime:: operator+=(AirTime t) {
	hrs += t.hrs;
	min += t.min;
	sec += t.sec;
	return *this;
}
AirTime AirTime:: operator-=(AirTime t) {
	hrs -= t.hrs;
	min -= t.min;
	sec -= t.sec;
	return *this;
}
AirTime AirTime:: operator*=(AirTime t) {
	hrs *= t.hrs;
	min *= t.min;
	sec *= t.sec;
	return *this;
}
AirTime AirTime:: operator%=(AirTime t) {
	hrs %= t.hrs;
	min %= t.min;
	sec %= t.sec;
	return *this;
}

AirTime AirTime :: operator--(int) {
	--hrs;
	--min;
	--sec;
	if (hrs == 0) {
		hrs = 12;
	}
	return *this;
}
AirTime AirTime :: operator--() {
	hrs--;
	min--;
	sec--;
	return *this;
}


AirTime AirTime :: operator++(int) {
	++hrs;
	++min;
	++sec;
	return *this;
}
AirTime AirTime :: operator++() {
	hrs++;
	min++;
	sec++;
	return *this;
}
AirTime AirTime::operator-(AirTime t2) {
	AirTime temp;
	temp.hrs = hrs - t2.hrs;
	temp.min = min - t2.min;
	temp.sec = sec - t2.sec;
	return temp;
}
void AirTime::setTime() {
	SYSTEMTIME currTime;
	GetSystemTime(&currTime);
	hrs = (currTime.wHour +5 )%12;
	if (hrs % 12 == 0) {
		hrs = 12;
	}
	min = currTime.wMinute;
	sec = currTime.wSecond;
}
void AirTime::dispTime() {
	int hrs2 = hrs;
	int min2 = min;
	int sec2 = sec;
	normalize();
	cout << hrs << " / " << min << " / " << sec;
	hrs = hrs2;
	min = min2;
	sec = sec2;
	cout <<" "<< hrs << " " << min << " " << sec << " ";
	cout << endl;
}
void menu() {
	cout << "1.Set or display Arrival Time " << endl;
	cout << "2.set or diplay departure Time" << endl;
	cout << "3.time taken to complete the flight" << endl;   // t2-t1
	cout << "4.Increment the Time" << endl;           //++
	cout << "5.Decrement the time" << endl;           //--
	cout << "6.Add arrival Time to departure time or vice versa" << endl;      //+=
	cout << "7.subtract arrival Time to departure time or vice versa" << endl; // -=

}
void submenu1() {
	cout << "1.Set Arrival Time" << endl;
	cout << "2.display Arrival Time" << endl;
	cout << "3.go back To main menu" << endl;
}
void operateSubmemu1(AirTime &arrival) {
	int option;
	cout << "chose your option" << endl;
	cin >> option;
	switch (option) {
	case 1:
		arrival.setTime();
		cout << "your arrival time is set as a currtime" << endl;
		cout << endl;
		break;
	case 2:
		arrival.dispTime();
		cout << endl;
		break;
	case 3:
		break;
	default:
		cout << "you chose the invalid option" << endl;
	}
}

void submenu2() {
	cout << "1.Set departure Time" << endl;
	cout << "2.display departure Time" << endl;
	cout << "3.go back To main menu" << endl;
}
void operateSubmenu2(AirTime &depart) {
	int option;
	cout << "chose your option" << endl;
	cin >> option;
	switch (option) {
	case 1:
		depart.setTime();
		cout << "your current time is set as departure time" << endl;
		cout << endl;
		break;
	case 2:
		depart.dispTime();
		break;
	case 3:
		break;
	default:
		cout << "chose the correct option" << endl;
	}
}

void submenu4() {
	cout << "1.post incremet the time" << endl;
	cout << "2.pre-increment the time" << endl;
}
void operateSubmenu4(AirTime &arrival) {
	int option;
	cout << "chose your option" << endl;
	cin >> option;
	switch (option) {
	case 1:
		arrival++;
		cout << "your arrival Time is post-incremented" << endl;
		cout << endl;
		break;
	case 2:
		++arrival;
		cout << "your arrival Time is pre-incremented" << endl;
		cout << endl;
		break;
	default:
		cout << "chose the correct option" << endl;
	}
}
void operateSubmenu4_2(AirTime &depart) {
	int option;
	cout << "chose your option" << endl;
	cin >> option;
	switch (option) {
	case 1:
		depart++;
		cout << "your departure Time is post-incremented" << endl;
		cout << endl;
		break;
	case 2:
		++depart;
		cout << "your departure Time is pre-incremented" << endl;
		cout << endl;
		break;
	default:
		cout << "chose the correct option" << endl;
	}
}
void submenu3() {
	cout << "1.increment the arrival time" << endl;
	cout << "2.increment the depart time" << endl;
	cout << "3.Go back to main menu" << endl;
}
void operateSubmenu3(AirTime &arrival, AirTime &depart) {
	int option;
	cout << "chose your option" << endl;
	cin >> option;
	switch (option) {
	case 1:
		submenu4();
		operateSubmenu4(arrival);
		break;
	case 2:
		submenu4();
		operateSubmenu4_2(depart);
		break;
	case 3:
		break;
	default:
		cout << "chose the correct option" << endl;
	}
}


void submenu6() {
	cout << "1.post-decremented the time" << endl;
	cout << "2.pre-decremented the time" << endl;
}
void operateSubmenu6(AirTime &arrival) {
	int option;
	cout << "chose your option" << endl;
	cin >> option;
	switch (option) {
	case 1:
		arrival--;
		cout << "your arrival Time is post-decremented" << endl;
		cout << endl;
		break;
	case 2:
		--arrival;
		cout << "your arrival Time is pre-decremented" << endl;
		cout << endl;
		break;
	default:
		cout << "chose the correct option" << endl;
	}
}
void operateSubmenu6_2(AirTime &depart) {
	int option;
	cout << "chose your option" << endl;
	cin >> option;
	switch (option) {
	case 1:
		depart--;
		cout << "your departure Time is post-decremented" << endl;
		cout << endl;
		break;
	case 2:
		--depart;
		cout << "your departure Time is pre-decremented" << endl;
		cout << endl;
		break;
	default:
		cout << "chose the correct option" << endl;
	}
}


void submenu5() {
	cout << "1.decrement the arrival time" << endl;
	cout << "2.decremet the depart time" << endl;
	cout << "3.Go back to main menu" << endl;
}
void operateSubmenu5(AirTime &arrival, AirTime &depart) {
	int option;
	cout << "chose your option" << endl;
	cin >> option;
	switch (option) {
	case 1:
		submenu6();
		operateSubmenu6(arrival);
		break;
	case 2:
		submenu6();
		operateSubmenu6_2(depart);
		break;
	case 3:
		break;
	default:
		cout << "chose the correct option" << endl;
	}
}




int main()
{
	AirTime arrival, depart, differ, sum;
	do {
		menu();
		int option;
		cout << "chose your option" << endl;
		cin >> option;
		switch (option) {
		case 1:
			submenu1();
			operateSubmemu1(arrival);
			break;
		case 2:
			submenu2();
			operateSubmenu2(depart);
			break;
		case 3:
			if (depart > arrival) {
				differ = depart - arrival;
				differ.dispTime();
			}
			else {
				differ = arrival - depart;
				differ.dispTime();
			}
			break;
		case 4:
			submenu3();
			operateSubmenu3(arrival, depart);
			break;
		case 5:
			submenu5();
			operateSubmenu5(arrival, depart);
			break;
		}
	} while (true);
}

