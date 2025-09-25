typedef struct _OFFLOAD_IPSEC_ADD_SA {
  IPAddr                       SrcAddr;
  IPMask                       SrcMask;
  IPAddr                       DestAddr;
  IPMask                       DestMask;
  ULONG                        Protocol;
  USHORT                       SrcPort;
  USHORT                       DestPort;
  IPAddr                       SrcTunnelAddr;
  IPAddr                       DestTunnelAddr;
  USHORT                       Flags;
  SHORT                        NumSAs;
  OFFLOAD_SECURITY_ASSOCIATION SecAssoc[OFFLOAD_MAX_SAS];
  HANDLE                       OffloadHandle;
  ULONG                        KeyLen;
  UCHAR                        KeyMat[1];
} OFFLOAD_IPSEC_ADD_SA, *POFFLOAD_IPSEC_ADD_SA;