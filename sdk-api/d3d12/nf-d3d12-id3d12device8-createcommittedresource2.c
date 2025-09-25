HRESULT CreateCommittedResource2(
  const D3D12_HEAP_PROPERTIES    *pHeapProperties,
  D3D12_HEAP_FLAGS               HeapFlags,
  const D3D12_RESOURCE_DESC1     *pDesc,
  D3D12_RESOURCE_STATES          InitialResourceState,
  const D3D12_CLEAR_VALUE        *pOptimizedClearValue,
  ID3D12ProtectedResourceSession *pProtectedSession,
  REFIID                         riidResource,
  void                           **ppvResource
);