typedef struct _IPSEC_OFFLOAD_V2_ADD_SA_EX {
  NDIS_OBJECT_HEADER                    Header;
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
  ULONG                                 KeyOffset;
  NDIS_SWITCH_PORT_ID                   SourceSwitchPortId;
  USHORT                                VlanId;
} IPSEC_OFFLOAD_V2_ADD_SA_EX, *PIPSEC_OFFLOAD_V2_ADD_SA_EX;