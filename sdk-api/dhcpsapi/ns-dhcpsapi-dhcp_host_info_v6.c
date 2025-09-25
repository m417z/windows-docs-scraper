typedef struct _DHCP_HOST_INFO_V6 {
  DHCP_IPV6_ADDRESS IpAddress;
  LPWSTR            NetBiosName;
  LPWSTR            HostName;
} DHCP_HOST_INFO_V6, *LPDHCP_HOST_INFO_V6;