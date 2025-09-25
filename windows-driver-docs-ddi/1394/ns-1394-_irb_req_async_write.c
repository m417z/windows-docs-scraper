typedef struct _IRB_REQ_ASYNC_WRITE {
  IO_ADDRESS DestinationAddress;
  ULONG      nNumberOfBytesToWrite;
  ULONG      nBlockSize;
  ULONG      fulFlags;
  PMDL       Mdl;
  ULONG      ulGeneration;
  UCHAR      chPriority;
  UCHAR      nSpeed;
  UCHAR      tCode;
  UCHAR      Reserved;
  ULONG      ElapsedTime;
} IRB_REQ_ASYNC_WRITE;