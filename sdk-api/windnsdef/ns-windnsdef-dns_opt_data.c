typedef struct {
  WORD wDataLength;
  WORD wPad;
#if ...
  BYTE Data[];
#else
  BYTE Data[1];
#endif
} DNS_OPT_DATA, *PDNS_OPT_DATA;