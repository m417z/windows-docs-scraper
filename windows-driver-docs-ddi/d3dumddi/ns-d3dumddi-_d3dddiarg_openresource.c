typedef struct _D3DDDIARG_OPENRESOURCE {
  [in]     UINT                      NumAllocations;
  union {
    [in]     D3DDDI_OPENALLOCATIONINFO  *pOpenAllocationInfo;
             D3DDDI_OPENALLOCATIONINFO2 *pOpenAllocationInfo2;
  };
  [in]     D3DDDI_OPENALLOCATIONINFO *pOpenAllocationInfo;
  [in]     D3DKMT_HANDLE             hKMResource;
  [in]     VOID                      *pPrivateDriverData;
  [in]     UINT                      PrivateDriverDataSize;
  [in/out] HANDLE                    hResource;
  [in]     D3DDDI_ROTATION           Rotation;
  [in]     D3DDDI_OPENRESOURCEFLAGS  Flags;
} D3DDDIARG_OPENRESOURCE;