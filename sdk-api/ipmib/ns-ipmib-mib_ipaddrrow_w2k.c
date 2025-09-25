typedef struct _MIB_IPADDRROW_W2K {
  DWORD          dwAddr;
  DWORD          dwIndex;
  DWORD          dwMask;
  DWORD          dwBCastAddr;
  DWORD          dwReasmSize;
  unsigned short unused1;
  unsigned short unused2;
} MIB_IPADDRROW_W2K, *PMIB_IPADDRROW_W2K;