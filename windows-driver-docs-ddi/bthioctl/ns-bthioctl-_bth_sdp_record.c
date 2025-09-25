typedef struct _BTH_SDP_RECORD {
  ULONG fSecurity;
  ULONG fOptions;
  ULONG fCodService;
  ULONG recordLength;
  UCHAR record[1];
} BTH_SDP_RECORD, *PBTH_SDP_RECORD;