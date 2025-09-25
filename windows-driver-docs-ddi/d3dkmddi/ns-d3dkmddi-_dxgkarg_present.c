typedef struct _DXGKARG_PRESENT {
  [out]    VOID                     *pDmaBuffer;
  [in]     UINT                     DmaSize;
  [in]     VOID                     *pDmaBufferPrivateData;
  [in]     UINT                     DmaBufferPrivateDataSize;
  union {
    [in]     DXGK_ALLOCATIONLIST               *pAllocationList;
    [in]     DXGK_PRESENTALLOCATIONINFO        *pAllocationInfo;
    [in]     DXGK_PRESENTMULTIPLANEOVERLAYINFO *pPresentMultiPlaneOverlayInfo;
  };
#if ...
  [in/out] D3DDDI_PATCHLOCATIONLIST *pPatchLocationListOut;
#if ...
  [in]     UINT                     PatchLocationListOutSize;
  [in]     DXGK_ALLOCATIONLIST      *pAllocationList;
#else
  [in/out] D3DDDI_PATCHLOCATIONLIST *pPatchLocationListOut;
#endif
#else
  [in]     UINT                     PatchLocationListOutSize;
#endif
  [in/out] UINT                     MultipassOffset;
  [in]     UINT                     Color;
  [in]     RECT                     DstRect;
  [in]     RECT                     SrcRect;
  [in]     UINT                     SubRectCnt;
  [in]     const RECT               *pDstSubRects;
  [in]     D3DDDI_FLIPINTERVAL_TYPE FlipInterval;
  [in]     DXGK_PRESENTFLAGS        Flags;
  [in]     UINT                     DmaBufferSegmentId;
  [in]     PHYSICAL_ADDRESS         DmaBufferPhysicalAddress;
  [in]     UINT                     Reserved;
           D3DGPU_VIRTUAL_ADDRESS   DmaBufferGpuVirtualAddress;
           UINT                     NumSrcAllocations;
           UINT                     NumDstAllocations;
           UINT                     PrivateDriverDataSize;
           PVOID                    pPrivateDriverData;
} DXGKARG_PRESENT;