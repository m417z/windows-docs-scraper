typedef struct _DHCP_CLIENT_SEARCH_INFO_V6 {
  DHCP_SEARCH_INFO_TYPE_V6     SearchType;
#if ...
  union {
    DHCP_IPV6_ADDRESS ClientIpAddress;
    DHCP_CLIENT_UID   ClientDUID;
    LPWSTR            ClientName;
  } SearchInfo;
#if ...
  _DHCP_CLIENT_SEARCH_UNION_V6 _DHCP_CLIENT_SEARCH_UNION_V6;
#else
  union {
    DHCP_IPV6_ADDRESS ClientIpAddress;
    DHCP_CLIENT_UID   ClientDUID;
    LPWSTR            ClientName;
  } SearchInfo;
#endif
#else
  _DHCP_CLIENT_SEARCH_UNION_V6 _DHCP_CLIENT_SEARCH_UNION_V6;
#endif
} DHCP_SEARCH_INFO_V6, *LPDHCP_SEARCH_INFO_V6;