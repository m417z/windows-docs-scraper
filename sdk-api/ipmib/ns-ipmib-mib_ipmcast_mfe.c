typedef struct _MIB_IPMCAST_MFE {
  DWORD           dwGroup;
  DWORD           dwSource;
  DWORD           dwSrcMask;
  DWORD           dwUpStrmNgbr;
  DWORD           dwInIfIndex;
  DWORD           dwInIfProtocol;
  DWORD           dwRouteProtocol;
  DWORD           dwRouteNetwork;
  DWORD           dwRouteMask;
  ULONG           ulUpTime;
  ULONG           ulExpiryTime;
  ULONG           ulTimeOut;
  ULONG           ulNumOutIf;
  DWORD           fFlags;
  DWORD           dwReserved;
  MIB_IPMCAST_OIF rgmioOutInfo[ANY_SIZE];
} MIB_IPMCAST_MFE, *PMIB_IPMCAST_MFE;