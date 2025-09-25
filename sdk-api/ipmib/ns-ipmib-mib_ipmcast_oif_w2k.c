typedef struct _MIB_IPMCAST_OIF_W2K {
  DWORD dwOutIfIndex;
  DWORD dwNextHopAddr;
  PVOID pvReserved;
  DWORD dwReserved;
} MIB_IPMCAST_OIF_W2K, *PMIB_IPMCAST_OIF_W2K;