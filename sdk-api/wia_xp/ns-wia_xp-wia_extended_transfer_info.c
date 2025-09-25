typedef struct _WIA_EXTENDED_TRANSFER_INFO {
  ULONG ulSize;
  ULONG ulMinBufferSize;
  ULONG ulOptimalBufferSize;
  ULONG ulMaxBufferSize;
  ULONG ulNumBuffers;
} WIA_EXTENDED_TRANSFER_INFO, *PWIA_EXTENDED_TRANSFER_INFO;