typedef struct _DXGKARG_CANCELCOMMAND {
  [in]  HANDLE                         hContext;
  [out] VOID                           *pDmaBuffer;
  [in]  UINT                           DmaBufferSize;
  [in]  UINT                           DmaBufferSubmissionStartOffset;
  [in]  UINT                           DmaBufferSubmissionEndOffset;
  [in]  VOID                           *pDmaBufferPrivateData;
  [in]  UINT                           DmaBufferPrivateDataSize;
  [in]  UINT                           DmaBufferPrivateDataSubmissionStartOffset;
  [in]  UINT                           DmaBufferPrivateDataSubmissionEndOffset;
  [in]  const DXGK_ALLOCATIONLIST      *pAllocationList;
  [in]  UINT                           AllocationListSize;
  [in]  const D3DDDI_PATCHLOCATIONLIST *pPatchLocationList;
  [in]  UINT                           PatchLocationListSize;
  [in]  UINT                           PatchLocationListSubmissionStart;
  [in]  UINT                           PatchLocationListSubmissionLength;
        D3DGPU_VIRTUAL_ADDRESS         DmaBufferVirtualAddress;
        UINT                           DmaBufferUmdPrivateDataSize;
} DXGKARG_CANCELCOMMAND;