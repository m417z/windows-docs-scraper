typedef struct _DHCP_SUBNET_INFO_V6 {
  DHCP_IPV6_ADDRESS SubnetAddress;
  ULONG             Prefix;
  USHORT            Preference;
  LPWSTR            SubnetName;
  LPWSTR            SubnetComment;
  DWORD             State;
  DWORD             ScopeId;
} DHCP_SUBNET_INFO_V6, *PDHCP_SUBNET_INFO_V6, *LPDHCP_SUBNET_INFO_V6;