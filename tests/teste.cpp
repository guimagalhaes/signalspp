#include <iostream>
#include "signals++.h"

using namespace std;

void alarm(int i)
{
    cout << "alarm!!" << endl;
}

void alarm2(int i)
{
    cout << "another alarm!" << endl;
    exit(0);
}

int main()
{
    signalspp sig;
    
    sig.install_signal_handler(1);
    sig.install_signal_handler(2);
    sig.install_signal_handler(3);
    sig.install_signal_handler(4);
    sig.install_signal_handler(6);
    sig.install_signal_handler(8);
    //sig.install_signal_handler(9);
    sig.install_signal_handler(11);
    sig.install_signal_handler(13);    
    sig.install_signal_handler(15);
    //sig.install_signal_handler(17);
    sig.install_signal_handler(18);
    //sig.install_signal_handler(19);
    //sig.install_signal_handler(20);    
    sig.install_signal_handler(21);
    sig.install_signal_handler(22);
    //sig.install_signal_handler(30);
    //sig.install_signal_handler(31);
    sig.install_alarm_handler(alarm);//sig 14
        
    sig.ignore_signal(1);
    
    sig.raise_signal(1);
    sig.raise_signal(2);
    sig.raise_signal(3);
    sig.raise_signal(4);
    sig.raise_signal(6);
    sig.raise_signal(8);
    //sig.raise_signal(9);
    sig.raise_signal(11);
    sig.raise_signal(13);
    sig.raise_signal(14);
    sig.raise_signal(15);
    //sig.raise_signal(17);
    sig.raise_signal(18);
    //sig.raise_signal(19);
    //sig.raise_signal(20);
    sig.raise_signal(21);
    sig.raise_signal(22);
    //sig.raise_signal(30);
    //sig.raise_signal(31);
    
    sig.enable_timer_sec(4);
        
    sig.pause(); //wait a signal, alarm is comming...
    
    return 0;
}

