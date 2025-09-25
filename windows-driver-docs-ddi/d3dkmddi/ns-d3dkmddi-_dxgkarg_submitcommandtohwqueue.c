typedef struct _DXGKARG_SUBMITCOMMANDTOHWQUEUE {
  [in] HANDLE                  hHwQueue;
       UINT64                  HwQueueProgressFenceId;
       D3DGPU_VIRTUAL_ADDRESS  DmaBufferVirtualAddress;
       UINT                    DmaBufferSize;
       UINT                    DmaBufferPrivateDataSize;
       VOID                    *pDmaBufferPrivateData;
       DXGK_SUBMITCOMMANDFLAGS Flags;
       D3DGPU_VIRTUAL_ADDRESS  HwQueueProgressFenceGpuVa;
       VOID                    *HwQueueProgressFenceCpuVa;
} DXGKARG_SUBMITCOMMANDTOHWQUEUE;