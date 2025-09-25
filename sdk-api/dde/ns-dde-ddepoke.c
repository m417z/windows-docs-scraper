typedef struct {
  unsigned short unused : 13;
  unsigned short fRelease : 1;
  unsigned short fReserved : 2;
  unsigned short usFlags;
  short          cfFormat;
  BYTE           Value[1];
} DDEPOKE;