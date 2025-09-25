typedef struct _IRB_REQ_ASYNC_STREAM {
  ULONG nNumberOfBytesToStream;
  ULONG fulFlags;
  PMDL  Mdl;
  ULONG ulTag;
  ULONG nChannel;
  ULONG ulSynch;
  ULONG Reserved;
  UCHAR nSpeed;
} IRB_REQ_ASYNC_STREAM;