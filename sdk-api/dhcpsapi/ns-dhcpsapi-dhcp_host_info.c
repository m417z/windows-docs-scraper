typedef struct _DHCP_HOST_INFO {
  DHCP_IP_ADDRESS IpAddress;
  LPWSTR          NetBiosName;
  LPWSTR          HostName;
} DHCP_HOST_INFO, *LPDHCP_HOST_INFO;