typedef struct _IRB_REQ_CONTROL {
  ULONG ulIoControlCode;
  PMDL  pInBuffer;
  ULONG ulInBufferLength;
  PMDL  pOutBuffer;
  ULONG ulOutBufferLength;
  ULONG BytesReturned;
} IRB_REQ_CONTROL;