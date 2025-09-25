typedef struct {
  DWORD dwStringCount;
#if ...
  PWSTR pStringArray[];
#else
  PWSTR pStringArray[1];
#endif
} DNS_TXT_DATAW, *PDNS_TXT_DATAW;