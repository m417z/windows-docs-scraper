typedef struct _DHCPV6_BIND_ELEMENT {
  ULONG             Flags;
  BOOL              fBoundToDHCPServer;
  DHCP_IPV6_ADDRESS AdapterPrimaryAddress;
  DHCP_IPV6_ADDRESS AdapterSubnetAddress;
  LPWSTR            IfDescription;
  DWORD             IpV6IfIndex;
  ULONG             IfIdSize;
  LPBYTE            IfId;
} DHCPV6_BIND_ELEMENT, *LPDHCPV6_BIND_ELEMENT;