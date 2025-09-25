typedef struct _IRB_REQ_ASYNC_LOCK {
  IO_ADDRESS DestinationAddress;
  ULONG      nNumberOfArgBytes;
  ULONG      nNumberOfDataBytes;
  ULONG      fulTransactionType;
  ULONG      fulFlags;
  ULONG      Arguments[2];
  ULONG      DataValues[2];
  PVOID      pBuffer;
  ULONG      ulGeneration;
  UCHAR      chPriority;
  UCHAR      nSpeed;
  UCHAR      tCode;
  UCHAR      Reserved;
} IRB_REQ_ASYNC_LOCK;