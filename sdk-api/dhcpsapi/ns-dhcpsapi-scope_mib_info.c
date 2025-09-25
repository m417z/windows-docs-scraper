typedef struct _SCOPE_MIB_INFO {
  DHCP_IP_ADDRESS Subnet;
  DWORD           NumAddressesInuse;
  DWORD           NumAddressesFree;
  DWORD           NumPendingOffers;
} SCOPE_MIB_INFO, *LPSCOPE_MIB_INFO;