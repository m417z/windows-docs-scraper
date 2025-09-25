typedef struct _MIB_MFE_STATS_TABLE {
  DWORD                 dwNumEntries;
  MIB_IPMCAST_MFE_STATS table[ANY_SIZE];
} MIB_MFE_STATS_TABLE, *PMIB_MFE_STATS_TABLE;