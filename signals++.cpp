#include "signals++.h"

#include <iostream>
using namespace std;

signalspp::signalspp()
{
}

signalspp::~signalspp()
{
}

void signalspp::signal_handler(int sig)
{
    switch(sig) {
    case SIGHUP:
        cout << "SIGHUP" << endl;
        break;
    case SIGINT:
        cout << "SIGINT" << endl;
        break;    
    case SIGQUIT:   
        cout << "SIGQUIT" << endl;
        break;
    case SIGILL:   
        cout << "SIGILL" << endl;
        break;
    case SIGABRT:  
        cout << "SIGABRT" << endl;
        break;
    case SIGFPE:  
        cout << "SIGFPE" << endl;
        break;
    case SIGKILL:  
        cout << "SIGKILL" << endl;
        break;
    case SIGSEGV:  
        cout << "SIGSEGV" << endl;
        break;
    case SIGPIPE:  
        cout << "SIGPIPE" << endl;
        break;
    case SIGALRM:  
        cout << "SIGALRM" << endl;
        break;
    case SIGTERM:  
        cout << "SIGTERM" << endl;
        break;
    case SIGSTOP:  
        cout << "SIGSTOP" << endl;
        break;
    case SIGTSTP:  
        cout << "SIGTSTP" << endl;
        break;
    case SIGCONT:  
        cout << "SIGCONT" << endl;
        break;
    case SIGCHLD:  
        cout << "SIGCHLD" << endl;
        break;
    case SIGTTIN:  
        cout << "SIGTTIN" << endl;
        break;
    case SIGTTOU:  
        cout << "SIGTTOU" << endl;
        break;
    case SIGUSR1:  
        cout << "SIGUSR1" << endl;
        break;
    case SIGUSR2:  
        cout << "SIGUSR2" << endl;
        break;
    }
}

void signalspp::install_signal_handler(int sig, void (*function)(int)) const
{
    struct sigaction sa = {0};

    //memset(&sa, 0, sizeof(sa));
    sa.sa_handler = function;

    sigaction(sig, &sa, NULL);
}
void signalspp::install_alarm_handler(void (*alarm_handler)(int)) const 
{
    struct sigaction defHandle = {0};
    defHandle.sa_handler = alarm_handler;
    sigemptyset(&defHandle.sa_mask);
    //defHandle.sa_flags = SA_ONESHOT;
    
    sigaction(SIGALRM,&defHandle,NULL);
}

int signalspp::enable_timer_sec(int time) const
{
    struct itimerval Z;
    
    Z.it_interval.tv_sec=0;
    Z.it_interval.tv_usec=0;
    Z.it_value.tv_sec=time;
    Z.it_value.tv_usec=0;
    setitimer(ITIMER_REAL,&Z,&Z);   
    
    return 0;
}

int signalspp::enable_timer_usec(int time) const
{
    struct itimerval Z;
    
    Z.it_interval.tv_sec=0;
    Z.it_interval.tv_usec=0;
    Z.it_value.tv_sec=0;
    Z.it_value.tv_usec=time;
    setitimer(ITIMER_REAL,&Z,&Z);
    
    return 0;
}

int signalspp::disable_timer() const
{
    struct itimerval Z;
    
    Z.it_interval.tv_sec=0;
    Z.it_interval.tv_usec=0;
    Z.it_value.tv_sec=0;
    Z.it_value.tv_usec=0;
    setitimer(ITIMER_REAL,&Z,&Z);
    
    return 0;
}

int signalspp::send_signal(pid_t pid, int sig) const
{
    return kill(pid,sig);
}

int signalspp::raise_signal(int sig) const
{
    return raise(sig);
}

int signalspp::pause() const
{
    return ::pause();
}

int signalspp::ignore_signal(int sig) const
{
    //SIG_DFL -- a pointer to a system default function SID_DFL(), which will terminate the process upon receipt of sig. 
    //SIG_IGN -- a pointer to system ignore function SIG_IGN() which will disregard the sig action (UNLESS it is SIGKILL). 
    //A function address-- a user specified function.
    if (signal(sig,SIG_IGN) != SIG_ERR) 
        return 0;
    else
        return 1;
}
