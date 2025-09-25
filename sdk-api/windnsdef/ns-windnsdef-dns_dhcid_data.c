typedef struct {
  DWORD dwByteCount;
#if ...
  BYTE  DHCID[];
#else
  BYTE  DHCID[1];
#endif
} DNS_DHCID_DATA, *PDNS_DHCID_DATA;