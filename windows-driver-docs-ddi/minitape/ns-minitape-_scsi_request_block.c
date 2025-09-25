typedef struct _SCSI_REQUEST_BLOCK {
  USHORT                     Length;
  UCHAR                      Function;
  UCHAR                      SrbStatus;
  UCHAR                      ScsiStatus;
  UCHAR                      PathId;
  UCHAR                      TargetId;
  UCHAR                      Lun;
  UCHAR                      QueueTag;
  UCHAR                      QueueAction;
  UCHAR                      CdbLength;
  UCHAR                      SenseInfoBufferLength;
  ULONG                      SrbFlags;
  ULONG                      DataTransferLength;
  ULONG                      TimeOutValue;
  PVOID                      DataBuffer;
  PVOID                      SenseInfoBuffer;
  struct _SCSI_REQUEST_BLOCK *NextSrb;
  PVOID                      OriginalRequest;
  PVOID                      SrbExtension;
  union {
    ULONG InternalStatus;
    ULONG QueueSortKey;
    ULONG LinkTimeoutValue;
  };
  ULONG                      Reserved;
  UCHAR                      Cdb[16];
} SCSI_REQUEST_BLOCK, *PSCSI_REQUEST_BLOCK;