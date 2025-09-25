typedef struct _VDS_IPADDRESS {
  VDS_IPADDRESS_TYPE type;
  ULONG              ipv4Address;
  UCHAR              ipv6Address[16];
  ULONG              ulIpv6FlowInfo;
  ULONG              ulIpv6ScopeId;
  WCHAR              wszTextAddress[257];
  ULONG              ulPort;
} VDS_IPADDRESS;