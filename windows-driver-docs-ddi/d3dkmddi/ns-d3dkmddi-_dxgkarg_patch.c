typedef struct _DXGKARG_PATCH {
  union {
    [in] HANDLE hDevice;
    [in] HANDLE hContext;
  };
  [in] UINT                           DmaBufferSegmentId;
  [in] PHYSICAL_ADDRESS               DmaBufferPhysicalAddress;
  [in] VOID                           *pDmaBuffer;
  [in] UINT                           DmaBufferSize;
  [in] UINT                           DmaBufferSubmissionStartOffset;
  [in] UINT                           DmaBufferSubmissionEndOffset;
  [in] VOID                           *pDmaBufferPrivateData;
  [in] UINT                           DmaBufferPrivateDataSize;
  [in] UINT                           DmaBufferPrivateDataSubmissionStartOffset;
  [in] UINT                           DmaBufferPrivateDataSubmissionEndOffset;
  [in] const DXGK_ALLOCATIONLIST      *pAllocationList;
  [in] UINT                           AllocationListSize;
  [in] const D3DDDI_PATCHLOCATIONLIST *pPatchLocationList;
  [in] UINT                           PatchLocationListSize;
  [in] UINT                           PatchLocationListSubmissionStart;
  [in] UINT                           PatchLocationListSubmissionLength;
  [in] UINT                           SubmissionFenceId;
  [in] DXGK_PATCHFLAGS                Flags;
  [in] UINT                           EngineOrdinal;
} DXGKARG_PATCH;