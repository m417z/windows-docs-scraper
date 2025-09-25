typedef struct _DHCP_BIND_ELEMENT {
  ULONG           Flags;
  BOOL            fBoundToDHCPServer;
  DHCP_IP_ADDRESS AdapterPrimaryAddress;
  DHCP_IP_ADDRESS AdapterSubnetAddress;
  LPWSTR          IfDescription;
  ULONG           IfIdSize;
  LPBYTE          IfId;
} DHCP_BIND_ELEMENT, *LPDHCP_BIND_ELEMENT;