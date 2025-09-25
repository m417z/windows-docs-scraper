typedef struct _SCSISCAN_INFO {
  ULONG Size;
  ULONG Flags;
  UCHAR PortNumber;
  UCHAR PathId;
  UCHAR TargetId;
  UCHAR Lun;
  UCHAR AdapterName[MAX_STRING];
  ULONG Reserved;
} SCSISCAN_INFO, *PSCSISCAN_INFO;