HRESULT CreateDirect3D12HardwareProtectedBackBufferResource(
  ID3D12Device                   *pDevice,
  D3D12_RESOURCE_DESC            *pTexture2DDesc,
  ID3D12ProtectedResourceSession *pProtectedResourceSession,
  ID3D12Resource                 **ppCreatedTexture2DResource
);