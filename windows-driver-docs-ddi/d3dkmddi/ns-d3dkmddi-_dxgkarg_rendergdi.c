typedef struct _DXGKARG_RENDERGDI {
  const VOID             *pCommand;
  UINT                   CommandLength;
  VOID                   *pDmaBuffer;
  D3DGPU_VIRTUAL_ADDRESS DmaBufferGpuVirtualAddress;
  UINT                   DmaSize;
  VOID                   *pDmaBufferPrivateData;
  UINT                   DmaBufferPrivateDataSize;
  DXGK_ALLOCATIONLIST    *pAllocationList;
  UINT                   AllocationListSize;
  UINT                   MultipassOffset;
} DXGKARG_RENDERGDI;