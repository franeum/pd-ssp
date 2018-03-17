#ifndef   PdSend_h
#define   PdSend_h

#if       ARDUINO < 100
#include  <WProgram.h>
#else
#include  <Arduino.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define MAXMSGSIZE  512
#define MAXADDRSIZE 128

class PdSend {

  private:

    const char  *startbyte;
    const char  *stopbyte;
    char        _addrmsg[MAXADDRSIZE];
    char        totmsg[MAXMSGSIZE];
    int         prec;

  public:

    PdSend();
    PdSend(char *addrmsg, int p = 2);
    void  sendmsg(char *types, ...);
    void  setAddr(char *address);
    void  setFloatPrecision(int p);
};

#endif
