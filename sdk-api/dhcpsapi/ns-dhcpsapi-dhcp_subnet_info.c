typedef struct _DHCP_SUBNET_INFO {
  DHCP_IP_ADDRESS   SubnetAddress;
  DHCP_IP_MASK      SubnetMask;
  LPWSTR            SubnetName;
  LPWSTR            SubnetComment;
  DHCP_HOST_INFO    PrimaryHost;
  DHCP_SUBNET_STATE SubnetState;
} DHCP_SUBNET_INFO, *LPDHCP_SUBNET_INFO;