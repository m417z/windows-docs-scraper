typedef struct _DHCPV6PrefixLeaseInformation {
  DWORD          nPrefixes;
  LPDHCPV6Prefix prefixArray;
  DWORD          iaid;
  time_t         T1;
  time_t         T2;
  time_t         MaxLeaseExpirationTime;
  time_t         LastRenewalTime;
  StatusCode     status;
  LPBYTE         ServerId;
  DWORD          ServerIdLen;
} DHCPV6PrefixLeaseInformation, *PDHCPV6PrefixLeaseInformation, *LPDHCPV6PrefixLeaseInformation;