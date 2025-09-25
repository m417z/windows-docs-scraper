typedef struct _D3DKMT_CREATE_DOORBELL {
  D3DKMT_HANDLE                hHwQueue;
  D3DKMT_HANDLE                hRingBuffer;
  D3DKMT_HANDLE                hRingBufferControl;
  D3DKMT_CREATE_DOORBELL_FLAGS Flags;
  UINT                         PrivateDriverDataSize;
  VOID                         *PrivateDriverData;
  VOID                         *DoorbellCPUVirtualAddress;
  VOID                         *DoorbellSecondaryCPUVirtualAddress;
  VOID                         *DoorbellStatusCPUVirtualAddress;
  VOID                         *HwQueueProgressFenceLastQueuedValueCPUVirtualAddress;
  D3DKMT_HANDLE                hDoorbell;
} D3DKMT_CREATE_DOORBELL;