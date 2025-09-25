typedef struct _DnsAddrArray {
  DWORD    MaxCount;
  DWORD    AddrCount;
  DWORD    Tag;
  WORD     Family;
  WORD     WordReserved;
  DWORD    Flags;
  DWORD    MatchFlag;
  DWORD    Reserved1;
  DWORD    Reserved2;
  DNS_ADDR AddrArray[];
} DNS_ADDR_ARRAY, *PDNS_ADDR_ARRAY;