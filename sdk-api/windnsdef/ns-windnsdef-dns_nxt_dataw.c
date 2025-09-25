typedef struct {
  PWSTR pNameNext;
  WORD  wNumTypes;
#if ...
  WORD  wTypes[];
#else
  WORD  wTypes[1];
#endif
} DNS_NXT_DATAW, *PDNS_NXT_DATAW;