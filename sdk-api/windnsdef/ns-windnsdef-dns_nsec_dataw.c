typedef struct {
  PWSTR pNextDomainName;
  WORD  wTypeBitMapsLength;
  WORD  wPad;
#if ...
  BYTE  TypeBitMaps[];
#else
  BYTE  TypeBitMaps[1];
#endif
} DNS_NSEC_DATAW, *PDNS_NSEC_DATAW;