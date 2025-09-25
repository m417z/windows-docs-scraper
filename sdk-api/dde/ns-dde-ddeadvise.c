typedef struct {
  unsigned short reserved : 14;
  unsigned short fDeferUpd : 1;
  unsigned short fAckReq : 1;
  unsigned short usFlags;
  short          cfFormat;
} DDEADVISE;