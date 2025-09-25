typedef struct {
  PSTR pNextDomainName;
  WORD wTypeBitMapsLength;
  WORD wPad;
#if ...
  BYTE TypeBitMaps[];
#else
  BYTE TypeBitMaps[1];
#endif
} DNS_NSEC_DATAA, *PDNS_NSEC_DATAA;