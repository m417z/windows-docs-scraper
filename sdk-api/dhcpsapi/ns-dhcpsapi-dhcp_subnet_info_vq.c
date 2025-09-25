typedef struct _DHCP_SUBNET_INFO_VQ {
  DHCP_IP_ADDRESS   SubnetAddress;
  DHCP_IP_MASK      SubnetMask;
  LPWSTR            SubnetName;
  LPWSTR            SubnetComment;
  DHCP_HOST_INFO    PrimaryHost;
  DHCP_SUBNET_STATE SubnetState;
  DWORD             QuarantineOn;
  DWORD             Reserved1;
  DWORD             Reserved2;
  INT64             Reserved3;
  INT64             Reserved4;
} DHCP_SUBNET_INFO_VQ, *LPDHCP_SUBNET_INFO_VQ;