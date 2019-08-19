#ifndef _SIGNALSPPH
#define _SIGNALSPPH

#include <csignal>
#include <cerrno>
#include <unistd.h>
#include <ctime>
#include <sys/time.h>
#include <sys/types.h>

//SIGHUP 1 /* hangup */ 
//SIGINT 2 /* interrupt */ 
//SIGQUIT 3 /* quit */ 
//SIGILL 4 /* illegal instruction */ 
//SIGABRT 6 /* used by abort */ 
//SIGFPE 8 /*floating point exception*/
//SIGKILL 9  /* hard kill - cannot be caught, blocked, or  ignored */ 
//SIGSEGV 11 /*Invalid memory reference*/
//SIGPIPE 13 /*Broken pipe: write to pipe with no readers */
//SIGALRM 14 /* alarm clock */   
//SIGTERM 15 /* Termination signal */
//SIGSTOP 17,19,23 /* Stop process - cannot be caught, blocked, or  ignored */
//SIGTSTP 18,20,24 /* Stop typed at tty */
//SIGCONT 19 /* continue if stopped */   
//SIGCHLD 20 /* to parent on child stop or exit */
//SIGTTIN 21,21,26 /* tty input for background process */
//SIGTTOU 22,22,27 /* tty output for background process */
//SIGUSR1 30,10,16 /* User-defined signal 1 */
//SIGUSR2 31,12,17 /* User-defined signal 2 */

class signalspp
{
    private:
        //assigned as default to handle a incoming signal
        //just print the signal name 
        static void signal_handler(int sig);
    
    public:
        signalspp();
        virtual ~signalspp();
    
        //send a signal to process with id pid
        //If pid equals 0, then sig is sent to every process in the process group of the current process.
        //If  pid equals -1, then sig is sent to every process except for process 1 (init)
        //If pid is less than -1, then sig is sent to every process in the process group pid.
        //If  sig  is 0, then no signal is sent, but error checking is still performed.
        //On success, zero is returned.
        int send_signal(pid_t pid, int sig) const;
        
        //raise a signal to the caller process
        //return 0 on success
        int raise_signal(int sig) const;
        
        //pause process until it receives a signal
        //allways returns -1
        int pause() const;
            
        //assign a signal handlers function, as default is used signal_halder function
        //as default, the signal handler is assign to signal_handler() function
        void install_signal_handler(int sig, void (*function)(int) = signal_handler) const;
        //assign a alarm handler function
        void install_alarm_handler(void (*alarm_handler)(int)) const;
        
        // enable a timer wich execute a function assigned by install_alarm_handler
        // alarm on time seconds
        int enable_timer_sec(int time) const;
        // alarm on time microseconds
        int enable_timer_usec(int time) const;
        // disable alarm timer
        int disable_timer() const;
        
        //caller process will ignore this signal
        //returns 0 on success
        int ignore_signal(int sig) const;
};

#endif

