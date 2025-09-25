typedef struct _D3DDDIARG_LOCKASYNC {
  [in]  HANDLE                 hResource;
  [in]  UINT                   SubResourceIndex;
  [in]  D3DDDI_LOCKASYNCFLAGS  Flags;
  union {
    [in]  D3DDDIRANGE Range;
    [in]  RECT        Area;
    [in]  D3DDDIBOX   Box;
  };
  [out] HANDLE                 hCookie;
  [out] VOID                   *pSurfData;
  [out] UINT                   Pitch;
  [out] UINT                   SlicePitch;
        D3DGPU_VIRTUAL_ADDRESS GpuVirtualAddress;
} D3DDDIARG_LOCKASYNC;