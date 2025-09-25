typedef struct _DHCP_CLIENT_SEARCH_INFO {
  DHCP_SEARCH_INFO_TYPE     SearchType;
#if ...
  union {
    DHCP_IP_ADDRESS ClientIpAddress;
    DHCP_CLIENT_UID ClientHardwareAddress;
    LPWSTR          ClientName;
  } SearchInfo;
#if ...
  _DHCP_CLIENT_SEARCH_UNION _DHCP_CLIENT_SEARCH_UNION;
#else
  union {
    DHCP_IP_ADDRESS ClientIpAddress;
    DHCP_CLIENT_UID ClientHardwareAddress;
    LPWSTR          ClientName;
  } SearchInfo;
#endif
#else
  _DHCP_CLIENT_SEARCH_UNION _DHCP_CLIENT_SEARCH_UNION;
#endif
} DHCP_SEARCH_INFO, *LPDHCP_SEARCH_INFO;