typedef struct _MCAST_LEASE_REQUEST {
  LONG         LeaseStartTime;
  LONG         MaxLeaseStartTime;
  DWORD        LeaseDuration;
  DWORD        MinLeaseDuration;
  IPNG_ADDRESS ServerAddress;
  WORD         MinAddrCount;
  WORD         AddrCount;
  PBYTE        pAddrBuf;
} MCAST_LEASE_REQUEST, *PMCAST_LEASE_REQUEST;