typedef struct _DXGKARG_RENDER {
  [in]     const VOID               *pCommand;
  [in]     UINT                     CommandLength;
  [out]    VOID                     *pDmaBuffer;
  [in]     UINT                     DmaSize;
  [in]     VOID                     *pDmaBufferPrivateData;
  [in]     UINT                     DmaBufferPrivateDataSize;
  [in]     DXGK_ALLOCATIONLIST      *pAllocationList;
  [in]     UINT                     AllocationListSize;
  [in]     D3DDDI_PATCHLOCATIONLIST *pPatchLocationListIn;
  [in]     UINT                     PatchLocationListInSize;
  [in/out] D3DDDI_PATCHLOCATIONLIST *pPatchLocationListOut;
  [in]     UINT                     PatchLocationListOutSize;
  [in/out] UINT                     MultipassOffset;
  [in]     UINT                     DmaBufferSegmentId;
  [in]     PHYSICAL_ADDRESS         DmaBufferPhysicalAddress;
} DXGKARG_RENDER;