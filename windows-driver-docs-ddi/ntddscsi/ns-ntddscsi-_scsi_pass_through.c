typedef struct _SCSI_PASS_THROUGH {
  USHORT    Length;
  UCHAR     ScsiStatus;
  UCHAR     PathId;
  UCHAR     TargetId;
  UCHAR     Lun;
  UCHAR     CdbLength;
  UCHAR     SenseInfoLength;
  UCHAR     DataIn;
  ULONG     DataTransferLength;
  ULONG     TimeOutValue;
  ULONG_PTR DataBufferOffset;
  ULONG     SenseInfoOffset;
  UCHAR     Cdb[16];
} SCSI_PASS_THROUGH, *PSCSI_PASS_THROUGH;