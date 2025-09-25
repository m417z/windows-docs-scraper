typedef struct {
  WORD  wOrder;
  WORD  wPreference;
  PWSTR pFlags;
  PWSTR pService;
  PWSTR pRegularExpression;
  PWSTR pReplacement;
} DNS_NAPTR_DATAW, *PDNS_NAPTR_DATAW;