HRESULT CreateRenderTargetEx(
  [in]          UINT                Width,
  [in]          UINT                Height,
  [in]          D3DFORMAT           Format,
  [in]          D3DMULTISAMPLE_TYPE MultiSample,
  [in]          DWORD               MultisampleQuality,
  [in]          BOOL                Lockable,
  [out, retval] IDirect3DSurface9   **ppSurface,
  [in]          HANDLE              *pSharedHandle,
  [in]          DWORD               Usage
);