typedef struct _D3DKMT_RENDER {
  union {
    [in]     D3DKMT_HANDLE hDevice;
    [in]     D3DKMT_HANDLE hContext;
  };
  [in]     UINT                                  CommandOffset;
  [in]     UINT                                  CommandLength;
  [in]     UINT                                  AllocationCount;
  [in]     UINT                                  PatchLocationCount;
  [out]    VOID                                  *pNewCommandBuffer;
  [in/out] UINT                                  NewCommandBufferSize;
  [out]    D3DDDI_ALLOCATIONLIST                 *pNewAllocationList;
  [in/out] UINT                                  NewAllocationListSize;
  [out]    D3DDDI_PATCHLOCATIONLIST              *pNewPatchLocationList;
  [in/out] UINT                                  NewPatchLocationListSize;
  [in]     D3DKMT_RENDERFLAGS                    Flags;
  [in]     D3DKMT_ALIGN64 ULONGLONG              PresentHistoryToken;
  [in]     ULONG                                 BroadcastContextCount;
           D3DKMT_HANDLE                         BroadcastContext[D3DDDI_MAX_BROADCAST_CONTEXT];
  [out]    ULONG                                 QueuedBufferCount;
  [out]    D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS NewCommandBuffer;
           VOID                                  *pPrivateDriverData;
           UINT                                  PrivateDriverDataSize;
} D3DKMT_RENDER;