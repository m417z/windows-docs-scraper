typedef struct _DHCPV6Prefix {
  UCHAR      prefix[16];
  DWORD      prefixLength;
  DWORD      preferredLifeTime;
  DWORD      validLifeTime;
  StatusCode status;
} DHCPV6Prefix, *PDHCPV6Prefix, *LPDHCPV6Prefix;