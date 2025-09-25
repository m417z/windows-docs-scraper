typedef struct _DHCP_CLIENT_INFO_V4 {
  DHCP_IP_ADDRESS ClientIpAddress;
  DHCP_IP_MASK    SubnetMask;
  DHCP_CLIENT_UID ClientHardwareAddress;
  LPWSTR          ClientName;
  LPWSTR          ClientComment;
  DATE_TIME       ClientLeaseExpires;
  DHCP_HOST_INFO  OwnerHost;
  BYTE            bClientType;
} DHCP_CLIENT_INFO_V4, *LPDHCP_CLIENT_INFO_V4;