typedef struct _SCHANNEL_ALG {
  DWORD  dwUse;
  ALG_ID Algid;
  DWORD  cBits;
  DWORD  dwFlags;
  DWORD  dwReserved;
} SCHANNEL_ALG, *PSCHANNEL_ALG;