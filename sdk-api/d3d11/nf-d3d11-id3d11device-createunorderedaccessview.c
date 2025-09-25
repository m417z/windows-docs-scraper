HRESULT CreateUnorderedAccessView(
  [in]            ID3D11Resource                         *pResource,
  [in, optional]  const D3D11_UNORDERED_ACCESS_VIEW_DESC *pDesc,
  [out, optional] ID3D11UnorderedAccessView              **ppUAView
);