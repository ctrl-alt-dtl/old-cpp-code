// Time.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Time.h"

using namespace std;

Time::Time(){
    hour = minute = second = 0;
}

void Time::setTime(int h, int m, int s){
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printUniversal(){
    cout << setfill('0') << setw(2) << hour << ":"
        << setw(2) << minute << ":" << setw(2) << second;
}

void Time::printStandard(){
    cout << ( (hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
        << setfill('0') << setw(2) << minute << ":" << setw(2)
        << second << (hour < 12 ? " AM" : " PM");
}

int _tmain(int argc, _TCHAR* argv[])
{
    Time t;

    cout << "Initital UTM is ";
    t.printUniversal();
    cout << "\nThe initial standard time is ";
    t.printStandard();

    t.setTime(13, 27, 6);

    cout << "\n\nUTM time after time set is ";
    t.printUniversal();
    cout << "\nStandard time is ";
    t.printStandard();

    t.setTime(99, 99, 99);

    cout << "\n\nAfter attemping invalid setting:" << "\nUniversal time: ";
    t.printUniversal();
    cout << "\nStandard time: ";
    t.printStandard();
    cout << endl;

	system("PAUSE");
	return 0;
}

