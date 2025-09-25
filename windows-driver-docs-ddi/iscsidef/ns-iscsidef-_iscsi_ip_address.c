typedef struct _ISCSI_IP_Address {
  ULONG Type;
  ULONG IpV4Address;
  UCHAR IpV6Address[16];
  ULONG IpV6FlowInfo;
  ULONG IpV6ScopeId;
  WCHAR TextAddress[256 + 1];
} ISCSI_IP_Address, *PISCSI_IP_Address;