HRESULT CreateOffscreenPlainSurface(
  [in]          UINT              Width,
  [in]          UINT              Height,
  [in]          D3DFORMAT         Format,
  [in]          D3DPOOL           Pool,
  [out, retval] IDirect3DSurface9 **ppSurface,
  [in]          HANDLE            *pSharedHandle
);