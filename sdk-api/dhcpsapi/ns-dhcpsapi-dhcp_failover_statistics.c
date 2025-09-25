typedef struct _DHCP_FAILOVER_STATISTICS {
  DWORD NumAddr;
  DWORD AddrFree;
  DWORD AddrInUse;
  DWORD PartnerAddrFree;
  DWORD ThisAddrFree;
  DWORD PartnerAddrInUse;
  DWORD ThisAddrInUse;
} DHCP_FAILOVER_STATISTICS, *LPDHCP_FAILOVER_STATISTICS;