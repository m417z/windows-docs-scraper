typedef struct {
  DWORD dwByteCount;
#if ...
  BYTE  Data[];
#else
  BYTE  Data[1];
#endif
} DNS_NULL_DATA, *PDNS_NULL_DATA;