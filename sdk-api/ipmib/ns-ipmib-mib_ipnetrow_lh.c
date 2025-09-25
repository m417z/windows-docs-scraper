typedef struct _MIB_IPNETROW_LH {
  IF_INDEX dwIndex;
  DWORD    dwPhysAddrLen;
  UCHAR    bPhysAddr[MAXLEN_PHYSADDR];
  DWORD    dwAddr;
  union {
    DWORD          dwType;
    MIB_IPNET_TYPE Type;
  };
} MIB_IPNETROW_LH, *PMIB_IPNETROW_LH;