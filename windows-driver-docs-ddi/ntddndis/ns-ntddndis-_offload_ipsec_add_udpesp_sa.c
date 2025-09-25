typedef struct _OFFLOAD_IPSEC_ADD_UDPESP_SA {
  IPAddr                               SrcAddr;
  IPMask                               SrcMask;
  IPAddr                               DstAddr;
  IPMask                               DstMask;
  ULONG                                Protocol;
  USHORT                               SrcPort;
  USHORT                               DstPort;
  IPAddr                               SrcTunnelAddr;
  IPAddr                               DstTunnelAddr;
  USHORT                               Flags;
  SHORT                                NumSAs;
  OFFLOAD_SECURITY_ASSOCIATION         SecAssoc[OFFLOAD_MAX_SAS];
  HANDLE                               OffloadHandle;
  OFFLOAD_IPSEC_UDPESP_ENCAPTYPE_ENTRY EncapTypeEntry;
  HANDLE                               EncapTypeEntryOffldHandle;
  ULONG                                KeyLen;
  UCHAR                                KeyMat[1];
} OFFLOAD_IPSEC_ADD_UDPESP_SA, *POFFLOAD_IPSEC_ADD_UDPESP_SA;