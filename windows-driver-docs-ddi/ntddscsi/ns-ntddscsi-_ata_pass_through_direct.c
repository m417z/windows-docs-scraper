typedef struct _ATA_PASS_THROUGH_DIRECT {
  USHORT Length;
  USHORT AtaFlags;
  UCHAR  PathId;
  UCHAR  TargetId;
  UCHAR  Lun;
  UCHAR  ReservedAsUchar;
  ULONG  DataTransferLength;
  ULONG  TimeOutValue;
  ULONG  ReservedAsUlong;
  PVOID  DataBuffer;
  UCHAR  PreviousTaskFile[8];
  UCHAR  CurrentTaskFile[8];
} ATA_PASS_THROUGH_DIRECT, *PATA_PASS_THROUGH_DIRECT;