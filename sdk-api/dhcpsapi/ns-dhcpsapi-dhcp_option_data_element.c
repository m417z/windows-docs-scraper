typedef struct _DHCP_OPTION_DATA_ELEMENT {
  DHCP_OPTION_DATA_TYPE      OptionType;
#if ...
  union {
    BYTE             ByteOption;
    WORD             WordOption;
    DWORD            DWordOption;
    DWORD_DWORD      DWordDWordOption;
    DHCP_IP_ADDRESS  IpAddressOption;
    LPWSTR           StringDataOption;
    DHCP_BINARY_DATA BinaryDataOption;
    DHCP_BINARY_DATA EncapsulatedDataOption;
    LPWSTR           Ipv6AddressDataOption;
  } Element;
#if ...
  _DHCP_OPTION_ELEMENT_UNION _DHCP_OPTION_ELEMENT_UNION;
#else
  union {
    BYTE             ByteOption;
    WORD             WordOption;
    DWORD            DWordOption;
    DWORD_DWORD      DWordDWordOption;
    DHCP_IP_ADDRESS  IpAddressOption;
    LPWSTR           StringDataOption;
    DHCP_BINARY_DATA BinaryDataOption;
    DHCP_BINARY_DATA EncapsulatedDataOption;
    LPWSTR           Ipv6AddressDataOption;
  } Element;
#endif
#else
  _DHCP_OPTION_ELEMENT_UNION _DHCP_OPTION_ELEMENT_UNION;
#endif
} DHCP_OPTION_DATA_ELEMENT, *LPDHCP_OPTION_DATA_ELEMENT;