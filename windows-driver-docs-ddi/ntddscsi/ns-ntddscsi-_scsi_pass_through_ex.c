typedef struct _SCSI_PASS_THROUGH_EX {
  ULONG     Version;
  ULONG     Length;
  ULONG     CdbLength;
  ULONG     StorAddressLength;
  UCHAR     ScsiStatus;
  UCHAR     SenseInfoLength;
  UCHAR     DataDirection;
  UCHAR     Reserved;
  ULONG     TimeOutValue;
  ULONG     StorAddressOffset;
  ULONG     SenseInfoOffset;
  ULONG     DataOutTransferLength;
  ULONG     DataInTransferLength;
  ULONG_PTR DataOutBufferOffset;
  ULONG_PTR DataInBufferOffset;
  UCHAR     Cdb[ANYSIZE_ARRAY];
} SCSI_PASS_THROUGH_EX, *PSCSI_PASS_THROUGH_EX;