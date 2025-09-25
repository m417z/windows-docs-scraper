typedef struct _ATA_ZONE_DESCRIPTOR {
  UCHAR     ZoneType : 4;
  UCHAR     Reserved0 : 4;
  UCHAR     Reset : 1;
  UCHAR     NonSeq : 1;
  UCHAR     Reserved1 : 2;
  UCHAR     ZoneCondition : 4;
  UCHAR     Reserved2[6];
  ULONGLONG ZoneLength : 48;
  ULONGLONG Reserved3 : 16;
  ULONGLONG ZoneStartLBA : 48;
  ULONGLONG Reserved4 : 16;
  ULONGLONG WritePointerLBA : 48;
  ULONGLONG Reserved5 : 16;
  UCHAR     Reserved6[32];
} ATA_ZONE_DESCRIPTOR, *PATA_ZONE_DESCRIPTOR;