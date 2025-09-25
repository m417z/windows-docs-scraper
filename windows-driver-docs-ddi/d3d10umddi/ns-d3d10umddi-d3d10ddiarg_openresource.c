typedef struct D3D10DDIARG_OPENRESOURCE {
  [in] UINT                      NumAllocations;
  union {
    [in] D3DDDI_OPENALLOCATIONINFO  *pOpenAllocationInfo;
         D3DDDI_OPENALLOCATIONINFO2 *pOpenAllocationInfo2;
  };
  [in] D3DDDI_OPENALLOCATIONINFO *pOpenAllocationInfo;
  [in] D3D10DDI_HKMRESOURCE      hKMResource;
  [in] VOID                      *pPrivateDriverData;
  [in] UINT                      PrivateDriverDataSize;
} D3D10DDIARG_OPENRESOURCE;