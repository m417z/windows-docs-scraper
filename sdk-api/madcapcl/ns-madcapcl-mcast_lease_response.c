typedef struct _MCAST_LEASE_RESPONSE {
  LONG         LeaseStartTime;
  LONG         LeaseEndTime;
  IPNG_ADDRESS ServerAddress;
  WORD         AddrCount;
  PBYTE        pAddrBuf;
} MCAST_LEASE_RESPONSE, *PMCAST_LEASE_RESPONSE;