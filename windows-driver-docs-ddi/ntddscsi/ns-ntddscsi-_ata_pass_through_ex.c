typedef struct _ATA_PASS_THROUGH_EX {
  USHORT    Length;
  USHORT    AtaFlags;
  UCHAR     PathId;
  UCHAR     TargetId;
  UCHAR     Lun;
  UCHAR     ReservedAsUchar;
  ULONG     DataTransferLength;
  ULONG     TimeOutValue;
  ULONG     ReservedAsUlong;
  ULONG_PTR DataBufferOffset;
  UCHAR     PreviousTaskFile[8];
  UCHAR     CurrentTaskFile[8];
} ATA_PASS_THROUGH_EX, *PATA_PASS_THROUGH_EX;