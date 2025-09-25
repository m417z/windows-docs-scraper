typedef struct _MIB_IPMCAST_OIF_STATS_W2K {
  DWORD dwOutIfIndex;
  DWORD dwNextHopAddr;
  PVOID pvDialContext;
  ULONG ulTtlTooLow;
  ULONG ulFragNeeded;
  ULONG ulOutPackets;
  ULONG ulOutDiscards;
} MIB_IPMCAST_OIF_STATS_W2K, *PMIB_IPMCAST_OIF_STATS_W2K;