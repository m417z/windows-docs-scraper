HRESULT CreateCommittedResource3(
  const D3D12_HEAP_PROPERTIES    *pHeapProperties,
  D3D12_HEAP_FLAGS               HeapFlags,
  const D3D12_RESOURCE_DESC1     *pDesc,
  D3D12_BARRIER_LAYOUT           InitialLayout,
  const D3D12_CLEAR_VALUE        *pOptimizedClearValue,
  ID3D12ProtectedResourceSession *pProtectedSession,
  UINT32                         NumCastableFormats,
  const DXGI_FORMAT              *pCastableFormats,
  REFIID                         riidResource,
  void                           **ppvResource
);