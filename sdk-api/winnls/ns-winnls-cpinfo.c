typedef struct _cpinfo {
  UINT MaxCharSize;
  BYTE DefaultChar[MAX_DEFAULTCHAR];
  BYTE LeadByte[MAX_LEADBYTES];
} CPINFO, *LPCPINFO;