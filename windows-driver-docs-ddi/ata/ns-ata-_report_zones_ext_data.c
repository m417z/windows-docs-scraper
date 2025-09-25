typedef struct _REPORT_ZONES_EXT_DATA {
  ULONG     ZoneListLength;
  UCHAR     SAME : 4;
  UCHAR     Reserved0 : 4;
  UCHAR     Reserved1[3];
  ULONGLONG MaxLBA : 48;
  ULONGLONG Reserved2 : 16;
  UCHAR     Reserved3[48];
} REPORT_ZONES_EXT_DATA, *PREPORT_ZONES_EXT_DATA;