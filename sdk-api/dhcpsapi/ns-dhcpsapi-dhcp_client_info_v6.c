typedef struct _DHCP_CLIENT_INFO_V6 {
  DHCP_IPV6_ADDRESS ClientIpAddress;
  DHCP_CLIENT_UID   ClientDUID;
  DWORD             AddressType;
  DWORD             IAID;
  LPWSTR            ClientName;
  LPWSTR            ClientComment;
  DATE_TIME         ClientValidLeaseExpires;
  DATE_TIME         ClientPrefLeaseExpires;
  DHCP_HOST_INFO_V6 OwnerHost;
} DHCP_CLIENT_INFO_V6, *LPDHCP_CLIENT_INFO_V6;