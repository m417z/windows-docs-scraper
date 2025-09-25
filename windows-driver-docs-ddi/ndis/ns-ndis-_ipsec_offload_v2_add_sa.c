typedef struct _IPSEC_OFFLOAD_V2_ADD_SA {
  NDIS_OBJECT_HEADER                    Header;
  PIPSEC_OFFLOAD_V2_ADD_SA              Next;
  ULONG                                 NumExtHdrs;
  ULONG                                 Flags;
  union {
    struct {
      IPAddr SrcAddr;
      IPAddr DestAddr;
    } IPv4Endpoints;
    struct {
      UCHAR SrcAddr[16];
      UCHAR DestAddr[16];
    } IPv6Endpoints;
  };
  NDIS_HANDLE                           OffloadHandle;
  ULONG                                 UdpEspEncapsulation;
  IPSEC_OFFLOAD_V2_SECURITY_ASSOCIATION SecAssoc[IPSEC_OFFLOAD_V2_MAX_EXTENSION_HEADERS];
  ULONG                                 KeyLength;
  UCHAR                                 KeyData[1];
} IPSEC_OFFLOAD_V2_ADD_SA, *PIPSEC_OFFLOAD_V2_ADD_SA;