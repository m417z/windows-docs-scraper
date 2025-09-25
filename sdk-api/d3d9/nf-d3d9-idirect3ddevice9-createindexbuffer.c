HRESULT CreateIndexBuffer(
  [in]          UINT                  Length,
  [in]          DWORD                 Usage,
  [in]          D3DFORMAT             Format,
  [in]          D3DPOOL               Pool,
  [out, retval] IDirect3DIndexBuffer9 **ppIndexBuffer,
  [in]          HANDLE                *pSharedHandle
);