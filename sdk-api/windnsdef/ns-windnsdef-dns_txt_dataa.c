typedef struct {
  DWORD dwStringCount;
#if ...
  PSTR  pStringArray[];
#else
  PSTR  pStringArray[1];
#endif
} DNS_TXT_DATAA, *PDNS_TXT_DATAA;