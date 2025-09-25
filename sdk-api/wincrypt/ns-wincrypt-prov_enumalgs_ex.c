typedef struct _PROV_ENUMALGS_EX {
  ALG_ID aiAlgid;
  DWORD  dwDefaultLen;
  DWORD  dwMinLen;
  DWORD  dwMaxLen;
  DWORD  dwProtocols;
  DWORD  dwNameLen;
  CHAR   szName[20];
  DWORD  dwLongNameLen;
  CHAR   szLongName[40];
} PROV_ENUMALGS_EX;