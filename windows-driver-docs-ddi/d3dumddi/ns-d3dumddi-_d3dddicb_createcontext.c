typedef struct _D3DDDICB_CREATECONTEXT {
  [in]  UINT                      NodeOrdinal;
  [in]  UINT                      EngineAffinity;
  [in]  D3DDDI_CREATECONTEXTFLAGS Flags;
  [in]  VOID                      *pPrivateDriverData;
  [in]  UINT                      PrivateDriverDataSize;
  [out] HANDLE                    hContext;
  [out] VOID                      *pCommandBuffer;
  [out] UINT                      CommandBufferSize;
  [out] D3DDDI_ALLOCATIONLIST     *pAllocationList;
  [out] UINT                      AllocationListSize;
  [out] D3DDDI_PATCHLOCATIONLIST  *pPatchLocationList;
  [out] UINT                      PatchLocationListSize;
        D3DGPU_VIRTUAL_ADDRESS    CommandBuffer;
} D3DDDICB_CREATECONTEXT;