typedef struct {
  char            HostName[MAX_HOSTNAME_LEN + 4];
  char            DomainName[MAX_DOMAIN_NAME_LEN + 4];
  PIP_ADDR_STRING CurrentDnsServer;
  IP_ADDR_STRING  DnsServerList;
  UINT            NodeType;
  char            ScopeId[MAX_SCOPE_ID_LEN + 4];
  UINT            EnableRouting;
  UINT            EnableProxy;
  UINT            EnableDns;
} FIXED_INFO_W2KSP1, *PFIXED_INFO_W2KSP1;