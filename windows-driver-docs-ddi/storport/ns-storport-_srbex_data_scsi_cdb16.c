typedef struct _SRBEX_DATA_SCSI_CDB16 {
  SRBEXDATATYPE       Type;
  ULONG               Length;
  UCHAR               ScsiStatus;
  UCHAR               SenseInfoBufferLength;
  UCHAR               CdbLength;
  UCHAR               Reserved;
  ULONG               Reserved1;
  PVOID POINTER_ALIGN SenseInfoBuffer;
  UCHAR POINTER_ALIGN Cdb[16];
} SRBEX_DATA_SCSI_CDB16, *PSRBEX_DATA_SCSI_CDB16;