typedef struct _D3DDDIARG_LOCK {
  [in]  HANDLE           hResource;
  [in]  UINT             SubResourceIndex;
  union {
    [in]  D3DDDIRANGE Range;
    [in]  RECT        Area;
    [in]  D3DDDIBOX   Box;
  };
  [out] VOID             *pSurfData;
  [out] UINT             Pitch;
  [out] UINT             SlicePitch;
  [in]  D3DDDI_LOCKFLAGS Flags;
} D3DDDIARG_LOCK;