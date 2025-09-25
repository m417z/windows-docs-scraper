typedef struct _DHCP_CLIENT_INFO {
  DHCP_IP_ADDRESS ClientIpAddress;
  DHCP_IP_MASK    SubnetMask;
  DHCP_CLIENT_UID ClientHardwareAddress;
  LPWSTR          ClientName;
  LPWSTR          ClientComment;
  DATE_TIME       ClientLeaseExpires;
  DHCP_HOST_INFO  OwnerHost;
} DHCP_CLIENT_INFO, *LPDHCP_CLIENT_INFO;