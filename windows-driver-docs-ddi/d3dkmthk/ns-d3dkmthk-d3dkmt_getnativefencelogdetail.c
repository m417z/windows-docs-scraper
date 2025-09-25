typedef struct _D3DKMT_GETNATIVEFENCELOGDETAIL {
  D3DKMT_HANDLE                        hHwQueue;
  D3DKMT_GETNATIVEFENCELOGDETAIL_FLAGS Flags;
  UINT32                               WaitLogNumberOfEntries;
  UINT32                               SignalLogNumberOfEntries;
  D3DGPU_VIRTUAL_ADDRESS               WaitLogGpuBaseAddress;
  D3DGPU_VIRTUAL_ADDRESS               SignalLogGpuBaseAddress;
  BYTE                                 Reserved[64];
} D3DKMT_GETNATIVEFENCELOGDETAIL;