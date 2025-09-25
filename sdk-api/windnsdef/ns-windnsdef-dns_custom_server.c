typedef struct _DNS_CUSTOM_SERVER {
  DWORD   dwServerType;
  ULONG64 ullFlags;
  union {
    PWSTR pwszTemplate;
    PWSTR pwszHostname;
  };
  CHAR    MaxSa[DNS_ADDR_MAX_SOCKADDR_LENGTH];
} DNS_CUSTOM_SERVER;