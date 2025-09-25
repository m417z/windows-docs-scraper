typedef struct _MIB_IPADDRROW_XP {
  DWORD          dwAddr;
  IF_INDEX       dwIndex;
  DWORD          dwMask;
  DWORD          dwBCastAddr;
  DWORD          dwReasmSize;
  unsigned short unused1;
  unsigned short wType;
} MIB_IPADDRROW_XP, *PMIB_IPADDRROW_XP;