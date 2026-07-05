typedef struct _DXGKARG_CREATEDOORBELL {
  HANDLE                       hHwQueue;
  UINT                         PrivateDriverDataSize;
  void                         *PrivateDriverData;
  HANDLE                       hRingBuffer;
  HANDLE                       hRingBufferControl;
  DXGKARG_CREATEDOORBELL_FLAGS Flags;
} DXGKARG_CREATEDOORBELL;