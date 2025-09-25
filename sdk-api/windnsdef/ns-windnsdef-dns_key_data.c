typedef struct {
  WORD wFlags;
  BYTE chProtocol;
  BYTE chAlgorithm;
  WORD wKeyLength;
  WORD wPad;
#if ...
  BYTE Key[];
#else
  BYTE Key[1];
#endif
} DNS_KEY_DATA, *PDNS_KEY_DATA, DNS_DNSKEY_DATA, *PDNS_DNSKEY_DATA;