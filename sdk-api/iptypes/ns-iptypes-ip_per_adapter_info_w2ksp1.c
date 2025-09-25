typedef struct _IP_PER_ADAPTER_INFO_W2KSP1 {
  UINT            AutoconfigEnabled;
  UINT            AutoconfigActive;
  PIP_ADDR_STRING CurrentDnsServer;
  IP_ADDR_STRING  DnsServerList;
} IP_PER_ADAPTER_INFO_W2KSP1, *PIP_PER_ADAPTER_INFO_W2KSP1;