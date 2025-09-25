HRESULT CreateReservedResource2(
       const D3D12_RESOURCE_DESC      *pDesc,
       D3D12_BARRIER_LAYOUT           InitialLayout,
       const D3D12_CLEAR_VALUE        *pOptimizedClearValue,
       ID3D12ProtectedResourceSession *pProtectedSession,
       UINT32                         NumCastableFormats,
       const DXGI_FORMAT              *pCastableFormats,
  [in] REFIID                         riid,
       void                           **ppvResource
);