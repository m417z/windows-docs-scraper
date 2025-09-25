typedef struct _D3DDDI_SURFACEINFO {
  [in] UINT       Width;
  [in] UINT       Height;
  [in] UINT       Depth;
  [in] const VOID *pSysMem;
  [in] UINT       SysMemPitch;
  [in] UINT       SysMemSlicePitch;
} D3DDDI_SURFACEINFO;