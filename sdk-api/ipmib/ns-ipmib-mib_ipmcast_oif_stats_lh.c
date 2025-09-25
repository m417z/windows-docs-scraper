typedef struct _MIB_IPMCAST_OIF_STATS_LH {
  DWORD dwOutIfIndex;
  DWORD dwNextHopAddr;
  DWORD dwDialContext;
  ULONG ulTtlTooLow;
  ULONG ulFragNeeded;
  ULONG ulOutPackets;
  ULONG ulOutDiscards;
} MIB_IPMCAST_OIF_STATS_LH, *PMIB_IPMCAST_OIF_STATS_LH;