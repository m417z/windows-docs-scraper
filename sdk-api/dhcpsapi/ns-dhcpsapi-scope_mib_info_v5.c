typedef struct _SCOPE_MIB_INFO_V5 {
  DHCP_IP_ADDRESS Subnet;
  DWORD           NumAddressesInuse;
  DWORD           NumAddressesFree;
  DWORD           NumPendingOffers;
} SCOPE_MIB_INFO_V5, *LPSCOPE_MIB_INFO_V5;