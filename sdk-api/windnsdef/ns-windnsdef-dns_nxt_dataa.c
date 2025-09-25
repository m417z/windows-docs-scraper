typedef struct {
  PSTR pNameNext;
  WORD wNumTypes;
#if ...
  WORD wTypes[];
#else
  WORD wTypes[1];
#endif
} DNS_NXT_DATAA, *PDNS_NXT_DATAA;