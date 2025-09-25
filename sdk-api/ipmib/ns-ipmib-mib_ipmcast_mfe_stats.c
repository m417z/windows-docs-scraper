typedef struct _MIB_IPMCAST_MFE_STATS {
  DWORD                 dwGroup;
  DWORD                 dwSource;
  DWORD                 dwSrcMask;
  DWORD                 dwUpStrmNgbr;
  DWORD                 dwInIfIndex;
  DWORD                 dwInIfProtocol;
  DWORD                 dwRouteProtocol;
  DWORD                 dwRouteNetwork;
  DWORD                 dwRouteMask;
  ULONG                 ulUpTime;
  ULONG                 ulExpiryTime;
  ULONG                 ulNumOutIf;
  ULONG                 ulInPkts;
  ULONG                 ulInOctets;
  ULONG                 ulPktsDifferentIf;
  ULONG                 ulQueueOverflow;
  MIB_IPMCAST_OIF_STATS rgmiosOutStats[ANY_SIZE];
} MIB_IPMCAST_MFE_STATS, *PMIB_IPMCAST_MFE_STATS;