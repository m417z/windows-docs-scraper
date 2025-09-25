typedef struct {
  WORD  wTypeCovered;
  BYTE  chAlgorithm;
  BYTE  chLabelCount;
  DWORD dwOriginalTtl;
  DWORD dwExpiration;
  DWORD dwTimeSigned;
  WORD  wKeyTag;
  WORD  wSignatureLength;
  PWSTR pNameSigner;
#if ...
  BYTE  Signature[];
#else
  BYTE  Signature[1];
#endif
} DNS_SIG_DATAW, *PDNS_SIG_DATAW, DNS_RRSIG_DATAW, *PDNS_RRSIG_DATAW;