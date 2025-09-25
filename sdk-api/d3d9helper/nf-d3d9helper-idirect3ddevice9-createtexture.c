HRESULT CreateTexture(
  [in]          UINT              Width,
  [in]          UINT              Height,
  [in]          UINT              Levels,
  [in]          DWORD             Usage,
  [in]          D3DFORMAT         Format,
  [in]          D3DPOOL           Pool,
  [out, retval] IDirect3DTexture9 **ppTexture,
  [in]          HANDLE            *pSharedHandle
);