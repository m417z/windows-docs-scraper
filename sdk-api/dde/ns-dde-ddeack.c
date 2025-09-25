typedef struct {
  unsigned short bAppReturnCode : 8;
  unsigned short reserved : 6;
  unsigned short fBusy : 1;
  unsigned short fAck : 1;
  unsigned short usFlags;
} DDEACK;