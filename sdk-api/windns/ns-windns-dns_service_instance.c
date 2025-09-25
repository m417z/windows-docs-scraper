typedef struct _DNS_SERVICE_INSTANCE {
#if ...
  DNSSD_RPC_STRING pszInstanceName;
#else
  LPWSTR           pszInstanceName;
#endif
#if ...
  DNSSD_RPC_STRING pszHostName;
#else
  LPWSTR           pszHostName;
#endif
  IP4_ADDRESS      *ip4Address;
  IP6_ADDRESS      *ip6Address;
  WORD             wPort;
  WORD             wPriority;
  WORD             wWeight;
  DWORD            dwPropertyCount;
#if ...
  DNSSD_RPC_STRING *keys;
#if ...
  DNSSD_RPC_STRING *values;
#else
  PWSTR            *keys;
#endif
#else
  PWSTR            *values;
#endif
  DWORD            dwInterfaceIndex;
} DNS_SERVICE_INSTANCE, *PDNS_SERVICE_INSTANCE;