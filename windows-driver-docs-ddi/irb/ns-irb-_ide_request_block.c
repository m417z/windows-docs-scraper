typedef struct _IDE_REQUEST_BLOCK {
  USHORT Function;
  UCHAR  IrbStatus;
  UCHAR  AtaStatus;
  UCHAR  AtaError;
  UCHAR  Channel;
  UCHAR  TargetId;
  UCHAR  Lun;
  UCHAR  CdbLength;
  UCHAR  SenseInfoBufferLength;
  UCHAR  SenseInfoBufferType;
  UCHAR  QueueTag;
  ULONG  ReservedAsUlong;
  ULONG  IrbFlags;
  ULONG  TimeOutValue;
  ULONG  DataTransferLength;
  PVOID  IrbExtension;
  PVOID  DataBuffer;
  PVOID  SenseInfoBuffer;
  PVOID  NextIrb;
  PVOID  Reserved;
  union {
    IDE_TASK_FILE  IdeTaskFile;
    UCHAR          Cdb[16];
    IDE_POWER_INFO PowerChange;
    UCHAR          AsUChar[16];
  };
} IDE_REQUEST_BLOCK, *PIDE_REQUEST_BLOCK;