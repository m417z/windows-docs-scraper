typedef struct _SecPkgInfoA {
  unsigned long  fCapabilities;
  unsigned short wVersion;
  unsigned short wRPCID;
  unsigned long  cbMaxToken;
  SEC_CHAR       *Name;
  SEC_CHAR       *Comment;
} SecPkgInfoA, *PSecPkgInfoA;