typedef struct _PKTMON_DROP_REPORT_IN {
  PKTMON_HEADER Header;
  UINT32        DropReason;
  UINT32        LocationCode;
} PKTMON_DROP_REPORT_IN;