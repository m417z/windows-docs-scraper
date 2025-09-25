typedef struct {
  DWORD       dwMappingFlag;
  DWORD       dwLookupTimeout;
  DWORD       dwCacheTimeout;
  DWORD       cWinsServerCount;
#if ...
  IP4_ADDRESS WinsServers[];
#else
  IP4_ADDRESS WinsServers[1];
#endif
} DNS_WINS_DATA, *PDNS_WINS_DATA;