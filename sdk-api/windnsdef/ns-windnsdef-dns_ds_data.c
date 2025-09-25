typedef struct {
  WORD wKeyTag;
  BYTE chAlgorithm;
  BYTE chDigestType;
  WORD wDigestLength;
  WORD wPad;
#if ...
  BYTE Digest[];
#else
  BYTE Digest[1];
#endif
} DNS_DS_DATA, *PDNS_DS_DATA;