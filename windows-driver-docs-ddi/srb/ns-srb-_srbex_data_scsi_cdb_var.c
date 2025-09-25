typedef struct _SRBEX_DATA_SCSI_CDB_VAR {
  SRBEXDATATYPE       Type;
  ULONG               Length;
  UCHAR               ScsiStatus;
  UCHAR               SenseInfoBufferLength;
  UCHAR               Reserved[2];
  ULONG               CdbLength;
  ULONG               Reserved1[2];
  PVOID POINTER_ALIGN SenseInfoBuffer;
  UCHAR POINTER_ALIGN Cdb[ANYSIZE_ARRAY];
} SRBEX_DATA_SCSI_CDB_VAR, *PSRBEX_DATA_SCSI_CDB_VAR;