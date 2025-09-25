HRESULT CreateVideoSurface(
  [in]      UINT                Width,
  [in]      UINT                Height,
  [in]      D3DFORMAT           Format,
  [in]      D3DPOOL             Pool,
  [in]      DWORD               Usage,
  [in]      DXVAHD_SURFACE_TYPE Type,
  [in]      UINT                NumSurfaces,
  [out]     IDirect3DSurface9   **ppSurfaces,
  [in, out] HANDLE              *pSharedHandle
);