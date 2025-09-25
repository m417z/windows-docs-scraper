typedef struct _DXGKARG_SIGNALMONITOREDFENCE {
  DXGK_KERNEL_SUBMISSION_TYPE KernelSubmissionType;
  VOID                        *pDmaBuffer;
  D3DGPU_VIRTUAL_ADDRESS      DmaBufferGpuVirtualAddress;
  UINT                        DmaSize;
  VOID                        *pDmaBufferPrivateData;
  UINT                        DmaBufferPrivateDataSize;
  UINT                        MultipassOffset;
  D3DGPU_VIRTUAL_ADDRESS      MonitoredFenceGpuVa;
  UINT64                      MonitoredFenceValue;
  VOID                        *MonitoredFenceCpuVa;
  HANDLE                      hHwQueue;
} DXGKARG_SIGNALMONITOREDFENCE;