HRESULT ReturnUnderlyingResource(
  [in] ID3D11Resource *pResource11,
  [in] UINT           NumSync,
  [in] UINT64         *pSignalValues,
  [in] ID3D12Fence    **ppFences
);