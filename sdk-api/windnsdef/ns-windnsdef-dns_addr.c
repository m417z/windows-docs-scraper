typedef struct _DnsAddr {
  CHAR  MaxSa[DNS_ADDR_MAX_SOCKADDR_LENGTH];
  DWORD DnsAddrUserDword[8];
} DNS_ADDR, *PDNS_ADDR;