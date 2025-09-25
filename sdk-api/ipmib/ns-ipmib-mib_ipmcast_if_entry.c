typedef struct _MIB_IPMCAST_IF_ENTRY {
  DWORD dwIfIndex;
  DWORD dwTtl;
  DWORD dwProtocol;
  DWORD dwRateLimit;
  ULONG ulInMcastOctets;
  ULONG ulOutMcastOctets;
} MIB_IPMCAST_IF_ENTRY, *PMIB_IPMCAST_IF_ENTRY;