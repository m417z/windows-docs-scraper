typedef struct _D3DDDI_DRIVERESCAPE_BUILDTESTCOMMANDBUFFER {
  D3DDDI_DRIVERESCAPETYPE            EscapeType;
  D3DKMT_HANDLE                      hDevice;
  D3DKMT_HANDLE                      hContext;
  D3DDDI_BUILDTESTCOMMANDBUFFERFLAGS Flags;
  D3DDDI_TESTCOMMANDBUFFER           Command;
  PVOID                              pDmaBuffer;
  PVOID                              pDmaBufferPrivateData;
  UINT                               DmaBufferSize;
  UINT                               DmaBufferPrivateDataSize;
} D3DDDI_DRIVERESCAPE_BUILDTESTCOMMANDBUFFER;