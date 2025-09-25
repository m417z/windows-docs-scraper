typedef struct _PROV_ENUMALGS {
  ALG_ID aiAlgid;
  DWORD  dwBitLen;
  DWORD  dwNameLen;
  CHAR   szName[20];
} PROV_ENUMALGS;