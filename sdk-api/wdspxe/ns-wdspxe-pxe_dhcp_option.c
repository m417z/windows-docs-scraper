typedef struct tagPXE_DHCP_OPTION {
  BYTE OptionType;
  BYTE OptionLength;
  BYTE OptionValue[1];
} PXE_DHCP_OPTION, *PPXE_DHCP_OPTION;