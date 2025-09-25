HRESULT CreateVolumeTexture(
  [in]          UINT                    Width,
  [in]          UINT                    Height,
  [in]          UINT                    Depth,
  [in]          UINT                    Levels,
  [in]          DWORD                   Usage,
  [in]          D3DFORMAT               Format,
  [in]          D3DPOOL                 Pool,
  [out, retval] IDirect3DVolumeTexture9 **ppVolumeTexture,
  [in]          HANDLE                  *pSharedHandle
);