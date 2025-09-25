typedef struct {
  WORD wOrder;
  WORD wPreference;
  PSTR pFlags;
  PSTR pService;
  PSTR pRegularExpression;
  PSTR pReplacement;
} DNS_NAPTR_DATAA, *PDNS_NAPTR_DATAA;