typedef struct _SRBEX_DATA_SCSI_CDB32 {
  SRBEXDATATYPE       Type;
  ULONG               Length;
  UCHAR               ScsiStatus;
  UCHAR               SenseInfoBufferLength;
  UCHAR               CdbLength;
  UCHAR               Reserved;
  ULONG               Reserved1;
  PVOID POINTER_ALIGN SenseInfoBuffer;
  UCHAR POINTER_ALIGN Cdb[32];
} SRBEX_DATA_SCSI_CDB32, *PSRBEX_DATA_SCSI_CDB32;