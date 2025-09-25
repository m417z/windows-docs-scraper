typedef struct _DNS_WIRE_RECORD {
  WORD  RecordType;
  WORD  RecordClass;
  DWORD TimeToLive;
  WORD  DataLength;
} DNS_WIRE_RECORD, *PDNS_WIRE_RECORD;