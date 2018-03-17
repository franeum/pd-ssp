
#include "PdSend.h"


PdSend::PdSend()
{
  char *addrmsg = "test";
  strcpy(_addrmsg, addrmsg);
  startbyte   = "{";
  stopbyte    = "}";
  prec        = 2;
}

PdSend::PdSend(char *addrmsg, int p)
{
  strcpy(_addrmsg, addrmsg);
  startbyte   = "{";
  stopbyte    = "}";
  prec        = p;
}


void PdSend::sendmsg(char *types, ...)
{
  va_list args;
  va_start(args, types);
  char  buf[100];

  strcpy(totmsg, startbyte);
  strcat(totmsg, _addrmsg);
  strcat(totmsg, " ");
  strcat(totmsg,types);

  while (*types != '\0') {
    if (*types == 'i') {
      int i = va_arg(args, int);
      sprintf(buf, " %d", i);
      strcat(totmsg, " ");
      strcat(totmsg, buf);
      *buf = '\0';
    } else if (*types == 's') {
       strcat(totmsg, " ");
       strcat(totmsg, va_arg(args, char *));
    } else if (*types == 'f') {
       float d = (float)va_arg(args, double);
       dtostrf(d,4,prec,buf);
       strcat(totmsg, " ");
       strcat(totmsg, buf);
       *buf = '\0';
    }
    ++types;
  }
  strcat(totmsg, stopbyte);

  Serial.write(totmsg);

  va_end(args);

  *totmsg = '\0';
}

void PdSend::setAddr(char *address)
{
  strcpy(_addrmsg, address);
}

void PdSend::setFloatPrecision(int p)
{
  prec = p;
}
