HRESULT CreateVertexBuffer(
  [in]          UINT                   Length,
  [in]          DWORD                  Usage,
  [in]          DWORD                  FVF,
  [in]          D3DPOOL                Pool,
  [out, retval] IDirect3DVertexBuffer9 **ppVertexBuffer,
  [in]          HANDLE                 *pSharedHandle
);