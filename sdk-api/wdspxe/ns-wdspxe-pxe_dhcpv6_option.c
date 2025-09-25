typedef struct tagPXE_DHCPV6_OPTION {
  WORD OptionCode;
  WORD DataLength;
  BYTE Data[1];
} PXE_DHCPV6_OPTION, *PPXE_DHCPV6_OPTION;