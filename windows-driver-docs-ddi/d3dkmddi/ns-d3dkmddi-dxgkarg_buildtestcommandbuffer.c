typedef struct _DXGKARG_BUILDTESTCOMMANDBUFFER {
  HANDLE                             hContext;
  D3DDDI_TESTCOMMANDBUFFER           Command;
  PVOID                              pDmaBuffer;
  PVOID                              pDmaBufferPrivateData;
  UINT                               DmaBufferSize;
  UINT                               DmaBufferPrivateDataSize;
  D3DDDI_BUILDTESTCOMMANDBUFFERFLAGS Flags;
} DXGKARG_BUILDTESTCOMMANDBUFFER;