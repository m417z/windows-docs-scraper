typedef struct {
  unsigned short unused : 12;
  unsigned short fResponse : 1;
  unsigned short fRelease : 1;
  unsigned short reserved : 1;
  unsigned short fAckReq : 1;
  unsigned short usFlags;
  short          cfFormat;
  BYTE           Value[1];
} DDEDATA;