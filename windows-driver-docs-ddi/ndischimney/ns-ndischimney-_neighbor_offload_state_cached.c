typedef struct _NEIGHBOR_OFFLOAD_STATE_CACHED {
  OFFLOAD_STATE_HEADER Header;
  UCHAR                DlDestinationAddress[32];
  ULONG                HostReachabilityDelta;
} NEIGHBOR_OFFLOAD_STATE_CACHED, *PNEIGHBOR_OFFLOAD_STATE_CACHED;