typedef struct _DXGKARG_CREATEDOORBELL {
  HANDLE                       hHwQueue;
  HANDLE                       hDoorbell;
  UINT                         PrivateDriverDataSize;
  void                         *PrivateDriverData;
  HANDLE                       hRingBuffer;
  HANDLE                       hRingBufferControl;
  DXGKARG_CREATEDOORBELL_FLAGS Flags;
} DXGKARG_CREATEDOORBELL;