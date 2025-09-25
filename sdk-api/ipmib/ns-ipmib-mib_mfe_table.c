typedef struct _MIB_MFE_TABLE {
  DWORD           dwNumEntries;
  MIB_IPMCAST_MFE table[ANY_SIZE];
} MIB_MFE_TABLE, *PMIB_MFE_TABLE;