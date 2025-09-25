typedef struct _SecPkgInfoW {
  unsigned long  fCapabilities;
  unsigned short wVersion;
  unsigned short wRPCID;
  unsigned long  cbMaxToken;
  SEC_WCHAR      *Name;
  SEC_WCHAR      *Comment;
} SecPkgInfoW, *PSecPkgInfoW;