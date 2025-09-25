typedef struct tagPXE_DHCPV6_MESSAGE {
  BYTE              MessageType;
  BYTE              TransactionIDByte1;
  BYTE              TransactionIDByte2;
  BYTE              TransactionIDByte3;
  PXE_DHCPV6_OPTION Options[1];
} PXE_DHCPV6_MESSAGE, *PPXE_DHCPV6_MESSAGE;