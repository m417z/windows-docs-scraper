typedef struct _DHCP_BOOTP_IP_RANGE {
  DHCP_IP_ADDRESS StartAddress;
  DHCP_IP_ADDRESS EndAddress;
  ULONG           BootpAllocated;
  ULONG           MaxBootpAllowed;
} DHCP_BOOTP_IP_RANGE, *LPDHCP_BOOT_IP_RANGE;