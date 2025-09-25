typedef struct {
  WORD  wTypeCovered;
  BYTE  chAlgorithm;
  BYTE  chLabelCount;
  DWORD dwOriginalTtl;
  DWORD dwExpiration;
  DWORD dwTimeSigned;
  WORD  wKeyTag;
  WORD  wSignatureLength;
  PSTR  pNameSigner;
#if ...
  BYTE  Signature[];
#else
  BYTE  Signature[1];
#endif
} DNS_SIG_DATAA, *PDNS_SIG_DATAA, DNS_RRSIG_DATAA, *PDNS_RRSIG_DATAA;