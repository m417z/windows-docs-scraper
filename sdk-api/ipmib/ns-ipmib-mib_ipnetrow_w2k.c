typedef struct _MIB_IPNETROW_W2K {
  IF_INDEX dwIndex;
  DWORD    dwPhysAddrLen;
  UCHAR    bPhysAddr[MAXLEN_PHYSADDR];
  DWORD    dwAddr;
  DWORD    dwType;
} MIB_IPNETROW_W2K, *PMIB_IPNETROW_W2K;