HRESULT CreateSurface(
  [in]      UINT              Width,
  [in]      UINT              Height,
  [in]      UINT              BackBuffers,
  [in]      D3DFORMAT         Format,
  [in]      D3DPOOL           Pool,
  [in]      DWORD             Usage,
  [in]      DWORD             DxvaType,
  [out]     IDirect3DSurface9 **ppSurface,
  [in, out] HANDLE            *pSharedHandle
);