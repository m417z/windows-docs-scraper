typedef enum _DHCP_OPTION_DATA_TYPE {
  DhcpByteOption,
  DhcpWordOption,
  DhcpDWordOption,
  DhcpDWordDWordOption,
  DhcpIpAddressOption,
  DhcpStringDataOption,
  DhcpBinaryDataOption,
  DhcpEncapsulatedDataOption,
  DhcpIpv6AddressOption
} DHCP_OPTION_DATA_TYPE, *LPDHCP_OPTION_DATA_TYPE;