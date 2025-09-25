typedef struct tagPXE_DHCPV6_RELAY_MESSAGE {
  BYTE              MessageType;
  BYTE              HopCount;
  BYTE              LinkAddress[16];
  BYTE              PeerAddress[16];
  PXE_DHCPV6_OPTION Options[1];
} PXE_DHCPV6_RELAY_MESSAGE, *PPXE_DHCPV6_RELAY_MESSAGE;