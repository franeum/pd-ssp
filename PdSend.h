#ifndef   PdSend_h
#define   PdSend_h 

#if       ARDUINO < 100
#include  <WProgram.h>
#else
#include  <Arduino.h>
#endif 

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAXMSGSIZE  512
#define MAXADDRSIZE 128

class PdSend {
   
    const char  *startbyte;        
    const char  *stopbyte;           
    char        _addrmsg[MAXADDRSIZE];
    char        totmsg[MAXMSGSIZE];
    int         prec;
    
  public:
  
    PdSend(char *addrmsg);
    void  sendmsg(char *types, ...);  
    void  setAddr(char *address);
    void  setFloatPrecision(int p);      
};

#endif 

