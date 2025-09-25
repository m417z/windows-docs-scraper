typedef struct _DnsRecordFlags {
  DWORD Section : 2;
  DWORD Delete : 1;
  DWORD CharSet : 2;
  DWORD Unused : 3;
  DWORD Reserved : 24;
} DNS_RECORD_FLAGS;