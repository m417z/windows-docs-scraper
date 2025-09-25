HRESULT Map(
  [in]            ID3D11Resource           *pResource,
  [in]            UINT                     Subresource,
  [in]            D3D11_MAP                MapType,
  [in]            UINT                     MapFlags,
  [out, optional] D3D11_MAPPED_SUBRESOURCE *pMappedResource
);