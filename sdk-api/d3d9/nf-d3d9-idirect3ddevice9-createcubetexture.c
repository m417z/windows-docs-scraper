HRESULT CreateCubeTexture(
  [in]          UINT                  EdgeLength,
  [in]          UINT                  Levels,
  [in]          DWORD                 Usage,
  [in]          D3DFORMAT             Format,
  [in]          D3DPOOL               Pool,
  [out, retval] IDirect3DCubeTexture9 **ppCubeTexture,
  [in]          HANDLE                *pSharedHandle
);